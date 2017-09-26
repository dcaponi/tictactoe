//
//  board.cpp
//  tictactoe
//
//  Created by Dominick Caponi on 9/24/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//


#include "board.h"
#include "player.h"
#include <iostream>

Board::Board(){
	using namespace std;
	m_size = 0;
	
	while ( m_size < 3 ) {
		cout << "Enter the size of board. Must be larger than 3: ";
		cin >> m_size;
		m_size = cin.fail() ? 0 : m_size;
		cout << endl;
	}
	
    board = new char*[ m_size ];
    for( int i = 0; i < m_size; i++ ){
        board[i] = new char[ m_size ];
        for( int j = 0; j < m_size; j++ ){
            board[i][j] = ' ';
        }
    }
}

char Board::getCharacter( int x, int y ){
    return board[x][y];
}

int Board::getSize(){
    return m_size;
}

bool Board::update( Player* player ){
    int* move = player -> getLastMove();
    board[move[0]][move[1]] = player -> getToken();
    delete [] move;
	m_moves++;
    draw();
	return computeWinner( player );
}

bool Board::computeWinner( Player* currentPlayer ){
	using namespace std;
	
	bool gameOver = false;
	int x = currentPlayer -> getLastMove()[0];
	int y = currentPlayer -> getLastMove()[1];
	
	// Check Row
	for( int i = 0; i < m_size; i++ ){
		if( board[x][i] != currentPlayer -> getToken() ){
			break;
		}
		if( i == m_size - 1){
			cout << currentPlayer -> getName() << " Wins!\n";
			gameOver = true;
		}
	}
	// Check Col
	for( int j = 0; j < m_size; j++ ){
		if( board[j][y] != currentPlayer -> getToken() ){
			break;
		}
		if( j == m_size - 1){
			cout << currentPlayer -> getName() << " Wins!\n";
			gameOver = true;
		}
	}
	
	// Check /
	for( int j = m_size - 1; j >= 0; j -- ){
		if( board[(m_size - 1) - j][j] != currentPlayer -> getToken() ){
			break;
		}
		if( j == 0 ){
			cout << currentPlayer -> getName() << " Wins!\n";
			gameOver = true;
		}
	}
	
	// Check "\"
	for( int i = 0; i < m_size; i++ ){
		if( board[i][i] != currentPlayer -> getToken() ){
			break;
		}
		if( i == m_size - 1 ){
			cout << currentPlayer -> getName() << " Wins!\n";
			gameOver = true;
		}
	}
	
	// Check Tie
	if( m_moves == (m_size * m_size - 1) ){
		gameOver = true;
		cout << "Tie Game!" << endl;
	}
	return gameOver;
}

void Board::draw(){
    for( int i = 0; i < m_size; i++ ){
        for( int j = 0; j < m_size; j++ ){
            std::cout << " | " << board[i][j];
            if( j == m_size - 1 ){
                std::cout << " | " ;
            }
        }
        std::cout << "\n\n";
    }
}

void Board::destroyBoard(){
    for( int i = 0; i < m_size; i ++ ){
        delete [] board[i];
    }
    delete [] board;
}
