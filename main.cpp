#include <iostream>
#include <fstream>

using namespace std;

void postMessage(string username) {
    string post;
    cout << "Write your post\n";
    cin.ignore();
    getline(cin, post);
    ofstream postsFile("posts.txt", ios::app);

    if (postsFile.is_open()) {
        postsFile << username << ":" << post << "\n";
        postsFile.close();
        cout << "Posted!\n";
    } else {
        cout << "Error: Unable to find posts file.\n";
    }
}

void viewPosts() {
    ifstream postsFile("posts.txt");
    
    if (postsFile.is_open()) {
        string post;
        while ( getline(postsFile, post) ) {
            cout << post.substr(0, post.find(":")) << "posted: \n";
            cout << post.substr(post.find(":") + 1) << "\n";
        }
    } else {
        cout << "Error. No posts file found.\n";
    }
}

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
                cout << "Success!";
                credentialsFile.close();
                return username;
            }
        }
    };
    cout << "User is not found or credentials do not match.";
    credentialsFile.close();
    return "";

}

void clearScreen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}
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
            case 2:
                cout << "Login\n";
                string loggedInUser = loginUser();
                if (loggedInUser != "") {
                    do {
                    showLoggedInMenu();
                    int loggedInMenuChoice;
                    cin >> loggedInMenuChoice;

                    switch(loggedInMenuChoice) {
                        case 1:
                            cout << "Post a Message\n";
                            postMessage(loggedInUser); 
                            break;
                        case 2:
                            cout << "Posts\n";
                            viewPosts();
                            break;
                        case 3:
                            cout << "Logging out... goodbye!";
                            break;
                        default:
                        cout << "Invalid choice, please try again";
                    } while (loggedInMenuChoice != 3);
                    break;
                //LOGGED IN CHOICES ENDED

                case 3:
                    cout << "Exiting... goodbye!";
                    break;
                default:
                    cout << "Invalid choice, please try again";
                } while (choice != 3);
            }
        }
    } while (choice != 3); //main menu loop
    

    return 0;
} 