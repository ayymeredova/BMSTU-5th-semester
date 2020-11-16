import timeit
import random
import time

import matplotlib.pyplot as plt
import pylab
import matplotlib.patches
import matplotlib.lines
import matplotlib.path
import numpy as np
string1 = input("Input 1 string: ")
string2 = input("Input 2 string: ")


def is_weight(char1, char2):
    if char1 != char2:
        return 1
    return 0 #ravny


def gener():
    words = ['submerge', 'difference', 'kitchen', 'kitten', 'mommy', 'puppy', 'independence', 'identify', 'employee', 'employment', 'differentiate', 'sufficiently', 'suffery']
    string1 = words[random.randint(0,12)]
    string2 = words[random.randint(0,12)]
    return string1, string2


def non_recursive_levenshtein (string1, string2):
    n1, n2 = len(string1), len(string2)
    d = [[0  for j in range(n2+1)]for i in range(n1+1)]

    stroka1 = list(' '+ string1)
    stroka2 = list(' '+' '+ string2)
    
    for i in range(n2+1):
        d[0][i] = i

    for i in range(n1+1):
        d[i][0] = i

    if n1 == 0 or n2 ==0:
        return max(n1, n2)
    
    for i in range(1, n1+1):
        for j in range(1, n2+1):
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + is_weight(string1[i-1], string2[j-1]))
            
    for i in range(len(stroka2)):
        print(stroka2[i], end = ' ')
    print('\n')
    
    for i in range(n1+1):
        print(stroka1[i], end=' ')
        for j in range(n2+1):
            print(d[i][j], end = ' ')
        print("\n")
    return d[n1][n2]

def recursive_leven(s1, s2):
    def recursive(n1, n2):
        if n1 == 0 or n2 == 0:
            return max(n1, n2)

        elif s1[n1-1] == s2[n2-1]:
            return recursive(n1-1, n2-1)
        else:
            return 1 + min(
                recursive(n1, n2 -1), #delete
                recursive(n1-1, n2), #insert
                recursive(n1-1, n2-1) # zamena
            )
    return recursive(len(s1), len(s2))



##def distance_matrix(a, b):
##    n, m = len(a), len(b)
##    if n > m:
##        # убедимся что n <= m, чтобы использовать минимум памяти O(min(n, m))
##        a, b = b, a
##        n, m = m, n
##    current_row = range(n + 1)  # 0 ряд - просто восходящая последовательность (одни вставки)
##    for i in range(1, m + 1):
##        previous_row, current_row = current_row, [i] + [0] * n
##        for j in range(1, n + 1):
##            add, delete, change = previous_row[j] + 1, current_row[j - 1] + 1, previous_row[j - 1]
##            if a[j - 1] != b[i - 1]:
##                change += 1
##            current_row[j] = min(add, delete, change)
##    return current_row[n]


def recursive_matrix_leven(string1, string2, matrix):
    def recursive(n1, n2):
        if n1 == 0 or n2 == 0:
            return max(n1, n2)
        for i in range(n2+1):
            matrix[0][i] = i

        for i in range(n1+1):
            matrix[i][0] = i

        if matrix[n1-1][n2-1] != -1:
            return matrix[n1-1][n2-1]

        if string1[n1-1] == string2[n2-1]:
            matrix[n1-1][n2-1] = recursive(n1-1, n2-1)
            return matrix[n1-1][n2-1]
        matrix[n1-1][n2-1] = 1 + min(recursive(n1, n2-1), recursive(n1-1, n2), recursive(n1-1, n2-1))
        return matrix[n1-1][n2-1]
    return recursive(len(string1),len(string2))






def damerau_levenshtein(string1, string2):
    n1, n2 = len(string1), len(string2)
    if n1 == 0:
        return n2
    if n2 == 0:
        return n1
    d = [[0  for j in range(n2+1)] for i in range(n1+1)]
    for i in range(n2+1):
        d[0][i] = i

    for i in range(n1+1):
        d[i][0] = i
                                        
    for i in range(1, n1+1):
        for j in range(1, n2+1):
            insert = d[i-1][j]+1
            delete = d[i][j-1]+1
            replace = d[i-1][j-1]+is_weight(string1[i-1], string2[j-1])
            minimum = min(insert, delete, replace)
            if i>1 and j >1 and is_weight(string1[i-1], string2[j-2]) and is_weight(string1[i-1], string2[j-1]) and is_weight(string1[i-1], string2[j-1]):
                minimum = min(minimum, d[i-2][j-2]+1)
            d[i][j] = minimum
    return d[n1][n2]

##print(distance_matrix(string1, string2))
##n1,n2 = len(string1), len(string2)
##matrix = [[-1  for j in range(n2+1)] for i in range(n1+1)]
##
##
##print("Levenshtein: ",non_recursive_levenshtein(string1, string2))
##print("Recursive Levenshtein: ",recursive_leven(string1, string2))
##print("\n")
##print("\n")
##print("Damerau-Levenshtein: ",damerau_levenshtein(string1, string2))
##print("Recursive matrix = ",  recursive_matrix_leven(string1, string2, matrix))



words = ['submerge', 'difference', 'kitchen', 'kitten', 'mommy', 'puppy', 'independence', 'identify', 'employee', 'employment', 'differentiate', 'sufficiently', 'suffery']
def test_lev_dist(f:callable, s1, s2, n= 500):
    tm = timeit.timeit("f(s1, s2)", globals = {'f' : f, 's1'  : s1, 's2' : s2}, number = n)
    r = f(s1, s2)
    print(f's1 = {s1!r} and s2 = {s2!r} and {f.__name__} = {r} and time = {tm:.10f}')


print("non_recursive - \n")

##for i in range(10):
##    print(i+1,"\n")
##    test_lev_dist(recursive_leven, words[random.randint(0,12)], words[random.randint(0,12)])


iter_time =[6777, 36872, 21574, 237151, 458068, 1823692, 2064513]
times = [5, 10, 15, 100, 200, 350, 500]
recursive_time = [1.8105180, 33.2723388, 10.4631506, 104.5942000, 229.7609000, 556.9742500, 2743362186.6999994]
damerau_time = [7421, 26163, 27570, 186527, 316668, 664259, 1170698]
matrix_time = [4715, 5407, 5446, 5570, 10059, 18948, 29770]

def levenshtein_iter():
    xmax = max(times)
    xmin = min(times)
    ymin = min(iter_time)
    ymax = max(iter_time)
    plt.title("Алгоритм Левенштейна")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')

    plt.plot( times, iter_time)
    plt.plot( times, damerau_time, label = "Дамерау-Левенштейн")
    
    plt.grid()
    plt.show()
def damerau():
    xmax = max(times)
    xmin = min(times)
    ymin = min(damerau_time)
    ymax = max(damerau_time)
    plt.title("Алгоритм Дамерау - Левенштейна")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')
    
    plt.plot( times, damerau_time, label = "Дамерау-Левенштейн")
    plt.grid()
    plt.show()

def levenshtein_recursive():
    xmax = max(times)
    xmin = min(times)
    ymin = min(recursive_time)
    ymax = max(recursive_time)
    plt.title("Рекурсивный алгоритм Левенштейна")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')
    
    plt.plot(times, recursive_time)
    plt.grid()
    plt.show()
    
def matrix():
    xmax = max(times)
    xmin = min(times)
    ymin = min(matrix_time)
    ymax = max(matrix_time)
    plt.title("Рекурсивный алгоритм Левенштейна с заполнением матрицы")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')
    plt.plot( times, matrix_time)
    plt.plot(times, recursive_time)
    plt.grid()
    plt.show()
    
matrix()
##damerau()
levenshtein_iter()
##levenshtein_recursive()

##def my_dist_cached(a, b):
##    @lru_cache(maxsize=len(a) * len(b))
##    def recursive(i, j):
##        if i == 0 or j == 0:
##            return max(i, j)
##        elif a[i - 1] == b[j - 1]:
##            return recursive(i - 1, j - 1)
##        else:
##            return 1 + min(
##                recursive(i, j - 1),
##                recursive(i - 1, j),
##                recursive(i - 1, j - 1)
##            )
##    return recursive(len(a), len(b))
##test_lev_dist(my_dist_cached, "hello world", "bye world!", n=10000)

def time_range(size):
    for i in range(size):
        pass

    
class Ticker:
    def __init__(self):
        self.t = time.clock()

    def __call__(self):
        dt = time.clock() - self.t
        self.t = time.clock()
        return  dt

##print('first took {}ms'.format(tick()))

    
#############################levenshtein obyknovennyi#############################################
    
##start1 = time.clock()
##
##for i in range(5):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time1 = time.clock()- start1
##
##print("non recursive(5) = ", time1)


##print('non recursive(5)  tick {}  '.format(tick()))
##
##general = 0
##for i in range( 10):
##    start1 = 0
##    start1 = time.clock()
##    for i in range(10):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general += time1
##print("non recursive(10) = ", general)
##print('non recursive(10)  tick {}   '.format(tick()))

##general = 0
##for i in range(10):
##    start1 = 0
##    start1 = time.clock()
##    for i in range(15):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general+=time1
##print("non recursive(15) = ", general)
##print('non recursive(15)  tick {}   '.format(tick()))

##general = 0
##for i in range(10):
##    start1 = 0
##    start1 = time.clock()
##    for i in range(100):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general+= time1
##print("non recursive(100) = ", general)
##print('non recursive(100)  tick {}   '.format(tick()))

##general = 0
##for i in range(10):
##    start1 = time.clock()
##    for i in range(200):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general += time1
##print("non recursive(200) = ", general)
##print('non recursive(200)  tick {}  '.format(tick()))
##
##general = 0
##for i in range(10):
##    start1 = 0
##    start1 = time.clock()
##    for i in range(350):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general += time1
##print("non recursive(350) = ", general)
##print('non recursive(350) tick {}  '.format(tick()))
##
##general = 0
##for i in range(10):
##    start1  = 0
##    start1 = time.clock()
##    for i in range(500):
##        tick = Ticker()
##        s1, s2 = gener()
##        non_recursive_levenshtein(s1, s2)
##    time1 = time.clock() - start1
##    general += time1
##print("non recursive(500) = ", general)
##print('non recursive(500) tick {}  '.format(tick()))


##
##
##
#############################################damerau-levenshtein#########################################################
##start2 = time.clock()
##for i in range(5):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(5) = ", time2)
##print('non recursive(5) tick {}  '.format(tick()))
##
##start2 = time.clock()
##for i in range(10):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(10) = ", time2)
##print('non recursive(10) tick {}  '.format(tick()))
##
##
##start2 = time.clock()
##for i in range(15):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(15) = ", time2)
##print('non recursive(15) tick {}  '.format(tick()))
##
##
##start2 = time.clock()
##for i in range(100):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(100) = ", time2)
##print('non recursive(100) tick {}  '.format(tick()))
##
##
##start2 = time.clock()
##for i in range(200):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(200) = ", time2)
##print('non recursive(200) tick {}  '.format(tick()))
##
##
##start2 = time.clock()
##for i in range(350):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(350) = ", time2)
##print('non recursive(350) tick {}  '.format(tick()))
##
##
##start2 = time.clock()
##for i in range(500):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time2 = time.clock() - start2
##print("non recursive(500) = ", time2)
##print('non recursive(500) tick {}  '.format(tick()))
##
##
##
################################################### recursive levenshtein #####################################################
##start3 = time.clock()
##for i in range(5):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(500) = ", time3)
##print('non recursive(500) tick {}  '.format(tick()))
##
##start3 = time.clock()
##for i in range(10):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(10) = ", time3)
##print('non recursive(10) tick {}  '.format(tick()))
##
##
##start3 = time.clock()
##for i in range(15):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(15) = ", time3)
##print('non recursive(15) tick {}  '.format(tick()))
##
##
##start3 = time.clock()
##for i in range(100):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(100) = ", time3)
##print('non recursive(100) tick {}  '.format(tick()))
##
##
##start3 = time.clock()
##for i in range(200):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(200) = ", time3)
##print('non recursive(200) tick {}  '.format(tick()))
##
##
##start3 = time.clock()
##for i in range(350):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(350) = ", time3)
##print('non recursive(350) tick {}  '.format(tick()))
##
##
##start3 = time.clock()
##for i in range(500):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print("non recursive(500) = ", time3)
##print('non recursive(500) tick {}  '.format(tick()))
##
##
##
####################################################### recursive matrix levenshtein #############################################################
##
##start4 = time.clock()
##for i in range(5):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(5) = ", time3)
##print('non recursive(5) tick {}  '.format(tick()))
##
##start4 = time.clock()
##for i in range(10):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(10) = ", time3)
##print('non recursive(10) tick {}  '.format(tick()))
##
##start4 = time.clock()
##for i in range(15):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(15) = ", time3)
##print('non recursive(15) tick {}  '.format(tick()))
##
##
##start4 = time.clock()
##for i in range(100):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(100) = ", time3)
##print('non recursive(100) tick {}  '.format(tick()))
##
##
##start4 = time.clock()
##for i in range(200):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(200) = ", time3)
##print('non recursive(200) tick {}  '.format(tick()))
##
##start4 = time.clock()
##for i in range(350):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(350) = ", time3)
##print('non recursive(350) tick {}  '.format(tick()))
##
##
##start4 = time.clock()
##for i in range(500):
##    tick = Ticker()
##    s1, s2 = gener()
##    non_recursive_levenshtein(s1, s2)
##time4 = time.clock() - start4
##print("non recursive(500) = ", time3)
##print('non recursive(500) tick {}  '.format(tick()))
##






##start2 = time.clock()
##for i in range(500):
##    tick = Ticker()
##    s1, s2 = gener()
##    recursive_leven(s1, s2)
##time2 = time.clock() - start2
##print('first took {}ms'.format(tick()))
##print("time recursive = ", time2)
##
##start3 = time.clock()
##for i in range(500):
##    tick = Ticker()
##    s1, s2 = gener()
##    damerau_levenshtein(s1, s2)
##time3 = time.clock() - start3
##print('first took {}ms'.format(tick()))
##print(time3)




##for i in range(n1+1):
##    for j in range(n2+1):
##        print(matrix[i][j], end =' ')
##    print("\n")
