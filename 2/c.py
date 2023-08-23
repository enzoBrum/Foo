def get_cards(cards):
    line = [int(x) for x in input().split()]

    points = 0
    for card in line:
        cards[card] += 1
        
        if card > 10:
            card = 10
        points += card
    return points


def main():
    n = int(input())
    cards = [0 for i in range(14)]
    john = get_cards(cards)
    mary = get_cards(cards)
    common_points = get_cards(cards)

    john += common_points
    mary += common_points

    mary_points_to_win = 23 - mary
    mary_can_23 = False
    mary_card_pos = None
    if mary_points_to_win == 10:
        for i,card in enumerate(cards[10:]):
            if card < 4:
                mary_can_23 = True
                mary_card_pos = 10 + i
                break

    elif mary_points_to_win < 10:
        if cards[mary_points_to_win] < 4:
            mary_can_23 = True
            mary_card_pos = mary_points_to_win
            
    
    john_points_to_bust = 24 - john
    john_can_bust = False
    john_card_pos = None
    if john_points_to_bust <= 10:
        for i,card in enumerate(cards[john_points_to_bust:]):
            if card < 4:
                john_can_bust = True
                john_card_pos = john_points_to_bust + i
                break
    

    if mary_can_23 and john_can_bust and mary+john_card_pos<24:
        print(min(mary_card_pos, john_card_pos))
    elif mary_can_23:
        print(mary_card_pos)
    elif john_can_bust and mary+john_card_pos<24:
        print(john_card_pos)
    else:
        print(-1)

main()
    
