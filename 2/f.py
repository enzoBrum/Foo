t = int(input())

for _ in range(t):
    c, d = [int(x) for x in input().split()]

    c = 9/5*c + 32 + d #f
    c = (c-32)*5/9 #c
    print(f"Case {_+1}: {c:.2f}") 