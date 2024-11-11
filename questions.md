# Questions
1. Why should this code be written in C/C++ only? Why not Java, C# or Python?

C/C++ is the most appropriate language due to its superior performance, runtime capabilities, and control over system resources compared to other languages. In terms of performance, C/C++ offers fine-grained control over memory and system resources, making it ideal for the development of highly efficient code, especially in smaller environments with limited memory and processing power. Additionally, C/C++ code compiles directly into machine code, making it the fastest choice for real-time calculations, such as the Taylor Series, in contrast to other languages that rely on virtual machines (Java and C#) or interpreters (Python). This lack of runtime overhead in C/C++ applications supports efficient memory management, reducing runtime resource consumption. This makes C/C++ more suitable than Java, C#, or Python for devices with stricter memory constraints. Furthermore, the mathematical computations required for this code benefit from C/C++'s ability to implement custom calculations without relying on external math libraries. This direct implementation of the sine wave function at a low level reduces code size, unlike Java, C#, and Python, which depend on math libraries, introducing additional overhead and making them impractical for constrained environments.

2. Name two other possible common usages for this design pattern.

- Web Application: The MVC pattern is widely used in web development frameworks. This is where the Model handles any interactions with a database, the View would be the front end displaying HTML and user interfaces and the Controller manages the user inputs and orchestrates communication between the Model and View.
- GUI Applications on the Desktop: For example, applications like a text editor or drawing tool would have a Model that manages data within (example: document content or the shapes being drawn), the View will render the user interface and the Controller processes the user interactions (example: mouse clicks, keystrokes).

3. What might cause a test build to behave differently from a release build?
4. Did you use interface classes for all components in this assignment? If not, why?
