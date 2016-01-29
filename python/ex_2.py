from math import sqrt

def is_square(n):
    return sqrt(n).is_integer()

t = int(raw_input())
for i in range(0,t):
    n = int(raw_input())
    x = 6
    c = 0
    f = 1
    p = 6
    while(True):
        if ( x < n or ( is_square(x) == True )):
            x = x + 1
            p = x
            continue
        c = 0
        f = 1
        for i in range(2,x+1):
            if ( x % i == 0 ):
                if ( n > i ):
                    f = 0
                    break
                if (i != x):
                    c = 1
                if ( is_square(i) == True ):
                    f = 0
                    break
                
        if ( f == 1 and c == 1 ):
            print(x)
            break
        x = x + 1
                
                
            
