#1) LAB 1
#Q1)

"""def backtrace(parent, start, end):
    path = [end]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path
        

def bfs(graph, start, end):
    parent = {}
    queue = []
    queue.append(start)
    while queue:
        node = queue.pop(0)
        if node == end:
            return backtrace(parent, start, end)
        for adjacent in graph.get(node, []):
            if node not in queue :
                parent[adjacent] = node 
                queue.append(adjacent)

def dfs(graph, start, end):
    parent = {}
    stack = []
    stack.append(start)
    while stack:
        node = stack.pop()
        if node == end:
            return backtrace(parent, start, end)
        for adjacent in graph.get(node, []):
            if node not in stack :
                parent[adjacent] = node 
                stack.append(adjacent)

graph = {
    "A":["B","C","D"],
    "B":["E","F"],
    "C":["G","H"],
    "D":["I","J"],
    "E":["K","L"],
    "F":["M"],
    "G":["N"],
    "H":["O"],
    "I":["P","Q"],
    "J":["R"],
    "K":["S"],
    "L":["T"],
    "P":["U"],
}
print("Using BFS: ")
print(bfs(graph, "A", "N"))
print("Using DFS: ")
print(dfs(graph, "A", "N"))"""


#Q2)
"""import sys
import numpy as np


class Node:
    def __init__(self, state, parent, action):
        self.state = state
        self.parent = parent
        self.action = action


class StackFrontier:
    def __init__(self):
        self.frontier = []

    def add(self, node):
        self.frontier.append(node)

    def contains_state(self, state):
        return any((node.state[0] == state[0]).all() for node in self.frontier)

    def empty(self):
        return len(self.frontier) == 0

    def remove(self):
        if self.empty():
            raise Exception("Empty Frontier")
        else:
            node = self.frontier[-1]
            self.frontier = self.frontier[:-1]
            return node


class QueueFrontier(StackFrontier):
    def remove(self):
        if self.empty():
            raise Exception("Empty Frontier")
        else:
            node = self.frontier[0]
            self.frontier = self.frontier[1:]
            return node


class Puzzle:
    def __init__(self, start, startIndex, goal, goalIndex):
        self.start = [start, startIndex]
        self.goal = [goal, goalIndex]
        self.solution = None

    def neighbors(self, state):
        mat, (row, col) = state
        results = []

        if row > 0:
            mat1 = np.copy(mat)
            mat1[row][col] = mat1[row - 1][col]
            mat1[row - 1][col] = 0
            results.append(('up', [mat1, (row - 1, col)]))
        if col > 0:
            mat1 = np.copy(mat)
            mat1[row][col] = mat1[row][col - 1]
            mat1[row][col - 1] = 0
            results.append(('left', [mat1, (row, col - 1)]))
        if row < 2:
            mat1 = np.copy(mat)
            mat1[row][col] = mat1[row + 1][col]
            mat1[row + 1][col] = 0
            results.append(('down', [mat1, (row + 1, col)]))
        if col < 2:
            mat1 = np.copy(mat)
            mat1[row][col] = mat1[row][col + 1]
            mat1[row][col + 1] = 0
            results.append(('right', [mat1, (row, col + 1)]))

        return results

    def print(self):
        solution = self.solution if self.solution is not None else None
        print("Start State:\n", self.start[0], "\n")
        print("Goal State:\n",  self.goal[0], "\n")
        print("\nStates Explored: ", self.num_explored, "\n")
        print("Solution:\n ")
        for action, cell in zip(solution[0], solution[1]):
            print("action: ", action, "\n", cell[0], "\n")
        print("Goal Reached!!")

    def does_not_contain_state(self, state):
        for st in self.explored:
            if (st[0] == state[0]).all():
                return False
        return True

    def solve(self):
        self.num_explored = 0

        start = Node(state=self.start, parent=None, action=None)
        frontier = QueueFrontier()
        frontier.add(start)

        self.explored = []

        while True:
            if frontier.empty():
                raise Exception("No solution")

            node = frontier.remove()
            self.num_explored += 1

            if (node.state[0] == self.goal[0]).all():
                actions = []
                cells = []
                while node.parent is not None:
                    actions.append(node.action)
                    cells.append(node.state)
                    node = node.parent
                actions.reverse()
                cells.reverse()
                self.solution = (actions,  cells)
                return

            self.explored.append(node.state)

            for action, state in self.neighbors(node.state):
                if not frontier.contains_state(state) and self.does_not_contain_state(state):
                    child = Node(state=state, parent=node, action=action)
                    frontier.add(child)


start = np.array([[0, 5, 2], [1, 8, 3], [4, 7, 6]])
goal = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 0]])


startIndex = (0, 0)
goalIndex = (2, 2)


p = Puzzle(start, startIndex, goal, goalIndex)
p.solve()
p.print()"""




#2) LAB 2

"""from copy import deepcopy
from collections import deque
import sys
import time

class State(object):
  def __init__(self, missionaries, cannibals, boats):
    self.missionaries = missionaries
    self.cannibals = cannibals
    self.boats = boats
  
  def successors(self):
    if self.boats == 1:
      sgn = -1
      direction = "from the original shore to the new shore"
    else:
      sgn = 1
      direction = "back from the new shore to the original shore"
    for m in range(3):
      for c in range(3):
        newState = State(self.missionaries+sgn*m, self.cannibals+sgn*c, self.boats+sgn*1);
        if m+c >= 1 and m+c <= 2 and newState.isValid():
          action = "take %d missionaries and %d cannibals %s. %r" % ( m, c, direction, newState) 
          yield action, newState
            
  def isValid(self):
    if self.missionaries < 0 or self.cannibals < 0 or self.missionaries > 3 or self.cannibals > 3 or (self.boats != 0 and self.boats != 1):
      return False   
    if self.cannibals > self.missionaries and self.missionaries > 0:
      return False
    if self.cannibals < self.missionaries and self.missionaries < 3:
      return False
    return True

  def is_goal_state(self):
    return self.cannibals == 0 and self.missionaries == 0 and self.boats == 0

  def __repr__(self):
    return "< State (%d, %d, %d) >" % (self.missionaries, self.cannibals, self.boats)



class Node(object):  
  def __init__(self, parent_node, state, action, depth):
    self.parent_node = parent_node
    self.state = state
    self.action = action
    self.depth = depth
  
  def expand(self):
    for (action, succ_state) in self.state.successors():
      succ_node = Node(
                       parent_node=self,
                       state=succ_state,
                       action=action,
                       depth=self.depth + 1)
      yield succ_node
  
  def extract_solution(self):
    solution = []
    node = self
    while node.parent_node is not None:
      solution.append(node.action)
      node = node.parent_node
    solution.reverse()
    return solution


def breadth_first_tree_search(initial_state):
  initial_node = Node(
                      parent_node=None,
                      state=initial_state,
                      action=None,
                      depth=0)
  fifo = deque([initial_node])
  num_expansions = 0
  max_depth = -1
  while True:
    if not fifo:
      print("%d expansions" % num_expansions)
      return None
    node = fifo.popleft()
    if node.depth > max_depth:
      max_depth = node.depth
      print("[depth = %d] %.2fs" % (max_depth, time.clock()))
    if node.state.is_goal_state():
      print("%d expansions" % num_expansions)
      solution = node.extract_solution()
      return solution
    num_expansions += 1
    fifo.extend(node.expand())


def usage():
  print >> sys.stderr, "usage:"
  print >> sys.stderr, "    %s" % sys.argv[0]
  raise SystemExit(2)


def main():
  initial_state = State(3,3,1)
  solution = breadth_first_tree_search(initial_state)
  if solution is None:
    print("no solution")
  else:
    print("solution (%d steps):" % len(solution))
    for step in solution:
      print("%s" % step)
  print("elapsed time: %.2fs" % time.clock())


if __name__ == "__main__":
  main()"""



#3) Lab 3

  #1) DLS
"""import copy

inp=[[2,8,3],[1,6,4],[7,-1,5]]
out=[[1,2,3],[8,-1,4],[7,6,5]]


def move(temp, movement):
  if movement=="up":
    for i in range(3):
      for j in range(3):
        if(temp[i][j]==-1):

          if i!=0:
            temp[i][j]=temp[i-1][j]
            temp[i-1][j]=-1
          return temp

  if movement=="down":
    for i in range(3):
      for j in range(3):
        if(temp[i][j]==-1):

          if i!=2:
            temp[i][j]=temp[i+1][j]
            temp[i+1][j]=-1
          return temp

  if movement=="left":
    for i in range(3):
      for j in range(3):
        if(temp[i][j]==-1):

          if j!=0:
            temp[i][j]=temp[i][j-1]
            temp[i][j-1]=-1
          return temp

  if movement=="right":
    for i in range(3):
      for j in range(3):
        if(temp[i][j]==-1):

          if j!=2:
            temp[i][j]=temp[i][j+1]
            temp[i][j+1]=-1
          return temp
def dls():
  global inp
  global out
  global flag

  limit=int(input('Enter the limit '))

  stack=[]
  inpx=[inp,"none"]
  stack.append(inpx)

  level=0
  while(True):
    if len(stack)==0:
      break
    puzzle=stack.pop(0)
    if level<=limit:
      print(str(puzzle[1])+" --> "+str(puzzle[0]))
      if(puzzle[0]==out):
        print("Found")
        print('Path cost='+str(level))
        flag=True
        return
      else:
        level=level+1

        if(puzzle[1]!="down"):
          temp=copy.deepcopy(puzzle[0])
          up=move(temp, "up")
          if(up!=puzzle[0]):
            upx=[up,"up"]
            stack.insert(0, upx)

        if(puzzle[1]!="right"):
          temp=copy.deepcopy(puzzle[0])
          left=move(temp, "left")
          if(left!=puzzle[0]):
            leftx=[left,"left"]
            stack.insert(0, leftx)

        if(puzzle[1]!="up"):
          temp=copy.deepcopy(puzzle[0])
          down=move(temp, "down")
          if(down!=puzzle[0]):
            downx=[down,"down"]
            stack.insert(0, downx)

        if(puzzle[1]!="left"):
          temp=copy.deepcopy(puzzle[0])
          right=move(temp, "right")
          if(right!=puzzle[0]):
            rightx=[right,"right"]
            stack.insert(0, rightx)
      

flag=False
dls()
if flag==False:
  print('Impossible , no path found')"""


    #2) UCS

# import math
# import time
# from operator import itemgetter
 
# PUZZLE_TYPE = 8
# MAT_SIZE = int(math.sqrt(PUZZLE_TYPE + 1))
 
# class PriorityQueue(object):
 
#     def __init__(self):
#         self.elements = []
#         self.max_elements = 0
 
#     def get_max_elements(self):
#     	return self.max_elements
 
#     def empty(self):
#         return len(self.elements) == 0
 
#     def put(self, item, h=0, g=0, priority=0):
#         self.elements.append((priority, h, g, item))
#         self.elements.sort(key=itemgetter(0))
#         self.max_elements = self.max_elements if self.max_elements > len(self.elements) else len(self.elements)
 
#     def get_item(self):
#         return self.elements.pop(0)
 
# class Problem(object):
 
# 	def __init__(self, initial_state=None):
# 		self.initial_state = initial_state
# 		self.goal_state = self.get_goal()
# 		self.explored = []
 
# 	def goal_test(self, node):
# 		self.explored.append(node)
# 		return node == self.goal_state
 
# 	def get_level(self):
# 		return len(self.explored);
 
# 	def is_explored(self, node):
# 		return node in self.explored
 
# 	def get_current_state(self):
# 		return self.initial_state
 
# 	def get_goal_state(self):
# 		return self.goal_state
 
# 	def get_goal(self):
# 		goal = []
# 		for x in range(1, PUZZLE_TYPE + 1):
# 			goal.append(x)
# 		goal.append(-1)
# 		return goal
 
# 	def print_current_board(self):
# 		print_board(self.initial_state)
 
 
# def print_board(mat):
# 	print("\nBoard:")
# 	print("*" * 5 * MAT_SIZE)
# 	for index, val in enumerate(mat):
# 		if (index + 1) % MAT_SIZE == 0:
# 			print(val if val != -1 else "x")
# 		else:
# 			print val if val != -1 else "x", " ",
# 	print("*" * 5 * MAT_SIZE)
 
 
# def can_move_up(mat):
# 	return True if mat.index(-1) >= MAT_SIZE else False
 
# def can_move_down(mat):
# 	return True if mat.index(-1) < PUZZLE_TYPE + 1 - MAT_SIZE else False
 
# def can_move_left(mat):
# 	return False if mat.index(-1) % MAT_SIZE == 0 else True
 
# def can_move_right(mat):
# 	return False if mat.index(-1) % MAT_SIZE == MAT_SIZE - 1 else True
 
# def move_x_up(mat):
# 	if can_move_up(mat):
# 		index = mat.index(-1)
# 		mat[index - MAT_SIZE], mat[index] = mat[index], mat[index - MAT_SIZE]
# 		return mat
# 	return None
 
# def move_x_down(mat):
# 	if can_move_down(mat):
# 		index = mat.index(-1)
# 		mat[index + MAT_SIZE], mat[index] = mat[index], mat[index + MAT_SIZE]
# 		return mat
# 	return None
 
# def move_x_left(mat):
# 	if can_move_left(mat):
# 		index = mat.index(-1)
# 		mat[index - 1], mat[index] = mat[index], mat[index - 1]
# 		return mat
# 	return None
 
# def move_x_right(mat):
# 	if can_move_right(mat):
# 		index = mat.index(-1)
# 		mat[index + 1], mat[index] = mat[index], mat[index + 1]
# 		return mat
# 	return None
 
# def general_search(problem, queueing_func):
# 	depth = 0
# 	nodes = PriorityQueue()
# 	nodes.put(problem.get_current_state())
# 	while not nodes.empty():
# 		entire_node = nodes.get_item()
# 		node = entire_node[3]
# 		if (entire_node[2] or entire_node[1]):
# 			print("The best state to expand with a g(n) = %d and h(n) = %d is.." % (entire_node[2], entire_node[1]),)
# 		print_board(node)
# 		if problem.goal_test(node): 
# 			print("Goal State")
# 			print("To solve this problem the search algorithm expanded a total of %d nodes." % problem.get_level())
# 			print("The maximum number of nodes in the queue at any one time was %d."% nodes.get_max_elements())
# 			print("The depth of the goal node was %d" % entire_node[2])
# 			return node
# 		print("Expanding this state\n\n")
# 		queueing_func(nodes, expand(entire_node, problem))
# 		depth += 1
 
# def expand(node, problem):
# 	all_nodes = PriorityQueue()
# 	node1 = move_x_up(node[3][:])
# 	node2 = move_x_down(node[3][:])
# 	node3 = move_x_left(node[3][:])
# 	node4 = move_x_right(node[3][:])
# 	if node1 and not problem.is_explored(node1):
# 		all_nodes.put(node1, 0, node[2] + 1, 1)
# 	if node2 and not problem.is_explored(node2):
# 		all_nodes.put(node2, 0, node[2] + 1, 3)
# 	if node3 and not problem.is_explored(node3):
# 		all_nodes.put(node3, 0, node[2] + 1, 2)
# 	if node4 and not problem.is_explored(node4):
# 		all_nodes.put(node4, 0, node[2] + 1, 4)
# 	return all_nodes
 
# def uniform_cost_search(nodes, new_nodes):
# 	while not new_nodes.empty():
# 		node = new_nodes.get_item()
# 		nodes.put(node[3], 0, node[2], 0)
 
 
 
 
# if __name__ == "__main__":
# 	print("Welcome to the awesome %d-puzzle solver." % PUZZLE_TYPE)
# 	mat = []
 
# 	print("Enter elements for %d Puzzle." % PUZZLE_TYPE)
# 	print("NOTE: Use \"x\" for blank.\n")
# 	for i in xrange(MAT_SIZE):
# 		print("Enter elements for row %d" % (i + 1))
# 		mat.extend([-1 if x == "x" else int(x) for x in raw_input().split()])
 
# 	problem = Problem(mat)
# 	print("Initial State",)
# 	problem.print_current_board()
# 	print("Goal State",)
# 	print_board(problem.get_goal_state())
# 	print("\n\n")
# 	print("*"*50)
 
# 	general_search(problem, uniform_cost_search)



# lab 4

  # a* algo
# class Node:

#   def __init__(self,data,level,fval):
#       self.data = data
#       self.level = level
#       self.fval = fval

#   def generate_child(self):
#       x,y = self.find(self.data,'_')
#       val_list = [[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
#       children = []
#       for i in val_list:
#           child = self.shuffle(self.data,x,y,i[0],i[1])
#           if child is not None:
#               child_node = Node(child,self.level+1,0)
#               children.append(child_node)
#       return children
      
#   def shuffle(self,puz,x1,y1,x2,y2):
#       if x2 >= 0 and x2 < len(self.data) and y2 >= 0 and y2 < len(self.data):
#           temp_puz = []
#           temp_puz = self.copy(puz)
#           temp = temp_puz[x2][y2]
#           temp_puz[x2][y2] = temp_puz[x1][y1]
#           temp_puz[x1][y1] = temp
#           return temp_puz
#       else:
#           return None
          

#   def copy(self,root):
#       temp = []
#       for i in root:
#           t = []
#           for j in i:
#               t.append(j)
#           temp.append(t)
#       return temp    
          
#   def find(self,puz,x):
#       for i in range(0,len(self.data)):
#           for j in range(0,len(self.data)):
#               if puz[i][j] == x:
#                   return i,j


# class Puzzle:
#   def __init__(self,size):
#       self.n = size
#       self.open = []
#       self.closed = []

#   def accept(self):
#       puz = []
#       for i in range(0,self.n):
#           temp = input().split(" ")
#           puz.append(temp)
#       return puz

#   def f(self,start,goal):
#       return self.h(start.data,goal)+start.level

#   def h(self,start,goal):
#       temp = 0
#       for i in range(0,self.n):
#           for j in range(0,self.n):
#               if start[i][j] != goal[i][j] and start[i][j] != '_':
#                   temp += 1
#       return temp
      

#   def process(self):
#       print("Enter the start state matrix \n")
#       start = self.accept()
#       print("Enter the goal state matrix \n")        
#       goal = self.accept()

#       start = Node(start,0,0)
#       start.fval = self.f(start,goal)
#       self.open.append(start)
#       print("\n\n")
#       while True:
#           cur = self.open[0]
#           print("")
#           print("  | ")
#           print("  | ")
#           print(" \\\'/ \n")
#           for i in cur.data:
#               for j in i:
#                   print(j,end=" ")
#               print("")
#           if(self.h(cur.data,goal) == 0):
#               break
#           for i in cur.generate_child():
#               i.fval = self.f(i,goal)
#               self.open.append(i)
#           self.closed.append(cur)
#           del self.open[0]
#           self.open.sort(key = lambda x:x.fval,reverse=False)


# puz = Puzzle(3)
# puz.process()

"""import numpy as np
import sys


class Puzzle8():

    def __init__(self, start, goal):
        self.table_of_states = {}
        self.goal_state = self.get_state(goal)
        self.initial_state = self.get_state(start)
        self.current_state = []
        self.reachable_states = []
        self.counter = 0
        self.table_coord = {0: (0, 0), 1: (0, 1), 2: (0, 2), 3: (1, 0), 4: (1, 1), 5: (1, 2), 6: (2, 0),
                            7: (2, 1), 8: (2, 2)}

    def get_tag(self, state):
        tag = ''
        for i in state:
            tag += str(i)
        return tag

    def add_state_to_list(self, tag, g, h, parent, explored):
        self.table_of_states[tag] = [g, h, g + h, parent, explored]
        return

    def print_state(self, state):
        print("\n", state[0:3])
        print(state[3:6])
        print(state[6:9], "\n")
        return

    def get_state(self, tag):
        state = []
        for i in range(9):
            state.append(int(tag[i]))
        return state[:]

    def find_state_minimum_cost(self):
        my_list = [x for x in list(self.table_of_states.values()) if x[-1] == 0]
        min1 = min([x[2] for x in my_list])
        min2 = [x for x in my_list if x[2] == min1]
        key = [x for x, y in list(self.table_of_states.items()) if y == min2[0]]
        if type(key) == list:
            return key[0]
        return key

    def distance_states(self, s1, s2):
        d = 0
        for i in range(len(s1)):
            ind1 = self.table_coord[s1.index(i)]
            ind2 = self.table_coord[s2.index(i)]
            d += abs(ind1[0] - ind2[0]) + abs(ind1[1] - ind2[1])
        return d

    def compute_h(self, state):
        return self.distance_states(state, self.goal_state)

    def mark_as_explored(self, state):
        self.table_of_states[self.get_tag(state)][-1] = 1
        return

    def print_sequence(self, state):
        list_sequence = [self.get_tag(state)]
        i = self.table_of_states[self.get_tag(state)][3]
        while i != 0:
            list_sequence.append(i)
            i = self.table_of_states[self.get_tag(i)][3]
        count = 1
        for j in reversed(list_sequence):
            if count == 1:
                print("\nInitial state :")
                self.print_state(self.get_state(j))
            elif count == self.counter + 1:
                print("Goal state :")
                self.print_state(self.get_state(j))
            else:
                print("Step ", count-1)
                self.print_state(self.get_state(j))
            count += 1

    def up(self, state):
        pos_zero = np.argmin(state)
        if pos_zero < 6:
            state[pos_zero] = state[pos_zero + 3]
            state[pos_zero + 3] = 0
        else:
            pass
        return state[:]

    def down(self, state):
        pos_zero = np.argmin(state)
        if pos_zero > 2:
            state[pos_zero] = state[pos_zero - 3]
            state[pos_zero - 3] = 0
        else:
            pass
        return state[:]

    def right(self, state):
        pos_zero = np.argmin(state)
        if pos_zero not in [0, 3, 6]:
            state[pos_zero] = state[pos_zero - 1]
            state[pos_zero - 1] = 0
        else:
            pass
        return state[:]

    def left(self, state):
        pos_zero = np.argmin(state)
        if pos_zero not in [2, 5, 8]:
            state[pos_zero] = state[pos_zero + 1]
            state[pos_zero + 1] = 0
        else:
            pass
        return state[:]

    def get_possible_states(self, state):
        possible_states = [self.up(state[:]), self.down(state[:]), self.right(state[:]), self.left(state[:])]
        possible_unique_states = []
        for i in possible_states:
            if i not in possible_unique_states and i != state:
                possible_unique_states.append(i)
        return possible_unique_states[:]

    def find_by_a_star(self):
        self.current_state = self.initial_state[:]
        self.add_state_to_list(self.get_tag(self.initial_state), 0, self.compute_h(self.initial_state), 0, 0)
        self.counter = 0
        while self.current_state != self.goal_state and self.counter < 300000:
            self.mark_as_explored(self.current_state)
            self.reachable_states = self.get_possible_states(self.current_state)

            for state in self.reachable_states:
                tag = self.get_tag(state)
                g = self.table_of_states[self.get_tag(self.current_state)][0] + 1
                if tag not in self.table_of_states:
                    self.add_state_to_list(tag, g, self.compute_h(state), self.get_tag(self.current_state), 0)
                elif self.table_of_states[tag][0] > g:
                    self.table_of_states[tag][0] = g
                    self.table_of_states[tag][2] = g + self.table_of_states[tag][1]
                    self.table_of_states[tag][3] = self.get_tag(self.current_state)
                    self.table_of_states[tag][-1] = 0

            self.current_state = self.get_state(self.find_state_minimum_cost())
            self.counter += 1

        print("\nTotal steps taken = ", self.counter)
        self.print_sequence(self.current_state)



if __name__ == "__main__":
    puzzle = Puzzle8('052183476', '123456780')
    puzzle.find_by_a_star()"""

