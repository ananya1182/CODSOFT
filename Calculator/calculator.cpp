#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    if(op == '+') cout << a + b;
    else if(op == '-') cout << a - b;
    else if(op == '*') cout << a * b;
    else if(op == '/') {
        if(b != 0) cout << a / b;
        else cout << "Cannot divide by zero";
    }
    else cout << "Invalid operator";

    return 0;
}






