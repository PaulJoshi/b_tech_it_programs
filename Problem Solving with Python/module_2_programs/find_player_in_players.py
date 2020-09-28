# Write a program that defines a list of players who are in a team. Check wether a particular player is there in the team or not

players = ["Smith", "Tom", "Harry", "Helen", "Smyle"]

player = input("Enter the name of the player: ")

if player in players:
    print(f"{player} is a member")
else:
    print(f"{player} is not a member")