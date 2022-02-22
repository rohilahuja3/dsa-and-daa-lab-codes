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
initial_state=[[1,2,3],[8,-1,4],[7,6,5]]
g.DFS(initial_state)"""




# 8 puzzle problem using dfs
"""from queue import Queue

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

        # queue_BFS=[current_location]

        queue_BFS=Queue()
        queue_BFS.put(current_location)
        # print(queue_BFS.pop(0))
        count=0
        # print(count)

        while(queue_BFS):
            new_location=queue_BFS.get()
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

            if(not visited_BFS.get(state_str)):
                x,y=new_location

                #check if we can go up
                if(self.check_if_location_is_inside_the_matrix_or_not((x-1,y))):
                    queue_BFS.put((x-1,y))

                #check if we can go down
                if(self.check_if_location_is_inside_the_matrix_or_not((x+1,y))):
                    queue_BFS.put((x+1,y))

                #check if we can go right
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y+1))):
                    queue_BFS.put((x,y+1))

                #check if we can go left
                if(self.check_if_location_is_inside_the_matrix_or_not((x,y-1))):
                    queue_BFS.put((x,y-1))

            else:
                state=self.create_a_new_state_using_current_and_new_location(state, new_location, current_location)

            current_location=self.find_location_of_space(state)
            visited_BFS[state_str]=True


g=eight_puzzle_probolem_using_BFS()
initial_state=[[1, 2, 3], [4, 5, 6], [7, -1, 8]]
g.BFS(initial_state)"""




"""import numpy as np
import time
class Node():
    def __init__(self,state,parent,action,depth,step_cost,path_cost,heuristic_cost):
        self.state = state 
        self.parent = parent # parent node
        self.action = action # move up, left, down, right
        self.depth = depth # depth of the node in the tree
        self.step_cost = step_cost # g(n), the cost to take the step
        self.path_cost = path_cost # accumulated g(n), the cost to reach the current node
        self.heuristic_cost = heuristic_cost # h(n), cost to reach goal state from the current node
        
        # children node
        self.move_up = None 
        self.move_left = None
        self.move_down = None
        self.move_right = None
    
    # see if moving down is valid
    def try_move_down(self):
        # index of the empty tile
        zero_index=[i[0] for i in np.where(self.state==0)] 
        if zero_index[0] == 0:
            return False
        else:
            up_value = self.state[zero_index[0]-1,zero_index[1]] # value of the upper tile
            new_state = self.state.copy()
            new_state[zero_index[0],zero_index[1]] = up_value
            new_state[zero_index[0]-1,zero_index[1]] = 0
            return new_state,up_value
        
    # see if moving right is valid
    def try_move_right(self):
        zero_index=[i[0] for i in np.where(self.state==0)] 
        if zero_index[1] == 0:
            return False
        else:
            left_value = self.state[zero_index[0],zero_index[1]-1] # value of the left tile
            new_state = self.state.copy()
            new_state[zero_index[0],zero_index[1]] = left_value
            new_state[zero_index[0],zero_index[1]-1] = 0
            return new_state,left_value
        
    # see if moving up is valid
    def try_move_up(self):
        zero_index=[i[0] for i in np.where(self.state==0)] 
        if zero_index[0] == 2:
            return False
        else:
            lower_value = self.state[zero_index[0]+1,zero_index[1]] # value of the lower tile
            new_state = self.state.copy()
            new_state[zero_index[0],zero_index[1]] = lower_value
            new_state[zero_index[0]+1,zero_index[1]] = 0
            return new_state,lower_value
        
    # see if moving left is valid
    def try_move_left(self):
        zero_index=[i[0] for i in np.where(self.state==0)] 
        if zero_index[1] == 2:
            return False
        else:
            right_value = self.state[zero_index[0],zero_index[1]+1] # value of the right tile
            new_state = self.state.copy()
            new_state[zero_index[0],zero_index[1]] = right_value
            new_state[zero_index[0],zero_index[1]+1] = 0
            return new_state,right_value
    
    # return user specified heuristic cost
    def get_h_cost(self,new_state,goal_state,heuristic_function,path_cost,depth):
        if heuristic_function == 'num_misplaced':
            return self.h_misplaced_cost(new_state,goal_state)
        elif heuristic_function == 'manhattan':
            return self.h_manhattan_cost(new_state,goal_state)
        # since this game is made unfair by setting the step cost as the value of the tile being moved
        # to make it fair, I made all the step cost as 1
        # made it a best-first-search with manhattan heuristic function
        elif heuristic_function == 'fair_manhattan':
            return self.h_manhattan_cost(new_state,goal_state) - path_cost + depth
    
    # return heuristic cost: number of misplaced tiles
    def h_misplaced_cost(self,new_state,goal_state):
        cost = np.sum(new_state != goal_state)-1 # minus 1 to exclude the empty tile
        if cost > 0:
            return cost
        else:
            return 0 # when all tiles matches
    
    # return heuristic cost: sum of Manhattan distance to reach the goal state
    def h_manhattan_cost(self,new_state,goal_state):
        current = new_state
        # digit and coordinates they are supposed to be
        goal_position_dic = {1:(0,0),2:(0,1),3:(0,2),8:(1,0),0:(1,1),4:(1,2),7:(2,0),6:(2,1),5:(2,2)} 
        sum_manhattan = 0
        for i in range(3):
            for j in range(3):
                if current[i,j] != 0:
                    sum_manhattan += sum(abs(a-b) for a,b in zip((i,j), goal_position_dic[current[i,j]]))
        return sum_manhattan
        
    # once the goal node is found, trace back to the root node and print out the path
    def print_path(self):
        # create FILO stacks to place the trace
        state_trace = [self.state]
        action_trace = [self.action]
        depth_trace = [self.depth]
        step_cost_trace = [self.step_cost]
        path_cost_trace = [self.path_cost]
        heuristic_cost_trace = [self.heuristic_cost]
        
        # add node information as tracing back up the tree
        while self.parent:
            self = self.parent

            state_trace.append(self.state)
            action_trace.append(self.action)
            depth_trace.append(self.depth)
            step_cost_trace.append(self.step_cost)
            path_cost_trace.append(self.path_cost)
            heuristic_cost_trace.append(self.heuristic_cost)

        # print out the path
        step_counter = 0
        while state_trace:
            print('step',step_counter)
            print(state_trace.pop())
            print('action=',action_trace.pop(),', depth=',str(depth_trace.pop()),\
            ', step cost=',str(step_cost_trace.pop()),', total_cost=',\
            str(path_cost_trace.pop() + heuristic_cost_trace.pop()),'\n')
            
            step_counter += 1
                    
    def breadth_first_search(self, goal_state):
        start = time.time()
        
        queue = [self] # queue of found but unvisited nodes, FIFO
        queue_num_nodes_popped = 0 # number of nodes popped off the queue, measuring time performance
        queue_max_length = 1 # max number of nodes in the queue, measuring space performance
        
        depth_queue = [0] # queue of node depth
        path_cost_queue = [0] # queue for path cost
        visited = set([]) # record visited states
        
        while queue:
            # update maximum length of the queue
            if len(queue) > queue_max_length:
                queue_max_length = len(queue)
                
            current_node = queue.pop(0) # select and remove the first node in the queue
            queue_num_nodes_popped += 1 
            
            current_depth = depth_queue.pop(0) # select and remove the depth for current node
            current_path_cost = path_cost_queue.pop(0) # # select and remove the path cost for reaching current node
            visited.add(tuple(current_node.state.reshape(1,9)[0])) # avoid repeated state, which is represented as a tuple
            
            # when the goal state is found, trace back to the root node and print out the path
            if np.array_equal(current_node.state,goal_state):
                current_node.print_path()
                
                print('Time performance:',str(queue_num_nodes_popped),'nodes popped off the queue.')
                print('Space performance:', str(queue_max_length),'nodes in the queue at its max.')
                print('Time spent: %0.2fs' % (time.time()-start))
                return True
            
            else:                
                # see if moving upper tile down is a valid move
                if current_node.try_move_down():
                    new_state,up_value = current_node.try_move_down()
                    # check if the resulting node is already visited
                    if tuple(new_state.reshape(1,9)[0]) not in visited:
                        # create a new child node
                        current_node.move_down = Node(state=new_state,parent=current_node,action='down',depth=current_depth+1,\
                                              step_cost=up_value,path_cost=current_path_cost+up_value,heuristic_cost=0)
                        queue.append(current_node.move_down)
                        depth_queue.append(current_depth+1)
                        path_cost_queue.append(current_path_cost+up_value)
                    
                # see if moving left tile to the right is a valid move
                if current_node.try_move_right():
                    new_state,left_value = current_node.try_move_right()
                    # check if the resulting node is already visited
                    if tuple(new_state.reshape(1,9)[0]) not in visited:
                        # create a new child node
                        current_node.move_right = Node(state=new_state,parent=current_node,action='right',depth=current_depth+1,\
                                              step_cost=left_value,path_cost=current_path_cost+left_value,heuristic_cost=0)
                        queue.append(current_node.move_right)
                        depth_queue.append(current_depth+1)
                        path_cost_queue.append(current_path_cost+left_value)
                 
                # see if moving lower tile up is a valid move
                if current_node.try_move_up():
                    new_state,lower_value = current_node.try_move_up()
                    # check if the resulting node is already visited
                    if tuple(new_state.reshape(1,9)[0]) not in visited:
                        # create a new child node
                        current_node.move_up = Node(state=new_state,parent=current_node,action='up',depth=current_depth+1,\
                                              step_cost=lower_value,path_cost=current_path_cost+lower_value,heuristic_cost=0)
                        queue.append(current_node.move_up)
                        depth_queue.append(current_depth+1)
                        path_cost_queue.append(current_path_cost+lower_value)

                # see if moving right tile to the left is a valid move
                if current_node.try_move_left():
                    new_state,right_value = current_node.try_move_left()
                    # check if the resulting node is already visited
                    if tuple(new_state.reshape(1,9)[0]) not in visited:
                        # create a new child node
                        current_node.move_left = Node(state=new_state,parent=current_node,action='left',depth=current_depth+1,\
                                              step_cost=right_value,path_cost=current_path_cost+right_value,heuristic_cost=0)
                        queue.append(current_node.move_left)
                        depth_queue.append(current_depth+1)
                        path_cost_queue.append(current_path_cost+right_value)
                        
                
test = np.array([0,5,2,1,8,3,4,7,6]).reshape(3,3)

initial_state = test
goal_state = np.array([1,2,3,4,5,6,7,8,0]).reshape(3,3)
print(initial_state,'\n')
print(goal_state)
print("======================")

root_node = Node(state=initial_state,parent=None,action=None,depth=0,step_cost=0,path_cost=0,heuristic_cost=0)
# search level by level with queue
root_node.breadth_first_search(goal_state)"""