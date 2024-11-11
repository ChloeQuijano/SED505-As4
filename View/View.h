#ifndef VIEW_H
#define VIEW_H

/**
 * @brief Interface for display components that can output predictions.
 */

class View {
public:

    /**
     * @brief Display a prediction.
     *
     * @param prediction The predicted value to display.
     */

    virtual void displayPrediction(double prediction) = 0;
    virtual ~View() {}
};

#endif