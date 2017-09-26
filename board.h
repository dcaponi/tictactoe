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
	bool computeWinner( Player* currentPlayer );
    
    public:
        Board();
        char getCharacter( int x, int y );
        int  getSize();
        void draw();
        bool update( Player* player );
        void destroyBoard();
};

#endif /* board_h */
