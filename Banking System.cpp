#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string timestamp;

    Transaction(string t, double a) : type(t), amount(a) {
        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back(); // remove newline
    }

    void display() {
        cout << type << ": ₹" << amount << " on " << timestamp << endl;
    }
};

class Account {
private:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accNo) : accountNumber(accNo), balance(0.0) {}

    string getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount);
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        transactions.emplace_back("Withdrawal", amount);
        return true;
    }

    bool transfer(Account &to, double amount) {
        if (amount > balance) return false;
        balance -= amount;
        to.balance += amount;
        transactions.emplace_back("Transfer to " + to.accountNumber, amount);
        to.transactions.emplace_back("Transfer from " + accountNumber, amount);
        return true;
    }

    void showTransactions() {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (auto &t : transactions) {
            t.display();
        }
    }

    void showDetails() {
        cout << "\nAccount Number: " << accountNumber << "\nBalance: ₹" << balance << endl;
    }
};

class Customer {
private:
    string name;
    string customerId;
    Account account;

public:
    Customer(string n, string id, string accNo) : name(n), customerId(id), account(accNo) {}

    void deposit(double amount) { account.deposit(amount); }
    void withdraw(double amount) {
        if (!account.withdraw(amount))
            cout << "Insufficient balance!\n";
    }
    void transferTo(Customer &other, double amount) {
        if (!account.transfer(other.account, amount))
            cout << "Transfer failed: Insufficient balance!\n";
    }

    void showInfo() {
        cout << "\nCustomer: " << name << " (ID: " << customerId << ")";
        account.showDetails();
        account.showTransactions();
    }
};

// ----------- Main Function -----------
int main() {
    Customer c1("Alice", "C001", "A1001");
    Customer c2("Bob", "C002", "A1002");

    c1.deposit(5000);
    c1.withdraw(1000);
    c1.transferTo(c2, 2000);

    c1.showInfo();
    c2.showInfo();

    return 0;
}
