#2 lab vinograd's algorithm
import random
import timeit
##import matplotlib
##import numpy as np
##import matplotlib.pyplot as plt
##import pylab
##import matplotlib.patches
##import matplotlib.lines
##import matplotlib.path
##import numpy as np

n = int(input("Input n: "))
m = int(input("Input m: "))

p = int(input("Input p(p == m): "))
q = int(input("Input q: "))

a = [[random.randint(-100, 100) for j in range(m)] for i in range (n)]
b = [[random.randint(-100, 100) for j in range(q)] for i in range (p)]
c = [[0 for j in range(q)] for i in range (n)]


# p == m

#standart algorithm
def standart(a, b, c, n, m,  q):

    for i in range (n):
        for j in range (q):
            for k in range (m):
                c[i][j]  += a[i][k] * b[k][j]


def print_matrix(a, n, m):
    print("Matrix: ")
    for i in range (n):
##        print("| ", end = "")
        for j in range (m):
            print( a[i][j],end = ' ')
##        print("|")
        print("\n")


    
#vinograd's algorithm
def vinograd(a, b, c, n, m, q):
    mulh = [0 for i in range(n)]
    mulv = [0 for i in range(q)]
                
    for j in range(q):
        for k in range(m // 2):
            mulv[j] = mulv[j] + (b[2*k][j] * b[2*k+1][j])


    for i in range(n):
        for k in range(m // 2):
            mulh[i] = mulh[i] + (a[i][2*k] * a[i][2*k+1])

    for i in range(n):
        for j in range(q):
            c[i][j] = - mulh[i] - mulv[j]
            for k in range(m // 2):
                c[i][j] = c[i][j] + (a[i][2*k] + b[2*k+1][j]) * (a[i][2*k+1] + b[2*k][j])
                
    if m % 2 != 0:
        for i in range(n):
            for j in range(q):
                c[i][j] = c[i][j] + a[i][m-1] * b[m-1][j]
    
def isOdd(a, b, m, i, j):
    if m % 2 == 0:
        return 0
    return a[i][m-1] * b[m-1][j]

def optimize_vinograd(a, b, c, n, m, q):
    mulh = [0 for i in range(n)]
    mulv = [0 for i in range(q)]

    d = m // 2     
    for j in range(q):
        for k in range(d):
            mulv[j] += (b[2*k][j] * b[2*k+1][j])


    for i in range(n):
        for k in range(d):
            mulh[i] += (a[i][2*k] * a[i][2*k+1])

    
    temp = 0
    for i in range(n):
        for j in range(q):
            temp = isOdd(a, b, m, i, j)
            temp -= mulh[i] + mulv[j]
            for k in range(0,d, 2):
                temp += (a[i][2*k] + b[2*k+1][j]) * (a[i][2*k+1] + b[2*k][j])
            c[i][j] = temp

def test(f:callable, a, b, c, p, m, q, n = 10):
    tm = timeit.timeit("f(a, b, c, p, m, q)", globals = {'f' : f, 'a'  : a, 'b' : b, 'c': c, 'p':p, 'm' :m, "q" : q }, number = n)
    r = f(a, b, c, p, m, q)
    print("vinograd_optimize\n")
    print(f'\ntime = {tm:.10f}\n')

    return tm




times = []

times.append(test(optimize_vinograd, a, b, c, n, m, q))
print(times)
        
def graph():
    xmax = 90
    ymax = 900
    plt.xlim(-xmax, xmax)
    plt.ylim(-ymax, ymax)
    axes = pylab.gca()
    axes.set_aspect("equal")
    plt.grid()
    plt.show()
    



##graph()
##print("DANO: \n")
##print_matrix(a, n, m)
##print_matrix(b, p, q)
##
##print("RESULTATY: \n")
##standart(a, b, c, n, m, q)
##print_matrix(c, n, q)
##c = [[0 for j in range(q)] for i in range (n)]
##vinograd(a, b, c, n, m, q)
##print_matrix(c, n, q)
##
##optimize_vinograd(a, b, c, n, m, q)
##print_matrix(c, n, q)

