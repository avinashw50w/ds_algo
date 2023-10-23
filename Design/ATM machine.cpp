/*Requirements for ATM LLD
1. user is able to swipe a card.
2. User is able to withraw funds from account of any bank
3. Deposit cash and cheque
4. Transfer funds
5. Check balance
*/

class ATM {
	int atmId;
	Address location;
	Screen screen;
	Keypad keypad;
	CardReader cardReader;
	CashDispenser cashDispenser;
	CashDeposit cashDeposit;
	ChequeDeposit chequeDeposit;

	BankService bankService;
};

class Address {
	string pincode;
	string street;
	string city;
	string state;
	string country;
};

class Screen {
public:
	void display(string message);
};

class CashDispenser {
	map<CashDenomination, int> cashMap; // {cash denomination, quantity}
public:
	vector<vector<Cash>> dispenseCash(int amount) {
		if (amount % 100 != 0) return;
		vector<Cash> returnCash;
		for (auto it = cashMap.rbegin(); it != cashMap.rend(); ++it) {
			CashDenomination deno = (*it).first;
			int quantity = (*it).second;
			// int amt = deno * quantity;
			if (amount >= deno and amount / deno <= quantity) {
				int t = amount / deno;
				returnCash.push_back(new vector<Cash>(t, new Cash(deno)));
				amount -= deno * (t);
				it->second->quantity -= t;
			}
		}
	}
};

enum CashDenomination {
	HUNDRED = 100, FIVE_HUNDRED = 500, TWO_THOUSAND = 2000
};

class Cash {
	CashDenomination cashDeno;
	int serialNumber;
};


class CardReader {
public:
	CardInfo fetchCardDetails();
};

enum PaymentGateway {
	VISA = "visa",
	MASTERCARD = "mastercard",
}

class CardInfo {
	CardType cardType;
	Bank bank;

	string cardNumber;
	string expirationDate;
	string cvv;
	string cardHolderName;
	PaymentGateway paymentGateway;
};

enum CardType {
	DEBIT, CREDIT
};

class KeyPad {
public:
	string getInput();
};

class Bank {
	string name;
	Address location;
	string branchName;

	vector<ATM> atmList;
};

// Each Bank exposes their APIs so that the ATM machine can use it to
// validate user and each of their transaction
class BankService {
	virtual bool isValidUser(string pin, CardInfo cardInfo) = 0;
	virtual Customer getCustomerDetails(CardInfo cardInfo) = 0;
	virtual TransactionDetail executeTransaction(Transaction transaction) = 0;
};

class ICICI : public BankService {
	bool isValidUser(string pin, CardInfo cardInfo);
	Customer getCustomerDetails(CardInfo cardInfo);
	TransactionDetail executeTransaction(Transaction transaction);
}

class BankServiceProvider {
public:
	// returns ICICI/or any other BankService obj
	static BankService getBankServiceObject(CardInfo cardInfo);
};

class Customer {
	string firstName;
	string lastName;
	Account account;
	CardInfo cardInfo;

	BankService bankServiceObj;
	CustomerStatus customerStatus;
};

enum CustomerStatus {
	ACTIVE, INACTIVE, BLOCKED
};

class Account {
	string accountNumber;
	string IFSCcode;
	double availableBalance;
};

class Transaction {
	string transactionId;
	Account sourceAccount;
	string transactionTimestamp;
};

class Deposit : protected Transaction {
	double amount;
};

class CashDeposit : protected Deposit {
public:
	vector<Cash> getCash();
};

class ChequeDeposit : protected Deposit {
public:
	Cheque getCheque();
};

class Withdraw : protected Transaction {
	double amount;
};

class Transfer : protected Transaction {
	Account destAccount;
};

class TransactionDetail {
	string transactionId;

	string sourceAccountNumber;
	TransactionStatus transactionStatus;
	string transactionTimestamp;
	TransactionType transactionType;

	double availableBalance;
};

enum TransactionStatus {
	SUCCESS, ERROR, PENDING, CANCELLED
};

enum TransactionType {
	WITHDRAW, DEPOSIT, TRANSFER
};

