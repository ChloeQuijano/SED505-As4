
#include "TaylorSeries.h"

int TaylorSeries::train() {
	const double w = 2.0 * PI * freq;//w=2*pi*frequency
	const double P = 1.0 / freq;//the period
	double time;//from time=0 to time=P, divided into steps
	int maxTerms = 10; // set max to avoid infinite loop
	int currentTerm = 1; // keep track of the current term in the Taylor Series


	while (true) {
		weights.assign(steps, 0.0); //initialize the weights to zero

		//Generate the first quarter of the sine wave
		for (int i = 0; i <= steps / 4; ++i) {
			time = P * (double)i / steps;//from 0 to P seconds
			double x = w * time;
			double term = x;
			double approxSine = term;

			// compute the Taylor Series for sine
			for (int n = 1; n < currentTerm; ++n) {
				term *= -x * x / ((2 * n + 1) * (2 * n)); // compute the next term
				approxSine += term;
			}

			weights[i] = approxSine; // assign the weight

#ifdef TEST_BUILD//define TEST_BUILD to visually see the accuracy of the Taylor Series
			std::cout.precision(6);
			std::cout.setf(std::ios::fixed);
			double trueValue = sin(x);
			std::cout << "i: " << i << " time: " << time << " weights:" << weights[i] << " trueValue: " << trueValue << std::endl;
#endif
		}

		//Generate the second quarter of the sine wave from the first quarter
		for (int i = steps / 4; i < steps / 2; ++i) {
			weights[i] = weights[steps / 2 - i];
		}

		//Generate the second half of the sine wave from the first half
		for (int i = steps / 2; i < steps; ++i) {
			weights[i] = -weights[i - steps / 2];
		}

		// Check the accuracy of the model
		if (ErrorAnalysis() == 0) {
			return 0; // success = exit the loop
		}

		// If the model is inaccurate, try again with a higher number of steps
		++currentTerm;
		if (currentTerm > maxTerms) {
			std::cout << "ERROR: Reached the maximum terms without meeting tolerance!" << std::endl << std::endl;
			return -1;
		}
	}
}

int TaylorSeries::ErrorAnalysis() {
	double stdDev = 0.0;
	const double TOLERANCE = 0.001;
	int retVal = 0;
	const double w = 2.0 * PI * freq;
	const double P = 1.0 / freq;//the period
	double diffSum = 0.0;
	for (int i = 0; i < steps; ++i) {
		double time = P * (double)i / steps;
		double trueValue = sin(w * time);
		diffSum += (weights[i] - trueValue) * (weights[i] - trueValue);
	}
	stdDev = sqrt(diffSum / (steps - 1));
	if (stdDev > TOLERANCE) {
		std::cout << std::endl << "stdDev: " << stdDev << std::endl;
		std::cout << "ERROR: The training model is inaccurate!" << std::endl << std::endl;
		retVal = -1;
	}
	else {
		std::cout << "The training model is accurate." << std::endl << std::endl;
	}
	return retVal;
}

double TaylorSeries::predict(const std::vector<double>& data) {
    double prediction = 0.0;
    for (size_t i = 0; i < data.size() && i < weights.size(); ++i) {
        prediction += weights[i] * data[i];
    }
    return prediction;
}
