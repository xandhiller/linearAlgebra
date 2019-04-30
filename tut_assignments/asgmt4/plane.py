#   from sympy import symbols, cos, sin
#   from sympy.plotting import plot3d_parametric_surface
#   t = symbols('t')
#
#
#   p = plot3d_parametric_surface(t, t, 2*t, (t, -10, 10))
#   p.show()

from sympy import symbols, cos, sin
from sympy.plotting import plot3d_parametric_surface
u, v = symbols('u v')

plot3d_parametric_surface( u, v, 2*u, 
                          (u, -5, 5), 
                          (v, -5, 5), 
                          axis=True)
