#include "ConsoleView.h"
#include <iostream>

class ConsoleView : public View {
public:
    void displayPrediction(double prediction) override {
        std::cout << "Console Prediction: " << prediction << std::endl;
    }
};

