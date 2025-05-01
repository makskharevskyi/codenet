#include <iostream>
#include <fstream>
#include "auth.h"
#include "posts.h"
#include "utils.h"

using namespace std;

// ************* //
// MENU SECTIONS //
// ************* //
void showMenu() {
    clearScreen();
    cout << "\nWelcome to CodeNet\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void showLoggedInMenu() {
    clearScreen();
    cout << "1. Post a Message" << "\n";
    cout << "2. View Posts" << "\n";
    cout << "3. Logout" << "\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Registartion\n";
                registerUser();
                break;

            //LOGGED IN CHOICES
            case 2: {
                cout << "Login\n";
                string loggedInUser = loginUser();
                if (loggedInUser != "") {
                int loggedInMenuChoice;
                    do {
                        showLoggedInMenu();
                        cin >> loggedInMenuChoice;

                        switch(loggedInMenuChoice) {
                            case 1:
                                cout << "Post a Message\n";
                                postMessage(loggedInUser); 
                                break;
                            case 2:
                                clearScreen();
                                cout << "Posts\n";
                                viewPosts();
                                break;
                            case 3:
                                cout << "Logging out... goodbye!";
                                break;
                            default:
                                cout << "Invalid choice, please try again";
                            }
                    } while (loggedInMenuChoice != 3);
                }
                    break;
                //LOGGED IN CHOICES ENDED
            }
                case 3:
                    cout << "Exiting... goodbye!";
                    break;
                default:
                    cout << "Invalid choice, please try again";
            }
    } while (choice != 3); //main menu loop
    

    return 0;
} 