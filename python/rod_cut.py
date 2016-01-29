#rod-cut using memoization
mem = {}
mem[0] = 0
s = None
def rcut(p,n):
    global s
    global mem
    if n in mem:
        return mem[n]
    if n == 0:
        return mem[0]
    for i in range(1,n+1):
        s = max(s,p[i-1]+rcut(p,n-i))            
    mem[i] = s
    return mem[n]
            
        
        





p = raw_input()
p = p.split()
p = map(int,p)
n = int(raw_input())
k = rcut(p,n)
print(k)
