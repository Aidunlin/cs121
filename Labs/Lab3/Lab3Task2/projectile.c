#include "projectile.h"

/* Gets the angle of elevation from the user */
double get_theta(void)
{
  double theta = 0;
  printf("Enter the angle of elevation (in radians): ");
  scanf("%lf", &theta);
  return theta;
}

/* Gets the distance to the target from the user */
double get_distance(void)
{
  double distance = 0;
  printf("Enter the distance to the target (in feet): ");
  scanf("%lf", &distance);
  return distance;
}

/* Gets the projectile's velocity from the user */
double get_velocity(void)
{
  double velocity = 0;
  printf("Enter the projectile's velocity (in feet/sec): ");
  scanf("%lf", &velocity);
  return velocity;
}

/* Calculates the duration of the projectile's flight */
double calculate_time(double distance, double velocity, double theta)
{
  return distance / (velocity * cos(theta));
}

/* Calculates the height of the impact with the target */
double calculate_height(double velocity, double theta, double time)
{
  return velocity * sin(theta) * time - (G * pow(time, 2)) / 2;
}
