#2 lab vinograd's algorithm
import random
import timeit
##import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import pylab
import matplotlib.patches
import matplotlib.lines
import matplotlib.path
import numpy as np

n = int(input("Input n: "))
m = int(input("Input m: "))

p = int(input("Input p(p == m): "))
q = int(input("Input q: "))

a = [[random.randint(-20, 20) for j in range(m)] for i in range (n)]
b = [[random.randint(-20, 20) for j in range(q)] for i in range (p)]
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

##def test(f:callable, a, b, c, n, m, q, n= 5):
##    tm = timeit.timeit("f(a, b, c, n, m, q)", globals = {'f' : f, 'a'  : a, 'b' : b, 'c': c, 'n':n, 'm' :m, "q" : q }, number = n)
##    r = f(a, b, c, n, m, q)
##    print(f'a = {a!r} and b = {b!r} and  c = {c!r} and n = {n!r} and m = {m!r} and q = {q!r} and {f.__name__} = {r} and time = {tm:.10f}')


##test(standart, a, b, c, n, m, q)






chot = [100, 200, 300, 400, 500, 600, 700, 800]
res_chot_standart = [round(5.6162905), round(44.0010567), round(173.8016143), round(380.9138712), round(912.571966), round(1407.4054368), round(2397.3076827), round(3172.6260907)]
res_chot_vinograd = [round(6.7204093), round(53.1906216), round(205.485461), round(567.5476952), round(789.9618352), round(944.2130672), round(1758.158032), round(2436.0321223)]
res_chot_optimize = [round(3.2405215), round(25.8641905), round(98.3173876), round(204.2867363), round(458.0167518), round(838.7004837), round(1281.73094), round(2323.6873016)]

chot = [100, 200, 300, 400, 500, 600, 700, 800]
res_chot_standart = [5.6162905, 44.0010567, 173.8016143, 380.9138712, 912.571966, 1407.4054368, 2397.3076827, 3172.6260907]
res_chot_vinograd = [6.7204093, 53.1906216, 205.485461, 567.5476952, 789.9618352, 944.2130672, 1758.158032, 2436.0321223]
res_chot_optimize = [3.2405215, 25.8641905, 98.3173876, 204.2867363, 458.0167518, 838.7004837, 1281.73094, 2323.6873016]



nechot = [101, 201, 301, 401, 501, 601, 701, 801]
res_nechot_standart = [round(3.1749277), round(26.6813208), round(79.4127341), round(186.5400959), round(393.0510236), round(1302.3922432), round(2475.5700095), round(3533.706012)]
res_nechot_vinograd = [round(7.2266733), round(59.313198), round(178.5420083), round(511.4633243), round(793.1521475), round(105.0051249), round(1525.7652134), round(2515.7837667)]
res_nechot_optimize = [round(3.2505525),round(32.0022945),round(105.7037387),round(258.90375),round(503.1960079),round(889.9397875),round(1382.6383293),round(1912.0638686)]
def graph1():
    xmax = 800
    xmin = 100
    plt.title("Четные размерности матриц")
    plt.xlim(xmin, xmax, 10)
    plt.ylim(min(res_chot_standart), (max(res_chot_standart)))
    axes = pylab.gca()

    plt.xlabel('Размер матрицы, символы')
    plt.ylabel('Время, секунды')

    plt.plot( chot, res_chot_standart, label = "Стандартный алгоритм")
    plt.plot(chot, res_chot_vinograd, label = "Алгоритм Винограда")
    plt.plot( chot, res_chot_optimize,label = "Оптимизированный алгоритм Винограда")
    legend = plt.legend(loc = "upper left", shadow = True)
    plt.grid()
    plt.show()
    

def graph2():
    xmax = 801
    xmin = 101
    plt.title("Нечетные размерности матриц")
    plt.xlim(xmin, xmax)
    plt.ylim(min(res_nechot_standart), (max(res_nechot_standart)))
    axes = pylab.gca()

    plt.xlabel('Размер матрицы, символы')
    plt.ylabel('Время, секунды')

    plt.plot( nechot, res_nechot_standart, label = "Стандартный алгоритм")
    plt.plot(nechot, res_nechot_vinograd, label = "Алгоритм Винограда")
    plt.plot(nechot, res_nechot_optimize,label = "Оптимизированный алгоритм Винограда")
    legend = plt.legend(loc = "upper left", shadow = True)
    plt.grid()
    plt.show()


graph2()
graph1()

def test(f:callable, a, b, c, p, m, q, n = 10):
    tm = timeit.timeit("f(a, b, c, p, m, q)", globals = {'f' : f, 'a'  : a, 'b' : b, 'c': c, 'p':p, 'm' :m, "q" : q }, number = n)
    r = f(a, b, c, p, m, q)
    print("vinograd_optimize\n")
    print(f'\ntime = {tm:.10f}\n')

    return tm






test(optimize_vinograd, a, b, c, n, m, q)

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

