// Created by : Md Jubayer Islam
#include <iostream>
#include <string>
using namespace std;

class User
{

protected:
    string userId[5] = {"user1", "user2", "user3", "user4", "user5"};
    int password[5] = {1234, 2345, 3456, 4567, 5678};
    int userBalance[5] = {1000, 2000, 3000, 4000, 5000};
};

class ATM : public User
{
private:
    int balance;
    int option;
    int amount;
    int userPassword;
    string user;
    bool correctPassword = false;
    bool correctUser = false;

public:
    ATM()
    {
        balance = 0;
    }

    void checkBalance()
    {
        cout << "Your balance is: " << balance << endl;
    }

    void deposit()
    {
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Your balance is: " << balance << endl;
    }

    void withdraw()
    {
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Your balance is: " << balance << endl;
        }
    }

    void exit()
    {
        cout << "Thank you for using the ATM Machine" << endl;
        login();
    }

    void login()
    {
        cout << "Enter your user id: ";
        cin >> user;
        cout << "Enter your password: ";
        cin >> userPassword;

        for (int i = 0; i < 5; i++)
        {
            if (user == userId[i] && userPassword == password[i])
            {
                correctUser = true;
                correctPassword = true;
                balance = userBalance[i];
                break;
            }
        }

        if (correctUser && correctPassword)
        {
            cout << "Welcome to the ATM Machine" << endl;
            cout << "1. Check balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your option: ";
            cin >> option;

            switch (option)
            {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                exit();
                break;
            default:
                cout << "Invalid option" << endl;
            }
        }
        else
        {
            cout << "Incorrect user id or password" << endl;
            login();
        }
    }

    void run()
    {
        login();
    }
};

int main()
{
    ATM atm;
    atm.run();
    system("pause");
    return 0;
}