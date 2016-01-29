n = int(raw_input())
k = raw_input()
s = k.split()
sum = 0
give = 0
take = 0
avg = 0
for i in range(0,len(s)):
    s[i] = int(s[i])
    sum = sum + s[i]
avg = sum/n
move = 0
for i in range(0,len(s)):
    if ( s[i] < avg ):
        take = take + ( avg - s[i] )
    if ( s[i] > avg ):
        diff = s[i] - avg
        take = take - diff
        s[i] = s[i] - diff
        move = move + diff

print(move)
    
