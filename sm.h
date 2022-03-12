#pragma once

#ifndef _SIMULATION_H
#define _SIMULATION_H

#include <random>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <omp.h>
#include "vec.h"
#include "particle.h"
#include "pot.h"



class LJSimulation
{
    int number_of_particles=3;//now 3
    const int mass = 1;//let it be 1 
    Particle* particles;
    LJPotential LJpot;
    Vec3D<double> torque;
    double time_div;    
    double energy;
    Vec3D<double> force_moment;
public:
    LJSimulation(Particle* _particles,double _time_div=0.1) :particles(_particles),time_div(_time_div) {};
    Vec3D<double> find_force_for_1_particle(int);
    void move_time_div();
    Vec3D<double> find_force_moment();
    double find_energy_of_the_system();
      
}

Vec3D<double> LJSimulation::find_force_for_1_particle(int particle_num) {
    Vec3D<double> ma;
    for (int i = 0; i < number_of_particles && i != particle_num; i++) {
        double U = LJpot((particles[particle_num].pos() - particles[i].pos()).abs());
        double r = (particles[particle_num].pos() - particles[i].pos()).abs();
        ma += U*r;
    }
     return ma;
};

double LJSimulation::find_energy_of_the_system() {
    double KE=0;
    double PE=0;
    for (int i = 0; i < number_of_particles; i++)
        KE += mass * (particles[i].getVel().abs()) * (particles[i].getVel().abs()) / 2;
    for (int i = 0; i < number_of_particles; i++)
        for (int j = i; j < number_of_particles; j++)
        PE+=mass* LJpot((particles[i].pos() - particles[j].pos()).abs());
    return KE + PE;
};

Vec3D<double> LJSimulation::find_force_moment() {
    Vec3D<double>ans;
    for (int i = 0; i < number_of_particles; i++)
        ans += (particles[i].getF()).cross(particles[i].getPos());
    return ans;
};

void LJSimulation::move_time_div() {
    for (int i = 0; i < number_of_particles; i++) {
        particles[i].setF(particles->getF() + find_force_for_1_particle(i));
        particles[i].setVel(particles->getVel() + particles->getF() * time_div / mass);
        particles[i].setPos(particles->getPos() + particles->getVel() * time_div);
    }
    energy = find_energy_of_the_system();
    force_moment = find_force_moment();
};

#endif