#include <bits/stdc++.h>
using namespace std;

class Customer {
private:
    string name;
    string email;
    long long mobile;
    vector<Account> accounts;  

public:
    Customer(string name, string email, long long mobile) {
        this->name = name;
        this->email = email;
        this->mobile = mobile;
    }

    void add_account(string id, string type, double balance) {
        Account a(id, type, balance);
        accounts.push_back(a);
    }

    void show_all_accounts() {
        cout << "\nCustomer: " << name << endl;
        for (auto& acc : accounts) {
            acc.show_account();
        }
    }

    Account* get_account(string account_id)
    {
        for(auto& a : accounts)
        {
            if(a.get_account_id() == account_id)
            {
                return &a;
            }
        }
        return nullptr;
        
    }
};