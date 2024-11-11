#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <string>

class View {
public:
    virtual void displayWeights(const std::vector<double>& weights) = 0;
    virtual void displayMessage(const std::string& message) = 0;
    virtual ~View() {}
};

#endif