#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Accounts {
private:
	int digitCapacity;
	string operations;

public:
	void setAccounts(int a) {
		this->digitCapacity = a;
	}

	void setOperations(string b) {
		this->operations = b;
	}
protected:
	void display() {
		cout << "Разрядность счетов: " << digitCapacity << endl;
		cout << "Выполняемые операции: " << operations << endl;
	}

	int getDigitCapacity() {
		return digitCapacity;
	}

	string getOperations() {
		return operations;
	}
};

class Calculator : public Accounts {
private:
	double price;

public:
	void setPrice(int a) {
		this->price = a;
	}
protected:
	double getPrice() {
		return price;
	}
};

class Computer : public Calculator {
protected:
	int processorCount;
	double performance;

public:
	void setCount(int a) {
		this->processorCount = a;
	}

	void setPerform(double b) {
		this->performance = b;
	}

	void display() {
		cout << "Разрядность " << getDigitCapacity() << endl;
		cout << "Опреации " << getOperations() << endl;
		cout << "Цена " << getPrice() <<" руб."<< endl;
		cout << "Кол-во процессоров " << processorCount << endl;
		cout << "Быстродействие " << performance << " ГГц" << endl;
	}
};

int main() {
	setlocale(0, "");
	Computer comp;

	comp.setAccounts(64);
	comp.setOperations("+, -, *, /");
	comp.setPrice(49990);
	comp.setCount(6);
	comp.setPerform(3.2);
	comp.display();

	return 0;
}
