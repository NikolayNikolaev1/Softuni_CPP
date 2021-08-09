/*
* Write a program, make a Class Bank Account. The class should have:
* Members:
*	User Name
*	Account Num (array of chars)
*	Balance (the balance should be floating number)
* Methods:
*	Print - Print all Info of the account (Name, Account Num, Balance)
*	Add Balance - Add balance method (you can not add ZERO or Negative balance)
*	Withdraw Balance - Withdraw balance method (you can not withdraw Zero or NEgative balance)
*	Set Initial Balance - Set Initial Balance method
*	Set Account Number - Setting account number Examle (BGN12)
*	Get Balance - returning current balance
*
* Write extern function that modifies the account, while the user choose to exit.
*	Would you like to do ?
*	Press 1 to Show All Information...
*	Press 2 to Add Balance...
*	Press 3 to Withdraw Balance...
*	Press 0 to Exit Program...
*/
#include <iostream>
#include <sstream>
#include <vector>;

using namespace std;

class BankAccount
{
private:
	string userName;
	string accountNumber;
	double balance;

public:
	BankAccount(string userName)
	{
		this->userName = userName;
		this->balance = 0;
	}

	// Getters
	double getBalance() { return this->balance; }
	// Setters
	void setAccountNumber(string accountNumber) { this->accountNumber = accountNumber; }
	void setBalance(double balance) { this->balance = balance; }

	// Adds to the existing account balance.
	void addBalance(double balance)
	{
		if (balance <= 0)
		{
			throwInvalidBalance(balance);
		}

		this->balance += balance;
	}

	void print()
	{
		cout << "Name: " << this->userName << endl
			<< "Account Number: " << this->accountNumber << endl
			<< "Balance: " << this->balance << endl;
	}

	void withdrawBalance(double balance)
	{
		if (balance <= 0)
		{
			throwInvalidBalance(balance);
		}

		if (balance > this->balance)
		{
			ostringstream outputStream;
			outputStream << "Balance in Bank Account is not enough for withdraw!" << endl;

			throw outputStream.str();
		}

		this->balance -= balance;
	}

private:
	void throwInvalidBalance(int balance)
	{
		ostringstream outputStream;
		outputStream << "Invalid Balance: " << balance << endl
			<< "Balance can not be ZERO or Negative number!" << endl;

		throw outputStream.str();
	}
};

BankAccount createBankAccount();
void printMenu();
void runCommand(int command, BankAccount& bankAccount);

void bankAccount()
{
	BankAccount bankAccount = createBankAccount();
	int command;

	do
	{
		printMenu();
		cin >> command;

		try
		{
			runCommand(command, bankAccount);
		}
		catch (string exceptionMessage)
		{
			// Show error messages around Bank Account Balance.
			cout << exceptionMessage;
		}
	} while (command != 0);
}

// Creates a valid Bank Account with User Name, Account Number and Balance from input and returns it.
BankAccount createBankAccount()
{
	string userName, accountNumber;
	double balance;

	cout << "Enter Name: ";
	cin >> userName;
	BankAccount bankAccount = BankAccount(userName);

	cout << "Enter 5 characters IBAN Code: ";

	while (cin >> accountNumber)
	{
		// Enter account number input until size is 5 characters.
		if (accountNumber.size() == 5)
		{
			bankAccount.setAccountNumber(accountNumber);
			break;
		}

		cout << "Invalid Account Number!" << endl;
		cout << "Enter 5 characters IBAN Code: ";
	}

	cout << "Enter Initial Balance: ";

	while (cin >> balance)
	{
		// Enter account balance until it is greater than 0.
		if (balance > 0)
		{
			bankAccount.setBalance(balance);
			break;
		}

		cout << "Balance can no be ZERO or Negative!" << endl;
		cout << "Enter Initial Balance: ";
	}

	return bankAccount;
}

// Prints the menu with options to the console.
void printMenu()
{
	cout << "Would you like to do ?" << endl
		<< "Press 1 to Show All Information..." << endl
		<< "Press 2 to Add Balance..." << endl
		<< "Press 3 to Withdraw Balance..." << endl
		<< "Press 0 to Exit Program..." << endl;
}

// Private methods used only by runCommand() function.
void addBalance(BankAccount& bankAccount, double balance);
void showAllInformation(BankAccount bankAccount);
void withdrawBalance(BankAccount& bankAccount, double balance);

// Performs given command on Bank Account.
void runCommand(int command, BankAccount& bankAccount)
{
	switch (command)
	{
	case 1:
		showAllInformation(bankAccount);
		break;
	case 2:
		double balanceAdd;
		cout << "Enter Balance to add: ";
		cin >> balanceAdd;
		addBalance(bankAccount, balanceAdd);
		break;
	case 3:
		double balanceWithdraw;
		cout << "Enter Balance to withdraw: ";
		cin >> balanceWithdraw;
		withdrawBalance(bankAccount, balanceWithdraw);
		break;
	case 0:
		cout << "Exiting Program..." << endl;
		break;
	default:
		cout << "Invalid command!" << endl;
		break;
	}
}

// Private Methods.

// Adds VALID Balance.
void  addBalance(BankAccount& bankAccount, double balance)
{
	bankAccount.addBalance(balance);
	cout << "Successfully added " << balance << " to your Bank Account." << endl;
}

// Prints Bank Account Info.
void showAllInformation(BankAccount bankAccount)
{
	bankAccount.print();
}

// Withdraws VALID Balance.
void withdrawBalance(BankAccount& bankAccount, double balance)
{
	bankAccount.withdrawBalance(balance);
	cout << "Successfully withdrawed " << balance << " from your Bank Account." << endl;
}