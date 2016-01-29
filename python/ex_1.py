def find_minima(arr,low,high,num):
    while ( high - low > 1 ):
        mid = low + (high - low)/2
        if( arr[mid] < num ):
             low = mid
        else:
             high = mid
    return ( min(abs(num - arr[low]),abs(arr[high]-num)))
t = int(raw_input())
x = raw_input()
xs = x.split()
num = map(int,xs)
y = raw_input()
ys = y.split()
p = int(ys[0])
q = int(ys[1])
max = -1
ch = -1
i = p
num1 = num
num = sorted(num1)

while(i <= q):
    g = find_minima(num,0,t-1,i)
    if ( g > max ):
        max = g
        ch = i
    i = i+1
print ch

