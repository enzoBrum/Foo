import sys
from string import  ascii_lowercase

#f = open("input.txt")
#input = lambda: f.readline().strip()
input = lambda: sys.stdin.readline().removesuffix('\n')
print = lambda s="",end="\n": sys.stdout.write(str(s) + end)


def right(pos,l,c):
	if pos[1] + 1 < c:
		return pos[0],pos[1]+1,True
	return pos[0],pos[1],False
	
def dright(pos,l,c):
	if pos[0] + 1 < l and pos[1] + 1 < c:
		return pos[0]+1,pos[1]+1,True
	return pos[0],pos[1],False
	
def down(pos,l,c):
	if pos[0] + 1 < l:
		return pos[0]+1,pos[1],True
	return pos[0],pos[1],False

def dleft(pos,l,c):
	if pos[0]+1 < l and pos[1] > 0:
		return pos[0]+1,pos[1]-1,True
	return pos[0],pos[1],False
	

def search(matrix, special, words, curr, i, j, d):
    ans = list()
    if curr in words:
        if (i,j) in special:
            special[(i,j)].add(curr)
        else:
            special[(i,j)] = {curr}
        ans.append(curr)

    ni,nj,not_end = d([i,j],len(matrix),len(matrix[0]))

    if not not_end:
        return ans

    curr += matrix[ni][nj]
    curr = "".join(sorted(curr))
    ans += search(matrix,special,words,curr,ni,nj,d)

    for w in ans:
        if (i,j) in special:
            special[(i,j)].add(w)
        else:
            special[(i,j)] = {w}
    return ans
	

def complete_search(matrix, special, words):
    l = len(matrix)
    c = len(matrix[0])
    dlist = [right, dright, down, dleft]
    for i in range(l):
        for j in range(c):
            for d in dlist:
                vec = search(matrix,special,words,matrix[i][j],i,j,d)

                for w in vec:
                    if (i,j) in special:
                        special[(i,j)].add(w)
                    else:
                        special[(i,j)] = {w}


def main():
    l, c = [int(x) for x in input().split()]
    matrix = []
    special = dict()
	 
    for i in range(l):
        w = input().lower()
        matrix.append(w)
	 
	 
    words = set()
    n = int(input())
	 
    for _ in range(n):
        w = input().lower()
        words.add("".join(sorted(w)))
	 	
    complete_search(matrix,special,words)
    ans = 0
	 
    for v in special.values():
        if len(v) > 1:
           ans += 1
	 
    print(ans)
	 
	 
	 
	 
	 
main()
