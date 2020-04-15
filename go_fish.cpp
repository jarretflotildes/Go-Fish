
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <ctime>

#include "card.h"
#include "player.h"
#include "deck.h"


using namespace std;

//prototypes

//deal cards 
void dealHand(Deck &d, Player &p, int numCards);

//draw card from deck
void draw(Deck &d, Player &p,ofstream &myfile);

//checks for matchs then books them 
void bookMatchs(Deck &d,Player &p,ofstream &myfile);

//main game of gofish
void mainGame(Deck &d,Player &p1,Player &p2,ofstream &myfile);


int main(){

    ofstream myfile;
    myfile.open("gofish_results.txt");
    
    int numCards = 7;

    Player p1("Joe");
    Player p2("Mama");

//player names
    cout << p1.getName() << " HAS ENTERED THE LOBBY." << endl;
    cout << p2.getName() << " HAS ENTERED THE LOBBY." << endl;

    myfile << p1.getName() << " HAS ENTERED THE LOBBY." << endl;
    myfile << p2.getName() << " HAS ENTERED THE LOBBY." << endl;

    myfile << endl << "Game Start" << endl << endl;

//shuffle deck and deal cards 
    myfile << "Dealing Cards..." << endl;  
 
    Deck d;  //create a deck of cards
    d.shuffle(); //shuffle em
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
//show starting hands
    cout << p1.getName() <<" Starting Hand: " << p1.showHand() << endl;
    cout << p2.getName() <<" Starting Hand: " << p2.showHand() << endl << endl;
    
    myfile << p1.getName() <<" Starting Hand : " << p1.showHand() << endl;
    myfile << p2.getName() <<" Starting Hand: " << p2.showHand() << endl << endl;
 
//check starting hands for matchs and book em if any
    for(int i = 0;i<(numCards/2);i++){ //check three times in case multiple matchs at start
       bookMatchs(d,p1,myfile);
       bookMatchs(d,p2,myfile);
    }

//show hands after initial dealing
    cout << endl << p1.getName() <<"'s Hand: " << p1.showHand() << endl;
    cout << p2.getName() <<"'s Hand: " << p2.showHand() << endl << endl;
    
    myfile << p1.getName() <<"'s Hand : " << p1.showHand() << endl;
    myfile << p2.getName() <<"'s Hand: " << p2.showHand() << endl << endl;

 //enter asking and turn phase
    mainGame(d,p1,p2,myfile);

//declare winner
   
    cout << endl;
    cout << p1.getName() << "'s Books: " << (p1.getBookSize())/2 << " " <<  p2.getName() << "'s Books: " << (p2.getBookSize())/2 << endl;

    myfile << endl;
    myfile << p1.getName() << "'s Books: " << (p1.getBookSize())/2 << " " <<  p2.getName() << "'s Books: " << (p2.getBookSize())/2 << endl;
    
    if(p1.getBookSize() > p2.getBookSize()){
       cout << p1.getName() << " wins!" << endl;
       myfile << p1.getName() << " wins!" << endl;


    } else if(p1.getBookSize() < p2.getBookSize()){
       cout << p2.getName() << " wins!" << endl;
       myfile << p2.getName() << " wins!" << endl;
    } else {
       cout << "It's a draw!" << endl;
       myfile << "It's a draw!" << endl;
    } 
  
    myfile.close();
    
    return EXIT_SUCCESS;  
}

void dealHand(Deck &d, Player &p, int numCards){
   for(int i=0; i < numCards; i++){
      p.addCard(d.dealCard());
   }
}

void draw(Deck &d, Player &p,ofstream &myfile){
       
      Card newCard = d.dealCard();
      p.addCard(newCard);
      cout << p.getName() << " draws " << newCard.toString() << endl << endl;
      myfile << p.getName() << " draws " << newCard.toString() << endl << endl;

}

/*
//random player goes first
int coinflip(){

   unsigned int currentTime = (unsigned) time(0);
   srand(currentTime); //seed rng
   int flip = rand() % 2;

   return flip;

}*/


//Function checks hand for matchs and books them to hand if any
void bookMatchs(Deck &d,Player &p,ofstream &myfile){

//Cards used to check for matchs
    Card match = Card();
    Card match2 = Card();
    
    bool matchStatus = p.checkHandForBook(match,match2);
 
    if(matchStatus == true) { //book em 

        p.bookCards(match,match2);

        p.removeCardFromHand(match);
        p.removeCardFromHand(match2); 

        cout << p.getName() << " books the " << match.toString() << " and the " << match2.toString() << endl;
        myfile << p.getName() << " books the " << match.toString() << " and the " << match2.toString() << endl; 

//cout << p.getName() << "'s Hand : " << p.showHand() << endl;
    
    } else { 
         //nothing
    } 
 
}

void mainGame(Deck &d,Player &p1,Player &p2,ofstream &myfile){
 //enter asking and turn phase

     int turn = 1; 
     int playerTurn = 1;  
   
     while((d.size() != 0) || ((p1.getHandSize() != 0) || (p2.getHandSize() != 0))) {
      
	bookMatchs(d,p1,myfile); 
	bookMatchs(d,p2,myfile);
	
	Card askCard;
	Card actualCard;

   //     cout << "Turn:" << turn << " Cards left in deck: " << d.size() << endl;
	cout << endl << p1.getName() <<"'s Hand: " << p1.showHand() << endl;
	cout << p2.getName() <<"'s Hand: " << p2.showHand() << endl << endl;

 //       myfile << "Turn:" << turn << " Cards left in deck: " << d.size() << endl;
	myfile << endl << p1.getName() <<"'s Hand: " << p1.showHand() << endl;
	myfile << p2.getName() <<"'s Hand: " << p2.showHand() << endl << endl;

	if((playerTurn == 1) && (p1.getHandSize() > 0)){ 
   
	   askCard = p1.chooseCardFromHand();
  
	   cout << p1.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl; 
	   myfile << p1.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl; 

	      if(p2.rankInHand(askCard) == true){ 
  
		 cout << p2.getName() << " says - Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;
		 myfile << p2.getName() << " says - Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;

		 actualCard = p2.card_rankInHand(askCard);  
	      
		 p2.removeCardFromHand(actualCard);            
		 p1.addCard(actualCard);

		 bookMatchs(d,p1,myfile);
		 turn++;
		 playerTurn = 1; 

	      } else {
		    cout << p2.getName() << " says - Go fish. " << endl;
		    myfile << p2.getName() << " says - Go fish. " << endl;

		    if(d.size() != 0){draw(d,p1,myfile);} //draw a card as long as deck is not empty

           	    bookMatchs(d,p1,myfile); 

		    turn++;
		    playerTurn = 2;
	     }
	} else if(playerTurn == 1) { 
	    cout << p1.getName() << " ran out of cards in hand!" << endl;
	    myfile << p1.getName() << " ran out of cards in hand!" << endl;

	    if(d.size() != 0){draw(d,p1,myfile);} //draw a card as long as deck is not empty

	    bookMatchs(d,p1,myfile); 

	    turn++;
	    playerTurn = 2;
	    myfile << endl;
	}
     

	if((playerTurn == 2) && (p2.getHandSize() > 0)){ 
   
	   askCard = p2.chooseCardFromHand();
  
	   cout << p2.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl; 
	   myfile << p2.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl; 

	      if(p1.rankInHand(askCard) == true){ 
  
		 cout << p1.getName() << " says - Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;
		 myfile << p1.getName() << " says - Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;

		 actualCard = p1.card_rankInHand(askCard);  
	      
		 p1.removeCardFromHand(actualCard);            
		 p2.addCard(actualCard);

		 bookMatchs(d,p2,myfile);
		 turn++;
		 playerTurn = 2; 

	      } else {
		    cout << p1.getName() << " says - Go fish. " << endl;
		    myfile << p1.getName() << " says - Go fish. " << endl;
		    if(d.size() != 0){draw(d,p2,myfile);} //draw a card as long as deck is not empty
	            bookMatchs(d,p2,myfile);
 		    turn++;
		    playerTurn = 1;
	     }
	} else if(playerTurn == 2) { 
	    cout << p2.getName() << " ran out of cards in hand!" << endl;
	    myfile << p2.getName() << " ran out of cards in hand!" << endl;
	    if(d.size() != 0){draw(d,p2,myfile);} //draw a card as long as deck is not empty
	    bookMatchs(d,p2,myfile);
            turn++;
	    playerTurn = 1;
	}
     } 
   } 
