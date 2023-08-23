import sys
input = sys.stdin.readline
print = lambda s="",end="\n": sys.stdout.write(str(s)+end)

vec = []

for i in range(int(input())):
    t, dir = [int(x) for x in input().split()]
    vec.append((t,dir))

i = 1
curr = vec[0][0] + 10
d = vec[0][1]
other = False
other_t = 0
while i < len(vec):
    while i < len(vec) and vec[i][0] < curr:
        if vec[i][1] != d:
            other = True
            other_t = vec[i][0]
        else:
            curr = vec[i][0] + 10
        i += 1
    
    if i == len(vec):
        continue
    
    if other:
        other = False
        curr = max(curr, other_t) + 10
        other_t = 0
        d = (d+1)%2

    if vec[i][0] > curr:
        if vec[i][1] == d:
            curr = vec[i][0] + 10
        else:
            other = True
            other_t = vec[i][0]
        i += 1

if other:
    other = False
    curr = max(curr, other_t) + 10
    d = (d+1)%2
print(curr)

    
