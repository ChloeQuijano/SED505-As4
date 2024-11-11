#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "View.h"
#include <iostream>

class ConsoleView : public View {
public:

    /**
    * @brief A concrete implementation of View for console output.
    */
    void displayPrediction(double prediction) override;
};

#endif // CONSOLE_VIEW_H
