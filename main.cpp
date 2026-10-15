#include "DifferentialDriveRobot.h"
#include <iostream>

int main(){

    DifferentialDriveRobot robot(0.0, 0.0, 0.0, 0.5);
    robot.updatePose(1.0,1.0,1.0);
    std::cout << "X: " <<  robot.getX() << std::endl << "Y: " <<  robot.getY() << std::endl << "Theta: "<< robot.getTheta();

    return 0;
}