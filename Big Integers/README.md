# Big Integers library

_Work in progress. May be unstable. Partially untested._

Currently stable:
- Constructors
    - Constructor with default value (= 0)
    
    - Constructor with given value (as string)
        (string starting with minus sign will be automatically detected and parsed correctly)

    - Constructor with given value (as string, sign given)
        (note: the given sign will override the sign detected from string, if any)
        
    - Constructor with given value (as `long long int`)
- Helper functions
    - Converting to `std::string` (directly or through an aliasing function)
    - Setting values through `std::string`
    - Setting & retrieving `negative` bit (in `bool` or in `char`)
    - Assignment operator (instead of setting values and signs each time, increasing complexity)


Work in progress:
- Arithmetic oprations
    - Addition
    - Subtraction