#include "projectile.h"

int main(void)
{
  printf("TASK 2: Projectile math\n");

  double theta = get_theta();
  double distance = get_distance();
  double velocity = get_velocity();
  double time = calculate_time(distance, velocity, theta);
  double height = calculate_height(velocity, theta, time);

  printf("Projectile flight duration: %.2lf sec\n", time);
  printf("Target impact height: %.2lf ft\n", height);

  return 0;
}
