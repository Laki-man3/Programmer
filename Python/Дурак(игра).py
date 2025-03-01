import random

deck = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14] * 4

def deal_cards(deck):
    random.shuffle(deck)
    return [deck.pop() for i in range(6)]

def play_durak(deck):
    players = [deal_cards(deck), deal_cards(deck)]
    trump = deck.pop()
    current_suit = None
    current_rank = None
    attacker = 0
    defender = 1
    while players[defender]:
        move = None
        if current_rank:
            print(f"The current rank is {current_rank} of {current_suit}")
        print(f"Player {attacker}'s turn. Their cards are {players[attacker]}")
        while not move:
            move = int(input("Enter the number of a card to attack with: "))
            if move not in players[attacker]:
                move = None
        current_rank = move
        current_suit = None
        print(f"Player {attacker} attacks with {move}")
        if not players[defender]:
            print(f"Player {defender} is out of cards. Player {attacker} wins!")
            break
        move = None
        print(f"Player {defender}'s turn. Their cards are {players[defender]}")
        while not move:
            move = int(input("Enter the number of a card to defend with: "))
            if move not in players[defender]:
                move = None
        if move > current_rank:
            current_rank = None
            current_suit = None
            print(f"Player {defender} successfully defends with {move}")
        else:
            print(f"Player {defender} cannot defend and must take the card")
            players[defender].remove(move)
            players[defender].append(current_rank)
            current_rank = None
            current_suit = None
        attacker, defender = defender, attacker

play_durak(deck)