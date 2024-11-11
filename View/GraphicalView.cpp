#include "GraphicalView.h"
#include <iostream>

class GraphicalView : public View {
public:
    void displayPrediction(double prediction) override {
        std::cout << "Graphical Prediction: " << prediction << std::endl;
    }
};