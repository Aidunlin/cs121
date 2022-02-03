#ifndef PROJECTILE_H
#define PROJECTILE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define G 32.17

/* Gets the angle of elevation from the user */
double get_theta(void);

/* Gets the distance to the target from the user */
double get_distance(void);

/* Gets the projectile' velocity from the user */
double get_velocity(void);

/* Calculates the duration of the projectile's flight */
double calculate_time(double distance, double velocity, double theta);

/* Calculates the height of the impact with the target */
double calculate_height(double velocity, double theta, double time);

#endif
