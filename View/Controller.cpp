#include "Controller.h"
#include <algorithm>

Controller::Controller(TaylorSeries& m) : model(m) {}

void Controller::attachView(std::shared_ptr<View> view) {
    views.push_back(view);
}

void Controller::detachView(std::shared_ptr<View> view) {
    views.erase(std::remove(views.begin(), views.end(), view), views.end());
}

void Controller::trainModel() {
    model.train();
}

void Controller::displayPredictions(const std::vector<double>& inputData) {
    double prediction = model.predict(inputData);
    for (auto& view : views) {
        view->displayPrediction(prediction);
    }
}

