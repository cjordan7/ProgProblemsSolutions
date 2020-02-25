#include <cmath>

using namespace std; 

double areaOfPolygonInsideCircle (double circleRadius , int numberOfSides ) {
  const double PI =  3.14159265 ;
  
  return round(numberOfSides*circleRadius*circleRadius/2*sin(2*PI/numberOfSides)*1000)/1000;
}
