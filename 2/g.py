import sys

lines = sys.stdin.readlines()
curr_line = 0
first = True

while True:
    if curr_line > len(lines):
        break
    line= lines[curr_line]
    curr_line += 1

    if line == "0":
        break

    if first:
        first = False
    else:
        print()
    n, k =  [int(x) for x in line.split()]

    players = [[0,0] for _ in range(n)]


    for i in range(k*n*(n-1)//2):
        p_one, c_one, p_two, c_two = lines[curr_line].split()
        curr_line += 1

        p_one = int(p_one)
        p_two = int(p_two)

        winner = 0
        
        if c_two == c_one:
            winner = 0
        elif (c_one == "rock" and c_two == "scissors") or \
            (c_one == "paper" and c_two == "rock") or \
            (c_one == "scissors" and c_two == "paper"):
            winner = 1
        else:
            winner = 2

        if winner == 1:
            players[p_one-1][0] += 1
            players[p_two-1][1] += 1
        elif winner == 2:
            players[p_one-1][1] += 1
            players[p_two-1][0] += 1
    
    for player in players:
        try:
            avg = player[0]/(player[1]+player[0])
            print(f"{avg:.3f}")
        except:
            print('-')
        
        