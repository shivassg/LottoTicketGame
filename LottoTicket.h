
/* 
 * File:   LottoTicket.h
 * Author: Shiva Shankar Ganesan
 * Date September 21, 2018
 * Compiler Used: g++
 * Descrption of the file: Class and function declaration are given in the file
 */

#ifndef LOTTOTICKET_H
#define LOTTOTICKET_H

#include <iostream>

class LottoTicket{
    
private:
    
    int tickets[15];
    int playerNumber;
    int wonCount=0;
    bool tempArray[15];
    
public:
    
    /*default constructor Initializing the temp array values to False. This tempArray is used in comparison with the tickets array
     * in LottoTicket.cpp 
     */
    LottoTicket(){ 
         for(int i=0;i<15;i++){
             tempArray[i]=false;
         }
     } 
    
    LottoTicket(int i){ //Initializing the player number while creating the object in LottoMain.cpp
        playerNumber=i;
    }
    void generateLotto(int min,int max);
    
    int getLottosWonCount();
    
    bool play(int a);
    
    int getId();
    
    int getPlayerNumber() const{
        return playerNumber;
    }
     
    friend std::ostream & operator << (std::ostream &out, const LottoTicket &l);
    
};

/*Since the LottoMain.cpp(driver code) uses the generateRandom function without the LottoTicket object, made this static inline function
 */
static inline int generateRandom(int min,int max){
    return rand()%(max-min + 1) + min;
}



#endif /* LOTTOTICKET_H */

 