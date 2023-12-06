#include "Complex.h"
using namespace std;

void Complex::calculate_polar()
{
    mag = sqrt(real * real + imag * imag);
    theta = atan(imag / real);
    polar = true;
}

void Complex::calculate_cartesian()
{
    assert(polar == true);
    real = mag * cos(theta);
    imag = mag * sin(theta);
    // I added a "polar = false"
    polar = false;
}

Complex::Complex() {
    mag = 0; theta = 0;
    polar = true;
}

Complex::Complex(double m, double t) {
    // cartesian
    mag = m; theta = t;
    polar = true;
    calculate_cartesian();
}

Complex::Complex(double m, double t, Flag) {
    // polar
    mag = m; theta = t;
    polar = true;
}

bool Complex::get_polar() 
{
    return polar;
}

double Complex::get_real()
{
    return real;
}

double Complex::get_imag()
{
    return imag;
}

double Complex::get_mag()
{
    if (polar == false) calculate_polar();
    return mag;
}

double Complex::get_theta()
{
    if (polar == false) calculate_polar();
    return theta;
}

Complex Complex::operator + (const Complex& c)
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator * (Complex& c)
{
    if (polar == false) calculate_polar();
    if (c.polar == false) c.calculate_polar();
    return Complex(mag * c.mag, theta + c.theta, POLAR);
}

Complex Complex::operator - (const Complex& c) 
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator / (Complex& c) 
{
    if (polar == false) calculate_polar();
    if (c.polar == false) c.calculate_polar();
    return Complex(mag / c.mag, theta - c.theta, POLAR);
}

Complex Complex::abs() 
{
    if (polar) {
        return Complex(std::abs(mag), std::abs(theta));
        
    }
    else {
        return Complex(std::abs(real), std::abs(imag), POLAR);

    }
}

string Complex::str_cartesian()
{
    return to_string(get_real()) + " + " + to_string(get_imag()) + "i";
}

string Complex::str_polar()
{
    string theta = to_string(get_theta());
    string mag = to_string(get_mag());
    return mag  + "e^" + theta + "i";
}

ostream& operator<<(ostream& os, Complex& c)
{
    if (c.get_polar()) {
        os << c.str_polar();
    }
    else {
        os << c.str_cartesian();
    }
    return os;
}