#ifndef TAYLOR_SERIES_H
#define TAYLOR_SERIES_H

#include <vector>

class TaylorSeries {
private:
    std::vector<double> weights;
    double freq;
    int steps;
    const double PI;

public:
    TaylorSeries(double frequency, int stepCount);

    int train();
    double predict(const std::vector<double>& inputData);
    int errorAnalysis();
};

#endif