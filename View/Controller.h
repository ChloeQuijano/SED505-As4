#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include "TaylorSeries.h"
#include <memory>
#include <vector>

/**
 * @brief Manages interactions between the model (TaylorSeries) and views.
 * This controller handles model training, predictions, and updating views.
 */
class Controller {
private:
    TaylorSeries& model; // Reference to the TaylorSeries model
    std::vector<std::shared_ptr<View>> views; // Container for views

public:
 
    //brief Construct a new Controller object
    Controller(TaylorSeries& m);

    //brief Attach a view to the controller.
    void attachView(std::shared_ptr<View> view);

    //brief Detach a view from the controller.
    void detachView(std::shared_ptr<View> view);

    //Initiate model training via the TaylorSeries model.
    void trainModel();

    //Display predictions on all attached views.
    void displayPredictions(const std::vector<double>& inputData);
};

#endif // CONTROLLER_H
