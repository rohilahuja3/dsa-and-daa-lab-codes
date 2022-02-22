#1) dfs and bfs algo for graphs usnig classes

# Input
# 5
# 4
# a,b
# a,c
# a,d
# b,e

"""class graph():


    def __init__(self):
        self.nodes = int(input("enter the number of nodes: "))
        self.edges = int(input("enter the number of edges: "))
        self.graph_using_adj_list = {}
        self.type_uni_or_bi = bool(input("True for Bi-Directional and False for Uni-Directional: "))


        for i in range(0, self.edges):
            u, v = tuple(input("enter the elements that have edges: "). split(" "))
            print(u, " <-> ", v)

            #for integer elments in graph
            #u=int(u)
            #v=int(v)

            if u in self.graph_using_adj_list.keys():
                self.graph_using_adj_list[u].append(v)
            else:
                self.graph_using_adj_list[u] = [v];

            if(self.type_uni_or_bi == True):

                if v in self.graph_using_adj_list.keys():
                    self.graph_using_adj_list[v].append(u)
                else:
                    self.graph_using_adj_list[v] = [u];

        
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

        for neigh_DFS in self.graph_using_adj_list[curremt_state_DFS]:
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
            current_state_BFS = queue_BFS.pop(0)
            print(current_state_BFS)

            if(current_state_BFS == goal_state_BFS):
                return

            for neigh in self.graph_using_adj_list[current_state_BFS]:

                if(not visited_BFS[neigh]):
                    queue_BFS.append(neigh)
                    visited_BFS[neigh] = True
                    

g=graph()
g.print_graph()
print()
g.DFS("b","c")
print()
g.BFS("b","c")
print("BFS END...")
print()"""




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
        print(current_location)

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
initial_state=[[-1,5,2],[1,8,3],[4,7,6]]
g.DFS(initial_state)"""




# 8 puzzle problem using dfs

class eight_puzzle_probolem_using_BFS():

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
initial_state=[[-1,5,2],[1,8,3],[4,7,6]]
g.BFS(initial_state)