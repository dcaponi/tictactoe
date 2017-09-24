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
    int size;
    int moves;
    
    public:
        Board( int size );
        void print();
        void update( Player::Player* player );
        Player* reportWinner();
    
};

#endif /* board_h */
