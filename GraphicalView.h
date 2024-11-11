#ifndef GRAPHICAL_VIEW_H
#define GRAPHICAL_VIEW_H

#include "View.h"

class GraphicalView : public View {
public:
    void displayPrediction(double prediction) override;
};

#endif