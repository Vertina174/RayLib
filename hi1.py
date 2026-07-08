    # 0 == empty
    # 1 == Player 1 [O]
    # 2 == Player 2 [X]
import os
board = [
    [0,0,0],
    [0,0,0],
    [0,0,0]
    ]
status = True
turn =False # 0->O 1->X

def show_board():
    for item in board:
         print(item)
                
def player_move():
    global board
    global turn
    for  i in range(9): 
        os.system("cls")
        show_board()
        print("\nplayer ",turn+1,"Turn:") # palyer 1 or Player 2 -> (0 or 1)+1

        x = int(input("Enter Row: "))
        y = int(input("Enter Column: "))
        board[x-1][y-1]=turn+1
        if turn==0:
            turn = turn +1
        else:
            turn = turn -1

def user_choice():
    os.system("cls")
    show_board()
    print("1. Play Game.")
    print("2. Clear Board.")
    print("3. Exit Game.")
    choice = int(input())
    match(choice):
        case 1:
             
             print("You Opted choice 1...")
             os.system("cls")
             
             player_move()
             
        case 2:
            os.system("cls")
            print("You Opted choice 2...")

        case 3:
            print("You Opted choice 3...")
            status = 0

user_choice()