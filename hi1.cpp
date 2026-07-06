// g++ hi1.cpp -o a -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include<iostream>
#include<vector>
#include"raylib.h"
#define width 800
#define height 600
using namespace std;
int player=0;
void drawboard(){
    DrawLine(300, 100, 300, height*0.85, WHITE);
DrawLine(500, 100, 500, height*0.85, WHITE);

DrawLine(180, 215, width*0.79, 215, WHITE);
DrawLine(180, 385, width*0.79, 385, WHITE);
for(int i=0; i<9; i++){
    
}
}

void getmouseposition(){
    int x=GetMouseX();
    int y= GetMouseY();
     if(x>180 && x<300 ){
        if( y>100 && y<215){ // First Cell
        cout<<"First Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",200,70,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",200,70,150,RED);
            player=0;}
            
        }
    }
        else if(y>216 && y<385){ // Fourth Cell
            cout<<"Fourth Cell"<<endl;
         if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",200,216,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",200,216,150,RED);
            player=0;}
            
        }
        }
        else if(y>386 && y<500){
            cout<<"Seventh Cell"<<endl;// Seventh Cell
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",200,370,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",200,370,150,RED);
            player=0;}
            
        }
        }
    }
     else if(x>301 && x<500 ){
        if( y>100 && y<215){ // second Cell
        cout<<"Second Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",350,70,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",350,70,150,RED);
            player=0;}
            
        }
    }
        else if(y>216 && y<385){// Fifth Cell
            cout<<"Fifth Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",350,216,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",350,216,150,RED);
            player=0;}
            
        }
        }
        else if(y>386 && y<500){ // Eighth Cell
            cout<<"Eight Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",350,370,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",350,370,150,RED);
            player=0;}
            
        }
        }
    }
    else if(x>501 && x<620 ){// Third Cell
        if( y>100 && y<215){
        cout<<"Third Cell"<<endl;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",521,70,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",521,70,150,RED);
            player=0;}
            
        }
    }
        else if(y>216 && y<385){
            cout<<"Sixth Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",521,216,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",521,216,150,RED);
            player=0;}
            
        }
        }
        else if(y>386 && y<500){
            cout<<"Nineth Cell"<<endl;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(player==0){
                DrawText("o",521,360,150,BLUE);
                player=1;                
            }
            else{
                DrawText("x",521,360,150,RED);
            player=0;}
            
        }
        }
    }
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
    }
    EndDrawing();
}
}