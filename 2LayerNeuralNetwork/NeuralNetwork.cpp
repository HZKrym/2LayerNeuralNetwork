#include "NeuralNetwork.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>



NeuralNetwork::NeuralNetwork()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			synapses1[i][j] = rand() % 10 * 0.1;
		}
		synapses2[i] = rand() % 10 * 0.1;
	}
}

void NeuralNetwork::summator() {
	output = 0.0;
	for (int i = 0; i < 2; i++) {
		neurons[1][i] = 0.0;
		for (int j = 0; j < 2; j++) {
			neurons[1][i] += neurons[0][j] * synapses1[j][i];
		}
		if (neurons[1][i] > 0.5) neurons[1][i] = 1.0; else neurons[1][i] = 0.0;
	}
	for (int i = 0; i < 2; i++) {
		output += neurons[1][i] * synapses2[i];
	}
	if (output > 0.5) output = 1.0; else output = 0.0;
}

void NeuralNetwork::test(double gError) {
	system("cls");
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			std::cout << "synapses1[" << j << "][" << k << "] = " << synapses1[j][k] << std::endl;
		}
	}
	for (int j = 0; j < 2; j++) {
		std::cout << "synapses2[" << j << "] = " << synapses2[j] << std::endl;
	}
	std::cout << "gError = " << gError << std::endl;
}

void NeuralNetwork::train() {
	double gError;
	double err[2];
	do {
		gError = 0.0;
		for (int i = 0; i < 4; i++) {
			setInput(tableXOR[i][0], tableXOR[i][1]);
			double localErr = tableXOR[i][2] - output;
			gError += abs(localErr);
			for (int j = 0; j < 2; j++) {
				err[j] = localErr * synapses2[j];
			}
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					synapses1[j][k] += 0.1 * err[k] * neurons[0][j];
				}
			}
			for (int j = 0; j < 2; j++) {
				synapses2[j] = 0.1 * localErr * neurons[1][j];
			}
		}
		test(gError);
	} while (gError != 0);
}

void NeuralNetwork::setInput(double x1, double x2) {
	neurons[0][0] = x1;
	neurons[0][1] = x2;
	summator();
}

double NeuralNetwork::getOutput() {
	return output;
}