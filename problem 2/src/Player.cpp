// Class definition for XO_Player class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include<iostream>
#include<random>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"

using namespace std;


Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move (int& y) {
    cout << "\nPlease enter your move y: ";
    cin >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

char Player::get_symbol() {
    return symbol;
}
