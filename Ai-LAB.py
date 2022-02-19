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

    """import math
import time
from operator import itemgetter
 
PUZZLE_TYPE = 8
MAT_SIZE = int(math.sqrt(PUZZLE_TYPE + 1))
 
class PriorityQueue(object):
 
    def __init__(self):
        self.elements = []
        self.max_elements = 0
 
    def get_max_elements(self):
    	return self.max_elements
 
    def empty(self):
        return len(self.elements) == 0
 
    def put(self, item, h=0, g=0, priority=0):
        self.elements.append((priority, h, g, item))
        self.elements.sort(key=itemgetter(0))
        self.max_elements = self.max_elements if self.max_elements > len(self.elements) else len(self.elements)
 
    def get_item(self):
        return self.elements.pop(0)
 
class Problem(object):
 
	def __init__(self, initial_state=None):
		self.initial_state = initial_state
		self.goal_state = self.get_goal()
		self.explored = []
 
	def goal_test(self, node):
		self.explored.append(node)
		return node == self.goal_state
 
	def get_level(self):
		return len(self.explored);
 
	def is_explored(self, node):
		return node in self.explored
 
	def get_current_state(self):
		return self.initial_state
 
	def get_goal_state(self):
		return self.goal_state
 
	def get_goal(self):
		goal = []
		for x in xrange(1, PUZZLE_TYPE + 1):
			goal.append(x)
		goal.append(-1)
		return goal
 
	def print_current_board(self):
		print_board(self.initial_state)
 
 
def print_board(mat):
	print "\nBoard:"
	print "*" * 5 * MAT_SIZE
	for index, val in enumerate(mat):
		if (index + 1) % MAT_SIZE == 0:
			print val if val != -1 else "x"
		else:
			print val if val != -1 else "x", " ",
	print "*" * 5 * MAT_SIZE
 
 
def can_move_up(mat):
	return True if mat.index(-1) >= MAT_SIZE else False
 
def can_move_down(mat):
	return True if mat.index(-1) < PUZZLE_TYPE + 1 - MAT_SIZE else False
 
def can_move_left(mat):
	return False if mat.index(-1) % MAT_SIZE == 0 else True
 
def can_move_right(mat):
	return False if mat.index(-1) % MAT_SIZE == MAT_SIZE - 1 else True
 
def move_x_up(mat):
	if can_move_up(mat):
		index = mat.index(-1)
		mat[index - MAT_SIZE], mat[index] = mat[index], mat[index - MAT_SIZE]
		return mat
	return None
 
def move_x_down(mat):
	if can_move_down(mat):
		index = mat.index(-1)
		mat[index + MAT_SIZE], mat[index] = mat[index], mat[index + MAT_SIZE]
		return mat
	return None
 
def move_x_left(mat):
	if can_move_left(mat):
		index = mat.index(-1)
		mat[index - 1], mat[index] = mat[index], mat[index - 1]
		return mat
	return None
 
def move_x_right(mat):
	if can_move_right(mat):
		index = mat.index(-1)
		mat[index + 1], mat[index] = mat[index], mat[index + 1]
		return mat
	return None
 
def general_search(problem, queueing_func):
	depth = 0
	nodes = PriorityQueue()
	nodes.put(problem.get_current_state())
	while not nodes.empty():
		entire_node = nodes.get_item()
		node = entire_node[3]
		if (entire_node[2] or entire_node[1]):
			print "The best state to expand with a g(n) = %d and h(n) = %d is.." % (entire_node[2], entire_node[1]),
		print_board(node)
		if problem.goal_test(node): 
			print "Goal State"
			print "To solve this problem the search algorithm expanded a total of %d nodes." % problem.get_level()
			print "The maximum number of nodes in the queue at any one time was %d."% nodes.get_max_elements()
			print "The depth of the goal node was %d" % entire_node[2]
			return node
		print "Expanding this state\n\n"
		queueing_func(nodes, expand(entire_node, problem))
		depth += 1
 
def expand(node, problem):
	all_nodes = PriorityQueue()
	node1 = move_x_up(node[3][:])
	node2 = move_x_down(node[3][:])
	node3 = move_x_left(node[3][:])
	node4 = move_x_right(node[3][:])
	if node1 and not problem.is_explored(node1):
		all_nodes.put(node1, 0, node[2] + 1, 1)
	if node2 and not problem.is_explored(node2):
		all_nodes.put(node2, 0, node[2] + 1, 3)
	if node3 and not problem.is_explored(node3):
		all_nodes.put(node3, 0, node[2] + 1, 2)
	if node4 and not problem.is_explored(node4):
		all_nodes.put(node4, 0, node[2] + 1, 4)
	return all_nodes
 
def uniform_cost_search(nodes, new_nodes):
	while not new_nodes.empty():
		node = new_nodes.get_item()
		nodes.put(node[3], 0, node[2], 0)
 
 
 
 
if __name__ == "__main__":
	print "Welcome to the awesome %d-puzzle solver." % PUZZLE_TYPE
	mat = []
 
	print "Enter elements for %d Puzzle." % PUZZLE_TYPE
	print "NOTE: Use \"x\" for blank.\n"
	for i in xrange(MAT_SIZE):
		print "Enter elements for row %d" % (i + 1)
		mat.extend([-1 if x == "x" else int(x) for x in raw_input().split()])
 
	problem = Problem(mat)
	print "Initial State",
	problem.print_current_board()
	print "Goal State",
	print_board(problem.get_goal_state())
	print "\n\n"
	print "*"*50
 
	general_search(problem, uniform_cost_search)"""