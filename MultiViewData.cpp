#include "TaylorSeries.h"
#include "ConsoleView.h"
#include "GraphicalView.h"
#include "Controller.h"
#include <vector>
#include <cstdlib>

int main() {
    TaylorSeries model(50.0, 360);
    Controller controller(model);

    ConsoleView consoleView;
    GraphicalView graphicalView;

    controller.attachView(&consoleView);
    controller.attachView(&graphicalView);

    if (controller.trainModel()) {
        std::vector<double> inputData;
        for (int i = 0; i < 360; ++i) {
            inputData.push_back(static_cast<double>(rand() % 1000) / 1000);
        }
        controller.predict(inputData);
        controller.displayPredictions();
    }

    controller.detachView(&graphicalView);
    controller.detachView(&consoleView);

    return 0;
}