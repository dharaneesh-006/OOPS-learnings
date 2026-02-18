#include <bits/stdc++.h>
#include "Account.h"
#include "Customer.h"
using namespace std;

int main() {
    Customer c("Alice", "alice@gmail.com", 9876543210);
    c.add_account("ACC001", "savings", 5000);
    c.add_account("ACC002", "current", 10000);
    c.show_all_accounts();

    Account* a = c.get_account("ACC001");
    if(a != nullptr)
    {
        a->deposit(555.8);
    }

    c.show_all_accounts();

    return 0;
}