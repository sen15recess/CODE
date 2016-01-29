t = int(raw_input())
for i in range(0,t):
    s = raw_input()
    y = s.split()
    n = int(y[0])
    x = int(y[1])
    a = []
    for i in range(0,n):
        a.append(i)
    l = len(a)
    c = 1
    k = 0
    g = x-1
    while( True ):  
        try:
            a.pop(g)
            k = g - 1
            if ( k < 0 ):
                k = k + len(a)
            c = c + 1
            if(len(a) == 1):
                print(a[0] + 1)
                break        
            if( len(a) > 0 ):
                g = ( k + c*x) % len(a)
        except RuntimeError:
            break
              
