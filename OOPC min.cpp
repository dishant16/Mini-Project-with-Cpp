#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include<windows.h>

using namespace std;

class AutoTellerMachine  //Object to represent each customer  who uses the ATM program
{

    private:
    int loggedInAccountLocation;
    double accountBalance;
    double beginningBalance;
    double lastMoneyMovement;
    char lastOperation;
    string username;
    string password;


    public:
    void CreateNewAccount(string newUsername, string newPassword);
    void AccountLogin(string loginUsername, string loginPassword);
    void DepositMoney(double depositAmount);
    void WithdrawMoney(double withdrawalAmount);
    void SetAccountLogin(int setAccountLocation);
    void SetLastMoneyMovement(int accountID, double amount);
    void SetBeginningBalance(int accountID);
    void SetLastOperation(int accountID, char userInput);
    void AccountMenu();
    int GetAccountLogin() const;
    double GetLastMoneyMovement(int accountID) const;
    double GetAccountBalance(int accountID) const;
    double GetBeginningBalance(int accountID) const;
    char GetLastOperation(int accountID) const;
    string GetUsername(int accountID) const;


};

AutoTellerMachine account;

vector<AutoTellerMachine> AccountList;  //This vector allows for multiple accounts to be stored so that if more than one person uses the account, all information is retained

//void AccountMenu();
void UserMenu();

void AutoTellerMachine:: SetAccountLogin(int setAccountLocation)
{
    loggedInAccountLocation = setAccountLocation;
    return;
}

int AutoTellerMachine::GetAccountLogin() const
{
    return loggedInAccountLocation;
}

void AutoTellerMachine::CreateNewAccount(string newUsername, string newPassword)    //Adds the new information to the vector to give the account personalized info
{
    int accountListSize = AccountList.size();

    AccountList.at(accountListSize - 1).accountBalance = 0.0;
    AccountList.at(accountListSize - 1).username = newUsername;
    AccountList.at(accountListSize - 1).password = newPassword;
}

void AutoTellerMachine::AccountLogin(string loginUsername, string loginPassword)
{
    int accountListSize = AccountList.size();
    bool successfulLogin = false;
    int accountLocation = 0;

    for(int i = 0; i < accountListSize; i++)
    {
        if(loginUsername == AccountList.at(i).username)
        {
            if(loginPassword == AccountList.at(i).password)
            {
                successfulLogin = true;
                accountLocation = i;
            }
        }
    }

    if(successfulLogin != true)
    {
        cout << endl << "\t******** LOGIN FAILED! ********" << endl << endl;
        UserMenu();
    }

    else if(successfulLogin == true)
    {
        SetAccountLogin(accountLocation);
        cout<<endl<<endl<<endl;
        cout<<"\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n"<<"\t";
        cout << endl << "\t+--+--+--+--+--+--+--+--+- Welcome " << AccountList.at(loggedInAccountLocation).username <<" -+--+--+--+--+--+--+--+--+"<< endl;
        cout<<"\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n"<<"\t";
        system("cls");
        AccountMenu();
    }
    return;
}

void AutoTellerMachine::DepositMoney(double depositAmount)
{
    AccountList.at(loggedInAccountLocation).accountBalance += depositAmount;
    return;
}

void AutoTellerMachine::WithdrawMoney(double withdrawalAmount)
{
    AccountList.at(loggedInAccountLocation).accountBalance -= withdrawalAmount;
    return;
}

double AutoTellerMachine::GetAccountBalance(int accountID) const
{
    return AccountList.at(loggedInAccountLocation).accountBalance;
}

void AutoTellerMachine::SetLastMoneyMovement(int accountID, double amount)
{
    AccountList.at(accountID).lastMoneyMovement = amount;
}

void AutoTellerMachine::SetBeginningBalance(int accountID)
{
    AccountList.at(accountID).beginningBalance = AccountList.at(loggedInAccountLocation).accountBalance;
}

void AutoTellerMachine::SetLastOperation(int accountID, char userInput)
{
    AccountList.at(accountID).lastOperation = userInput;
}

double AutoTellerMachine::GetLastMoneyMovement(int accountID) const
{
    return AccountList.at(accountID).lastMoneyMovement;
}

double AutoTellerMachine::GetBeginningBalance(int accountID) const
{
    return AccountList.at(accountID).beginningBalance;
}

char AutoTellerMachine::GetLastOperation(int accountID) const
{
    return AccountList.at(accountID).lastOperation;
}

string AutoTellerMachine::GetUsername(int accountID) const
{
    return AccountList.at(GetAccountLogin()).username;
}

void UserMenu()    //Implements a user interface that allows the user to make selections based on what they want to do
{
    char userSelection;
    string createUserId;
    string createUserPass;
    string usernameCheck;
    string passwordCheck;

    cout <<endl<< endl<< endl<< "\t Login --------------> L" << endl;
    cout << "\t Create New Account -> C" << endl;
    cout << "\t Exit  ------------ -> E" << endl << endl;
    cout << "\t =>";
    cin >> userSelection;
    PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);

    system("cls");
    if((userSelection == 'l') || (userSelection == 'L')) //Checks to make sure the login is valid and if not, couts an error statement
    {
        cout<< endl<<"\t+--+--+--+--+--+--+--+--+--+--+- Log in -+--+--+--+--+--+--+--+--+--+--+";
        cout << endl<<endl<<endl << "\tPlease enter your user name: " << endl<<"\t";
        cin >> usernameCheck;
        cout <<endl<< "\tPlease enter your password: " << endl<<"\t";
        cin >> passwordCheck;
        PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
        system("cls");

        account.AccountLogin(usernameCheck, passwordCheck);
    }
     else if((userSelection == 'c') || (userSelection == 'C'))   //Captures info for a new account
    {

        cout<<endl<<endl<<endl<<"\t+--+--+--+--+--+--+--+--+- Create New Account -+--+--+--+--+--+--+--+--+";
        cout << endl <<endl<< "\tPlease enter your user name: " << endl<<"\t";
        cin >> createUserId;
        cout << "\tPlease enter your password: " << endl<<"\t";
        cin >> createUserPass;
        PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
        AccountList.push_back(account); //This creates a new object in the vector to be filled with the information gathered

        account.CreateNewAccount(createUserId,createUserPass);

        cout << endl << "\tThank You! Your account has been created!" << endl << endl;
        //cout << endl << "\tBeginning balance: " << fixed << setprecision(2) << GetBeginningBalance(GetAccountLogin())<<"₹"<< endl;
        system("cls");
        UserMenu();
    }

    else if((userSelection == 'e') || (userSelection == 'E'))    //Exits the entire program
    {
        cout << endl<<endl<<endl << "\tThanks for Banking with us" << endl << endl;
        exit(1);
    }

    else
    {
        PlaySound(TEXT("beep01.wav"), NULL, SND_SYNC);
        cout << endl << "\t!!!!!!Invalid selection!!!!!!\n\tPlease Enter from provided " << endl;
        UserMenu();
    }

    return;
}

void AutoTellerMachine::AccountMenu()          //This is a separate menu from the user menu because it deals with all options available to a logged in customer
{
    int e;
    char userInput;
    double amountOfDeposit;
    double amountOfWithdrawal;

    cout << endl << "\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Main Menu \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << endl << endl;
	cout << "\t\t 1 -> To  Deposit Cash" << endl;
	cout << "\t\t 2 -> To Withdraw Cash" << endl;
	cout << "\t\t 3 -> To Request Balance" << endl;
	cout << "\t\t 4 -> Logout" << endl;
	cout << "\t\t 5 -> to Exit ATM" << endl << endl;
	cout << "\n";
	cout<<"\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n"<<"\t";
    cin>>e;
    PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
    if(e==1){userInput='d';}
    if(e==2){userInput='w';}
    if(e==3){userInput='r';}
    if(e==4){userInput='o';}
    if(e==5){userInput='e';}

switch(e)
{
    case 1:
            SetBeginningBalance(GetAccountLogin());
            cout << endl << "\tEnter Deposit Amount: " << endl<<"\t";
            cin >> amountOfDeposit;
            PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
            SetLastMoneyMovement(GetAccountLogin(), amountOfDeposit);
            SetLastOperation(GetAccountLogin(), userInput);
            DepositMoney(amountOfDeposit);
            cout << "\tYour account balance is : " << fixed << setprecision(2) << GetAccountBalance(GetAccountLogin()) <<"$"<< endl;
            system("PAUSE");
            system("cls");
            AccountMenu();
            break;
    case 2:
            cout << endl << "\tEnter Withdrawal Amount: " << endl<<"\t";
            cin >> amountOfWithdrawal;

            if(amountOfWithdrawal > GetAccountBalance(GetAccountLogin()))
            {
                PlaySound(TEXT("beep01.wav"), NULL, SND_SYNC);
                cout << endl << "\t!!!!!!******Your balance is Insufficient******!!!!!!" << endl;
                cout << "\tYour available balance is : " << fixed << setprecision(2) << GetAccountBalance(GetAccountLogin()) <<"$"<< endl;
                system("PAUSE");
                system("cls");
                AccountMenu();
            }
            else
            {
                PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
                SetBeginningBalance(GetAccountLogin());
                SetLastMoneyMovement(GetAccountLogin(), amountOfWithdrawal);
                SetLastOperation(GetAccountLogin(), userInput);
                WithdrawMoney(amountOfWithdrawal);
                cout << "\tYour balance is : " << fixed << setprecision(2) << GetAccountBalance(GetAccountLogin()) <<"$"<< endl;
            }
            system("PAUSE");
            system("cls");
            AccountMenu();
            break;
    case 3:

                   /* if(GetLastOperation(GetAccountLogin()) == 'd')
                        {
                            cout << "\tDeposit amount: " << fixed << setprecision(2) << GetLastMoneyMovement(GetAccountLogin())<<"$"<< endl;
                        }
                    else if(GetLastOperation(GetAccountLogin()) == 'w') {
                            cout << "\tWithdrawal amount: " << fixed << setprecision(2) << GetLastMoneyMovement(GetAccountLogin())<<"$" << endl;
                        }*/

                    cout << "\tYour balance is : " << fixed << setprecision(2) << GetAccountBalance(GetAccountLogin()) <<"$"<< endl;
                        system("PAUSE");
                        system("cls");
                        AccountMenu();
	                break;
    case 4:
	                cout << endl << "\tYou have successfully logged out, " << GetUsername(GetAccountLogin()) << "!" << endl << endl;

                    system("cls");
                    UserMenu();
	                break;

    case 5:
                    cout << endl << "\tThanks for banking with us , " << GetUsername(GetAccountLogin()) << "!" << endl;
                    break;

    default:
        PlaySound(TEXT("beep01.wav"), NULL, SND_SYNC);
        cout<<"\tPlease Enter the Correct Number Choice"<<endl;
        system("PAUSE");
        system("cls");
        AccountMenu();
        break;
}

}

int main()
{
     system ("PAUSE");
      system ("cls");
    system ("Color 1F");
            cout<<"\n\t======================= WELCOME TO ATM=======================\n";
            time_t now;
            time(&now);
            printf("\n\t\t\t\t\t :-: %s\n", ctime(&now));
            PlaySound(TEXT("welcome.wav"), NULL, SND_SYNC);

    //cout<<endl;    cout << "\tPlease select an option from the menu below: " << endl << endl;
    string createUserId;
    string createUserPass;
    char userSelection;
    c:
            cout << "\t Create New Account -> C" << endl;
            cout << "\t Exit  ------------ -> E" << endl << endl;
            cout << "\t =>";
            cin >> userSelection;
            PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);

            system("cls");
    if((userSelection == 'c') || (userSelection == 'C'))   //Captures info for a new account
    {
        cout<<endl<<endl<<"\t+--+--+--+--+--+--+--+--+- Create New Account -+--+--+--+--+--+--+--+--+";
        cout << endl <<endl<< "\tPlease enter your user name: " << endl<<"\t";
        cin >> createUserId;
        cout <<endl<< "\tPlease enter your password: " << endl<<"\t";
        cin >> createUserPass;
        PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
        AccountList.push_back(account); //This creates a new object in the vector to be filled with the information gathered

        account.CreateNewAccount(createUserId,createUserPass);

        cout << endl << "\t Your account has been created!" << endl << endl;
        //cout << endl << "\tBeginning balance: " << fixed << setprecision(2) << GetBeginningBalance(GetAccountLogin())<<"₹"<< endl;
        system("PAUSE");
        system("cls");
        UserMenu();
    }
    else if((userSelection == 'e') || (userSelection == 'E'))    //Exits the entire program
    {
        cout << endl << "\tThank You" << endl << endl;
    }
     else
    {
        PlaySound(TEXT("beep01.wav"), NULL, SND_SYNC);
        cout << endl << "\t!!!!!!Invalid selection!!!!!!\n\tPlease Enter from provided " << endl;
        goto c;
    }

};
