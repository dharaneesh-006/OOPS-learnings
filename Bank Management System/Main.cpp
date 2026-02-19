#include <bits/stdc++.h>
#include "Account.h"
#include "Customer.h"
using namespace std;

int main() {
    Customer c("Alice", "alice@gmail.com", 9876543210);
    // c.add_account("ACC001", "savings", 5000);
    c.add_account("ACC002", "current", 10000);
    // c.show_all_accounts();

    // Account* a = c.get_account("ACC001");
    // if(a != nullptr)
    // {
    //     a->deposit(555.8);
    // }

    // c.show_all_accounts();

    c.add_account("ACC003","savings",10000);
    // c.add_account("ACC004","current",10000);

    // Account* b = c.get_account("ACC003");
    // b->withdraw(10001);
    // c.show_all_accounts();
    // Account* d = c.get_account("ACC004");
    // d->withdraw(10001);
    
    c.close_account("ACC003");
    c.show_all_accounts();



    return 0;
}