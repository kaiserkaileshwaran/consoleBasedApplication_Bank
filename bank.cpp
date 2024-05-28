#include<bits/stdc++.h>
using namespace std;

void createAccount(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);
void readAccount(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);
void updateAccount(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);
void deleteAccount(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);
void Transaction(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);
void choice(vector<string>&, vector<int>&, vector<int>&, vector<string>&, vector<string>&);

void createAccount(vector<string> &acc_name, vector<int> &acc_number, vector<int> &acc_balance, vector<string> &bank_name, vector<string> &branch){
    string str;
    int num = 0;
    cout << "Account Name : ";
    cin >> str;
    acc_name.push_back(str);
    cout << "Account Number : ";
    cin >> num;
    acc_number.push_back(num);
    cout << "Account Balance : ";
    cin >> num;
    acc_balance.push_back(num);
    cout << "Bank Name : ";
    cin >> str;
    bank_name.push_back(str);
    cout << "Bank Branch : ";
    cin >> str;
    branch.push_back(str);
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
}

void readAccount(vector<string> &acc_name, vector<int> &acc_number, vector<int> &acc_balance, vector<string> &bank_name, vector<string> &branch){
    int length = acc_name.size();
    cout << "Total Customers : " << length << '\n';
    for(int i = 0; i < length; i++){
        cout << "==========";
        cout << "\nCustomer " << i + 1;
        cout << "\nAccount Name : " << acc_name[i];
        cout << "\nAccount Number : " << acc_number[i];
        cout << "\nAccount Balance : " << acc_balance[i];
        cout << "\nBank Name : " << bank_name[i];
        cout << "\nBranch Name : " << branch[i];
        cout << "\n==========\n";
    }
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
}

void updateAccount(vector<string> &acc_name, vector<int> &acc_number, vector<int> &acc_balance, vector<string> &bank_name, vector<string> &branch){
    int change = 0, num = 0, num1 = 0;
    string str;
    cout << "Total Customers : " << acc_name.size() << '\n';
    for(int i = 0; i < acc_name.size(); i++){
        cout << "==========";
        cout << "\nCustomer " << i + 1;
        cout << "\nAccount Name : " << acc_name[i];
        cout << "\nAccount Number : " << acc_number[i];
        cout << "\nAccount Balance : " << acc_balance[i];
        cout << "\nBank Name : " << bank_name[i];
        cout << "\nBranch Name : " << branch[i];
        cout << "\n==========\n";
    }
    cout << "In which account number you want to change?\n";
    cin >> num;
    cout << "What content you want to change\n";
    cout << "1.Account name.\n2.Account Number.\n3.Account Balance.\n3.Bank name.\n4.Bank Branch\n";
    cin >> num1;
    if(num1 == 1){
        cout << "New Account name : ";
        cin >> str;
        acc_name[num - 1] = str;
        cout << "=====Data Updated=====\n";
    }else if(num1 == 2){
        cout << "New Account number : ";
        cin >> change;
        acc_number[num - 1] = change;
        cout << "=====Data Updated=====\n";
    }else if(num1 == 3){
        cout << "New Account balance : ";
        cin >> change;
        acc_balance[num - 1] = change;
        cout << "=====Data Updated=====\n";
    }else if (num1 == 4){
        cout << "New Bank name : ";
        cin >> str;
        bank_name[num - 1] = str;
        cout << "=====Data Updated=====\n";
    }else if(num1 == 5){
        cout << "New Bank Branch : ";
        cin >> str;
        branch[num - 1] = str;
        cout << "=====Data Updated=====\n";
    }else{
        cout << "Invalid Number, Please try again.";
    }
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
}

void deleteAccount(vector<string> &acc_name, vector<int> &acc_number, vector<int> &acc_balance, vector<string> &bank_name, vector<string> &branch){
    int num;
    cout << "Whcih account you want to delete: ";
    cin >> num;
    if(num  > 0){
        acc_name.erase(acc_name.begin() + (num - 1));
        acc_number.erase(acc_number.begin() + (num - 1));
        acc_balance.erase(acc_balance.begin() + (num - 1));
        bank_name.erase(bank_name.begin() + (num - 1));
        branch.erase(branch.begin() + (num - 1));
        cout << "Account Deleted Succesfully.\n";
    }else{
                cout << "Invalid Number, Please try again.";
    }
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
}

void Transaction(vector<string>& acc_name, vector<int>& acc_number, vector<int>& acc_balance, vector<string>& bank_name, vector<string>& branch){
    int from = 0, to = 0, amount = 0;
    if(acc_name.size() >= 2){
        cout << "Mention the account that needs to send money : ";
        cin >> from;
        if(from > acc_name.size()){
            cout << "Invalid Account\n";
            choice(acc_name, acc_number, acc_balance, bank_name, branch);
        }
        cout << "Mention the account that needs to receive money : ";
        cin >> to;
        if(to > acc_name.size()){
            cout << "Invalid Account\n";
            choice(acc_name, acc_number, acc_balance, bank_name, branch);
        }
        cout << "Amount to be transactioned : ";
        cin >> amount;
        if((acc_balance[from - 1] - amount) >= 0){
            acc_balance[from - 1] -= amount;
            acc_balance[to - 1] += amount;
            cout << "\n==========\n";
            cout << "Transaction Completed\n";
            cout << "\n==========\n";

        }else{
            cout << "Balance is not enough.\n";
        }
    }else{
        cout << "Needed more accounts for transactions.\n";
    }
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
}


void choice(vector<string>& acc_name, vector<int>& acc_number, vector<int>& acc_balance, vector<string>& bank_name, vector<string>& branch){
    int num = -1;
    while(num != 0){
        cout << "1. Create An Account\n2. Read An Account.\n3. Update An Account.\n4. Delete An Account.\n5. Transactions\n0. Exit\n";
        cout << "Mention the operation number : ";
        cin >> num;
        switch(num)
        {
        case 1:
            createAccount(acc_name, acc_number, acc_balance, bank_name, branch);
            break;
        case 2:
            readAccount(acc_name, acc_number, acc_balance, bank_name, branch);
            break;
        case 3:
            updateAccount(acc_name, acc_number, acc_balance, bank_name, branch);
            break;
        case 4:
            deleteAccount(acc_name, acc_number, acc_balance, bank_name, branch);
            break;
        case 5:
            Transaction(acc_name, acc_number, acc_balance, bank_name, branch);
            break;
        
        default:
            if(num != 0){
                cout << "Invalid Number, Please try again.";
            }
            break;
        }
    }
}

int main(void){
    vector<int> acc_number, acc_balance;
    vector<string> acc_name, bank_name, branch;
    choice(acc_name, acc_number, acc_balance, bank_name, branch);
    return 0;
}
