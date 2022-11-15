#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Player{
    string name;
    int position;
    public:
        explicit Player(){
            name = "JonyJhon";
            position = 0;
        };
        Player(string n){
            name = n;
            position = 0;
        };
        void setPosition(int p){
            position = p;

        };
        int getPosition(){
            return position;
        };
        int rollDice(){
            string Ans;
            cin>>Ans;
            /*while(Ans!="C" || Ans!="E" || Ans!="c"){                    //.
                cout<<"Invalid command : Try again"<<endl;              //
                cin>>Ans;                                               //.
            }*/

            if(Ans=="C"|| Ans=="c"){

            //get a random number from 1 to 6
                srand(time(0));
                int randNum = 1 + rand()%6;
                //cout << name << " got a " << randNum << endl;
                return randNum;
            }else if(Ans=="E" || position>=30 ||Ans=="e"){
                cout<<"Game ended...."<<endl;
                return 0;
            }    
        };
        string PP(){
            return name;
        }
        void printPlayerInfo(string playerNumber){

            cout <<playerNumber;
        };
};
