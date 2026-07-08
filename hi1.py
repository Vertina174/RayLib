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

def winner():
        for i in range(3): # checking winner for rows
            if(board[i][0]== board[i][1] and board[i][1]==board[i][2]):
                    if(board[i][0]==1):
                        print("Player 1 Wins!!!")
                    else:
                        print("Player 2 Wins!!!")
        for j in range(3): # checking Winner for columns
            if(board[0][j] == board[1][j] and board[1][j] == board[2][j]):
                    if(board[i][0]==1):
                        print("Player 1 Wins!!!")
                    else:
                        print("Player 2 Wins!!!")
#checking Winner for Main Digonal
        if(board[0][0]== board[1][1] and board[1][1]==board[2][2]):
                if(board[0][0]==1):
                        print("Player 1 Wins!!!")
                else:
                    print("Player 2 Wins!!!")

# Checking Winner for Other Digonal
if(board[0][2]==board[1][1] and board[1][1]==board[2][0]):
                if(board[0][2]==1):
                        print("Player 1 Wins!!!")
                else:
                    print("Player 2 Wins!!!")

        
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

        turn = not(turn)

def user_choice():
    os.system("cls")
    show_board()
    print("1. Play Game.")
    print("2. Exit Game.")
    choice = int(input())
    match(choice):
        case 1:
             print("You Opted choice 1...")
             os.system("cls")
             player_move()
             
        case 2:
            print("You Opted choice 3...")
            status = 0

user_choice()