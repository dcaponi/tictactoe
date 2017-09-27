//
//  player.h
//  tictactoe
//
//  Created by Dominick Caponi on 9/24/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include <string>

class Player{
    
    std::string m_name;
    char m_token;
    int last_x;
    int last_y;
    
    public:
        Player(char const& token);
        void set_move(int x, int y);
        int* get_last_move();
        char get_token();
        std::string get_name();
};

#endif /* player_h */
