#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "View.h"

class ConsoleView : public View {
public:
    void displayWeights(const std::vector<double>& weights) override;
    void displayMessage(const std::string& message) override;
};

#endif