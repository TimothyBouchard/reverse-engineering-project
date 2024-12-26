#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Having the sensitive data harde coded into the system is a secerity issue.
vector<string> ClientNames = { "Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears" };
vector<int> ClientService = { 1, 2, 2, 1, 2 };
// This information should be encrypted and stored in a location outside the source code.

int primCheck(string arg1, string arg2);
void displayInfo();
void custChoice();

bool isValidInput(const string& input) { // input validation
    for (char c : input) { // this checks to see if the input is only alphanumaric
        if (!isalnum(c)) { // which means that no special charactors can be entered
            return false;
        }
    }
    return true;
}

int main() { // input validation, this system accepts all and any input which is a 
             // secerity issue as an attacker can inject malicious code.


    //cout << "Hello! Welcome to Tim Bouchards Investment Company" << endl;
    //cout << "Enter Your Username:" << endl;
    //string Username;
    //cin >> Username;
    //cout << "Enter your password:" << endl;
    //string Password;
    //cin >> Password;

    cout << "Hello! Welcome to Tim Bouchard's Investment Company" << endl;

    string Username;
    string Password;

    cout << "Enter Your Username:" << endl;
    cin >> Username;
    if (!isValidInput(Username)) { //check if input is only alphanumaric
        cout << "Invalid username." << endl;
        return 1; 
    }

    cout << "Enter Your Password:" << endl;
    cin >> Password;
    if (!isValidInput(Password)) {//check if input is only alphanumaric
        cout << "Invalid password." << endl;
        return 1; 
    }

    while (primCheck(Username, Password) == 1) { // input validation this system will accept any input 
        cout << "What would you like to do?" << endl;// which can result in unexspected errors
        cout << "DISPLAY the Client list. (Enter 1)" << endl;
        cout << "CHANGE the client's choice. (Enter 2)" << endl;
        cout << "Exit the program. (Enter 3)" << endl;

        string userInput;
        cin >> userInput;
        if (userInput != "1" && userInput != "2" && userInput != "3") { // this checks the input 
            cout << "Only Enter 1, 2, or 3" << endl; // and only allows the number 1,2 and 3 anything else 
        } else {                                     // will notify the user.

            if (userInput == "1") {
            displayInfo();
        }
            else if (userInput == "2") {
            custChoice();
        }
            else if (userInput == "3") {
            break;
        }
    }
    }
    return 0;
}

void custChoice() {
    cout << "Enter the number of the client that you wish to change: " << endl;
    int clientNum;
    cin >> clientNum;
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement):" << endl;
    int clientServ;
    cin >> clientServ;

    ClientService[clientNum] = clientServ;
}

void displayInfo() {
    for (int i = 0; i < ClientNames.size(); ++i) {
        cout << ClientNames[i] << " - Service Level: " << ClientService[i] << endl;
    }
}

int primCheck(string arg1, string arg2) {
    string Username = "tim"; // This should be stored outside the sourcecode and encrypted
    string Password = "123"; // This should be stored outside the sourcecode and encrypted

    if (arg1 == Username) {
        if (arg2 == Password) {
            return 1;
        }
        else {
            cout << "Invalid credentials. Please try again." << endl;
            return 0;
        }
    }
    else {
        cout << "Invalid credentials. Please try again." << endl;
        return 0;
    }
}
