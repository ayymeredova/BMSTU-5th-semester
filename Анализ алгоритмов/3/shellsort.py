import random
import timeit

import matplotlib.pyplot as plt
import pylab
import matplotlib.patches
import matplotlib.lines
import matplotlib.path
import numpy as np


#shell sorting
def shellSort(data):
    inc = len(data) // 2
    while inc:
        for i, el in enumerate(data):
            while i >= inc and data[i - inc] > el:
                data[i] = data[i - inc]
                i -= inc
            data[i] = el
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)


def bubbleSort(data):
    N = len(data)
    for i in range(N-1):
        for j in range(N-i-1):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]




def cocktailSort(array): 
    length = len(array) 
    swapped = True
    start_index = 0
    end_index = length - 1
    
    while (swapped == True): 
        
        swapped = False
          
        # проход слева направо
        for i in range(start_index, end_index): 
            if (array[i] > array[i + 1]) : 
                # обмен элементов
                array[i], array[i + 1] = array[i + 1], array[i] 
                swapped = True
  
        # если не было обменов прерываем цикл
        if (not(swapped)): 
            break

        swapped = False
        end_index = end_index - 1
  
        #проход справа налево
        for i in range(end_index - 1, start_index - 1, -1): 
            if (array[i] > array[i + 1]): 
                # обмен элементов
                array[i], array[i + 1] = array[i + 1], array[i] 
                swapped = True
 
        start_index = start_index + 1
                
                
                
            



def test(f:callable, a, n = 10):
    tm = timeit.timeit("f(a)", globals = {'f' : f, 'a'  : a }, number = n)
    r = f(a)
    print("bubble\n")
    print(f'\ntime = {tm:.10f}\n')

    return tm

##result = 0
##for i in range(10):
result = test(cocktailSort,[random.randint(-200, 200) for i in range(10)])
print("RESULT = \n", result)


##print([sorted(random.randint(-200, 200) for i in range(300))])
##n = 6
##a = sorted([random.randint(-200, 200) for i in range(n)], reverse = True)
##a = [5 for i in range(n)]
##print("Исходный массив: ", a)
##shellSort(a)
##bubbleSort(a)
##cocktailSort(a)
##print("Ожидаемый массив: ",     a)
##print("Сортировка пузырьком: ", a)
##print("Сортировка Шелла: ",     a)
##print("Шейкер сортировка: ",    a)

time_bubble_sort = [1084, 77603, 433224, 1199938, 2562328, 5016702]
elem = [10, 100, 300, 500, 700, 1000]

time_reverse_sort = [2215,56473, 477015,  1386094, 2862636, 5539335]

time_random_bubble = [2145, 71631, 500447, 1310741, 2577064, 5378399]
def bubble():
    xmax = max(elem)
    xmin = min(elem)
    ymin = min(time_reverse_sort)
    ymax = max(time_reverse_sort)
    plt.title("Сортировка пузырьком")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')

    plt.plot( elem,  time_bubble_sort, label = "Отсортированный массив")
    plt.plot( elem, time_random_bubble,  label = "Случайный массив")
    plt.plot( elem, time_reverse_sort, label = "Обратно отсортированный массив")
    legend = plt.legend(loc = "upper left", shadow = True)
    plt.grid()
    plt.show()

time_shaker_sort = [242, 2137, 2854, 7722, 7089, 12066]
time_random_shaker = [300,7308, 86722, 262657,  460562, 942419]
time_reverse_shaker = [480, 11633, 107924, 362706, 635177, 1343340]
def cocktail():
    xmax = max(elem)
    xmin = min(elem)
    ymin = min(time_reverse_shaker)
    ymax = max(time_reverse_shaker)
    plt.title("Шейкер - сортировка")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')

    plt.plot( elem,  time_shaker_sort, label = "Отсортированный массив")
    plt.plot( elem, time_random_shaker,  label = "Случайный массив")
    plt.plot( elem, time_reverse_shaker, label = "Обратно отсортированный массив")
    legend = plt.legend(loc = "upper left", shadow = True)
    plt.grid()
    plt.show()

time_shell_sort = [842,8437,34295,57884,95701,149729]
time_reverse_shell = [907,7352, 35593, 69416,114963,137485]
time_random_shell = [906,8068, 40303, 121758, 128520, 142852]

def shell():
    xmax = max(elem)
    xmin = min(elem)
    ymin = min(time_reverse_shell)
    ymax = max(time_reverse_shell)
    plt.title("Сортировка Шелл")
    plt.xlim(xmin, xmax)
    plt.ylim(ymin, ymax)
    axes = pylab.gca()

    plt.xlabel('Размерность массива')
    plt.ylabel('Время, тики')

    plt.plot( elem,  time_shell_sort, label = "Отсортированный массив")
    plt.plot( elem, time_random_shell,  label = "Случайный массив")
    plt.plot( elem, time_reverse_shell, label = "Обратно отсортированный массив")
    legend = plt.legend(loc = "upper left", shadow = True)
    plt.grid()
    plt.show()

bubble()
cocktail()
shell()

