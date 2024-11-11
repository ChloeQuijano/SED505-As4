//Masuma Begum
//Chloe Quijano
//Mary-Anne Chinonyelum Ibeh

#include <cstdlib>
#include <ctime>
#include <memory>
#include "Controller.h"
#include "TaylorSeries.h"
#include "ConsoleView.h"
#include "GraphicalView.h"

int main() {
    srand(static_cast<unsigned>(time(NULL)));  // Seed random number generator

    TaylorSeries model(50.0, 360);
    Controller controller(model);

    auto consoleView = std::make_shared<ConsoleView>();
    auto graphicalView = std::make_shared<GraphicalView>();

    controller.attachView(consoleView);
    controller.attachView(graphicalView);


    controller.trainModel();  // Train the model

    const int TRIALS = 5;
    for (int i = 0; i < TRIALS; ++i) {
        const int NUM = 1000;
        std::vector<double> inputData(NUM);

        inputData.clear();  // Clear any existing data
        for (int j = 0; j < NUM; ++j) {
            inputData.push_back(static_cast<double>(rand() % 1000) / 1000.0);//generate a number between 0 and 1
        }
        controller.displayPredictions(inputData);  // Display predictions

        inputData.push_back((double)(rand() % 1000) / 1000);
        std::cout << std::endl;

    }

    return 0;
}
