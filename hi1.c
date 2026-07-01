#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"raylib.h"
#define width 800
#define height 600
int main(){

InitWindow(width,height, "Hello World!");
SetTargetFPS(60);
system("cls");
while (!WindowShouldClose()){
    BeginDrawing();
    DrawFPS(3,3);
    ClearBackground(BLACK);
    DrawLine(width*0.3,height*0.3,width*0.7,height*0.3,WHITE);
    
    EndDrawing();
}
}