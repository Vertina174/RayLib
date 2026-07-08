// g++ hi1.cpp -o a -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include<iostream>
#include<vector>
#include"raylib.h"
#define width 800
#define height 600
using namespace std;

int board[3][3] ={
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
int player=0;
int counter=0;
int winner=0;

int checkwinner(){
    for(int i=0; i<3; i++){// checking for rows
        if(board[i][0]!=0){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                return board[i][0];
            }
        }
    }
    for(int i=0; i<3; i++){// Checking for Columns
        if(board[0][i]!=0){
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                return board[0][i];
            }
        }
    }
    if(board[0][0]!=0){// First Digonal
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            return board[0][0];
        }
    }
    if(board[0][2]!=0){// Second Digonal
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            return board[0][2];
        }
    }
    return 0;
}
void HandleInput(){
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        return;

    int mouseX=GetMouseX();
    int mouseY= GetMouseY();
    if(mouseX<180 && mouseX>621)
        return;
    if(mouseY<100 && mouseY>501)
        return;
        
        int y = (mouseX-180)/140;
        int x = (mouseY-100)/133;

    if(board[x][y]!=0)
        return;
 
            board[x][y]= player+1;
            player = !player;
            ++counter;
winner = checkwinner();            
     
}

void drawboard(){
    DrawLine(300,100,300,510,WHITE);
    DrawLine(480,100,480,510,WHITE);

    DrawLine(180,215,620,215,WHITE);
    DrawLine(180,385,620,385,WHITE);
}
void drawmarks(){
    int startx = 200;
    int starty = 70;
    int cellwidth = 150;
    int cellheight = 145;
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        int x = startx + j*cellwidth;
        int y = starty + i*cellheight;
        if(board[i][j]==1)
            DrawText("o",x,y,150,BLUE);
        else if(board[i][j]==2)
            DrawText("x",x,y,150,RED);
        
    }
}
}
void drawwinner(){
    if(winner == 1){
        DrawText("Player 1 Wins!!!",110,height-90,80,YELLOW);
    }
    else if(winner ==2){
        DrawText("Player 2 Wins!!!",110,height-90,80,YELLOW);
    }
    else if(counter==9){
        DrawText("DRAW",300,height-90,80,YELLOW);
    }
}
void drawUI(){
    DrawText("Player: ",10,10,40,WHITE);
    if(!player)
        DrawText("o",170,-20,100,BLUE);
    else
        DrawText("x",170,-20,100,RED);

    if(winner==1)
        DrawText(" Player o Wins!",200,520,60,YELLOW);
    else if(winner==2)
        DrawText("Player x Wins!",200,520,60,YELLOW);
    else if(counter==9)
        DrawText("DRAW!",310,520,60,YELLOW);
    
    

    
}
void drawGame(){
    ClearBackground(BLACK);
    drawboard();
    drawmarks();
    drawUI();
}
int main(){
InitWindow(width,height, "Hello World!");
SetTargetFPS(60);
system("cls");

while (!WindowShouldClose()){
    BeginDrawing();
    drawGame();
    int x=GetMouseX();
    int y=GetMouseY();
    
        system("cls");
        cout<<"Inside Board"<<endl;
        cout<<"Cell: ["<<(GetMouseX()-180)/140<<",";
        cout<< (GetMouseY()-100)/133<<"]"<<endl;
        if(winner==0){
            HandleInput();}
        for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j];
        
        }
        cout<<endl;
            
        }
        
    EndDrawing();
    }
}