# 21 Points Game
import random

print("Добро пожаловать в игру 21 очко!")

player_points = 0
computer_points = 0

while player_points < 21 and computer_points < 21:
    choice = input("Хочешь взять карту? (д/н) ")
    if choice == 'н':
        break
    player_points += random.randint(1, 11)
    print("Ты взял карту и сейчас имеешь", player_points, "очков.")

    if player_points > 21:
        print("Ты проиграл. Повезёт в следующий раз!")
        break

    computer_points += random.randint(1, 11)
    print("Бот взял карту и сейчас имеет", computer_points, "очков.")

    if computer_points == 21:
        print("Бот победил!")
        break

if player_points == computer_points:
    print("Ничья, попробуй ещё раз).")
elif player_points > computer_points:
    print("Ты победил, поздравляю!")
else:
    print("Ты проиграл. Повезёт в следующий раз!")