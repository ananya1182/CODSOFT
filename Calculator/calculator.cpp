#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;

    do {
        cout << "\n===== ADVANCED CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> a;

            cout << "Enter second number: ";
            cin >> b;
        }

        switch (choice) {
            case 1:
                cout << "Result: " << a + b << endl;
                break;

            case 2:
                cout << "Result: " << a - b << endl;
                break;

            case 3:
                cout << "Result: " << a * b << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Result: " << a / b << endl;
                else
                    cout << "Error: Cannot divide by zero!" << endl;
                break;

            case 5:
                cout << "Exiting calculator... Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}






