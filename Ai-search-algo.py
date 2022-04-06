#1) dfs and bfs algo for graphs usnig classes

# Input
# 5
# 4
# a,b
# a,c
# a,d
# b,e
import heapq
import queue

class graph():


    def __init__(self):
        self.nodes = int(input("enter the number of nodes: "))
        self.edges = int(input("enter the number of edges: "))
        self.graph_using_adj_list = {}
        self.type_uni_or_bi = bool(input("True for Bi-Directional and False for Uni-Directional: "))


        for i in range(0, self.edges):
            u, v, w= tuple(input("enter the elements that have edges along with their weight: "). split(" "))
            print(u, " <-> ", v, ", weight is: ", w)

            #for integer elments in graph
            #u=int(u)
            #v=int(v)
            w=int(w)

            if u in self.graph_using_adj_list.keys():
                self.graph_using_adj_list[u].append((w, v))
            else:
                self.graph_using_adj_list[u] = [(w, v)];

            if(self.type_uni_or_bi == True):

                if v in self.graph_using_adj_list.keys():
                    self.graph_using_adj_list[v].append((w, u))
                else:
                    self.graph_using_adj_list[v] = [(w, u)];


    def print_graph(self):
        for key in self.graph_using_adj_list.keys():
            print("{0} -> ".format(key), end = "")
  
            for val in self.graph_using_adj_list[key]:
                print("{0} , ".format(val), end = "")
            print()


    def _dfs_helper(self, curremt_state_DFS, visited_DFS, goal_state_DFS):
        if(visited_DFS[curremt_state_DFS]):
            return False

        print(curremt_state_DFS)
        visited_DFS[curremt_state_DFS] = True

        if(curremt_state_DFS == goal_state_DFS):
            return True

        for i in range(0, len(self.graph_using_adj_list[curremt_state_DFS])):
            for neigh_DFS in self.graph_using_adj_list[curremt_state_DFS][i][1]:
                # print("\t",self.graph_using_adj_list[curremt_state_DFS][i][1])
                if(self._dfs_helper(neigh_DFS, visited_DFS, goal_state_DFS)):
                    return True

        return False


    def DFS(self, start_state_DFS, goal_state_DFS):
        visited_DFS = {}

        for key in self.graph_using_adj_list.keys():
            visited_DFS[key]=False

        print("DFS START...")
        self._dfs_helper(start_state_DFS, visited_DFS, goal_state_DFS)
        print("DFS END...")


    def BFS(self, start_state_BFS, goal_state_BFS):
        print("BFS START...")
        visited_BFS = {}
        queue_BFS = []

        for key in self.graph_using_adj_list.keys():
            visited_BFS[key] = False

        queue_BFS.append(start_state_BFS)
        visited_BFS[start_state_BFS]=True
        
        while queue_BFS:
            # current_state_BFS = queue_BFS.pop(0)[0]
            current_state_BFS = queue_BFS.pop(0)
            print(current_state_BFS)

            if(current_state_BFS == goal_state_BFS):
                return

            for i in range(0, len(self.graph_using_adj_list[current_state_BFS])):
                for neigh in self.graph_using_adj_list[current_state_BFS][i][1]:

                    if(not visited_BFS[neigh]):
                        queue_BFS.append(neigh)
                        visited_BFS[neigh] = True


    def _dls_helper(self, curremt_state_DLS, visited_DLS, goal_state_DLS, stack_DLS, level, limit):
        if(visited_DLS[curremt_state_DLS]):
            return False

        print(curremt_state_DLS)
        visited_DLS[curremt_state_DLS] = True

        if(curremt_state_DLS == goal_state_DLS):
            return True

        if(level==limit):
            return False


        for i in range(0, len(self.graph_using_adj_list[curremt_state_DLS])):
            for neigh_DLS in self.graph_using_adj_list[curremt_state_DLS][i][1]:
                if(self._dls_helper(neigh_DLS, visited_DLS, goal_state_DLS, stack_DLS, level+1, limit)):
                    return True

        return False


    def DLS(self, start_state_DLS, goal_state_DLS, level, limit):
        visited_DLS = {}
        stack_DLS = []

        for key in self.graph_using_adj_list.keys():
            visited_DLS[key]=False

        print("DLS START...")
        self._dls_helper(start_state_DLS, visited_DLS, goal_state_DLS, stack_DLS, level, limit)
        print("DLS END...")

    
    # def dijkstra(self, start_node_dijistra):
    #     # The only criterium of adding a node to queue is if its distance has changed at the current step.
    #     minDistances = {}
    #     queue = [start_node_dijistra]
    #     minDistances[start_node_dijistra] = 0
    #     predecessor = {}

    #     for key in self.graph_using_adj_list.keys():
    #         minDistances[key] = float("inf")


    #     while queue:
    #         currentNode = queue.pop(0)

    #         # for i in range(0, len(self.graph_using_adj_list[currentNode])):
    #         #     for neighbor in self.graph_using_adj_list[currentNode][i][1]:
    #         #         print(self.graph_using_adj_list[currentNode][neighbor])

    #         for neighbor in self.graph_using_adj_list[currentNode]:
    #             # get potential newDist from start to neighbor
    #             newDist = minDistances[currentNode] + self.graph_using_adj_list[currentNode][neighbor]
                
    #             # if the newDist is shorter to reach neighbor updated to newDist
    #             if newDist < minDistances[neighbor]:
    #                 minDistances[neighbor] = min(newDist, minDistances[neighbor])
    #                 queue.append(neighbor)
    #                 predecessor[neighbor] = currentNode

    #     return minDistances, predecessor

    # shortest_path_cost, predecessor = dijkstra(directed_weighted_graph, 'a')
    # print("shortest_path_cost from node a to every nodes in graph:", shortest_path_cost, "\npredecessor dictionary:", predecessor)



    # def UCS(self, start_state_UCS, goal_state_UCS):
    #     visited_UCS={}
    #     queue_UCS = []
    #     li = [(0,start_state_UCS)]
    #     heapq.heapify(li)
    #     print (list(li))
    #     # print(goal_state_UCS)


    def ucs(G, v):
        visited = set()                  # set of visited nodes
        visited.add(v)                   # mark the starting vertex as visited
        q = queue.PriorityQueue()        # we store vertices in the (priority) queue as tuples with cumulative cost
        q.put((0, v))                    # add the starting node, this has zero *cumulative* cost   
        goal_node = None                 # this will be set as the goal node if one is found
        parents = {v:None}               # this dictionary contains the parent of each node, necessary for path construction

        while not q.empty():             # while the queue is nonempty
            dequeued_item = q.get()        
            current_node = dequeued_item[1]             # get node at top of queue
            current_node_priority = dequeued_item[0]    # get the cumulative priority for later

            if current_node.is_goal:                    # if the current node is the goal
                path_to_goal = [current_node]           # the path to the goal ends with the current node (obviously)
                prev_node = current_node                # set the previous node to be the current node (this will changed with each iteration)

                while prev_node != v:                   # go back up the path using parents, and add to path
                    parent = parents[prev_node]
                    path_to_goal.append(parent)   
                    prev_node = parent

                path_to_goal.reverse()                  # reverse the path
                return path_to_goal                     # return it

            else:
                for edge in current_node.out_edges:     # otherwise, for each adjacent node
                    child = edge.to()                   # (avoid calling .to() in future)

                    if child not in visited:            # if it is not visited
                        visited.add(child)              # mark it as visited
                        parents[child] = current_node   # set the current node as the parent of child
                        q.put((current_node_priority + edge.weight, child)) # and enqueue it with *cumulative* priority
        


g=graph()

g.print_graph()
print()

# g.DFS("a","g")
# print()

# g.BFS("a","g")
# print("BFS END...\n")

# limit=int(input("maximum level till u can go: \n"))
# level=0 #the starting level
# g.DLS("a", "g", level, limit)

g.ucs("a", "g")

# g.dijkstra("a")


# 8 puzzle problem using dfs

"""class eight_puzzle_probolem():

    def __init__(self):
        self.goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, -1]]
        self.size = 3

    def print_the_matrix(self, state):
        for list in state:
            for ele in list:
                print(ele, end=" ")
            print()
        print("====")

    def check_if_location_is_inside_the_matrix_or_not(self, current_location):
        x, y = current_location
        if(x<0 or y<0 or x>=self.size or y>=self.size):
            return False
        return True

    def find_location_of_space(self, current_state):
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if(current_state[i][j] == -1):
                    return i,j   #why don't we write about the case that -1 does not exist in the matrix

    def create_a_new_state_using_current_and_new_location(self, current_state, current_location, new_location):
        x1, y1 = current_location
        x2, y2 = new_location

        if(self.check_if_location_is_inside_the_matrix_or_not(new_location)):
            current_state[x1][y1], current_state[x2][y2] = current_state[x2][y2], current_state[x1][y1]

        return current_state

    def DFS(self, state):
        current_location=self.find_location_of_space(state)
        #print(current_location)

        visited_DFS={}
        stack_DFS=[current_location]
        count=0

        while (stack_DFS):
            new_location=stack_DFS.pop()
            state=self.create_a_new_state_using_current_and_new_location(state, current_location, new_location)

            state_str=str(state)
            if(state_str == str(self.goal_state)):
                print("No. of states iterated: ")
                print(count)
                print("Goal state reached: ")
                self.print_the_matrix(state)
                #print(visited_DFS)
                return

            self.print_the_matrix(state)
            count+=1

            if(not visited_DFS.get(state_str, False)):
                x,y=new_location

                #check if we can go up
                if(self.check_if_location_is_inside_the_matrix_or_not((x-1,y))):
                    stack_DFS.append((x-1,y))

                #check if we can go down
                if(self.check_if_location_is_inside_the_matrix_or_not((x+1,y))):
                    stack_DFS.append((x+1,y))

                #check if we can go right
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y+1))):
                    stack_DFS.append((x,y+1))

                #check if we can go left
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y-1))):
                    stack_DFS.append((x,y-1))

            else:
                state=self.create_a_new_state_using_current_and_new_location(state, new_location, current_location)

            current_location=self.find_location_of_space(state)
            visited_DFS[state_str]=True
        


g=eight_puzzle_probolem()
initial_state=[[1,2,3],[8,-1,4],[7,6,5]]
g.DFS(initial_state)"""




# 8 puzzle problem using bfs
#from queue import Queue

"""class eight_puzzle_probolem_using_BFS():

    def __init__(self):
        self.goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, -1]]
        self.size = 3

    def print_the_matrix(self, state):
        for list in state:
            for ele in list:
                print(ele, end=" ")
            print()
        print("====")

    def check_if_location_is_inside_the_matrix_or_not(self, current_location):
        x, y = current_location
        if(x<0 or y<0 or x>=self.size or y>=self.size):
            return False
        return True

    def find_location_of_space(self, current_state):
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if(current_state[i][j] == -1):
                    return i,j   #why don't we write about the case that -1 does not exist in the matrix

    def create_a_new_state_using_current_and_new_location(self, current_state, current_location, new_location):
        x1, y1 = current_location
        x2, y2 = new_location

        if(self.check_if_location_is_inside_the_matrix_or_not(new_location)):
            current_state[x1][y1], current_state[x2][y2] = current_state[x2][y2], current_state[x1][y1]

        return current_state

    def BFS(self, state):
        # self.print_the_matrix(state)
        current_location=self.find_location_of_space(state)
        # print(current_location)

        visited_BFS={}
        # print(visited_BFS)

        queue_BFS=[current_location]

        #queue_BFS=Queue()
        #queue_BFS.put(current_location)
        # print(queue_BFS.pop(0))
        count=0
        # print(count)

        while(queue_BFS):
            new_location=queue_BFS.pop(0)
            state=self.create_a_new_state_using_current_and_new_location(state, current_location, new_location)

            state_str=str(state)
            if(state_str == str(self.goal_state)):
                print("No. of states iterated: ")
                print(count)
                print("Goal state reached: ")
                self.print_the_matrix(state)
                return
                
            self.print_the_matrix(state)
            count+=1

            if(not visited_BFS.get(state_str, False)):
                x,y=new_location

                #check if we can go up
                if(self.check_if_location_is_inside_the_matrix_or_not((x-1,y))):
                    queue_BFS.append((x-1,y))

                #check if we can go down
                if(self.check_if_location_is_inside_the_matrix_or_not((x+1,y))):
                    queue_BFS.append((x+1,y))

                #check if we can go right
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y+1))):
                    queue_BFS.append((x,y+1))

                #check if we can go left
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y-1))):
                    queue_BFS.append((x,y-1))

            else:
                state=self.create_a_new_state_using_current_and_new_location(state, new_location, current_location)

            current_location=self.find_location_of_space(state)
            visited_BFS[state_str]=True


g=eight_puzzle_probolem_using_BFS()
initial_state=[[1, 2, 3], [4, 5, 6], [7, -1, 8]]
g.BFS(initial_state)"""




# 8 puzzle problem using dls

"""class eight_puzzle_probolem():

    def __init__(self):
        self.goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, -1]]
        self.size = 3

    def print_the_matrix(self, state):
        for list in state:
            for ele in list:
                print(ele, end=" ")
            print()
        print("====")

    def check_if_location_is_inside_the_matrix_or_not(self, current_location):
        x, y = current_location
        if(x<0 or y<0 or x>=self.size or y>=self.size):
            return False
        return True

    def find_location_of_space(self, current_state):
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if(current_state[i][j] == -1):
                    return i,j   #why don't we write about the case that -1 does not exist in the matrix

    def create_a_new_state_using_current_and_new_location(self, current_state, current_location, new_location):
        x1, y1 = current_location
        x2, y2 = new_location

        if(self.check_if_location_is_inside_the_matrix_or_not(new_location)):
            current_state[x1][y1], current_state[x2][y2] = current_state[x2][y2], current_state[x1][y1]

        return current_state

    def DFS(self, state):
        current_location=self.find_location_of_space(state)
        #print(current_location)

        visited_DFS={}
        stack_DFS=[current_location]
        count=0

        while (stack_DFS):
            new_location=stack_DFS.pop()
            state=self.create_a_new_state_using_current_and_new_location(state, current_location, new_location)

            state_str=str(state)
            if(state_str == str(self.goal_state)):
                print("No. of states iterated: ")
                print(count)
                print("Goal state reached: ")
                self.print_the_matrix(state)
                #print(visited_DFS)
                return

            #self.print_the_matrix(state)
            count+=1

            if(not visited_DFS.get(state_str, False)):
                x,y=new_location

                #check if we can go up
                if(self.check_if_location_is_inside_the_matrix_or_not((x-1,y))):
                    stack_DFS.append((x-1,y))

                #check if we can go down
                if(self.check_if_location_is_inside_the_matrix_or_not((x+1,y))):
                    stack_DFS.append((x+1,y))

                #check if we can go right
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y+1))):
                    stack_DFS.append((x,y+1))

                #check if we can go left
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y-1))):
                    stack_DFS.append((x,y-1))

            else:
                state=self.create_a_new_state_using_current_and_new_location(state, new_location, current_location)

            current_location=self.find_location_of_space(state)
            visited_DFS[state_str]=True
        


g=eight_puzzle_probolem()
initial_state=[[1, 2, 3], [4, 5, 6], [7, -1, 8]]
g.DFS(initial_state)"""