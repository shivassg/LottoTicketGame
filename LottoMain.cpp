

/* 
 * File:   LottoMain.cpp
 * Author: shiva
 * Created on September 21, 2018
 * Compiler Used: g++
 * Description of the file: Driver program of the assignment. It gets the file name,minimum number, max number
 * maximum number of rounds to be played from user. And creates LottoTicket class object and uses the function
 * to play the game.
 */

#include <iostream>
#include "LottoTicket.h"
#include <fstream>


using namespace std;

int main() {
    int num_of_players=5;
    LottoTicket players[5];
    int min=0;
    int max=0;
    int max_rounds=0;
    int winner=-1;
    bool gameover;
    string filename="output.txt";
    ofstream fout;
    srand(time(NULL));
    
    cout<<"Enter the output filename";
    cin>> filename;
    cout<<"Enter the minimum number";
    cin>>min;
    cout<<"Enter the maximum number";
    cin>>max;
    cout<<"Enter the number of rounds to be played:";
    cin>>max_rounds;
    fout.open(filename,ofstream::app);
    
    int i=0;
    
    while(i!=num_of_players){
        LottoTicket player1(i); //Initializing player numbers inside this constructor
        player1.generateLotto(min,max);
        players[i]=player1;
        i++;
    }
    
    cout<<"\nGenerating Lottos for all players....\n\n";
    fout<<"********************************************";
    fout<<"\nGenerating Lottos for all players.....\n\n";
    for(LottoTicket lotto: players){
        cout<<lotto;
        fout<<lotto;
    }
    
    i=0;
    cout<<"\n";
    cout<<"-----------------------------------------------";
    cout<<"\nGame is starting" <<endl;
    cout<<"Round# \tLotto\tP#0\tP#1\tP#2\tP#3\tP#4"<<endl;
    
    fout<<"\n";
    fout<<"------------------------------------------------";
    fout<<"\nGame is starting" <<endl;
    fout<<"Round# \tLotto\tP#0\tP#1\tP#2\tP#3\tP#4"<<endl;
    
    for(int j=0;j<max_rounds;j++){
        int current_lotto=generateRandom(min,max);
        
        cout<<j<<"\t"<<current_lotto<<"\t";
        fout<<j<<"\t"<<current_lotto<<"\t";
        for(LottoTicket &lotto: players){
            gameover=lotto.play(current_lotto);
            cout<<lotto.getLottosWonCount()<<"\t";
            fout<<lotto.getLottosWonCount()<<"\t";
            if(gameover){
                winner=lotto.getId();
                break;
            }
        }
        cout<<endl;
        fout<<endl;
        
        if(gameover){
            break;
        }
    }
        
        cout<<"-----------------------------------------------";
        cout<<"\nRESULT:\t";
        fout<<"-----------------------------------------------";
        fout<<"\n\tRESULT:\t";
        if(winner>=0){
            cout<<"Winner is: PLayer"<<winner<<endl;
            fout<<"Winner is: Player"<<winner<<endl;
        }else{
            cout<<"This game is a draw"<<endl;
            fout<<"This game is a draw"<<endl;
        }
        
    return 0;
}

