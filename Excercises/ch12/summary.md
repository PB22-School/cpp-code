# Member Functions

## Properties:

- Can be transfered to and from "free standing functions", which are just functions that don't belong to a struct.
- Member functions are named {Class Name}::{function Name}().
- Member functions need to be referenced in a struct definition.
- Variables can be called without dot notation, so "cName.variable" becomes "variable".
- Member functions can make a process more optimized, but sometimes it's still better to use a free standing function.
- If a member function only reads the values in a struct, you can define it as a "const".  You do this by putting the "const" keyword before the curly brackets and after the function inputs.
- Member functions can and usually do make code more readable.
- You can define a struct's constructor (the function that is called when an instance of a struct is made), by defining a function like {className}::{className}(), with no return type.
- You can initialize a struct by doing {class Name} {variableName}(inputs);

## Header Files

- Header files are used to store structure definitions
- Usually named after the struct it defines

## Implementation Files

- Used to define functions referenced in the header file
- You need to #include your header file.

## Main Files

- Used to run code with previously defined structs.
- You need to #include your header file.