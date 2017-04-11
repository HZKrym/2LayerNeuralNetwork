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
			synapses1[i][j] = rand() % 9 * 0.1 + 0.1;
		}
		synapses2[i] = rand() % 9 * 0.1 + 0.1;
	}
}

void NeuralNetwork::summator() {
	output = 0.0;
	for (int i = 0; i < 2; i++) {
		hidden[i] = 0.0;
		for (int j = 0; j < 2; j++) {
			hidden[i] += inputs[j] * synapses1[j][i];
		}
		hidden[i] > 0.5 ? hidden[i] = 1.0 : hidden[i] = 0.0;
	}
	for (int i = 0; i < 2; i++) {
		output += hidden[i] * synapses2[i];
	}
	output > 0.5 ? output = 1.0 : output = 0.0;
}

void NeuralNetwork::train() {
	double gError = 0;
	double err[2];
	do {
		gError = 0;
		for (int i = 0; i < 4; i++) {
			setInput(tableXOR[i][0], tableXOR[i][1]);
			double localErr = tableXOR[i][2] - output;
			gError += abs(localErr);		
			
			for (int j = 0; j < 2; j++) {
				err[j] = localErr * synapses2[j];
			}
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					synapses1[j][k] += 0.1 * err[j] * inputs[k];
				}
			}
			for (int j = 0; j < 2; j++) {
				synapses2[j] += 0.1 * localErr * hidden[j];
			}
		}
	} while (gError != 0);
}

void NeuralNetwork::setInput(double x1, double x2) {
	inputs[0] = x1;
	inputs[1] = x2;
	summator();
}

double NeuralNetwork::getOutput() {
	return output;
}