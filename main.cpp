#include <iostream>
#include <string>
#include <time.h>
#include "MyGame.h"
#include "Player.h"
//Carlos Alberto Mendoza Medina  
//Jonathan Josué Fuentes Ramírez


using namespace std;

int main(){
    MyGame g;
    g.start();
    g.printBoard();
    //Testing player...
    Player player1;
    Player player2("Carl");

    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Player 1 starts"<<endl;
    cout<<"Press C to continue next turn, or E to end the game"<<endl;
    int fin;
    fin=1;
    int Cont1 =0;
    int Cont2=0;
    
    while(fin >= 0 || (Cont1<30 && Cont2<30)){
        cout<<"------Turn: "<<fin<<"------"<<endl;
        //Mimic player 1 turn (needs re-factoring...)
        int player1res = player1.rollDice();
        if (player1res==0|| player1.getPosition()>=30|| player2.getPosition()>=30){
            break;
        }else if(player1res!=0){
            int variable1=player1.getPosition();
            if(g.board[player1.getPosition() + player1res] == 'L'){
                if(g.board[player1.getPosition() + player1res+2] == 'L'){
                    int end = player1.getPosition() + player1res + 4;
                    player1.setPosition(end);
                }
                
            }else if(g.board[player1.getPosition() + player1res] == 'S'){
                if(g.board[player1.getPosition() + player1res-2] == 'S'){
                    int end = player1.getPosition() + player1res - 4;
                    player1.setPosition(end);
                }

            }else{
                int end = player1.getPosition() + player1res;
                player1.setPosition(end);
            }
            cout<<"Turno: "<<fin<<"  Numero de jugador: ";
            player1.printPlayerInfo(" 1 ");
            cout<<" Posicion original: "<<variable1<<" Dado: ";
            cout<<player1res<<" Tipo de casilla: ";
            cout<<g.board[player1.getPosition()]<<" Casilla final: ";
            Cont1=player1.getPosition();
            cout<<Cont1<<endl;
            //player 2...
            
            int player2res = player2.rollDice();
            if (player2res==0 || player2.getPosition()>=30|| player1.getPosition()>=30){
                break;
            }else if(player2res!=0){
                int variable2=player2.getPosition();
                if(g.board[player2.getPosition() + player2res] == 'L'){
                    if(g.board[player2.getPosition() + player2res +2 ] == 'L'){
                        int end = player2.getPosition() + player2res + 4;
                        player2.setPosition(end);
                    }
                    
                }else if(g.board[player2.getPosition() + player2res] == 'S'){
                    if(g.board[player2.getPosition() + player2res] == 'S'){
                        int end = player2.getPosition() + player2res - 2;
                        player2.setPosition(end);
                    }

                }else{
                    int end = player2.getPosition() + player2res;
                    player2.setPosition(end);
                }
                cout<<"Turno: "<<fin<<"  Numero de jugador: ";
                player2.printPlayerInfo(" 2 ");
                cout<<" Posicion original: "<<variable2<<" Dado: ";
                cout<<player2res<<" Tipo de casilla: ";
                cout<<g.board[player2.getPosition()]<<" Casilla final: ";
                Cont2=player2.getPosition();
                cout<<Cont2<<endl;
                fin+=1;            
            }

        }

    }
    if(Cont1>=30){
        cout<<"And the Winner is....."<<player1.PP()<<" !!"<<endl;
        return 0;
    }else if(Cont2>=30){
        cout<<"And the Winner is....."<<player2.PP()<<" !!"<<endl;
        return 0;
    }
}
