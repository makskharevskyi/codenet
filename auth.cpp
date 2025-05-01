#include "auth.h"
#include <iostream>
#include <fstream>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin  >> username;
    cout << "Enter password: ";
    cin  >> password;

    ofstream userFile("users.txt", ios::app); //open for appending to file
    if (userFile.is_open()) {
        userFile << username << ":" << password << "\n";
        userFile.close();
        cout << "Registration successfull!\n";
    } else {
        cout << "Error: Unable to open users file.\n";
    }
}

string loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream credentialsFile("users.txt");

    string credentialsLine;
    while(getline(credentialsFile, credentialsLine)) {
        if (credentialsLine.substr(0, credentialsLine.find(":")) == username) {
            if(credentialsLine.substr(credentialsLine.find(":")+1) == password) {
                cout << "Success!\n";
                credentialsFile.close();
                return username;
            }
        }
    };
    cout << "User is not found or credentials do not match.";
    credentialsFile.close();
    return "";

}