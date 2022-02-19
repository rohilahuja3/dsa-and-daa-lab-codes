#class fac:
"""c=0
def permute(l,start,end):
    if(start==end): #only 1 no. in list
        print(l)
        global c
        c=c+1
        return
        
    for i in range(start,end):
        l[i],l[start]=l[start],l[i]
        permute(l,start+1,end)
        l[i],l[start]=l[start],l[i] #back tracking


l=[1,2,3]
start=0
end=len(l)
permute(l,start,end)
print(c)"""

#Ai lab 1

#basic class concept
"""class Complex():

    def __init__(self): #self is just like this in c++
        self.real=0 #IF WE dont write self then they are not data members
        self.imag=0

    def add(self,c):
        self.real+=c.real
        self.imag+=c.imag
    
    def print_complex(self):
        print(self.real, self.imag);


c=Complex()

l=list()
l.append(c)

c1=Complex()
c1.real=4
c1.imag=5

c.print_complex()

c.add(c1)
c.print_complex()"""

#graph

"""class Graph():
    def __init__(self):
        self.graph = {}  # graph is a var and data struc is dictionary
        self.bi_directional = True
        self.nodes = int(input("enter no. of nodes: "))
        self.edges = int(input("enter no. of edges: "))

        for i in range(self.edges):  # eg = 2,3
            u, v = tuple(input("enter edge: ").split(","))  # no. of values should be same both sides for u and v to unpack
            print(u, v)

            # inserting u and v in dictionary in the form of adjacency list
            if u in self.graph.keys():
                self.graph[u].append(v)
            else:
                self.graph[u] = [v]

            if v in self.graph.keys():
                self.graph[v].append(u)
            else:
                self.graph[v] = [u]

    def print_graph(self):
        for key in self.graph.keys():
            print("{0} ->".format(key), end="")
            for val in self.graph[key]:
                print("{0}, ".format(val), end="")
            print()

    def _dfs_helper(self, current_state, vis):
        if (vis[current_state]):
            return

        print(current_state)
        vis[current_state] = True

        for neigh in self.graph[current_state]:
            self._dfs_helper(neigh, vis)
    
    #CODE WHEN U NEED TO STOP AT GOAL STATE    
    def _dfs_helper(self, current_state, vis,goal_state):
        if (vis[current_state]):
            return False 
            
        print(current_state)
        vis[current_state] = True
        
        if(current_state==goal_state):
            return True

        for neigh in self.graph[current_state]:
            if(self._dfs_helper(neigh, vis,goal_state)):
                return True

        return False

    def dfs(self, start_state,goal_state):
        visited = {}

        for key in self.graph.keys():
            visited[key] = False  # nothing is visited

        print("DFS Start....")
        self._dfs_helper(start_state,visited,goal_state) #can not be accesed from outside
        print("DFS End....")
        

g = Graph()
g.print_graph()
g.dfs('a','e')"""


"""class Graph():



    def __init__(self):

        self.nodes=int(input("enter the no. of nodes: "))
        self.edges=int(input("enter the no. of edges: "))
        self.graph_adj_list={}
        self.uni_or_bi=True

        for i in range(self.edges):
            u,v=tuple(input("enter the edges: ").split(",")) #why can't i input int values
            #u=int(u)
            #v=int(v)
            print(u,v)

            if u in self.graph_adj_list.keys():
                self.graph_adj_list[u].append(v)
            else:
                self.graph_adj_list[u]=[v]

            if v in self.graph_adj_list.keys():
                self.graph_adj_list[v].append(u)
            else:
                self.graph_adj_list[v]=[u]

    

    def print_graph(self):

        for key in self.graph_adj_list.keys():
            print("{0} -> ".format(key),end="")
  
            for val in self.graph_adj_list[key]:
                print("{0} , ".format(val),end="")
            print()



    def _dfs_helper(self,current_state_DFS,visited_DFS,goal_state_DFS):

        if(visited_DFS[current_state_DFS]):
            return False

        print(current_state_DFS)
        visited_DFS[current_state_DFS]=True

        if(current_state_DFS==goal_state_DFS):
            return True

        for neigh in self.graph_adj_list[current_state_DFS]:
            if(self._dfs_helper(neigh,visited_DFS,goal_state_DFS)):
                return True
        
        return False



    def DFS(self,start_state_DFS,goal_state_DFS):

        visited_DFS={}

        for key in self.graph_adj_list.keys():
            visited_DFS[key]=False

        print("DFS start....")
        self._dfs_helper(start_state_DFS,visited_DFS,goal_state_DFS)
        print("DFS end....")



    def BFS(self,start_state_BFS,goal_state_BFS):

        print("BFS start....")
        visited_BFS={}
        queue=[]

        for key in self.graph_adj_list.keys():
            visited_BFS[key]=False

        queue.append(start_state_BFS)
        visited_BFS[start_state_BFS]=True

        while queue:
            current_state=queue.pop(0)
            print(current_state)


            if(current_state==goal_state_BFS):
                return
            
            for neigh in self.graph_adj_list[current_state]:

                if(not visited_BFS[neigh]):                   
                    queue.append(neigh)
                    visited_BFS[neigh]=True



g=Graph()
g.print_graph()
print()
g.DFS('a','c')
print()
g.BFS('a','c')
print()
print(g.graph_adj_list)
print()"""



# 8 puzzle using DFS and BFS

"""class puzzle():


    def __init__(self):
        self.goal_state = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', 'x']]
        self.size=3


    def print_puzzle(self,state):
        for item in state:
            for ele in item:
                print(ele,end=" ")
            print()
        print("=====")


    def get_state(self,current_state,current_location,new_location):
        x,y=current_location #tuple unpacking
        x1,y1=new_location

        if(x1<0 or y1>=self.size or y1<0 or x1>=self.size):
            return current_state

        current_state[x][y],current_state[x1][y1]=current_state[x1][y1],current_state[x][y]
        return current_state


    def get_location(self,state):
        for i in range(self.size):
            for j in range(self.size):
                if(state[i][j]=='x'):
                    return i,j


    def check_in_range(self,location):
        x,y=location
        if(x<0 or y>=self.size or y<0 or x>=self.size):
            return False
        return True


    def DFS(self,initial_state):
        previous_location=self.get_location(initial_state)
        
        visited={}
        stack=[previous_location]
        count=0

        #self.print_puzzle(initial_state)

        while(stack):
            current_location=stack.pop()
            initial_state=self.get_state(initial_state,previous_location,current_location)
            initial_state_str=str(initial_state)

            if(initial_state_str==str(self.goal_state)):
                print("=====Goal state reached======")
                print(count)
                self.print_puzzle(initial_state)
                return
          
            self.print_puzzle(initial_state)
            count+=1

            if(not visited.get(initial_state_str,False)):
                x,y=current_location

                #check if we can go up
                if(self.check_in_range((x-1,y))):
                    stack.append((x-1,y))

                #check if we can go down
                if(self.check_in_range((x+1,y))):
                    stack.append((x+1,y))

                #check if we can go right
                if(self.check_in_range((x,y+1))):
                    stack.append((x,y+1))

                #check if we can go left
                if(self.check_in_range((x,y-1))):
                    stack.append((x,y-1))

            else: #back track to initial position
                initial_state=self.get_state(initial_state,current_location,previous_location)
                
            previous_location=self.get_location(initial_state)
            visited[initial_state_str]=True


p=puzzle()
initial_state=[['x', '5', '2'], ['1', '8', '3'], ['4', '7', '6']]
p.DFS(initial_state)"""



class eight_puzzle_proble():


    def __init__(self):
        self.goal_state=[[1,2,3],[4,5,6],[7,8,-1]]
        self.size=3

    
    def print_state(self,current_state):
        for list in current_state:
            for ele in list:
                print(ele,end=" ")
            print()
        print("====")


    def find_location_of_x(self,current_state):
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if(current_state[i][j]==-1):
                    return i,j


    def check_if_in_range_of_the_matrix(self,current_location):
        x,y=current_location
        if(x<0 or x>=self.size or y<0 or y>=self.size):
            return False
        return True


    def create_state_using_intial_and_final_location(self,current_state,current_location,new_location):
        x,y=current_location
        u,v=new_location

        if(self.check_if_in_range_of_the_matrix(new_location)):
            current_state[x][y],current_state[u][v]=current_state[u][v],current_state[x][y]

        return current_state

    def DFS(self,state):
        current_location=self.find_location_of_x(state)

        visited={}
        stack=[current_location]
        count=0;

        while(stack):
            new_location=stack.pop()
            state=self.create_state_using_intial_and_final_location(state,current_location,new_location)

            state_str=str(state)
            if(state_str==str(self.goal_state)):
                print("Goal state reached")
                print(count)
                self.print_state(state)
                return

            #self.print_state(state)
            count+=1
            
            if(not visited.get(state_str,False)):
                x,y=new_location

                #check if we can go up
                if(self.check_if_in_range_of_the_matrix((x-1,y))):
                    stack.append((x-1,y))

                #check if we can go down
                if(self.check_if_in_range_of_the_matrix((x+1,y))):
                    stack.append((x+1,y))

                #check if we can go right
                if(self.check_if_in_range_of_the_matrix((x,y+1))):
                    stack.append((x,y+1))

                #check if we can go left
                if(self.check_if_in_range_of_the_matrix((x,y-1))):
                    stack.append((x,y-1))

            else:
                state=self.create_state_using_intial_and_final_location(state,new_location,current_location)

            current_location=self.find_location_of_x(state)
            visited[state_str]=True


p=eight_puzzle_proble();
#p.print_state(p.goal_state)
#p.find_location_of_x(p.goal_state)
#p.check_if_in_range_of_the_matrix([0,21])
initial_state=[[-1,5,2],[1,8,3],[4,7,6]]
p.DFS(initial_state)