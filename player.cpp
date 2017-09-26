//
//  player.cpp
//  tictactoe
//
//  Created by Dominick Caponi on 9/24/17.
//  Copyright © 2017 Dominick Caponi. All rights reserved.
//

#include <string>
#include <iostream>
#include "player.h"

using namespace std;

Player::Player( std::string const& name, char const& token ){
    m_name = name;
    m_token = token;
};

void Player::setMove( int x, int y ){
    last_x = x;
	last_y = y;
	};

int* Player::getLastMove(){
    int* lastMove = new int[2];
    lastMove[0] = last_x;
    lastMove[1] = last_y;
    return lastMove;
};

char Player::getToken(){ return m_token; };

std::string Player::getName(){ return m_name; };
