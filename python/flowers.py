N, K = raw_input().split()
N = int(N)
K = int(K)
z = []
for i in range(N):
    z.append(0)
for i in range(K):
    y = raw_input()
    x = y.split()
    y = map(int,x)
    a = y[0]
    b = y[1]
    k = y[2]
    if(a-1 >= 0):
        z[a-1] += k
    if( b < N ):
        z[b] -= k
max = 0
s = 0
for i in range(N):
    s = s + z[i]
    if ( s > max ):
        max = s
    
print(max)   
