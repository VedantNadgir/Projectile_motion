% Read data from the file
data =readtable('projectile_data.txt');

%Extract time, x and y values
time=data.Time;
x=data.X;
y=data.Y;

%Plot the projectile Motion
figure;
plot(x,y,'b-','LineWidth',2);
xlabel('Distance (m)');
ylabel('Height (m)');
title('Projectile Motion');
grid on;

%Save the plot as an image
saveas(gcf,'projectile_motion.png');
set(gcf,'Visible','on');
pause;