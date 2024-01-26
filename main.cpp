#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for formatting output

using namespace std;

// Define a class for Bank Account
class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string accNumber, string owner, double initialBalance) {
        accountNumber = accNumber;
        ownerName = owner;
        balance = initialBalance;
    }

    // Method to deposit funds into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << fixed << setprecision(2) << balance << endl;
    }

    // Method to withdraw funds from the account
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Method to display account information
    void displayInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }

    // Getter for account number
    string getAccountNumber() {
        return accountNumber;
    }
};

// Function to open a new bank account
void openAccount(vector<BankAccount> &accounts) {
    string accNumber, ownerName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNumber;
    cout << "Enter owner name: ";
    cin >> ownerName;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create a new BankAccount object and add it to the vector of accounts
    BankAccount newAccount(accNumber, ownerName, initialBalance);
    accounts.push_back(newAccount);

    cout << "Account opened successfully!" << endl;
}

// Function to deposit funds into an existing account
void deposit(vector<BankAccount> &accounts) {
    string accNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accNumber;

    // Search for the account
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            return;
        }
    }

    cout << "Account not found!" << endl;
}

// Function to withdraw funds from an existing account
void withdraw(vector<BankAccount> &accounts) {
    string accNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accNumber;

    // Search for the account
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            return;
        }
    }

    cout << "Account not found!" << endl;
}

// Function to display information of an existing account
void displayInfo(vector<BankAccount> &accounts) {
    string accNumber;

    cout << "Enter account number: ";
    cin >> accNumber;

    // Search for the account
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accNumber) {
            account.displayInfo();
            return;
        }
    }

    cout << "Account not found!" << endl;
}

int main() {
    vector<BankAccount> accounts;

    int choice;
    do {
        // Display menu
        cout << "\nBanking System Menu" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Info" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                openAccount(accounts);
                break;
            case 2:
                deposit(accounts);
                break;
            case 3:
                withdraw(accounts);
                break;
            case 4:
                displayInfo(accounts);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
