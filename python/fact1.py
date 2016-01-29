t = int(raw_input())
for i in range(0,t):
    p = int(raw_input())
    k = raw_input()
    if ( p == 1):
        print("YES")
        continue
    x = k.split()
    flag = 0
    y = []
    for i in range(0,p):
        x[i] = int(x[i])
        if ( i == 0 ):
            y.append(x[0])
        else:
            y.append( y[i-1] + x[i] )
    tot = y[len(y)-1]
    for i in range(1,len(y)):
        if ( y[i-1] == tot - y[i]):
            flag = 1
            print('YES')
            break
    if ( flag == 0 ):
        print('NO')
    
