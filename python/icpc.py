t = int(raw_input())
for i in range(0,t):
    x = raw_input()
    a = x.split()
    n = int(a[0])
    k = int(a[1])
    b = []
    f = 1
    for i in range(0,101):
        b.append(0)
    for i in range(0,n):
        nm = raw_input()
        l = len(nm)
        b[l] = b[l] + 1
    for i in b:
        if ( i % k != 0):
            f = 0
            break
                
    if ( f == 0):
        print("Not possible")
    if ( f == 1):
        print("Possible")
        
            
    
