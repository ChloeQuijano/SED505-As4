#include "TaylorSeries.h"
#include "ConsoleView.h"
#include "GraphicalView.h"
#include "Controller.h"
#include <vector>
#include <cstdlib>

int main() {
    TaylorSeries model(50.0, 360);
    ConsoleView consoleView;
    GraphicalView graphicalView;

    Controller consoleController(model, consoleView);
    Controller graphicalController(model, graphicalView);

    // Generate random input data
    std::vector<double> inputData;
    for (int i = 0; i < 360; ++i) {
        inputData.push_back(static_cast<double>(rand() % 1000) / 1000);
    }

    // Use ConsoleView
    consoleController.execute(inputData);

    // Use GraphicalView
    graphicalController.execute(inputData);

    return 0;
}