#ifndef GRAPHICAL_VIEW_H
#define GRAPHICAL_VIEW_H

#include "View.h"
#include <iostream>

class GraphicalView : public View {
public:
    /**
    * @brief A concrete implementation of View for graphical output.
    */
    void displayPrediction(double prediction) override;
};

#endif // GRAPHICAL_VIEW_H
