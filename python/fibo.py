from math import sqrt
def F(n):
    return ((1+sqrt(5))**n-(1-sqrt(5))**n)/(2**n*sqrt(5))
n = int(input())
a = []
for i in range(0,n):
    a.append(int(F(i)))

F = lambda x : x**3
k = map(F,a)
print(list(k))
