n = int(raw_input())
c = 1
p = 0
x = raw_input()
a = x.split()
x = map(int,a)
x = sorted(x)
for i in range(1,n):
    if ( x[i] >= x[p] and x[i] <= ( x[p] + 4 ) ):
        continue
    else:
        c = c + 1
        p = i
print(c)
