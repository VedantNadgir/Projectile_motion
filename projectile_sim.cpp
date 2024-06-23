#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

const double g=9.81;
const double pi=(22.0/7.0);
int main(){

    cout<<"Projectile Motion Simulator:"<<endl;
    //Declaration of variables and input.
    double v0=0,theta=0;

    cout<<"Enter the inital velocity(m/s): ";
    cin>>v0;
    cout<<"Enter the angle of projection (degrees): ";    
    cin>>theta;
    // Convert angle to radians
    theta = theta*(pi/180.0);

    //Calculate Total time of flight
    double T= (2*v0*sin(theta))/g;
    //Calculate Range
    double R=(pow(v0,2)*sin(2*theta))/g;
    //Calculate Max Height
    double H=(pow((v0*sin(theta)),2))/(2*g);

    ofstream outfile("projectile_data.txt");
    outfile<<"Time\tX\tY\n";
    for(double t=0;t<=T;t+=0.01){
        double x=v0*t*cos(theta);
        double y=(v0*sin(theta)*t)-(0.5*g*t*t);
        outfile<<t<<"\t"<<x<<"\t"<<y<<"\n";
    }
    outfile.close();
    cout<<"Total Time of Flight: "<<T<<" sec"<<endl;
    cout<<"Maximum Height: "<<H<<" m"<<endl;
    cout<<"Total Distance Travelled: "<<R<<" m"<<endl;

    //Run Matlab script
    system("/Applications/MATLAB_R2023b.app/bin/matlab -batch plot_projectile"); //Adjust accordingly as the path location on your local computer.
}
