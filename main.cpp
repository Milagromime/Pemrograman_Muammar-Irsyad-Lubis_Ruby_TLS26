#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptMessage(string message) {
    string encrypted = message;

    for (size_t i = 1; i < message.size(); i++) {
        int currentValue = toupper(message[i]) - 'A' + 1;      // A=1 ... Z=26
        int precedingValue = toupper(message[i - 1]) - 'A' + 1; // uses ORIGINAL preceding letter

        int shifted = currentValue + precedingValue;

        // wrap around: if it passes 26, restart from 1
        shifted = ((shifted - 1) % 26) + 1;

        encrypted[i] = 'A' + (shifted - 1);
    }

    return encrypted;
}

int main() {
    string message;

    cout << "Enter the message to encrypt: ";
    cin >> message;

    string result = encryptMessage(message);

    cout << "Encrypted message: " << result << endl;

    return 0;
}
