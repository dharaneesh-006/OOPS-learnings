#include <bits/stdc++.h>
using namespace std;

class Customer {
private:
    string name;
    string email;
    long long mobile;
    vector<Account*> accounts;  
 

public:
    Customer(string name, string email, long long mobile) {
        this->name = name;
        this->email = email;
        this->mobile = mobile;
    }
    ~Customer()
    {
        for(auto a : accounts)
        {
            delete a;
        }
        cout <<  "All Accounts Cleared !!" << endl;
    }

    void add_account(string id, string type, double balance) {
        if(type == "savings")
        {
            accounts.push_back(new SavingsAccount(id,balance, 0.05));
        }
        else if(type == "current")
        {
            accounts.push_back(new CurrentAccount(id,balance));
        }
    }

    void close_account(string id)
    {
        for(auto a : accounts)
        {
            if(a->get_account_id() == id )
            {
                delete a;
                accounts.erase(remove(accounts.begin(),accounts.end(),a),accounts.end());
                cout << "Account Deletion Success!!" << endl;
                return;
            }
        }
        cout << "Account Not Found !!" << endl;
        return;

    }

    void show_all_accounts() {
        cout << "\nCustomer: " << name << endl;
        for (auto& acc : accounts) {
            acc->show_account();
        }
    }

    Account* get_account(string account_id)
    {
        for(auto& a : accounts)
        {
            if(a->get_account_id() == account_id)
            {
                return a;
            }
        }
        return nullptr;
    }

    void transfer(string from_id, string to_id, double amount)
    {
        Account* from = get_account(from_id);
        Account* to = get_account(to_id);
        if(from)
        {
            from->withdraw(amount);
        }
        else{
            cout << "Sender Account not found !!" << endl ;
            return;
        }
        if(to)
        {
            to->deposit(amount);
        }
        else{
            cout << "Receiver Account not found !!" << endl ;
            return;
        }

    }
};