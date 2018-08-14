# tictactoe
Taught myself come c++ and made this

### To Compile Without VS or XCode
1) clone the project
2) cd into the repository
3) run the command `g++ board.h board.cpp player.h player.cpp main.cpp -o tictactoe` (or use your favorite cpp compiler)
4) run the command `./tictactoe` to start a game.

#To Win on Any Board Size
You will be prompted to enter a board size, must be larger than 3.
A win is when an entire row, column or diagonal is filled with all the same character X or O
