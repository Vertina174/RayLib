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
int player=0,counter=0;
void drawboard(){
    DrawLine(300, 100, 300, height*0.85, WHITE);
DrawLine(500, 100, 500, height*0.85, WHITE);

DrawLine(180, 215, width*0.79, 215, WHITE);
DrawLine(180, 385, width*0.79, 385, WHITE);
DrawText("Player: ",5,5,50,WHITE);
if(!player){
    DrawRectangle(190,5,50,70,BLACK);
    DrawText("o",190,-20,100,WHITE);
}
else{
    DrawRectangle(190,5,50,70,BLACK);
    DrawText("x",190,-20,100,WHITE);
}
}
int checkwinner(){
    for(int i=0; i<3; i++){ // checking for rows
        if(board[i][0]!=0){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                return board[i][0];
            }
        }
    }
    for(int i=0; i<3; i++){
        if(board[0][i]!=0){
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                return board[0][i];
            }
        }
    }
    if(board[0][0]!=0){
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            return board[0][0];
        }
    }
    if(board[0][2]!=0){
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            return board[0][2];
        }
    }
    return 0;
}

void playermove(int position){
    counter++;
    switch(position){
        case 1:{
            if(player==0){
                BeginDrawing();
                
                DrawText("o",200,70,150,BLUE);
                EndDrawing();
                board[0][0]=1;
                player=1;                
            }
            else{
                BeginDrawing();
                EndDrawing();
                DrawText("x",200,70,150,RED);
                EndDrawing();
                board[0][0]=2;
            player=0;}
            break;
        }
        case 2:{
            if(player==0){
                BeginDrawing();
                DrawText("o",350,70,150,BLUE);
                EndDrawing();
                board[0][1]=1;
                player=1;                
            }
            else{
                BeginDrawing();
                DrawText("x",350,70,150,RED);
                EndDrawing();
                board[0][1]=2;
            player=0;}
            
            break;
        }
        case 3:{
             if(player==0){
                DrawText("o",521,70,150,BLUE);
                board[0][2]=1;
                player=1;                
            }
            else{
                DrawText("x",521,70,150,RED);
                board[0][2]=2;
            player=0;}
            break;
        }
        case 4:{
            if(player==0){
                DrawText("o",200,216,150,BLUE);
                board[1][0]=1;
                player=1;                
            }
            else{
                DrawText("x",200,216,150,RED);
                board[1][0]=2;
            player=0;}
            break;
        }
        case 5:{
            if(player==0){
                DrawText("o",350,216,150,BLUE);
                board[1][1]=1;
                player=1;                
            }
            else{
                DrawText("x",350,216,150,RED);
                board[1][1]=2;
            player=0;}
            break;
        }
        case 6:{
            if(player==0){
                DrawText("o",521,216,150,BLUE);
                board[1][2]=1;
                player=1;                
            }
            else{
                DrawText("x",521,216,150,RED);
                board[1][2]=2;
            player=0;}
            break;
        }
        case 7:{
            if(player==0){
                DrawText("o",200,370,150,BLUE);
                board[2][0]=1;
                player=1;                
            }
            else{
                DrawText("x",200,370,150,RED);
                board[2][0]=2;
            player=0;}
            break;
        }
        case 8:{
            if(player==0){
                DrawText("o",350,370,150,BLUE);
                board[2][1]=1;
                player=1;                
            }
            else{
                DrawText("x",350,370,150,RED);
                board[2][1]=2;
            player=0;}
            break;
        }
        case 9:{
            if(player==0){
                DrawText("o",521,360,150,BLUE);
                board[2][2]=1;
                player=1;                
            }
            else{
                DrawText("x",521,360,150,RED);
                board[2][2]=2;
            player=0;}
            break;
        }
        default:{
            break;
        }
    }
    int winner = checkwinner();
    if(winner == 1){
        DrawText("Player 1 Wins!!!",110,5,80,YELLOW);
    }
    else if(winner ==2){
        DrawText("Player 2 Wins!!!",110,5,80,YELLOW);
    }
    else if(counter==9){
        DrawText("DRAW",300,5,80,YELLOW);
    }
}
void getmouseposition(){
    int x=GetMouseX();
    int y= GetMouseY();
     if(x>180 && x<300 ){
        if( y>100 && y<215){ // First Cell
        cout<<"First Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(board[0][0]==0){
            playermove(1);}
            
        }
    }
        else if(y>216 && y<385){ // Fourth Cell
            cout<<"Fourth Cell"<<endl;
         if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(board[1][0]==0)
            playermove(4);
            
        }
        }
        else if(y>386 && y<500){
            cout<<"Seventh Cell"<<endl;// Seventh Cell
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(board[2][0]==0)
            playermove(7);
            
        }
        }
    }
     else if(x>301 && x<500 ){
        if( y>100 && y<215){ // second Cell
        cout<<"Second Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(board[0][1]==0)
            playermove(2);
            
        }
    }
        else if(y>216 && y<385){// Fifth Cell
            cout<<"Fifth Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(board[1][1]==0)
            playermove(5);
        }
        }
        else if(y>386 && y<500){ // Eighth Cell
            cout<<"Eight Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(board[2][1]==0)
            playermove(8);
            
        }
        }
    }
    else if(x>501 && x<620 ){// Third Cell
        if( y>100 && y<215){
        cout<<"Third Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(board[0][2]==0){
           playermove(3);}
            
        }
    }
        else if(y>216 && y<385){
            cout<<"Sixth Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(board[1][2]==0){
            playermove(6);}
            
        }
        }
        else if(y>386 && y<500){
            cout<<"Nineth Cell"<<endl;
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(board[2][2]==0){
            playermove(9);}
            
        }
        }
    }
}

void clear_board(){
    ClearBackground(BLACK);
}
int main(){

InitWindow(width,height, "Hello World!");
SetTargetFPS(60);
system("cls");
while (!WindowShouldClose()){
    BeginDrawing();
    
    drawboard();
    
    int x=GetMouseX();
    int y=GetMouseY();
    if(x>180 && x<621 && y>100 && y<501){
        system("cls");
        cout<<"Inside Board"<<endl;
        getmouseposition();
        for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    }
    
    EndDrawing();
}
}