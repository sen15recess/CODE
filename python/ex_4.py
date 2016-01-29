x = raw_input()
a = x.split()
a[0] = int(a[0])
a[1] = int(a[1])
n = a[0]
q = a[1]
s1 = []
s2 = []

for i in range(0,q):
    sum = 0
    x = raw_input()
    b = x.split()
    for i in range(0,len(b)):
        b[i] = int(b[i])
    if ( b[0] == 1 ):
        s1.append(b)
    if ( b[0] == 2 ):
        s2.append(b)
    if ( b[0] == 3 ):
        l = b[1]
        r = b[2]
        for j in range(l,r+1):
            sum1 = 0
            sum2 = 0
            for x in s1:
                if ( j >= (x[1]) and j <= (x[2])):
                    sum1 = sum1 + x[3]
            for x in s2:
                if ( j >= (x[1]) and j <= (x[2])):
                    sum2 = sum2 + x[3]
            sum = sum + sum1*sum2
        sum = sum % 1000000007
        print(sum)
                    
