t = int(raw_input())
for i in range(t):
    x = raw_input()
    y = x.split()
    x = map(int,y)
    a = raw_input()
    aq = a.split()
    a = map(int,aq)
    b = raw_input()
    bq = b.split()
    b = map(int,bq)
    c = 0
    a = sorted((a), reverse=True)
    b = sorted(b)
    for j in range(0,x[0]):
        if ( a[j] + b[j] < x[1]):
            print("NO")
            break
        else:
            c = c + 1
    if ( c == x[0] ):
        print("YES")
