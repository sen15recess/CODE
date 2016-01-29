z = raw_input()
z = z.split()
n = int(z[0])
k = int(z[1])
x = raw_input()
y = x.split()
x = map(int,y)
y = sorted(x,reverse=True)
p = 0
g = 0
i = 0
mov = 0
if( x != y):
    while(True):
        g = x.index(y[p])
        p = p + 1
        if ( x[g] > x[i] ):
            x[i],x[g] = x[g],x[i]
            mov = mov + 1
        i = i + 1
        if ( x == y or mov == k):
            break

print(' '.join(map(str,x)))
