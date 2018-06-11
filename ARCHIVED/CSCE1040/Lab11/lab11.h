/*
        Name:                   Axel Yates
        Email:                  axelyates@my.unt.edu
        Class Section:          002
        Lab Section:            308
*/



class Bank{
private:

	int accounts[9];

public:

	Bank();
	void deposit(int num, int value); 	
	void withdraw(int num, int value);
	void balance(int num);
	void transfer(int num1, int num2, int value);
};
