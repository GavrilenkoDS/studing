#pragma once

#ifndef _LJPOTENTIAL_H
#define _LJPOTENTIAL_H

class LJPotential
{
private:
    double _epsilon;
    double _sigma;
public:
    LJPotential(double epsilon = 5.9, double sigma = 3.57) : _epsilon(epsilon), _sigma(sigma)
    {
        // use atomic units so hbar is 1
        _epsilon /= 1000. * 27.211385; //meV converted to Hartrees
        _sigma /= 0.52917721092; // Angstroms converted to Bohrs
    };

    double operator()(double dist) const
    {
        const double rhor = _sigma / dist;

        return _epsilon * (pow(rhor, 12.) - 2. * pow(rhor, 6.));
    }

    double calc(double dist) {
        const double rhor = _sigma / dist;

        return _epsilon * (pow(rhor, 12.) - 2. * pow(rhor, 6.));
    }

    void set_epsilon(double epsilon) { _epsilon = epsilon; }
    double get_epsilon() const { return _epsilon; }
    void set_sigma(double sigma) { _sigma = sigma; }
    double get_sigma() const { return _sigma; }
    double getEpsilon() const { return _epsilon; }
    double getRho() const { return _sigma; }
};

#endif