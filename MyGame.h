#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class MyGame{
    
    void startNewGame(){
        //Create the board:
        for(int i = 0; i < sizeof(board); i++){
            board[i] = 'N';
        };
        // LADDER
        //Get a random number from 0 to 31:
        srand(time(0));
        int randium;
        int ladderIndex;
        for(int x=0;x<=4;x++){
            randium= (rand() % 31);
            if(randium>0){
                ladderIndex =randium ;
                board[ladderIndex] = 'L'; 
                //SNAKE
                int snakeIndex = ladderIndex;
                while(snakeIndex == ladderIndex ||
                    snakeIndex == 0 ||
                    snakeIndex == 1 ||
                    snakeIndex == ladderIndex + 2
                    ){
                    //generate another snake index:
                    snakeIndex = 2 + rand()%30;
                };
                board[snakeIndex] = 'S';
            }

        }
 
    };
    public:
        char board[31];
        void printBoard(){
            for(int i = 0; i < sizeof(board); i++){
                char tempBox = board[i];
                cout << tempBox << "  | ";
            };
            cout << endl;
            for(int i = 0; i < sizeof(board); i++){
                if(i<10){
                    cout << i << "  | "; 
                }else{
                    cout << i << " | ";
                };
                
            };
            cout << endl;
        };
        void start(){
            //TODO: start new game logic...
            // ['N','N','N','L','N','S','N','N']
            // [ 0,  1,  2,  3,  4,  5,  6,  7]
            startNewGame();
            cout << "Game Started" << endl;
        };
};
