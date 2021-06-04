// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: June 4, 2021
// This programs asks the user for two numbers and then performs the operation
// the user inputted on those numbers, displaying the result

#include <iostream>
#include <string>
#include <cmath>

float Calculate(float number1, float number2, char operation) {
    // does the operation depending on which one the user inputted
    // displays error message as fail safe
    float result = 0;

    if (operation == '+') {
        result = number1 + number2;
    } else if (operation == '-') {
        result = number1 - number2;
    } else if (operation == '*') {
        result = number1 * number2;
    } else if (operation == '/') {
        result = static_cast<float>(number1) / static_cast<float>(number2);
    } else if (operation == '%') {
        result = fmodf(number1, number2);
    } else {
        std::cout << operation << " is not an operation, try again.\n";
    }
    return result;
}


int main() {
    // declare local variables
    char userOperator;
    float userNum1Float, userNum2Float, calc;
    std::string userNum1String, userNum2String;

    // greet message
    std::cout << "This program performs calculations between two numbers.\n";
    std::cout << "\n";

    while (true) {
        // get the operation from the user
        std::cout << "Enter the operation you want to perform ";
        std::cout << "(+, -, *, /, %): ";
        std::cin >> userOperator;

        if ((userOperator == '+') || (userOperator == '-') ||
            (userOperator == '*') || (userOperator == '/') ||
            (userOperator == '%')) {
                // check if the user inputted the right operation
                std::cout << "\n";
                while (true) {
                    // get the first number from the user
                    std::cout << "Enter the first number: ";
                    std::cin >> userNum1String;

                    try {
                        // convert from string to float
                        userNum1Float = std::stof(userNum1String);
                        break;
                    } catch (std::invalid_argument) {
                        // error message of the input is not a number
                        std::cout << userNum1String << " is not a number, ";
                        std::cout << "try again.\n";
                    }
                } std::cout << "\n";
                while (true) {
                    // get the second number from the user
                    std::cout << "Enter the second number: ";
                    std::cin >> userNum2String;

                    try {
                        // convert from string to float
                        userNum2Float = std::stof(userNum2String);
                        break;
                    } catch (std::invalid_argument) {
                        // error message of the input is not a number
                        std::cout << userNum2String << " is not a number, ";
                        std::cout << "try again.\n";
                    }
                }  // assign calculate function to calc to get the result
                calc = Calculate(userNum1Float, userNum2Float, userOperator);
                std::cout << "\n";
                // display the result
                std::cout << userNum1String << " " << userOperator << " ";
                std::cout << userNum2String << " = " << calc << "\n";
                break;
            } else {
                // error message if the operation was invalid
                std::cout << userOperator << " is not an operation, ";
                std::cout << "try again.\n";
            }
    }
}
