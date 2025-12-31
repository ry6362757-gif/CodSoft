#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0));
    
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        int secretNumber = rand() % 100 + 1;
        int userGuess = 0;
        int attempts = 0;
        const int MAX_ATTEMPTS = 10;
        
        cout << "\n=== Number Guessing Game ===\n";
        cout << "I'm thinking of a number between 1 and 100.\n";
        cout << "You have " << MAX_ATTEMPTS << " attempts to guess it!\n\n";
        
        bool guessed = false;
        
        for (attempts = 1; attempts <= MAX_ATTEMPTS; attempts++) {
            cout << "Attempt " << attempts << "/" << MAX_ATTEMPTS << ": ";
            cout << "Enter your guess: ";
            
            // Input validation with better error handling
            while (!(cin >> userGuess) || userGuess < 1 || userGuess > 100) {
                if (cin.fail()) {
                    cout << "Invalid input! Please enter a number between 1 and 100: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    cout << "Please enter a number between 1 and 100: ";
                }
            }
            
            if (userGuess > secretNumber) {
                cout << "Too high! ";
            } 
            else if (userGuess < secretNumber) {
                cout << "Too low! ";
            } 
            else {
                guessed = true;
                break;
            }
            
            // Give a hint after a few attempts
            if (attempts == MAX_ATTEMPTS / 2) {
                if (secretNumber % 2 == 0) {
                    cout << "\nHint: The number is even.\n";
                } else {
                    cout << "\nHint: The number is odd.\n";
                }
            }
        }
        
        if (guessed) {
            cout << "\nExcellent! You guessed the number " << secretNumber;
            cout << " in " << attempts << " attempt";
            if (attempts != 1) cout << "s";
            cout << "!\n";
        } else {
            cout << "\nGame over! You've used all " << MAX_ATTEMPTS << " attempts.\n";
            cout << "The secret number was " << secretNumber << ".\n";
        }
        
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "\nThanks for playing! Goodbye!\n";
    return 0;
}
