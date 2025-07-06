#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i) : name(n), id(i) {}
    virtual void display() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

class Customer : public Person {
protected:
    string accountType;
public:
    Customer(string n, int i, string a) : Person(n, i), accountType(a) {}
    void display() override {
        cout << "Customer Details:\n";
        Person::display();
        cout << "Account Type: " << accountType << endl;
    }
};

class Employee : public Person {
protected:
    string position;
public:
    Employee(string n, int i, string p) : Person(n, i), position(p) {}
    void display() override {
        cout << "Employee Details:\n";
        Person::display();
        cout << "Position: " << position << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int i) : Employee(n, i, "Manager") {}
};

class Cashier : public Employee {
public:
    Cashier(string n, int i) : Employee(n, i, "Cashier") {}
};

class Account {
protected:
    int accountNumber;
    double balance;
public:
    Account(int num, double bal) : accountNumber(num), balance(bal) {}
    virtual void display() {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int num, double bal) : Account(num, bal) {}
    void display() override {
        cout << "Savings ";
        Account::display();
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int num, double bal) : Account(num, bal) {}
    void display() override {
        cout << "Current ";
        Account::display();
    }
};

class Transaction {
private:
    int transactionID;
    string type;
    double amount;
public:
    Transaction(int id, string t, double amt) : transactionID(id), type(t), amount(amt) {}
    void display() {
        cout << "Transaction ID: " << transactionID << "\nType: " << type << "\nAmount: " << amount << endl;
    }
};

class Branch {
private:
    string branchCode;
    string location;
public:
    Branch(string code, string loc) : branchCode(code), location(loc) {}
    void display() {
        cout << "Branch Code: " << branchCode << "\nLocation: " << location << endl;
    }
};

class Bank {
private:
    static int totalCustomers;
public:
    static void addCustomer() {
        totalCustomers++;
    }
    static void showTotalCustomers() {
        cout << "Total Customers: " << totalCustomers << endl;
    }
};
int Bank::totalCustomers = 0;

class Loan {
private:
    double amount;
public:
    Loan(double amt) : amount(amt) {}
    friend void showLoanAmount(Loan l);
};

void showLoanAmount(Loan l) {
    cout << "Loan Amount: " << l.amount << endl;
}

class Interest {
private:
    double rate;
public:
    Interest(double r) : rate(r) {}
    Interest operator+(Interest i) {
        return Interest(rate + i.rate);
    }
    void showRate() {
        cout << "Interest Rate: " << rate << "%" << endl;
    }
};

class ATM {
private:
    int atmID;
    string location;
public:
    ATM(int id, string loc) : atmID(id), location(loc) {}
    void display() {
        cout << "ATM ID: " << atmID << "\nLocation: " << location << endl;
    }
};

class Card {
private:
    string cardType;
    string expiryDate;
public:
    Card(string type, string exp) : cardType(type), expiryDate(exp) {}
    void display() {
        cout << "Card Type: " << cardType << "\nExpiry Date: " << expiryDate << endl;
    }
};

class Utility {
public:
    static void welcomeMessage() {
        cout << "Welcome to the Bank Account Management System!\n";
    }
};

int main() {
    Utility::welcomeMessage();

    Customer c1("Ahmed", 1001, "Savings");
    Manager m1("Mr. Tariq", 2001);
    Cashier cashier1("Ms. Fatima", 2002);

    cout << "\n--- Customer ---\n";
    c1.display();
    Bank::addCustomer();

    cout << "\n--- Employees ---\n";
    m1.display();
    cashier1.display();

    SavingsAccount sa1(5001, 10000);
    CurrentAccount ca1(5002, 25000);

    cout << "\n--- Accounts ---\n";
    sa1.display();
    ca1.display();

    Transaction t1(3001, "Deposit", 5000);
    cout << "\n--- Transaction ---\n";
    t1.display();

    Branch b1("B001", "Lahore");
    cout << "\n--- Branch ---\n";
    b1.display();

    Bank::showTotalCustomers();

    Loan loan1(75000);
    cout << "\n--- Loan ---\n";
    showLoanAmount(loan1);

    Interest i1(3.5), i2(1.5);
    Interest totalInterest = i1 + i2;
    cout << "\n--- Interest ---\n";
    totalInterest.showRate();

    ATM atm1(9001, "DHA");
    cout << "\n--- ATM ---\n";
    atm1.display();

    Card card1("Debit", "12/27");
    cout << "\n--- Card ---\n";
    card1.display();

    return 0;
}

