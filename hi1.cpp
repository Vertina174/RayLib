// g++ hi1.cpp -o a -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include<iostream>
#include"raylib.h"
#define width 800
#define height 600
using namespace std;

void drawboard(){
    DrawLine(300, 100, 300, height*0.85, WHITE);
DrawLine(500, 100, 500, height*0.85, WHITE);

DrawLine(180, 215, width*0.79, 215, WHITE);
DrawLine(180, 385, width*0.79, 385, WHITE);

}
void getmouseposition(){
    int x=GetMouseX();
    int y= GetMouseY();
     if(x>180 && x<300 ){
        if( y>100 && y<215){
        cout<<"First Cell"<<endl;
    }
        else if(y>216 && y<385){
            cout<<"Fourth Cell"<<endl;
        }
        else if(y>386 && y<500){
            cout<<"Seventh Cell"<<endl;
        }
    }
     else if(x>301 && x<500 ){
        if( y>100 && y<215){
        cout<<"Second Cell"<<endl;
    }
        else if(y>216 && y<385){
            cout<<"Fifth Cell"<<endl;
        }
        else if(y>386 && y<500){
            cout<<"Eight Cell"<<endl;
        }
    }
    else if(x>501 && x<620 ){
        if( y>100 && y<215){
        cout<<"Third Cell"<<endl;
    }
        else if(y>216 && y<385){
            cout<<"Sixth Cell"<<endl;
        }
        else if(y>386 && y<500){
            cout<<"Nineth Cell"<<endl;
        }
    }
}
int main(){

InitWindow(width,height, "Hello World!");
SetTargetFPS(60);
system("cls");
while (!WindowShouldClose()){
    BeginDrawing();
    DrawFPS(3,3);
    ClearBackground(BLACK);
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