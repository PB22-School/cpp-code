#include "string"

struct Fraction {
    int numerator, denominator;

    void plus(Fraction);
    void minus(Fraction);
    void times(Fraction);
    void divided_by(Fraction);
    void simplify();

    std::string to_string() const;

    Fraction();
    Fraction(int, int);
};