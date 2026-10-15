#include "DifferentialDriveRobot.h"
#include <cmath>
DifferentialDriveRobot::DifferentialDriveRobot(double initialX,
            double initialY,
            double initialTheta,
            double trackWidth){
                this->theta = initialTheta;
                this->trackWidth = trackWidth;
                this->x = initialX;
                this->y = initialY;

            }

void DifferentialDriveRobot::updatePose(double vL,double vR, double dt){

    double linearVelocity = (vL + vR)/2;
    double angularVelocity = (vR - vL)/ trackWidth;
    x = x + (linearVelocity * std::cos(theta) * dt);
    y = y + (linearVelocity * std::sin(theta) * dt);
    theta = theta + (angularVelocity * dt);

}

double DifferentialDriveRobot::getX(){
    return x;
}

double DifferentialDriveRobot::getY(){
    return y;
}

double DifferentialDriveRobot::getTheta(){
    return theta;
}