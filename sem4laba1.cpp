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

void sellProduct(dispenserType& pDispenser, cashRegister& pCash) {

	int ByMoney, ByMoney2;

	if (pDispenser.getNoOfItems() > 0) {
		cout << "\nYou need to give " << pDispenser.getCost() << " money\n" << endl;
		cin >> ByMoney;

		if (ByMoney < pDispenser.getCost()) {
			cout << "\nIt is necessary to deposit additional funds in the amount of: " << pDispenser.getCost() - ByMoney << "\n" << endl;
			cin >> ByMoney2;
			ByMoney = ByMoney + ByMoney2;
		}

		if (ByMoney > pDispenser.getCost()) {
			pCash.acceptAmount(pDispenser.getCost());
			pDispenser.makeSale();
			cout << "\nYou have some change left: " <<ByMoney - pDispenser.getCost() << "\n" << endl;

		}

		if (ByMoney == pDispenser.getCost()) {
			pCash.acceptAmount(ByMoney);
			pDispenser.makeSale();
			cout << "\nThe purchase was successful!\n" << endl;

		}

		if (ByMoney < pDispenser.getCost()) {
			cout << "\nYou didn't have enough money to buy again. Choose something else." << "\n" << endl;
		}

	}
	else {
		cout << "Out of stock" << endl;
	}

}

int main(){
	cashRegister counter;
	int Item;
	Item = 1;

	dispenserType candy(150, 25);
	dispenserType chips(200, 70);
	dispenserType gum(70, 15);
	dispenserType cookies(90, 150);

	cout << "Hi! Welcome to the candy store. We have candy, chips, gum and coookies" << endl;

	while ((Item >= 1) and (Item < 5)) {

		cout << "\nHere are our prices and the rest in the store:" << endl;
		cout << "1. Candy. The cost is " << candy.getCost() << " and the rest in the store: " << candy.getNoOfItems() << endl;
		cout << "2. Chips. The cost is " << chips.getCost() << " and the rest in the store: " << chips.getNoOfItems() << endl;
		cout << "3. Gum. The cost is " << gum.getCost() << " and the rest in the store: " << gum.getNoOfItems() << endl;
		cout << "4. Cookies. The cost is " << cookies.getCost() << " and the rest in the store: " << cookies.getNoOfItems() << endl;
		cout << "5. No one. Bye!\n" << endl;
		//password is "123456"
		cout << "If you are the owner of the store, enter the password to find out the cash at the checkout: " << endl;

		cin >> Item;

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
		case 5:
			cout << "\nBye-Bye!" << endl;
			break;
		case 123456:
			cout << "\nThe amount in the cash register is: " << counter.getCurrentBalance() << endl;
			Item = 1;
			break;
		default:
			cout << "\nSelect the item again.\n" << endl;

			cin >> Item;
		}

	}

	return 0;
}
