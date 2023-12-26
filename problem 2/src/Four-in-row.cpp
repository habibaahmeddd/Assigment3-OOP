// File name:A3_Task2_3_s21_20220105
// Purpose: Game 2 in task 3
// Author(s): Habiba Amr Abdelfattah
// ID(s): 20220105
// Section: s21
// Date: 17/12/2023

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"

using namespace std;

// Set the board
Four_in_row::Four_in_row () {
    no_of_rows = 6,no_of_cols = 7;
    board = new char*[no_of_rows];
    for (int i = 0; i < no_of_rows; i++) {
        board [i] = new char[no_of_cols];
        for (int j = 0; j < no_of_cols; j++)
            board[i][j] = 0;
    }
}

void Four_in_row::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool Four_in_row::update_board (int y, char mark){
    // Only update if move is valid
    int cnt = 5; //as x
    if (!( y < 0 || y > 6)){
        if (board[cnt][y] == 0){
            board[cnt][y] = toupper(mark);
            no_of_moves++;
            return true;
        }
        else{
            while (board[cnt][y] && cnt > 0){
                cnt--;
            }
            board[cnt][y] = toupper(mark);
            no_of_moves++;
            return true;
        }
    }
}

bool Four_in_row::is_winner(){
    char by_row,by_col,d1,d2;
    for (int i=5;i>=0;i--) {
        for(int j=0;j<4;j++) {
            by_row = board[i][j] & board[i][j + 1] & board[i][j + 2] & board[i][j + 3];
            if (by_row and by_row == board[i][j] )
                return true;
        }
    }

    for (int j=0;j<7;j++) {
        for(int i=0;i<3;i++)
        {
            by_col = board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j];
            if (by_col and by_col == board[i][j] )
                return true;

        }
    }
    for (int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
        {
            d1 = board[i][j] & board[i+1][j+1] & board[i+2][j+2] & board[i+3][j+3];
            if (d1 and d1 == board[i][j])
                return true;
        }
    }
    for (int i=5;i>=3;i--) {
        for(int j=0;j<4;j++)
        {
            d2 = board[i][j] & board[i-1][j+1] & board[i-2][j+2] & board[i-3][j+3];
            if (d2 and d2 == board[i][j] )
                return true;
        }
    }

    return false;
}

// Return true if 42 moves are done and no winner
bool Four_in_row::is_draw() {
    return (no_of_moves == 42 && !is_winner());
}

bool Four_in_row::game_is_over () {
    return no_of_moves >= 42;
}
