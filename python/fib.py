t = raw_input()
s = t.split()
s = map(int,s)
p = s[0]
q = s[1]
r = s[2]
a = []
a.append(p)
a.append(q)
if r == 1:
    print(p)
elif r == 2:
    print(q)
else:
    for i in range(2,r+1):
        a.append(a[i-1]+a[i-2])
print(a[r])
