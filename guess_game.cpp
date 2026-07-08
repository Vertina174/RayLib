#include<iostream>
#include<vector>
#include<random>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> random_number(1,100);
int guess=random_number(gen);
int guesses=7;
int start(){
    while(guesses>0){
        
    cout<<"Guess the Number: ";
    int num;
    cin>>num;
    
        if(num<guess){
            system("cls");
            cout<<"TOO LOW!!!\n";
            --guesses;

        }
        else if(num>guess){
            system("cls");
            cout<<"TOO HIGH!!!\n";
            --guesses;
        }
        else if(num==guess){
            system("cls");
            cout<<"CONGRATULATION, You have made the Correct Guess!!!\n";
            cout<<endl<<"Would Your Like to Play Again\n";
            cout<<endl<<"Yes[y]/No[n]\n";
            char c;
            cin>>c;
            if(c=='y'){
                return 1;
            }
            return 0;

        }

    }
    system("cls");
    cout<<"You have Exhausted the Number of guesses\n";
    cout<<"Yes[y]/No[n]\n";
    cout<<"Would You like to Play Again\n";
    char c;
            cin>>c;
            if(c=='y'){
                return 1;
            }
            return 0;
}
int main(){
system("cls");
cout<<"\nGuess a Number Between 1 to 100\n";
start();
return 0;
}