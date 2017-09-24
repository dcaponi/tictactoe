//
//  player.cpp
//  tictactoe
//
//  Created by Dominick Caponi on 9/24/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "player.h"

Player::Player( std::string const& name, char const& token ){
    m_name = name;
    m_token = token;
};

void Player::setMove( int x, int y ){
    last_x = x;
    last_y = y;
};

int* Player::getLastMove(){ return new int[2]; };

char Player::getToken(){ return m_token; };

std::string Player::getName(){ return m_name; };
