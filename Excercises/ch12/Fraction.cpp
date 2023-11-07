#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

void Fraction::simplify() {
    for(int i = 2; i < max(numerator,denominator); i++) {
        if(! (numerator % i || numerator % i)) {
            numerator /= i;
            denominator /= i;
            break;
        }
    }
}

string Fraction::to_string() const {
    int b = max(numerator,denominator);
    string c = "";
    while (b != 0) {
        b  = int(b/10);
        c += '-';
    }
    if(denominator != 1) {
        return std::to_string(numerator) + "\n" + c + "\n" + std::to_string(denominator) + "\n";
    }
    else {
        return std::to_string(numerator) + "\n" + c + "\n1\n";
    }
}

void Fraction::plus(Fraction frac) {
    if(frac.denominator != denominator) {
        numerator *= frac.denominator;
        frac.numerator *= denominator;
        denominator *= frac.denominator;
    }

    numerator += frac.numerator;
    simplify();
}

void Fraction::minus(Fraction frac) {
    if(frac.denominator != denominator) {
        numerator *= frac.denominator;
        frac.numerator *= denominator;
        denominator *= frac.denominator;
    }

    numerator -= frac.numerator;
    simplify();
}

void Fraction::times(Fraction frac) {
    denominator *= frac.denominator;
    numerator *= frac.numerator;
    simplify();
}

void Fraction::divided_by(Fraction frac) {
    int t = frac.denominator;
    frac.denominator = frac.numerator;
    frac.numerator = t;
    times(frac);
}