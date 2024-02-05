% To calculate the catenary displacement
t_min = 0;
t_max = 100;
num_of_points = 100;
t_values = linspace(t_min,t_max,num_of_points);
g = 9.8;
Tc = 10000;
p = 0.95;
% Using the unknown parameter t, find the vector/matrix values
y_values = 5.5 - (0.045*sin(0.01904116*t_values.^2))-(0.01*sin(0.394384*t_values.^2));
% Plot the results
plot(t_values, y_values);
xlabel('Time');
ylabel('Catenary Displacement');
title('Catenary Displacement Vs Time');