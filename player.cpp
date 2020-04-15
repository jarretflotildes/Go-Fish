#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime> 
#include <cstdlib>

#include "card.h"
#include "player.h"
using namespace std;

    //a default player
    Player::Player(){
       myName = "Player";
      
    }

//    Player::Player(string name) {
  //     myName = name;
  //  }
/*
    string Player::getName() const {
    //   return myName;
    }
  */  
    
    void Player::addCard(Card c){  //adds a card to the hand
      myHand.push_back(c);
    }



    void Player::bookCards(Card c1, Card c2){
      
       myBook.push_back(c1);
       myBook.push_back(c2);


    }

    //OPTIONAL 
    //comment out if you decide to not use it
    //this function will check a players hand for a pair
    //if a pair is found,it returns true and populates the two variables with the same cards that make the pair
    
    bool Player::checkHandForBook(Card &c1, Card &c2){
   
       for(vector <Card>::iterator it = myHand.begin(); it != myHand.end();it++){
          for(vector <Card>::iterator it2 = myHand.begin(); it2 !=myHand.end();it2++){

              if((it->getRank() == it2->getRank()) && !(it->sameSuitAs(*it2))){
                  c1 = *it;
                  c2 = *it2;
                  return true;
              }
          } 

       }        

       return false;
     
    }


    //OPTIONAL
    //comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
     
     bool Player::rankInHand(Card c) const{

       for(int i = 0;i<getHandSize();i++){

          Card myCard = myHand[i];
         
          if(c.getRank() == myCard.getRank()){
             return true;
          }
       }

       return false;

    }

     //returns card of rankInHand
     Card Player::card_rankInHand(Card c) const{

       Card myCard;

       for(int i = 0;i<getHandSize();i++){

          myCard = myHand[i];
         
          if(c.getRank() == myCard.getRank()){
             return myHand[i];
          }
       }

       return myCard;

    }

   

    //uses some strategy to choose one card from the hand
    //so they can say "Do you have a 4?
    //return card want to say
    Card Player::chooseCardFromHand() const{

       Card calledCard = Card();

       unsigned int currentTime = (unsigned) time(0);
       srand(currentTime); //seed rng

       if(getHandSize() == 0){ //zero hand size means cant call anything
          return calledCard; 
       }  

       int roll = rand() % getHandSize(); //chooses random card's rank in hand to declare
       calledCard = myHand[roll];
 
       return calledCard;    

    }


    //does the player have the card c in hand??
    bool Player::cardInHand(Card c) const{

       for(int i = 0;i<getHandSize();i++){

          Card myCard = myHand[i];
         
          if(c == myCard){
             return true;
          }
       }

       return false;

    }



    //remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){

        Card calledCard = Card(1,Card::spades);

        for(vector <Card>::iterator it = myHand.begin(); it != myHand.end();it++){

           if(*it == c){
              calledCard = *it; 

              myHand.erase(it);
              return calledCard;
           }

        }

               
    }

    string Player::showHand() const{ //return string of hand 
   
        stringstream output;

        for(int i = 0; i<getHandSize();i++){
           output << myHand[i].toString() << " ";
        }
     
        string hand = output.str(); 

        return hand;

    }
   
  
    string Player::showBooks() const{

        stringstream output;

        for(int i = 0; i<getBookSize();i++){
           output << myBook[i].toString() << " ";
        }
     
        string hand = output.str(); 

        return hand;


    }

    int Player::getHandSize() const{
        return myHand.size();
    }


    int Player::getBookSize() const{
        return myBook.size();
    }

