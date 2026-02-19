#include <bits/stdc++.h>
using namespace std;

class Account {
    protected:
        double balance;
    private:
        string account_id;
        string account_type; 

    public:
        Account(string id, string type, double initial_balance) {
            account_id = id;
            account_type = type;
            balance = initial_balance;
        }

        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        }

        virtual void withdraw(double amount) = 0;

        double get_balance() {
            return balance;
        }

        void show_account() {
            cout << "Account ID: " << account_id << ", Type: " << account_type << ", Balance: " << balance << endl;
        }
        string get_account_id()
        {
            return account_id;
        }
};

class SavingsAccount : public Account{
    private:
        double interest_rate;

    public:
        SavingsAccount(string id, double balance, double rate) : Account(id,"savings",balance)
        {
            interest_rate = rate;
        }

        void apply_interest()
        {
            balance = balance + (balance * interest_rate);
        }
        void withdraw(double amount)
        {
            if (amount > balance)
                cout << "Insufficient funds!" << endl;
            else {
                balance -= amount;
                cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
            }
        }
};

class CurrentAccount : public Account{

    public:
        CurrentAccount (string id, double balance) : Account(id,"current",balance)
        {
            
        }

        void withdraw(double amount) override
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
};