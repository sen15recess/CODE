from operator import itemgetter
n = int(input())
c = 0
a = []
k = []
for i in range(0,n*2):
    c = c + 1
    k.append(input())
    if(c == 2):
      a.append(k)  
      k = []
      c = 0
for i in range(0,n):
    a[i][1] = float(a[i][1])
k = a    
a.sort(key=itemgetter(1))
min = a[0][1]
g = min
for i in range(0,n):
    if a[i][1] != min :
        g = a[i][1]
        break
k.sort()
for i in range(0,n):
    if k[i][1] == g :
        print(k[i][0])
        
        
