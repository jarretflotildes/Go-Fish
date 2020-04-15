
#include <cstdlib>
#include <ctime>

#include "card.h"
#include "deck.h"

#define suitAmount 13 //number of cards in each suit

//size of deck 
//static const int SIZE = 52;
  

//private variables 
//Card myCards[SIZE];
//int myIndex;  // current card to deal
   
    Deck::Deck(){           // pristine, sorted deck

       int j = 0;
        
       for(int i = 0;i<suitAmount;i++){
          Card newCard = Card(i+1,Card::spades);
          myCards[j] = newCard;
          j++;

//cout << " count is " << j <<  endl;
       }


       for(int i = 0;i<suitAmount;i++){
          Card newCard = Card(i+1,Card::hearts);
          myCards[j] = newCard;
          j++;

//cout << " count is " << j <<  endl;
       } 


       for(int i = 0;i<suitAmount;i++){
          Card newCard = Card(i+1,Card::diamonds);
          myCards[j] = newCard;
          j++;

//cout << " count is " << j <<  endl;

       }
 


       for(int i = 0;i<suitAmount;i++){
          Card newCard = Card(i+1,Card::clubs);
          myCards[j] = newCard;
          j++;

//cout << " count is " << j <<  endl;
       }

       myIndex = 0; //assign index to 0 cards drawn  

    } 


    void Deck::shuffle(){   // shuffle the deck, all 52 cards present

          unsigned int currentTime = (unsigned) time(0);
          srand(currentTime); //seed rng
  
          int roll = 0;
          int roll2 = 0;
 
          //shuffle as many cards that are in the deck
          for(int i = 0;i < size(); i++){

              roll = rand() % SIZE;
              roll2 = rand() % SIZE;

              Card randCard1 = myCards[roll];
              Card randCard2 = myCards[roll2];

              myCards[roll] = randCard2;
              myCards[roll2] = randCard1;
            
          } 
          
    } 

    Card Deck::dealCard(){   // get a card, after 52 are dealt, fail 

        Card newCard = Card(); //default card

        if(size() == 0){
        //dealCard fail 
          return newCard;          
        } else {
            newCard = myCards[myIndex];
            myIndex = myIndex + 1;
            return newCard;
        } 
    }

    int Deck:: size() const{ // # cards left in the deck
        int deckSize = SIZE - myIndex;
        return deckSize; 
    }
