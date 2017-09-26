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
bool evaluateGame( Board* board, int& moves, Player* player );

int main(int argc, const char * argv[]) {
    
    //cout << "board address " << board << " " << &board[0] << endl;
    //cout << "value of first pointer (row array address) " << *board << " " << board[0] << " Same thing" << endl;
    //cout << "value of first entry " << **board << " " << *board[0] << endl;
    
    bool playAgain = true;
    
    while( playAgain ){
        int boardSize = 0;
        string name;
        bool gameOver = false;
        Player* currentPlayer;
        Board* boardPtr;
        
        cout << "Enter the size of board or any non-integer to quit. Must be larger than 3: ";
        cin >> boardSize;
        cout << endl;
        
        if( cin.fail() || boardSize < 3 ){
            return 1;
        }
        
        else{
            cout << "Enter Player 1 Name: ";
            cin >> name;
            Player player1( name, 'X' );
            cout << "Enter Player 2 Name: ";
            cin >> name;
            Player player2( name, 'O' );
            cout << endl;
            cout << "Player 1: " << player1.getName() << endl;
            cout << "Player 2: " << player2.getName() << endl;
            
            currentPlayer = &player1;
            
            Board gameBoard( boardSize );
            boardPtr = &gameBoard;
            
            gameBoard.draw();
            
            while( !gameOver ){
                takeTurn( boardPtr, currentPlayer );
                gameBoard.update( currentPlayer );
                gameOver = gameBoard.computeWinner( currentPlayer );
                currentPlayer = currentPlayer == &player1 ? &player2 : &player1;
            }
        
            gameBoard.destroyBoard();
            
            char pa;
            cout << "Play again? y/n: ";
            cin >> pa;
            cout << ( pa == 'y' ) << endl;
            playAgain = pa == 'y';
        }
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
