#include <cmath>
#include <string>
#include "main.h"
#include "json.hpp"
#include "logging.hpp"

using json = nlohmann::json;

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	//Demo of motion profile logging
	double pos = 0;
	double vel = 0;
	double accel = 1;

	//Demo of odometry logging
	double x = 0;
	double y = 0;
	int heading_deg = 0;

	while(true) {
		//Simulate the robot accelerating while moving in a straight line
		vel += accel * 0.01;
		pos += vel * 0.01;
		
		MotionProfile profile{pos, vel, accel};
		FoxgloveMessage profile_message = {"motion_profile", profile};
		std::cout << static_cast<json>(profile_message) << std::flush;

		//Simulate the robot moving in a circle
		heading_deg = std::fmod(heading_deg + 1, 360);
		double heading_rad = heading_deg * M_PI / 180;
		x += std::cos(M_PI_2 - heading_rad);
		y += std::sin(M_PI_2 - heading_rad);

		Odometry odom{x, y, heading_rad};
		// In order to use the 2D VEX panel you *must* name your topic "odometry"
		FoxgloveMessage odom_message = {"odometry", odom};
		std::cout << static_cast<json>(odom_message) << std::flush;		

		pros::delay(10);
	}
}