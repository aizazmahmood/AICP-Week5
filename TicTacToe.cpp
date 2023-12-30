// Tic Tac Toe game in c++
#include <iostream>
#include <vector>

using namespace std;

class TicTacToe{
    //Private members contain a vector array of characters
    //Current Player will be either X or O
    private:
       vector<vector<char>> board;
       char currentPlayer;
    public:
    //constructor to initialize the board
       TicTacToe(): board(3, vector<char>(3, ' ')), currentPlayer('X') {}

       //function to print the board
       void printBoard() const {
            for(const auto& row : board){
                for(char cell : row){
                    cout << cell << " ";
                }
            }
       }

       //function to check the winner
       bool checkWin() const {
        for(int i = 0; i < 3; ++i){
            if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
               (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
               }
            }
        
        if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
           (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
           }
           return false;
       }

       //function to check if the board is full or not
       bool isBoardFull() const {
        for (const auto& row : board){
            for(char cell : row){
                if(cell == ' ')
                return false;
            }
        }
        return true;
       }

       // function to make a move
       void makeMove(int row, int col){
           if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' '){
             board[row][col] = currentPlayer;
           } else {
              cout << "Invalid Move! Try Again!" << endl;
           }
       }

       // function to switch player
       void switchPlayer(){
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
       }

       //now the function for playing the game
       void playGame(){
        while(true){
            //first printing the current state of the board
            cout << "Current Board: " << endl;
            printBoard();

            //now getting the player's move
            int row,col;
            cout << "Player " << currentPlayer << ", Enter Your Move (Row & Column): ";
            cin >> row >> col;

            //now making the move
            makeMove(row,col);

            //checking if the current player has won
            if(checkWin()){
                cout << "Player " << currentPlayer << " Wins!" << endl;
                break;
            }

            //checking if the board is full
            if(isBoardFull()){
                cout << "It's a Tie!" << endl;
                break;
            }

            //switching to other player
            switchPlayer();
        }
       }
};

int main(){
    TicTacToe game;
    game.playGame();

    return 0;
}