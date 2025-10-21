#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	string filename;

	cout << "Введите имя файла: ";
	getline(cin, filename);

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Не удалось открыть файл." << endl;
		return 1;
	}

	string line;
	int count = 0;

	while (getline(file, line)) {
		int spaces = 0;
		for (char c : line) {
			if (c == ' ' || c == '\t') {
				spaces++;
			}
		}
		if (spaces <= 3) {
			count++;
			cout << line << endl;
		}
	}

	cout << "Количество строк с не более чем тремя пустыми символами: " << count << endl;
	file.close();

	return 0;
}