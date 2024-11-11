# SED505-As4

## Introduction
For this assignment you will train a data model and make predictions based on this model. The model is based on the Taylor Series representation of a sine wave. The predictions will be displayed in multiple view, which in this case are a console view and a graphical view.

## Design Considerations
There is a design pattern built for machine learning that suits the hosting of multiple views. You have to research this design pattern and use it in your assignment. You do not have to follow the design pattern if you do not wish to, but you must justify your reasons for doing so.

**TODO:** After you have decided on a design pattern, be sure to draw a UML diagram to show how you plan to approach this problem.

Although C++ is the only appropriate language for this assignment, you can write your code in one of the following four languages: C++, C#, Java or Python. Also keep in mind that at least one of your assignments has to be written in Java and at least one in C#.

## The Components
There are two major components to this assignment: the machine learning data model and the viewing of the data. Each component can be broken into sub-components.

The Machine Learning Data Model
The machine learning data model consists of two parts: the training of the model, and the predictor. For the purposes of this assignment, the training of the weights of the model are based on a sine wave. There are two builds for the data model: a test build where you can see debug print's as your code is running, and a release build where the debug print's are disabled. The customer will get the release build. The goal is that the training model will reside on a small device that is limited in memory, therefore a reduced instruction set will be used to save space. This reduced instruction set purposefully excludes the maths library, therefore the sine wave used in the training has to be approximated by a Taylor Series.

The Taylor Series is a mathematical model that attempts to approximate mathematical functions through a series of polynomials. See Taylor's Series of sinx for the mathematical derivation of a Taylor Series that approximates a sine wave. As you can see from the derivation, the Taylor Series for a sin wave is as follows:
sinx = x - x3/3! + x5/5! - x7/7! + x9/9! . . .

Standard deviation is a measure of how close actual data is to the true data. It calculates the sum of the squares of this difference for all data points, divides this by the number of data points, and then takes the square root of this number. See Variance and Standard Deviation. For our case, the standard deviation will be calculated from the difference between our approximated sine wave and an actual sine for n data points:
Std Dev = sqrt( sum(estimate-true)2/(n-1)).

Code has been given to you that attempts to approximate a sine wave with a Taylor Series. The standard deviation is found for the approximation, and if the standard deviation is below a tolerance, the approximation is accepted. If not, the Taylor Series is expanded by one. See:
C++: MathUtils.cpp,

For instance, the Taylor Series for the sine wave is initially given as:
sinx = x.

Most likely the standard deviation will be well off the tolerance. Therefore expand this series to:
sinx = x - x3/3!.

The standard deviation for this approximation probably will not meet the tolerance threshold therefore the series might have to be expanded to:
sinx = x - x3/3! + x5/5!.

**TODO:** You will have to modify the train() function in MathUtils.cpp to continue this expansion continues until the tolerance threshold is met.

## The Views
There are two view in this assignment: console view and graphical view. There is no time to set up a proper console view or a proper graphical view, so for displaying the prediction, please have each simply print out:
std::cout << "Console Prediction: " << prediction << std::endl; or
std::cout << "Graphical Prediction: " << prediction << std::endl;

MultiView Data Main Function and Other Classes
You should have some kind of intermediary class that attaches and detaches a view, that somehow calls a display prediction function, and somehow trains the model.

**TODO:** Your main function will set everything up, generate some random data, make a prediction, and display the results on all the views. It will do this five times. Skeleton code for the main function can be seen at:
C++: MultiViewData.cpp,

Test Program
A sample run might look as follows:

stdDev: 0.222223
ERROR: The training model is inaccurate!

stdDev: 0.0229135
ERROR: The training model is inaccurate!

stdDev: 0.00117588
ERROR: The training model is inaccurate!

The training model is accurate.

Console Prediction: 3.94557
Graphical Prediction: 3.94557

Console Prediction: -2.73723
Graphical Prediction: -2.73723

Console Prediction: 3.29787
Graphical Prediction: 3.29787

Console Prediction: 0.801149
Graphical Prediction: 0.801149

Console Prediction: 2.27915
Graphical Prediction: 2.27915

## Questions
[Questions](questions.md)

