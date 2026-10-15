# Differential Drive Robot Model

A C++ implementation of a differential-drive robot kinematic model for a 2D autonomous mobile robot.

This component models the motion of a differential-drive robot using left and right wheel velocities and updates the robot's 2D pose `(x, y, theta)` over time.

## Overview

A differential-drive robot controls its motion using independently driven left and right wheels.

The robot pose is represented as:

- `x` – position along the world X-axis
- `y` – position along the world Y-axis
- `theta` – robot orientation in radians

The physical robot model also contains:

- `trackWidth` – distance between the left and right wheels

The motion model receives:

- `vL` – left wheel linear velocity
- `vR` – right wheel linear velocity
- `dt` – elapsed time

and updates the robot pose.

## Differential Drive Kinematics

The robot's linear velocity is calculated as:

```text
v = (vL + vR) / 2
```

The angular velocity is:

```text
omega = (vR - vL) / trackWidth
```

The pose is updated using:

```text
x_new     = x + v * cos(theta) * dt
y_new     = y + v * sin(theta) * dt
theta_new = theta + omega * dt
```

## Project Structure

```text
DifferentialDriveRobot/
│
├── DifferentialDriveRobot.h
├── DifferentialDriveRobot.cpp
├── main.cpp
└── README.md
```

### DifferentialDriveRobot.h

Defines the `DifferentialDriveRobot` class and its public interface.

The class maintains the robot's:

- Position
- Orientation
- Track width

It provides:

- A constructor for initializing the robot
- `updatePose()` for updating robot motion
- Getter functions for reading the current pose

### DifferentialDriveRobot.cpp

Implements the differential-drive kinematic equations and pose update logic.

### main.cpp

Provides a simple test program that:

1. Creates a differential-drive robot
2. Provides left and right wheel velocities
3. Updates the robot pose
4. Reads the resulting pose
5. Prints the result

## Example

Initial robot state:

```text
x = 0 m
y = 0 m
theta = 0 rad
trackWidth = 0.5 m
```

Wheel commands:

```text
vL = 1 m/s
vR = 1 m/s
dt = 1 s
```

Result:

```text
X: 1
Y: 0
Theta: 0
```

The equal wheel velocities cause the robot to move straight forward along the positive X-axis.

## Role in the Autonomous Robot Project

This repository represents the robot motion-model component of a larger 2D autonomous mobile robot project.

The overall system is being developed as separate components including:

```text
Path Planning
      ↓
Motion Control
      ↓
Differential Drive Robot Model
      ↓
Robot Pose
```

A separate A* path-planning component generates collision-free paths through a 2D environment. Future development will integrate path planning, robot motion, localization, mapping, and motion control.

## Current Status

Implemented:

- Differential-drive robot class
- Robot pose `(x, y, theta)`
- Configurable track width
- Linear velocity calculation
- Angular velocity calculation
- Discrete pose update
- Pose getter functions
- Basic straight-line motion test

The project is under active development as part of a larger autonomous mobile robotics learning and development project.

## Technologies

- C++
- Differential-drive kinematics
- Object-oriented programming
- Git / GitHub
