#include "posts.h"
#include <iostream>
#include <fstream>
#include <ctime>

void postMessage(string username) {
    string post;
    cout << "Write your post\n";
    cin.ignore();
    getline(cin, post);
    ofstream postsFile("posts.txt", ios::app);

    if (postsFile.is_open()) {
        time_t now = time(0);
        tm* localTime = localtime(&now);

        char timeString[20];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M", localTime);
        
        postsFile << username << ":" << post << " [" << timeString << "]" << "\n";
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
            cout << post.substr(0, post.find(":")) << " posted: \n";
            cout << post.substr(post.find(":") + 1) << "\n";

            string message = post.substr(post.find(":")+1);

            size_t pos = 0;
            while ((pos = message.find("@", pos)) != string::npos) {
                size_t end = message.find(" ", pos);
                if (end == string::npos) end = message.length();
    
                string mention = message.substr(pos, end - pos);
    
                cout << "📣 Mention detected: " << mention << "\n";
    
                pos = end;
            }
            cout << "\n";
        }
        postsFile.close();
        } else {
            cout << "Error. No posts file found.\n";
        }
            

        //LOOKING FOR MENTIONS

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}