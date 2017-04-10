#pragma once
class NeuralNetwork
{
public:
	NeuralNetwork();
	double getOutput();
	void setInput(double x1, double x2);
	void train();
	
private:
	const int SPEEDEDU = 10;
	double tableXOR[4][3] = {
		{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0},{0.0,0.0,0.0}
	};
	double synapses1[2][2];
	double synapses2[2];
	double neurons[2][2];
	double output;
	void summator();
	void test(double gError);
};

