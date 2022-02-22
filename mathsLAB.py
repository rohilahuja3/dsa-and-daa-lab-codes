#LAB 1

"""import numpy as np
a=np.array([[1,2],[3,4]])
b=np.array([[11,12],[13,14]])
#b1=np.array([1,2,3,4])
#print(a)
#print(b)
a1=np.arange(15).reshape(3,5)
print("1. ")
print(a1,"\n")
print("2. ")
print(a1.shape,"\n")
print("3. ")
print(np.dot(a,b),"\n")
print("4. ")
print(np.vdot(a,b),"\n")
print("5. ")
print(np.matmul(a,b),"\n")
print("6. ")
print(a[1,1],"\n")
i3=np.identity(3,dtype=int)
print("7. ")
print(i3,"\n")"""


"""import numpy as np
A=np.array([[0,1,1,-2],[1,2,-1,0],[2,4,1,-3],[1,-4,-7,-1]])
print("the matrix A is: \n",A)
print("rank of A is: ",np.linalg.matrix_rank(A))
print("addition of the diagnals trace of A: ",np.trace(A))
print("determinat of A: ",np.linalg.det(A))
print("inverse of A: \n",np.linalg.inv(A))
print("power if matrix A is: \n",np.linalg.matrix_power(A,3))
B=np.array([[2,1,3],[1,2,3],[4,2,6]])
print("rank of B is: ",np.linalg.matrix_rank(B))"""


"""import numpy as np
a=np.array([[10,1,1],[1,10,1],[1,1,10]])
b=np.array([12,12,12])
print("solution of linear equation: ",np.linalg.solve(a,b))"""

#LAB 2

#code 1  how to find a argument matrix in the form of a row
"""import numpy as np
A=np.array([1,2,7,4,1,8,3,5])
A1=np.array(range(6))
Abig=np.concatenate((A,A1))
print(Abig)"""

#code 2  how to find a argument matrix in the form of a column using transpose
"""import numpy as np
A=np.array([[10,1,1],[1,10,1],[1,1,10]])
A1=np.array([12,12,12]).T
abig=np.column_stack((A,A1))
print(abig)"""

#code 3  how to find r.r.e.f and then using back substituition method to get the soln. of the eqn. (guass elimination)
"""from sympy import *
M=Matrix([[10,1,1,12],[1,10,1,12],[1,1,10,12]]);
M_rref=M.rref()
print(M_rref)"""

"""from sympy import *
M=Matrix([[1,-2,3,9],[-1,3,0,-4],[2,-5,5,17]]);
M_rref=M.rref()
print(M_rref)"""

#code 4
"""import numpy as np
from scipy.linalg import lu
A=np.array([[2,5,8,7],[5,2,2,8],[7,5,6,6],[5,4,4,8]])
p,l,u=lu(A)
print(p)
print(l)
print(u)"""

"""import numpy as np
from scipy.linalg import lu
A=np.array([[1,-3,0],[0,1,3],[2,-10,2]])
p,l,u=lu(A)
print(p)
print(l)
print(u)"""

#code 5

#code 6
"""import numpy as np
A=np.array([[6,3,4,8],[3,6,5,1],[4,5,10,7],[8,1,7,25]])
L=np.linalg.cholesky(A)
print(L)
print(np.dot(L,L.T))"""




#lab 3

#code 1
"""import numpy as np
a=np.array([[5,4],[1,2]])
w,v=np.linalg.eig(a)
print('eigen value',w)
print()
print('eigen vector',v)
print()"""

#code 2 (for 3,3 matrix)
"""import numpy as np
a=np.array([[1,1,3],[1,5,1],[3,1,1]])
w,v=np.linalg.eig(a)
print('eigen value',w)
print()
print('eigen vector',v)
print()"""

#code 3 (pot / vizualise eigen vector)
"""from turtle import color
import numpy as np
import  matplotlib.pyplot as plt

a=np.array([[5,4],[1,2]])
w,M=np.linalg.eig(a)

print('eigen value',w)
print()
print('eigen vector',M)
print()

rows,cols=M.T.shape
colors=['b','r']

for i, l in enumerate(range(0,cols)):
    plt.arrow(0, 0, M[0, i], M[1, i], head_width=0.15, head_length=0.15, color=colors[i], length_includes_head=True)

plt.plot(0, 0, 'og')  # plot a point (green) at the origin
plt.axis('equal')
plt.xlim([-3, 3])
plt.ylim([-3, 3])
plt.show()"""

#code 4 ( to create a figure object)
"""from turtle import color
import numpy as np
import  matplotlib.pyplot as plt

a=np.array([[5,4],[1,2]])
w,M=np.linalg.eig(a)

print('eigen value',w)
print()
print('eigen vector',M)
print()

fig=plt.figure()
ax=plt.axes()
ax.set_xlim([-1,1])
ax.set_ylim([-1,1])
start=[0,0]
colors=['b','r']

for i, l in enumerate(range(0,2)):
    plt.arrow(0, 0, M[0, i], M[1, i], head_width=0.15, head_length=0.15, color=colors[i], length_includes_head=True)

plt.show()"""

#code 5 (plot / vizualise eigen vector for 3 dimension)
"""import numpy as np
import matplotlib.pyplot as plt

a = np.array([[1, 1, 3], [1, 5, 1], [3, 1, 1]])
w,v= np.linalg.eig(a)
print('Eigenvalue:', w)
print('Eigenvector', v)

fig=plt.figure()
ax=plt.axes(projection='3d')
ax.set_xlim([-2, 2])
ax.set_ylim([-2, 2])
ax.set_zlim([-2, 2])
start=[0,0,0]

for i, l in enumerate(range(0,3)):
    ax.quiver(start[0],start[0],start[0],v[0,i],v[1,i],v[2,i])

plt.show()"""



#lab 4

#code 1 (2 curves on 1 graph)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 20, 100)
y = 2*np.sin(x)
y1= 2*np.cos(x)
fig, ax = plt.subplots()
ax.plot(x, y, linewidth=2.0, color='r')
ax.plot(x, y1, linewidth=2.0, color='g')
ax.set(xlim=(0, 20),   ylim=(-3, 3))
plt.show()"""

#code 2 (3 curves in the same graph)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 20, 100)
y = 2*np.sin(x)
y1= 2*np.cos(x)
y2= x*x
fig, ax = plt.subplots()
ax.plot(x, y, linewidth=2.0, color='r')
ax.plot(x, y1, linewidth=2.0, color='g')
ax.plot(x, y2, linewidth=2.0, color='b')
ax.set_title("plotting of 3 curves")
ax.set(xlim=(0, 20),   ylim=(-3, 3))
plt.show()"""

#code 3 ( 6 in 1 graph)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(0,10.0, 0.1)
fig, ax = plt.subplots(2,3)
ax[0,0].plot(x, x)
ax[0,1].plot(x, x**2)
ax[0,2].plot(x, np.sin(x))
ax[1,0].plot(x, np.sqrt(x))
ax[1,1].plot(x, 1/x)
ax[1,2].plot(x, np.cos(x))
plt.show()
plt.savefig('demo1.png')
plt.close()"""


#code 4 (alternative of code 3)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 20, 100)
y = 2*np.sin(x)
y1= 2*np.cos(x)
y2= np.cos(2*x)
y3= np.sin(2*x)
fig, axs = plt.subplots(2, 2, layout='constrained')
pc = axs[0, 0].plot(x, y, linewidth=2.0, color='r')
axs[0, 0].set_title('2sin(x)')
co = axs[0, 1].plot(x,y1, linewidth=2.0, color='g')
axs[0, 1].set_title('2cos(x)')
pc1 = axs[1, 0].plot(x, y2, linewidth=2.0, color='r')
axs[1, 0].set_title('cos(2x)')
co1 = axs[1, 1].plot(x,y3, linewidth=2.0, color='g')
axs[1, 1].set_title('sin(2x)')
plt.show()"""


#code 5 (continue of code 5)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 20, 100)
y = 2*np.sin(x)
y1= 2*np.cos(x)
y2= np.cos(2*x)
y3= np.sin(2*x)
fig, axs = plt.subplots(1, 4, layout='constrained')
pc = axs[0].plot(x, y, linewidth=2.0, color='r')
axs[0].set_title('2sin(x)')
co = axs[1].plot(x,y1, linewidth=2.0, color='g')
axs[1].set_title('2cos(x)')
pc1 = axs[2].plot(x, y2, linewidth=2.0, color='r')
axs[2].set_title('cos(2x)')
co1 = axs[3].plot(x,y3, linewidth=2.0, color='g')
axs[3].set_title('sin(2x)')
plt.show()"""

#code 6 (print surface)
"""from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt
x = np.outer(np.linspace(-2, 2, 30), np.ones(30))
y = x.copy().T # transpose
z = np.sqrt(x **2 + y** 2)
fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, z,cmap='viridis', edgecolor='none')
ax.set_title('Surface plot z=sqrt(x^2+y^2)')
plt.show()"""

#code 7 (2 curves in 1)
"""import numpy as np
import matplotlib.pyplot as plt
fig=plt.figure()
ax=fig.add_subplot(1,2,1,projection='3d')
x = np.outer(np.linspace(-2, 2, 30), np.ones(30))
y = x.copy().T # transpose
z = (x*y**6 + y)
ax.plot_surface(x,y,z,cmap='magma',edgecolor='none')
ax.set_title("surface plot -> z = x(y^6)+y")
ax=fig.add_subplot(1,2,2,projection='3d')
z2=np.sin(2*x)
ax.plot_surface(x,y,z2,cmap='RdPu',edgecolor='none')
ax.set_title("surface plot -> z2 = sin(2x)")
plt.show()
"""

#code 8 (extension of code 7)
"""import numpy as np
import matplotlib.pyplot as plt
fig=plt.figure()
x = np.outer(np.linspace(-2, 2, 30), np.ones(30))
y = x.copy().T # transpose

ax=fig.add_subplot(2,2,1,projection='3d')
z = np.cos(x*y)
ax.plot_surface(x,y,z,cmap='magma',edgecolor='none')
ax.set_title("surface plot -> z = cos(xy)")

ax=fig.add_subplot(2,2,2,projection='3d')
z2=np.cos(x+y)
ax.plot_surface(x,y,z2,cmap='RdPu',edgecolor='none')
ax.set_title("surface plot -> z2 = cos(x+y)")

ax=fig.add_subplot(2,2,3,projection='3d')
z3=np.sin(x+y)
ax.plot_surface(x,y,z3,cmap='RdPu',edgecolor='none')
ax.set_title("surface plot -> z3 = sin(x+y)")

ax=fig.add_subplot(2,2,4,projection='3d')
z4=np.sin(x*y)
ax.plot_surface(x,y,z4,cmap='RdPu',edgecolor='none')
ax.set_title("surface plot -> z4 = sin(x*y)")

plt.show()"""


#code 9 (plot parametric curve)
"""import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['legend.fontsize'] = 10
fig = plt.figure()
ax = fig.gca(projection='3d')
theta = np.linspace(-4 * np.pi, 4 * np.pi, 100)
z = np.linspace(-2, 2, 100)
r = 2
x = r * np.sin(theta)
y = r * np.cos(theta)
ax.plot(x, y, z, label='parametric curve')
ax.legend()
plt.show()"""


#lab 5

# code 1 (contour for z=x^2+y^2))
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-10, 10, 0.2)
y = np.arange(-10, 10, 0.2)
[X,Y] = np.meshgrid(x,y)
print([X,Y])
fig, ax = plt.subplots(1, 1)
Z = X ** 2 + Y ** 2
ax.contour(X, Y, Z)
ax.set_title('Contour Plot')
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.show()"""

# code 2 (contour for z=sin(xy))
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-10, 10, 0.2)
y = np.arange(-10, 10, 0.2)
[X,Y] = np.meshgrid(x,y)
print([X,Y])
fig, ax = plt.subplots(1, 1)
Z = np.sin(X*Y)
ax.contour(X, Y, Z, cmap='RdGy')
ax.set_title('Contour Plot')
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.show()"""

# code 3 (contourf z=sin(xy))
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-10, 10, 0.2)
y = np.arange(-10, 10, 0.2)
[X,Y] = np.meshgrid(x,y)
print([X,Y])
fig, ax = plt.subplots(1, 1)
Z = np.sin(X*Y)
ax.contourf(X, Y, Z, 20)
ax.set_title('Contour Plot')
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.show()"""

# code 4 (contourf z=sin(xy) usimg colorbar() )
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-10, 10, 0.2)
y = np.arange(-10, 10, 0.2)
[X,Y] = np.meshgrid(x,y)
print([X,Y])
fig, ax = plt.subplots(1, 1)
Z = np.sin(X*Y)
ax.contourf(X, Y, Z, 20)
ax.set_title('Contour Plot')
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.show()
plt.imshow(Z,extent=[0,5,0,5],origin='lower')
plt.colorbar()
plt.axis(aspect='image')"""

#code 5 (plotting 6 contour graph using subplots(2,3) )
"""import matplotlib.pyplot as plt
import numpy as np
x = np.arange(-10, 10, 0.2)
y = np.arange(-10, 10, 0.2)
[X,Y] = np.meshgrid(x,y)

Z1 = np.sin(X*Y)
Z2 = np.sin(X-Y)
Z3 = (1 - X**2)*(1 - Y**2)
Z4 = np.exp(X) * np.cos(Y)
Z5 = np.sin(X) - np.sin(Y)
Z6 = (X - Y)/(1 + X**2 + Y**2)

fig, axs = plt.subplots(2, 3)
pc = axs[0, 0].contour(X, Y, Z1)
axs[0, 0].set_title('sin(xy)')
pc = axs[0, 1].contour(X, Y, Z2)
axs[0, 1].set_title('sin(x-y)')
pc = axs[0, 2].contour(X, Y, Z3)
axs[0, 2].set_title('(1 - x^2)(1-y^2')
pc = axs[1, 0].contour(X, Y, Z4)
axs[1, 0].set_title('e^x cos(y)')
pc = axs[1, 1].contour(X, Y, Z5)
axs[1, 1].set_title('sin(x) - sin(y)')
pc = axs[1, 2].contour(X, Y, Z6)
axs[1, 2].set_title('(x-y)/(1 + x^2 + y^2)')
plt.show()"""

# code 6 (2d vector field for F=x^2 i +y^3 j)
"""import numpy as np
import matplotlib.pyplot as plt
x,y = np.meshgrid(np.linspace(-5,5,10),np.linspace(-5,5,10))
u = x**2
v = pow(y,3)
plt.quiver(x,y,u,v)
plt.show()"""

# code 7 (2d vector field for F=)

# code 8 (3d vector field)
"""from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np
fig = plt.figure()
ax = fig.gca(projection='3d')
x, y, z = np.meshgrid(np.arange(-1, 1, 0.2),np.arange(-1, 1, 0.2),np.arange(-1, 1, 0.8))
u=x**x
v=y**y
w=z**z
plt.quiver(x, y, z, u, v, w, length=0.4, color = 'black')
plt.show()"""

# code 9 (vistualizing the discreate function)
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0.1, 2 * np.pi,84)
y = np.exp(np.cos(x))
plt.stem(x, y)
plt.show()"""

# code 10
"""import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0.1, 2 * np.pi, 41)
y = np.exp(np.cos(x))
markerline, stemlines, baseline = plt.stem(x, y, linefmt='grey', markerfmt='D', bottom=1.1)
markerline.set_markerfacecolor('none')
plt.show()"""

# code 11 (pie chart)
"""from matplotlib import pyplot as plt
import numpy as np
colors = ( "orange", "blue")
Earth = ['Land ',  ' Water']
data = [29.2, 70.8]
fig=plt.figure(figsize=(10, 7))
plt.pie(data, labels = Earth, colors = colors)
plt.title('Earth')
plt.show()"""

# code 12 (draw the sample pie given)

# code 13 (bar graph)
"""import numpy as np
import matplotlib.pyplot as plt
fig = plt.figure(figsize = (6, 4))
langs = ['C++', 'Java', 'Python']
students = [50,45,85]
plt.bar(langs,students,color = ['r','g','b'], width = 0.3)
plt.xlabel("Courses offered")
plt.ylabel("No. of students enrolled")
plt.title('Bar plot')
plt.show()"""