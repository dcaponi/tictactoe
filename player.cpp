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

Player::Player(char const& token)
{
	m_token = token;
	cout << "Enter Player " << m_token << "'s Name: ";
	cin >> m_name;
};

void Player::set_move(int x, int y)
{
	last_x = x;
	last_y = y;
};

int* Player::get_last_move()
{
    static int last_move[2];
    last_move[0] = last_x;
    last_move[1] = last_y;
    return last_move;
};

char Player::get_token(){ return m_token; };

std::string Player::get_name(){ return m_name; };
