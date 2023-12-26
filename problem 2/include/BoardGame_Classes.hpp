// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

using namespace std;

class Board {

protected:

   int no_of_rows, no_of_cols;
   char** board;
   int  no_of_moves = 0;

public:

   virtual bool update_board ( int y, char symbol) = 0;
   virtual bool is_winner() = 0;
   virtual bool is_draw() = 0;
   virtual void display_board() = 0;
   virtual bool game_is_over() = 0;
};


class Four_in_row:public Board {
public:
    Four_in_row();
   bool update_board (int y, char mark);
   void display_board();
   bool is_winner();
   bool is_draw();
   bool game_is_over();
};

class Player {

    protected:
        string name;
        char symbol;

    public:
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2

        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);

        // Virtual (can change for other player types)
        virtual void get_move(int& y);
        // Give player info as a string
        string to_string();
        char get_symbol();
};

class RandomPlayer: public Player{
    protected:

        int dimension;

    public:
        RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);
};

class GameManager {
    private:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager(Board*, Player* playerPtr[2]);
        void run();
};

