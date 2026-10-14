#ifndef DIFFERENTIALDRIVEROBOT_H
#define DIFFERENTIALDRIVEROBOT_H

class DifferentialDriveRobot
{
    private:

        double theta;
        double x;
        double y;
        double trackWidth;

    public:
        void updatePose(double vL,double vR, double dt);
        DifferentialDriveRobot(
            double initialX,
            double initialY,
            double initialTheta,
            double trackWidth
        );

};

#endif