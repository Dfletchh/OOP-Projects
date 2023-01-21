/* 
* Auhtor: CP4 Group 7 (Dean Fletcher)
* Purpose: This program defines a traditional Tic Tac Toe game. The 
*          game pieces are placed by the user and are checked for 
*          validity by the program. A player a can win by getting a 
*          3 of the same pieces in a vertical, horizontal, or diagonal line. 
*/

#include <iostream>
#include <array>
#include <string>
#include <limits>

using namespace std;

// Functions for getting valid input from the user
void discard_remaining_chars();
void handle_invalid_number();
bool check_range(double num, double min, double max);
int get_int(string prompt, int min, int max);

// Game play functions 
void check_board(array<array<char, 3>, 3> &grid, bool &end, char move); 
void draw(array<array<char, 3>, 3> &grid);
void move (array<array<char, 3>, 3> &grid, int x, int y, char move);

int main()
{
    int row, column;
    int turn = 1;
    char player;
    bool gameOver = false;
    array<array<char, 3>, 3> board_grid {{
        {' ',' ',' '}, 
        {' ',' ',' '}, 
        {' ',' ',' '}
        }};

    cout << "Welcome to Tic Tac Toe\n";
    draw(board_grid); // function will output board to console

    while (!gameOver) {
        if (turn%2 == 0) { // current players turn
            player = 'O';
        } else
            player = 'X';

        move(board_grid, row, column, player); // function places game piece on board
        turn++;           // increment turn counter
        draw(board_grid); // output board to console
        check_board(board_grid, gameOver, player); // function checks if game was won
                                                   // appropriately sets gameOver flag 
        if (turn > 9 && !gameOver) // test if the board is full
        {
            cout << "\nTie Game!\n" << endl;
            return 0;
        }
    }
    cout << "\nGame over!\n" << endl;
    return 0;
}

// function draws the game board
void draw(array<array<char, 3>, 3> &grid)
{ 
    cout << "\n+---+---+---+\n";
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++) 
        {
            cout << "| " << grid[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "+---+---+---+\n";
    }
}
// function checks all posssible ways to win
void check_board(array<array<char, 3>, 3> &grid, bool &end, char move) 
{
    for (int i = 0; i < grid.size(); i++)
    {
        // horizontal and vertical tests
        if ((grid[i][0] == move && grid[i][1] == move && grid[i][2] == move)
              || (grid[0][i] == move && grid[1][i] == move && grid[2][i] == move))
              {
                  cout << "\n" << move << " wins!" << endl;
                  end = true;
                  break;
              }
    }
    if (!end) // Diagonal test
        if ((grid[0][0] == move && grid[1][1] == move && grid[2][2] == move)
            || (grid[0][2] == move && grid[1][1] == move && grid[2][0] == move))
        {
            cout << "\n" << move << " wins!" << endl;
            end = true;
        }
}
// Gets the plays move and places in the grid if valid
void move (array<array<char, 3>, 3> &grid, int x, int y, char move)
{
    const int min = 1;
    const int max = 3;

    cout << "\n" << move << "'s turn" << endl;
    x = get_int("Pick a row (1, 2, 3): ", min, max); // input validation function call
    y = get_int("Pick a column (1, 2, 3): ", min, max);

    while (grid[x-1][y-1] == 'X' || grid[x-1][y-1] == 'O') // Position taken test loop
    {     
        cout << "\nPosition taken try again!" << endl;
        x = get_int("Pick a row (1, 2, 3): ", min, max);
        y = get_int("Pick a column (1, 2, 3): ", min, max);
    }
    grid[x-1][y-1] = move; // place game piece 
}   
// input validation function
int get_int(string prompt, int min, int max)
{
    int num = 0;
    bool is_valid = false;
    while (!is_valid) {
        cout << prompt;
        if (!(cin >> num)) {
            handle_invalid_number();
        } else {
            discard_remaining_chars();
            is_valid = check_range(num, min, max);
        }
    }
    return num;
}
// define helper functions
void discard_remaining_chars()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handle_invalid_number()
{
    cout << "\nError! Invalid number. Try again.\n";
    cin.clear(); // clear the failure flag
    discard_remaining_chars();
}

bool check_range(double num, double min, double max)
{
    if (num < min) {
        cout << "\nError! Number must be greater than "
                    << min << ". Try again.\n";
        return false;
    }
    else if (num > max) {
        cout << "\nError! Number must be less than "
                    << max << ". Try again.\n";
        return false;
    } else
        return true;
}