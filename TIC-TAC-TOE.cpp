#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char> >& board) {
    cout << "\n";
    cout << "    1   2   3\n";
    cout << "  +---+---+---+\n";
    
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << " |\n";
        
        if (i < 2) {
            cout << "  +---+---+---+\n";
        }
    }
    cout << "  +---+---+---+\n\n";
}

// Function to initialize the game board
void initializeBoard(vector<vector<char> >& board) {
    board.clear();
    board.resize(3, vector<char>(3, ' '));
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<char> >& board, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
}
    
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get a valid move from the player
void getPlayerMove(const vector<vector<char> >& board, int& row, int& col, char player) {
    bool validInput = false;
    
    while (!validInput) {
        cout << "Player " << player << ", enter your move (row and column: 1-3): ";
        
        // Clear any previous errors and leftover input
        cin.clear();
        if (cin.peek() == '\n') cin.ignore();
        
        if (cin >> row >> col) {
            // Convert to 0-based indexing
            row--;
            col--;
            
            if (isValidMove(board, row, col)) {
                validInput = true;
            } else {
                if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                    cout << "Invalid input. Row and column must be between 1 and 3.\n";
                } else {
                    cout << "That cell is already occupied. Please choose an empty cell.\n";
                }
            }
        } else {
            cout << "Invalid input. Please enter two numbers between 1 and 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // Clear the newline after reading row and col
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get play again choice with validation
bool getPlayAgainChoice() {
    char choice;
    
    // Clear any leftover input first
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (true) {
        cout << "\nDo you want to play again? (y/n): ";
        
        if (cin.get(choice)) {
            // Clear the rest of the line including newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (choice == 'y' || choice == 'Y') {
                return true;
            } else if (choice == 'n' || choice == 'N') {
                return false;
            } else {
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


// Main game function
void playGame() {
    vector<vector<char> > board;
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    
    initializeBoard(board);
    cout << "****************************************\n";
    cout << "        WELCOME TO TIC-TAC-TOE!\n";
    cout << "****************************************\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n";
    cout << "****************************************\n";
    
    // Game loop...
    while (!gameWon && !gameDraw) {
        displayBoard(board);
        cout << "Current turn: Player " << currentPlayer << "\n";
        
        int row, col;
        getPlayerMove(board, row, col, currentPlayer);
        
        // Update board...
        board[row][col] = currentPlayer;
        
        // Check for win...
        gameWon = checkWin(board, currentPlayer);
        
        if (gameWon) {
            displayBoard(board);
            cout << "========================================\n";
            cout << "  Congratulations! Player " << currentPlayer << " wins!\n";
            cout << "========================================\n";
        } else if (checkDraw(board)) {
            gameDraw = true;
            displayBoard(board);
            cout << "========================================\n";
            cout << "          It's a draw!\n";
            cout << "========================================\n";
        } else {
            // Switch players...
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    bool playAgain = true;
    
    do {
        playGame();
        playAgain = getPlayAgainChoice();
        
    } while (playAgain);
    
    cout << "\n*****************************************\n";
    cout << "     Thank you for playing Tic-Tac-Toe!\n";
    cout << "****************************************\n";
    
    return 0;
}

