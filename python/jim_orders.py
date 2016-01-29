import operator
x = raw_input()
y = x.split()
x = map(int,y)
p = raw_input()
q = p.split()
p = map(int,q)
q = sorted(p)
s = 0
for i in range(x[0]):
    if s > x[1]:
        print(i-1)
        break
    else:
        s = s + q[i]
    
