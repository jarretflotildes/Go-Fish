#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
  public:
    Player();

    Player(string name) {
       myName = name;
    }

    string getName() const {
       return myName;
    }
    
    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //OPTIONAL 
    //comment out if you decide to not use it
    //this function will check a players hand for a pair
    //if a pair is found,it returns true and populates the two variables with the same cards that make the pair
    
    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    //comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
     
    bool rankInHand(Card c) const;
  
    //returns card found when checking with Function rankInHand
    Card card_rankInHand(Card c) const; 


    //uses some strategy to choose one card from the hand
    //so they can say "Do you have a 4?
    Card chooseCardFromHand() const;

    bool cardInHand(Card c) const;

    //remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const; //return string of hand 
    string showBooks() const;
 
    int getHandSize() const;
    int getBookSize() const;
  
  private: 

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};

#endif
