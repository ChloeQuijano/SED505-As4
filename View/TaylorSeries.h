#ifndef TAYLOR_SERIES_H
#define TAYLOR_SERIES_H

#include <vector>
#include <cmath>
#include <iostream>

class TaylorSeries {
private:
    std::vector<double> weights;
    const double freq = 50.0;
    const int steps = 360;
    const double PI = 3.14159265358979323846;

public:
    TaylorSeries(double frequency, int stepCount)
        : freq(frequency), steps(stepCount) {}

    int train();
    int ErrorAnalysis();
    double predict(const std::vector<double>& data);
};

#endif // TAYLOR_SERIES_H
