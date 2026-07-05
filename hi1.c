// gcc hi1.c -o a -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"raylib.h"
#define width 800
#define height 600

void drawboard(){
    DrawLine(300, 100, 300, height*0.85, WHITE);
DrawLine(500, 100, 500, height*0.85, WHITE);

DrawLine(180, 215, width*0.79, 215, WHITE);
DrawLine(180, 385, width*0.79, 385, WHITE);

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
    Vector2 position = GetMousePosition();
    
    EndDrawing();
}
}