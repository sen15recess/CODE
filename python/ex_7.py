t = int(raw_input())
for i in range(0,t):
    k = raw_input()
    p = k.split()
    n = int(p[0])
    x = int(p[1])
    y = int(p[2])
    s = 0
    s1 = x*'1' + '0'
    s2= x*'0' + '1'
    if ( n > 0 ):
        for i in range(0,y+1):
            c1 = s1
            c2 = s2
            c1 = c1 + '1'*i
            l1 = n - len(c1)
            if( l1 == 0):
                s = s + 1
            if ( l1 > 0 ):
                s = s + 1

            c2 = c2 + '0'*i
            l2 = n - len(c2)
            if( l2 == 0):
                s = s + 1
            if ( l2 > 0 ):
                s = s + 1
    print(s)
