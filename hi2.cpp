#include<raylib.h>
#include<iostream>
#include<random>
#include<vector>
#define width 800
#define height 600
using namespace std;
int main(){
InitWindow(width,height,"asdf");

BeginDrawing();
DrawFPS(3,3);
DrawRectangle(5,5,50,50,WHITE);

EndDrawing();

while(!WindowShouldClose()){
BeginDrawing();
EndDrawing();
}
}