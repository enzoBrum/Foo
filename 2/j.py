t = int(input())

for _ in range(t):
    cards = []
    while len(cards) != 52:
        cards.extend(input().split())

    y = 0

    away = []
    remaining = []

    for i in range(len(cards) - 25, len(cards)):
        away.append(cards[i])
    for i in range(0, len(cards)-25):
        remaining.append(cards[i])
    for i in range(3):
        value = remaining[-1]
        x = 10 if not value[0].isnumeric() else int(value[0])
        y += x
        for j in range(10-x+1):
            remaining.pop()

    cards = remaining + away

    print(f"Case {_+1}: {cards[y-1]}")
        
    