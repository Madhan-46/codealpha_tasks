#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUsernameTaken(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Register\nUsername: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Username already taken.\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << "\n";
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return;
        }
    }
    cout << "Invalid credentials.\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice\n";

    return 0;
}
