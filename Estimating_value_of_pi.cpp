#include"raylib.h"
#include<iostream>
using namespace std;
#define width 800
#define height 600
float a=width*0.2, b=0;
float x=width*0.7, y=-1;
Rectangle rect1= {width*0.2,height*0.7-30,30,30};
Rectangle rect2={width*0.7+100,height*0.7-300,1200,300};
unsigned long long counter=0;
float   m1=1,m2=1000000;


void update_position(){
    
    rect1.x+=b;
    rect2.x+=y;
    if(rect1.x<=60)  {b*=-1;
   cout<<"Collision Occured: "<<++counter<<endl;}
    
     
 if(CheckCollisionRecs(rect1,rect2)){
    cout<<"Collision Occured: "<<++counter<<endl;
    float temp1=(((m1-m2)/(m1+m2))*b)+((2*m2)/(m1+m2))*y;
    float temp2=(((2*m1)/(m1+m2))*b)+((m2-m1)/(m1+m2))*y;

    b=temp1;
    y=temp2;
 }
}
int main(){
InitWindow(width,height,"Calculating Value of PI...");
if(m2>10000)
    SetTargetFPS(200);
else
    SetTargetFPS(60);

while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(BLACK);
DrawFPS(4,4);
update_position();
DrawLine(60,height*0.7,60,0,WHITE);
DrawLine(0,height*0.7,width,height*0.7,WHITE);

DrawRectangleRec(rect1,WHITE);
DrawRectangleRec(rect2,WHITE);
EndDrawing();
}
CloseWindow();
} 