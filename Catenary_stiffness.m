% To model the catenary stiffness equation
equation = 'kmean*(1-0.5*cos(0.2093*14*t))';
% Define the range of values for the unknown parameter (time)
t_min = 0;
t_max = 100;
num_of_points = 10;
t_values = linspace(t_min,t_max,num_of_points);
kmean= 2000;
pi = 3.14;
% Using the unknown parameter t, find the vector/matrix values
y_values = kmean*(1-(0.5*cos(0.2093*t_values)));
% Plot the results
plot(t_values, y_values);

xlabel('Time');
ylabel('Catenary stiffness');
title('Catenary stiffness Vs Time');