//
//  main.cpp
//  hello_xcode
//
//  Created by Dominick Caponi on 9/23/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#include <iostream>

using namespace std;

void draw( char** board, int& size );
bool move( char** board, char& player, int& size, int& moves );
bool evaluateGame( char** board, int& size, int& moves, char& player, int& x, int& y );

int main(int argc, const char * argv[]) {
    
    //cout << "board address " << board << " " << &board[0] << endl;
    //cout << "value of first pointer (row array address) " << *board << " " << board[0] << " Same thing" << endl;
    //cout << "value of first entry " << **board << " " << *board[0] << endl;
    
    bool playAgain = true;
    
    while( playAgain ){
        int boardSize = 0;
        int moves = 0;
        bool gameOver = false;
        char player = 'X';
        
        cout << "Enter the size of board. Must be larger than 3: ";
        cin >> boardSize;
        cout << endl;
        
        if( cin.fail() || boardSize < 3 ){
            cout << "Invalid Input" << endl;
            return 1;
        }
        
        else{
            char* *board = new char*[boardSize];
            for( int i = 0; i < boardSize; i++ ){
                board[i] = new char[boardSize];
                for( int j = 0; j < boardSize; j++ ){
                    board[i][j] = ' ';
                }
            }
            
            draw ( board, boardSize );
            
            while( !gameOver ){
                gameOver = move( board, player, boardSize, moves );
                player = player == 'X' ? 'O' : 'X';
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

bool evaluateGame( char** board, int& size, int& moves, char& player, int& x, int& y ){
    bool gameOver = false;
    
    // Check Row
    for( int i = 0; i < size; i++ ){
        if( board[x][i] != player ){
            break;
        }
        if( i == size - 1){
            cout << player << " Wins!\n";
            gameOver = true;
        }
    }
    // Check Col
    for( int j = 0; j < size; j++ ){
        if( board[j][y] != player ){
            break;
        }
        if( j == size - 1){
            cout << player << " Wins!\n";
            gameOver = true;
        }
    }
    
    // Check /
    for( int j = size - 1; j >= 0; j -- ){
        if( board[(size - 1) - j][j] != player ){
            break;
        }
        if( j == 0 ){
            cout << player << " Wins!\n";
            gameOver = true;
        }
    }
    
    // Check "\"
    for( int i = 0; i < size; i++ ){
        if( board[i][i] != player ){
            break;
        }
        if( i == size - 1 ){
            cout << player << " Wins!\n";
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

bool move( char** board, char& player, int& size, int& moves ){
    bool turnOver = false;
    int maxEntry = size - 1;
    int x, y;
    
    cout << "Player " << player << ", put in (x, y) coords: ";
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
            board[x][y] = player;
            turnOver = true;
        }
    }
    moves++;
    draw( board, size );
    return evaluateGame( board, size, moves, player, x, y );
}
