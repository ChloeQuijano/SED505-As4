#include "TaylorSeries.h"
#include <cmath>
#include <iostream>

TaylorSeries::TaylorSeries(double frequency, int stepCount)
    : freq(frequency), steps(stepCount), PI(3.141592653589793238) {
    weights.resize(steps);
}

int TaylorSeries::train() {
    const double w = 2.0 * PI * freq;
    const double P = 1.0 / freq;
    double time;
    int maxTerms = 10;
    int currentTerm = 1;

    while (true) {
        weights.assign(steps, 0.0);

        for (int i = 0; i <= steps / 4; ++i) {
            time = P * (double)i / steps;
            double x = w * time;

            double term = x;
            double approxSine = term;

            for (int n = 1; n < currentTerm; ++n) {
                term *= -x * x / ((2 * n + 1) * (2 * n));
                approxSine += term;
            }

            weights[i] = approxSine;
        }

        for (int i = steps / 4; i < steps / 2; ++i) {
            weights[i] = weights[steps / 2 - i];
        }

        for (int i = steps / 2; i < steps; ++i) {
            weights[i] = -weights[i - steps / 2];
        }

        if (errorAnalysis() == 0) {
            return 0;
        }

        ++currentTerm;
        if (currentTerm > maxTerms) {
            std::cout << "ERROR: Reached the maximum terms without meeting tolerance!" << std::endl;
            return -1;
        }
    }
}

int TaylorSeries::errorAnalysis() {
    double stdDev = 0.0;
    const double TOLERANCE = 0.001;
    int retVal = 0;
    const double w = 2.0 * PI * freq;
    const double P = 1.0 / freq;
    double diffSum = 0.0;

    for (int i = 0; i < steps; ++i) {
        double time = P * (double)i / steps;
        double trueValue = sin(w * time);
        diffSum += (weights[i] - trueValue) * (weights[i] - trueValue);
    }
    stdDev = sqrt(diffSum / (steps - 1));
    if (stdDev > TOLERANCE) {
        std::cout << "ERROR: The training model is inaccurate! StdDev: " << stdDev << std::endl;
        retVal = -1;
    } else {
        std::cout << "The training model is accurate." << std::endl;
    }
    return retVal;
}

const std::vector<double>& TaylorSeries::getWeights() const {
    return weights;
}