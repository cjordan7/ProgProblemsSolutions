#Calculate the area of a regular n sides polygon inside a circle of radius r

from math import pi
from math import sin

def area_of_polygon_inside_circle(circle_radius, number_of_sides):
    return round(number_of_sides*(circle_radius**2) * sin(2*pi / number_of_sides)/2, 3)
