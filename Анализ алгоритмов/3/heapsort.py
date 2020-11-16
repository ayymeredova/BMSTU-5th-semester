
a = [6, 5, 4, 3, 2, 1, 0]

n = len(a)
def sift(l, r):
    i = l
    j = 2*i+1
    x = a[i]
    if j < r and a[j] < a[j+1]:
        j+=1
    while (j <= r and a[j] < a[j+1]):
           a[i] =a[j]
           i = j
           j = 2*j+1
           if j < r and a[j]<a[j+1]:
               j+=1
    a[i] = x



def heapsort():
    l = n//2
    r  = n-1
    while l>0:
        l -= 1
        sift(l, r)
    while r > 0:
        x = a[0]
        a[0] = a[r]
        a[r] = x
        r -= 1
        sift(l, r)
heapsort()
print(a)
        
