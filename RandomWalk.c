#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double randDoubleRadius()
{
  double MIN=0.0, MAX= 5.0;
  return (MAX-MIN)*(rand()/(RAND_MAX+1.0)) + MIN;
}
double randDoubleDegree()
{
  double MIN=0.0, MAX= 360.0;
  return (MAX-MIN)*(rand()/(RAND_MAX+1.0)) + MIN;
}

void polarToRect(double radius, double theta, double *x, double *y)
{
  *x = *x+radius*cos(theta);
  *y = *y+radius*sin(theta);
}

int main()
{
  int moves;
  double x=0, y=0;
  double distanceFromCenter;

  srand( time(NULL) );
  printf("Enter how many moves for Flavia: ");
  scanf("%d",&moves);

  for (int i=0; i < moves; i++ )
  {
    double r = roundf(randDoubleRadius()*100)/100; //to include 5
    double degree = roundf(randDoubleDegree()*100)/100; //to include 360
    polarToRect(r,degree,&x,&y);
    distanceFromCenter = sqrt(pow(x,2)+pow(y,2)); //Pythagoras Theorem
    printf("\nBug Moves to (%.2lf, %.2lf), distance = %.2lf", x, y, distanceFromCenter);
  }

  if(distanceFromCenter>=10.0)
  {
    printf("\nOh No! The bug escapes.\n");
  }
  else
  {
    printf("\nYUM YUM. Spider eats the bug.\n");
  }

  return 0;
}
