    # 0 == empty
    # 1 == Player 1 [O]
    # 2 == Player 2 [X]
import os
import sys
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

def Checkwinner():
# checking winner for rows
    for i in range(3): 
        if(board[i][0]!=0):
            if(board[i][0]== board[i][1] and board[i][1]==board[i][2]):
                return board[i][0]

# checking Winner for columns
    for j in range(3):
        if(board[0][j]!=0):
            if(board[0][j] == board[1][j] and board[1][j] == board[2][j]):
                return board[0][j]

#checking Winner for Main Digonal
    if(board[0][0]!=0):
        if(board[0][0]== board[1][1] and board[1][1]==board[2][2]):
            return board[0][0]

# Checking Winner for Other Digonal
    if(board[0][2]!=0):
        if(board[0][2]==board[1][1] and board[1][1]==board[2][0]):
            if(board[0][2]==1):
                return board[0][2]
    return 0
    
def player_move():
    global board
    global turn
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
             winner=0
             print("You Opted choice 1...")
             os.system("cls")
             for i in range(9):
                os.system("cls")
                show_board()
                player_move()
                winner=Checkwinner()
                if(winner==1):
                    os.system("cls")
                    show_board()
                    print("Player 1 Won!!!")
                    sys.exit()

                elif(winner==2):
                        os.system("cls")
                        show_board()
                        print("Player 2 Won!!!")
                        sys.exit()
            
        case 2:
            print("You Opted choice 3...")
            status = 0

user_choice()