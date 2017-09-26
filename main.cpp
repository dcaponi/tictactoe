//
//  main.cpp
//  hello_xcode
//
//  Created by Dominick Caponi on 9/23/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "board.h"

using namespace std;

void takeTurn( Board* board, Player* player );

int main() {
    
    //cout << "board address " << board << " " << &board[0] << endl;
    //cout << "value of first pointer (row array address) " << *board << " " << board[0] << " Same thing" << endl;
    //cout << "value of first entry " << **board << " " << *board[0] << endl;
    
    bool playAgain = true;
	
    while( playAgain ){
        bool gameOver = false;
		
		Player player1( 'X' );
		Player player2( 'O' );
		Player* currentPlayer = &player1;
		Board gameBoard;
		
		cout << "Player " << player1.getToken() << ": " << player1.getName() << endl;
		cout << "Player " << player2.getToken() << ": " << player2.getName() << "\n" << endl;
		
		gameBoard.draw();
		
		// Main game loop
		while( !gameOver ){
			takeTurn( &gameBoard, currentPlayer );
			gameOver = gameBoard.update( currentPlayer );
			currentPlayer = currentPlayer == &player1 ? &player2 : &player1;
		}
	
		gameBoard.destroyBoard();
		
		char pa;
		cout << "Play again? y/n: ";
		cin >> pa;
		cout << ( pa == 'y' ) << endl;
		playAgain = pa == 'y';
    }
    return 0;
}



void takeTurn( Board* board, Player* player ){
    bool turnOver = false;
    int maxEntry = board -> getSize() - 1;
    int x, y;
    
    cout << "Player " << player -> getName() << ", put in (x, y) coords: ";
    cin >> x >> y;
    cout << endl;
	
	// Turn loop
    while( !turnOver ){
        if( x > maxEntry || y > maxEntry ){
            cout << "That choice is out of bounds, please try again: ";
            cin >> x >> y;
            cout << endl;
        }
        else if( board -> getCharacter( x, y ) != ' ' ){
            cout << "That spot is occupied, please try again: ";
            cin >> x >> y;
            cout << endl;
        }
        else{
            player -> setMove( x, y );
            turnOver = true;
        }
    }
}
