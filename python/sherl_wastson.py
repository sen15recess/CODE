def find_minima(arr,low,high,num):
    while ( high - low > 1 ):
        mid = low + (high - low)/2
        if( arr[mid] < num ):
             low = mid
        else:
             high = mid
    return ( min(abs(num - arr[low]),abs(arr[high]-num)))
def sort(array):
    less = []
    equal = []
    greater = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x < pivot:
                less.append(x)
            if x == pivot:
                equal.append(x)
            if x > pivot:
                greater.append(x)
        # Don't forget to return something!
        return sort(less)+equal+sort(greater)  # Just use the + operator to join lists
    # Note that you want equal ^^^^^ not pivot
    else:  # You need to hande the part at the end of the recursion - when you only have one element in your array, just return the array.
        return array
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
num = sort(num1)

while(i <= q):
    g = find_minima(num,0,t-1,i)
    if ( g > max ):
        max = g
        ch = i
    i = i+1
print ch

