#include <iostream>
#include <cmath>

using namespace std;

void displayMenu() {
    cout << "=== Scientific Calculator ===" << endl;
    cout << "1. Basic arithmetic operations" << endl;
    cout << "2. Trigonometric functions" << endl;
    cout << "3. Unit converter" << endl;
    cout << "4. Programming functions" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void basicArithmetic() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 == 0) {
                cout << "Error: division by zero." << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Error: invalid operator." << endl;
    }
}

void trigonometricFunctions() {
    double angle;

    cout << "Enter angle in degrees: ";
    cin >> angle;

    cout << "sin(" << angle << ") = " << sin(angle * M_PI / 180.0) << endl;
    cout << "cos(" << angle << ") = " << cos(angle * M_PI / 180.0) << endl;
    cout << "tan(" << angle << ") = " << tan(angle * M_PI / 180.0) << endl;
}

void unitConverter() {
    double value;
    int choice;

    cout << "=== Unit Converter ===" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Kilometers to Miles" << endl;
    cout << "4. Miles to Kilometers" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter temperature in Celsius: ";
            cin >> value;
            cout << value << " degrees Celsius = " << (value * 9 / 5) + 32 << " degrees Fahrenheit." << endl;
            break;
        case 2:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> value;
            cout << value << " degrees Fahrenheit = " << (value - 32) * 5 / 9 << " degrees Celsius." << endl;
            break;
        case 3:
            cout << "Enter distance in kilometers: ";
            cin >> value;
            cout << value << " kilometers = " << value / 1.609 << " miles." << endl;
            break;
        case 4:
            cout << "Enter distance in miles: ";
            cin >> value;
            cout << value << " miles = " << value *
