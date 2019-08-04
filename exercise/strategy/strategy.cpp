#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <limits>
#include <cmath>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        return b*b - 4*a*c;
    };
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c)override
    {
        double discriminant =  b*b - 4*a*c;
        return discriminant >= 0 ? discriminant : numeric_limits<double>::quiet_NaN();
    };
    
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        complex<double> disc{strategy.calculate_discriminant(a,b,c), 0};
        auto root_disc = sqrt(disc);
        return tuple<complex<double>, complex<double>>{
          (-b+root_disc) / (2*a),
          (-b-root_disc) / (2*a) 
        };
    };

};
