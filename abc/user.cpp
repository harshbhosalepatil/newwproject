#include <iostream>
#include "spdlog/spdlog.h"
using namespace std;

string get_password() {
    string password;
    char ch;
    cout << "Enter password: ";
    
    while ((ch = getchar()) != '\n') {
        password.push_back(ch);
        cout << '*'; // Mask input
    }
    cout << endl;
    return password;
}

int main() {
    string password = get_password();
    spdlog::info("User entered a password of length: {}", password.length());
    
    return 0;
}
