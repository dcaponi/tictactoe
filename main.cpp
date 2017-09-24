//
//  main.cpp
//  hello_xcode
//
//  Created by Dominick Caponi on 9/23/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#include <iostream>
#include "player.h"

using namespace std;

void draw( char** board, int& size );
void initializePlayers();
bool move( char** board, Player* player, int& size, int& moves );
bool evaluateGame( char** board, int& size, int& moves, Player* player, int& x, int& y );

int main(int argc, const char * argv[]) {
    
    //cout << "board address " << board << " " << &board[0] << endl;
    //cout << "value of first pointer (row array address) " << *board << " " << board[0] << " Same thing" << endl;
    //cout << "value of first entry " << **board << " " << *board[0] << endl;
    
    bool playAgain = true;
    
    while( playAgain ){
        int boardSize = 0;
        int moves = 0;
        string name;
        bool gameOver = false;
        Player* currentPlayer;
        
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
            
            char* *board = new char*[boardSize];
            for( int i = 0; i < boardSize; i++ ){
                board[i] = new char[boardSize];
                for( int j = 0; j < boardSize; j++ ){
                    board[i][j] = ' ';
                }
            }
            
            draw ( board, boardSize );
            
            while( !gameOver ){
                gameOver = move( board, currentPlayer, boardSize, moves );
                currentPlayer = currentPlayer == &player1 ? &player2 : &player1;
            }
        
            for( int i = 0; i < boardSize; i ++ ){
                delete [] board[i];
            }
            delete [] board;
            
            char pa;
            cout << "Play again? y/n: ";
            cin >> pa;
            cout << ( pa == 'y' ) << endl;
            playAgain = pa == 'y';
        }
    }
    return 0;
}

void initialziePlayers(){
    
}

bool evaluateGame( char** board, int& size, int& moves, Player* player, int& x, int& y ){
    bool gameOver = false;
    
    // Check Row
    for( int i = 0; i < size; i++ ){
        if( board[x][i] != player -> getToken() ){
            break;
        }
        if( i == size - 1){
            cout << player -> getName() << " Wins!\n";
            gameOver = true;
        }
    }
    // Check Col
    for( int j = 0; j < size; j++ ){
        if( board[j][y] != player -> getToken() ){
            break;
        }
        if( j == size - 1){
            cout << player -> getName() << " Wins!\n";
            gameOver = true;
        }
    }
    
    // Check /
    for( int j = size - 1; j >= 0; j -- ){
        if( board[(size - 1) - j][j] != player -> getToken() ){
            break;
        }
        if( j == 0 ){
            cout << player -> getName() << " Wins!\n";
            gameOver = true;
        }
    }
    
    // Check "\"
    for( int i = 0; i < size; i++ ){
        if( board[i][i] != player -> getToken() ){
            break;
        }
        if( i == size - 1 ){
            cout << player -> getName() << " Wins!\n";
            gameOver = true;
        }
    }
    
    // Check Tie
    if( moves == (size*size - 1) ){
        gameOver = true;
        cout << "Tie Game!" << endl;
    }
    return gameOver;
}

void draw( char** board, int& size ){
    for( int i = 0; i < size; i++ ){
        for( int j = 0; j < size; j++ ){
            cout << " | " << board[i][j];
            if( j == size - 1 ){
                cout << " | " ;
            }
        }
        cout << "\n\n";
    }
}

bool move( char** board, Player* player, int& size, int& moves ){
    bool turnOver = false;
    int maxEntry = size - 1;
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
        else if( board[x][y] != ' ' ){
            cout << "That spot is occupied, please try again: ";
            cin >> x >> y;
            cout << endl;
        }
        else{
            board[x][y] = player -> getToken();
            turnOver = true;
        }
    }
    moves++;
    draw( board, size );
    return evaluateGame( board, size, moves, player, x, y );
}
