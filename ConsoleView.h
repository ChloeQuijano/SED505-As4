#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "View.h"

class ConsoleView : public View {
public:
    void displayPrediction(double prediction) override;
};

#endif