#include <iostream>
#include <iomanip>  

void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
bool isValidChoice(char choice);

int main() {
    double num1, num2, result;
    char operation;
    char continueCalculation;
    
    std::cout << "***********************\n";
    std::cout << "   BASIC CALCULATOR\n";
    std::cout << "***********************\n\n";
    
    do {
        // Taking the first number. 
        std::cout << "Enter first number: ";
        while (!(std::cin >> num1)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        
        // Taking the second number.
        std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        
        displayMenu();  // Display operation menu
        
        std::cout << "Choose operation (+, -, *, /): ";  // Get operation choice
        std::cin >> operation;
        
        // Validate operation choice
        while (!isValidChoice(operation)) {
            std::cout << "Invalid operation. Please choose from +, -, *, /: ";
            std::cin >> operation;
        }
        
        // Performing the calculation based on user's choice..........
        switch (operation) {
            case '+':
                result = add(num1, num2);
                std::cout << "\nResult: " << num1 << " + " << num2 << " = " << result << std::endl;
                break;
                
            case '-':
                result = subtract(num1, num2);
                std::cout << "\nResult: " << num1 << " - " << num2 << " = " << result << std::endl;
                break;
                
            case '*':
                result = multiply(num1, num2);
                std::cout << "\nResult: " << num1 << " * " << num2 << " = " << result << std::endl;
                break;
                
            case '/':
                if (num2 == 0) {
                    std::cout << "\nError: Division by zero is not allowed!" << std::endl;
                } else {
                    result = divide(num1, num2);
                    std::cout << "\nResult: " << num1 << " / " << num2 << " = ";
                    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
                }
                break;
        }  
        
        // Asking.....if user wants to perform another calculation
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> continueCalculation;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        std::cout << std::endl;
        
    } while (continueCalculation == 'y' || continueCalculation == 'Y');
    
    std::cout << "Thank you for using the calculator. Goodbye!\n";
    
    return 0;
}

// Function to display the menu of operations.
void displayMenu() {
    std::cout << "\nAvailable Operations:\n";
    std::cout << "  + : Addition\n";
    std::cout << "  - : Subtraction\n";
    std::cout << "  * : Multiplication\n";
    std::cout << "  / : Division\n";
}

// Function to add two numbers.
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers.
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers.
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers.
double divide(double a, double b) {
    return a / b;
}

// Function to validate the operation choice.
bool isValidChoice(char choice) {
    return (choice == '+' || choice == '-' || choice == '*' || choice == '/');
}
