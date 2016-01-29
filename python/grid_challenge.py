t  = int(raw_input())
for i in range(t):
    n = int(raw_input())
    a = []
    f = 1
    for j in range(n):
        a.append(raw_input())
        a[j] = sorted(a[j])
        if ( j > 0):
            if f != -1:          
                for k in range(0,n):         
                    if ( a[j][k] < a[j-1][k] ):
                        f = -1
                        break
    if f == 1:
        print("YES")
    else:
        print("NO")
