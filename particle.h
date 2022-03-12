#pragma once


#include "vec.h"

#ifndef PARTICLE
#define PARTICLE

class Particle
{
    Vec3D<double> position;
    Vec3D<double> velocity;
    Vec3D<double> force;
public:
    Particle(Vec3D<double> _position, Vec3D<double> _velocity, Vec3D<double> _force)
        :position(_position),velocity(_velocity),force(_force)
    {};
  
    friend double distance(Particle&, Particle&);

    Vec3D<double>& pos() { return position; }
    const Vec3D<double>& pos() const { return position; }
    Vec3D<double> getPos() const { return position; }
    void setPos(const Vec3D<double>& pos) { position = pos; }

    Vec3D<double>& vel() { return velocity; }
    const Vec3D<double>& vel() const { return velocity; }
    Vec3D<double> getVel() const { return velocity; }
    void setVel(const Vec3D<double>& vel) { velocity = vel; }

    Vec3D<double>& f() { return force; }
    const Vec3D<double>& f() const { return force; }
    Vec3D<double> getF() const { return force; }
    void setF(const Vec3D<double>& f) { force = f; }

};

double distance(Particle& p1, Particle& p2)
{
    double dist = 0;
    Vec3D<double> d = p1.pos() - p2.pos();
    return d.abs();
};

#endif