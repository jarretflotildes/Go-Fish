//File Name: card.cpp
//
////

#include <iostream>
#include <string>
#include <sstream>
#include "card.h"
using namespace std;  

// A standard deck of playing cards includes
// (A)ce 2 3 4 5 6 7 8 9 10 (J)ack (Q)ueen (K)ing

#define A 1
#define J 11
#define Q 12
#define K 13
  
    Card::Card(){          // default, ace of spades
        myRank = A;
        mySuit = spades;
     } 

    Card::Card(int rank, Suit s){
        myRank = rank;
        mySuit = s;
    } 

    // return string version e.g. Ac 4h Js
    string Card::toString() const{
/* 
       stringstream output;
       switch (myRank) { //ADD RANK
            case 1: output << "A";
                    break;
            case 11:output << "J";
                    break;
            case 12:output << "Q";
                    break;
            case 13:output << "K";
                    break;
            default:output << myRank;
       }
       
       output << mySuit;  //ADD SUIT
       string cardStr = output.str();
*/
       string cardStr = rankString(getRank()) + suitString(getSuit());

       return cardStr;

    }


    // true if suit same as c
    bool Card::sameSuitAs(const Card &c) const{
         return (mySuit == c.mySuit);  
    }

    // return rank, 1..13
    int Card::getRank() const{
        return myRank;
    }


    //return suit
    Card::Suit Card::getSuit() const{
        return mySuit;
    }


    // return "s", "h",...
    string Card::suitString(Suit s) const{
        
        stringstream output; 

        switch (s) {
            case spades: output << "s";
                    break;
            case hearts:output << "h";
                    break;
            case diamonds:output << "d";
                    break;
            case clubs:output << "c";
                    break;
            default:output << NULL;
                    break; 
        }

       string rankStr = output.str();
       return rankStr;
    }
    


    // return "A", "2", ..."Q"  
    string Card::rankString(int r)       const{

        stringstream output; 

        switch (r) {
            case 1: output << "A";
                    break;
            case 11:output << "J";
                    break;
            case 12:output << "Q";
                    break;
            case 13:output << "K";
                    break;
            default:output << myRank;
                    break; 
        }

       string rankStr = output.str();
       return rankStr;

    } 

    
    bool Card::operator == (const Card& rhs) const{

        return ((myRank == rhs.myRank) &&
                (mySuit == rhs.mySuit));
   
    }

    bool Card::operator != (const Card& rhs) const{
     
    }
    

    ostream& operator << (ostream& out, const Card& c){
      

    }
