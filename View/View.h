#ifndef VIEW_H
#define VIEW_H

class View {
public:
    virtual void displayPrediction(double prediction) = 0;
    virtual ~View() {}
};

#endif