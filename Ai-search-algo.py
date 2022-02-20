#1) dfs and bfs algo for graphs usnig classes

# Input
# 5
# 4
# a,b
# a,c
# a,d
# b,e

class graph():


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
print()