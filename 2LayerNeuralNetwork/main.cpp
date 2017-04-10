#include "NeuralNetwork.h"
#include <iostream>
#include <conio.h>



using namespace std;

int main() {
	double n1, n2;
	NeuralNetwork objXOR;
	objXOR.train();
	cout << "Ready!" << endl;
	for (int i = 0; i < 4; i++) {
		cin >> n1;
		cin >> n2;
		objXOR.setInput(n1, n2);
		cout << "Result: " << objXOR.getOutput() << endl;
	}

	getch();
}