from fractions import Fraction
def subs(s):
  l = len(s)
  c = 0
  rk =''
  for i in xrange(l):
      for j in xrange(i,l):
          k = [s[i:j+1]]
          rk = k[0][::-1]
          print k
          print rk
          if k[0] == rk:
               print("y")
               c = c + 1
  return c
               
  
    
t = int(raw_input())
for i in range(t):
    s = raw_input()
    c= subs(s)
    n = len('hacker')
    tot = n * (n + 1) / 2
    for j in range(1,c+1):
        if c%j == 0 and tot %j == 0:
            c = c/j
            tot = tot/j
    final = str(c)+"/"+str(tot)
    print(final)
