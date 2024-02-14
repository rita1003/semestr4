#include <iostream>

using namespace std;

class cashRegister {
private:
	int cashOnHand;
public:
	cashRegister() {
		cashOnHand = 500;
	}
	cashRegister(int HaveMoney) {
		cashOnHand = HaveMoney;
	}
	int getCurrentBalance() {
		return cashOnHand;
	}
	void acceptAmount(int BuyerCash) {
		cashOnHand = cashOnHand + BuyerCash;
	}
};

class dispenserType {
private:
	int numberOfItems;
	int TypeCost;
public:
	dispenserType() {
		numberOfItems = 50;
		TypeCost = 50;
	}
	dispenserType(int BuyerCost, int BuyerItems) {
		numberOfItems = BuyerItems;
		TypeCost = BuyerCost;
	}
	int getNoOfItems() {
		return numberOfItems;
	}
	int getCost() {
		return TypeCost;
	}
	void makeSale() {
		numberOfItems = numberOfItems - 1;
	}

};
void showSelection();
void sellProduct(cashRegister& pCash, dispenserType pDispenser);

void showSelection() {

	cout << "\nHello! Which item you want to choose?" << endl;
	cout << "1. Candy" << endl;
	cout << "2. Chips" << endl;
	cout << "3. Gum" << endl; 
	cout << "4. Cookies" << endl;
	cout << "5. No one. Bye!\n" << endl;

}

void sellProduct(dispenserType& pDispenser, cashRegister& pCash) {

	int ByMoney, ByMoney2;

	if (pDispenser.getNoOfItems() > 0) {
		cout << "\nYou need to give " << pDispenser.getCost() << " money\n" << endl;
		cin >> ByMoney;

		if (ByMoney >= pDispenser.getCost()) {
			pCash.acceptAmount(ByMoney);
			pDispenser.makeSale();
			cout << "\nThe purchase was successful!\n" << endl;

		}
		else if (ByMoney < pDispenser.getCost()) {
			cout << "\nIt is necessary to deposit additional funds in the amount of: " << pDispenser.getCost() - ByMoney << "\n" << endl;
			cin >> ByMoney2;
			ByMoney = ByMoney + ByMoney2;
		}
		else {
			cout << "Insufficient funds" << endl;
		}

	}
	else {
		cout << "Out of stock" << endl;
	}

}

int main(){
	int Item;
	showSelection();
	cin >> Item;

	cashRegister counter;
	dispenserType candy(150, 25);
	dispenserType chips(200, 70);
	dispenserType gum(70, 15);
	dispenserType cookies(90, 150);

	while (Item != 5) {
		switch (Item) {
		case 1:
			sellProduct(candy, counter);
			break;
		case 2:
			sellProduct(chips, counter);
			break;
		case 3:
			sellProduct(gum, counter);
			break;
		case 4:
			sellProduct(cookies, counter);
			break;
		default:
			cout << "NONE" << endl;
		}
		showSelection();
		cin >> Item;
	}

	return 0;
}