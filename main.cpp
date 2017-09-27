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

void take_turn(Board* board, Player* player);

int main() {
    
    //cout << "board address " << board << " " << &board[0] << endl;
    //cout << "value of first pointer (row array address) " << *board << " " << board[0] << " Same thing" << endl;
    //cout << "value of first entry " << **board << " " << *board[0] << endl;
    
    bool play_again = true;
	
    while(play_again){
        bool game_over = false;
		
		Board game_board;
		Player player1('X');
		Player player2('O');
		Player* current_player = &player1;
		
		cout << "Player " << player1.get_token() << ": " << player1.get_name() << endl;
		cout << "Player " << player2.get_token() << ": " << player2.get_name() << "\n" << endl;
		game_board.draw();
		
		// Main game loop
		while(!game_over)
		{
			take_turn(&game_board, current_player);
			game_over = game_board.update(current_player);
			current_player = current_player == &player1 ? &player2 : &player1;
		}
	
		game_board.destroy_board();
		
		char pa;
		cout << "Play again? y/n: ";
		cin >> pa;
		cout << (pa == 'y') << endl;
		play_again = pa == 'y';
    }
    return 0;
}



void take_turn(Board* board, Player* player)
{
    bool turn_over = false;
    int max_entry = board -> get_size() - 1;
    int x, y;
    
    cout << "Player " << player -> get_name() << ", put in (x, y) coords: ";
    cin >> x >> y;
    cout << endl;
	
	// Turn loop
    while(!turn_over)
	{
        if(x > max_entry || y > max_entry)
		{
            cout << "That choice is out of bounds, please try again: ";
            cin >> x >> y;
            cout << endl;
        }
        else if(board -> get_character(x, y) != ' ')
		{
            cout << "That spot is occupied, please try again: ";
            cin >> x >> y;
            cout << endl;
        }
        else
		{
            player -> set_move(x, y);
            turn_over = true;
        }
    }
}
