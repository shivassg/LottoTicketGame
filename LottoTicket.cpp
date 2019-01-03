/* 
 * File:   LottoTicket.cpp
 * Author: Shiva Shankar Ganesan
 * Created on September 21, 2018
 * Compiler Used: g++
 * Description of the file: Definition of the functions is given in this file
 */


#include "LottoTicket.h"
#include <string>

void LottoTicket::generateLotto(int min, int max) {
//Generate 15 random numbers between the user given range
    for(int i=0;i<15;i++){
       tickets[i] = generateRandom(min,max);
    }
}


bool LottoTicket::play(int randomNumber){
    //Each player has 15 slots. play function input gets one random number. Need to check if this random number is there in the lotto ticket
    //Iterating the array to check if the random number is present.
    //If it is already striken out, we should ignore it and not count it. For this purpose we use the tempArray. Once we strike the number, in temp array we make it as true
    for(int i=0;i<15;i++){
        if(tickets[i]==randomNumber && tempArray[i]==false){
            tempArray[i]=true;
            wonCount=wonCount+1;
            break;
        }
    }
    if(wonCount==15){
        return 1;
    }
    return 0;
}

int LottoTicket::getLottosWonCount(){
    return wonCount;
}

int LottoTicket::getId(){
    return playerNumber;
}


std::ostream & operator<<(std::ostream & out, const LottoTicket &t){
    
    out<<"Player#"<<t.getPlayerNumber()<<":";
    for(int values: t.tickets){
        out<<" "<<values;
    }
    out<<"\n";
    return out;
}