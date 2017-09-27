//
//  board.h
//  tictactoe
//
//  Created by Dominick Caponi on 9/24/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#ifndef board_h
#define board_h

#include <stdio.h>
#include <string>
#include "player.h"

class Board{
    int m_size;
    int m_moves;
    char* *board;
	bool compute_winner(Player* current_player);
    
    public:
        Board();
		~Board();
        char get_character(int x, int y);
        int  get_size();
        void draw();
        bool update(Player* player);
        void destroy_board();
};

#endif /* board_h */
