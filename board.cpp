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

Board::Board()
{
	using namespace std;
	m_size = 0;
	
	while (m_size < 3)
	{
		cout << "Enter the size of board. Must be larger than 3: ";
		cin >> m_size;
		m_size = cin.fail() ? 0 : m_size;
		cout << endl;
	}
	
    board = new char*[m_size];
    for(int i = 0; i < m_size; i++)
	{
        board[i] = new char[m_size];
        for(int j = 0; j < m_size; j++)
		{
            board[i][j] = ' ';
        }
    }
}

char Board::get_character(int x, int y)
{
    return board[x][y];
}

int Board::get_size()
{
    return m_size;
}

bool Board::update(Player* player)
{
    int* move = player -> get_last_move();
    board[move[0]][move[1]] = player -> get_token();
    delete [] move;
	m_moves++;
    draw();
	return compute_winner(player);
}

bool Board::compute_winner(Player* current_player)
{
	using namespace std;
	
	bool game_over = false;
	int x = current_player -> get_last_move()[0];
	int y = current_player -> get_last_move()[1];
	
	// Check Row
	for(int i = 0; i < m_size; i++)
	{
		if(board[x][i] != current_player -> get_token())
		{
			break;
		}
		if(i == m_size - 1)
		{
			cout << current_player -> get_name() << " Wins!\n";
			game_over = true;
		}
	}
	// Check Col
	for(int j = 0; j < m_size; j++)
	{
		if(board[j][y] != current_player -> get_token())
		{
			break;
		}
		if( j == m_size - 1)
		{
			cout << current_player -> get_name() << " Wins!\n";
			game_over = true;
		}
	}
	
	// Check /
	for(int j = m_size - 1; j >= 0; j --)
	{
		if(board[(m_size - 1) - j][j] != current_player -> get_token())
		{
			break;
		}
		if(j == 0)
		{
			cout << current_player -> get_name() << " Wins!\n";
			game_over = true;
		}
	}
	
	// Check "\"
	for(int i = 0; i < m_size; i++)
	{
		if(board[i][i] != current_player -> get_token())
		{
			break;
		}
		if(i == m_size - 1)
		{
			cout << current_player -> get_name() << " Wins!\n";
			game_over = true;
		}
	}
	
	// Check Tie
	if(m_moves == (m_size * m_size - 1))
	{
		game_over = true;
		cout << "Tie Game!" << endl;
	}
	return game_over;
}

void Board::draw()
{
    for(int i = 0; i < m_size; i++)
	{
        for(int j = 0; j < m_size; j++)
		{
            std::cout << " | " << board[i][j];
            if(j == m_size - 1)
			{
                std::cout << " | " ;
            }
        }
        std::cout << "\n\n";
    }
}

Board::~Board()
{
    for(int i = 0; i < m_size; i ++)
	{
        delete [] board[i];
    }
    delete [] board;
}
