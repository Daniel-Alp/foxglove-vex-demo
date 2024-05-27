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
	double position = 0;
	double velocity = 0;
	double acceleration = 1;

	while(true) {
		velocity += acceleration * 0.01;
		position += velocity * 0.01;
		
		MotionProfile motion_profile{position, velocity, acceleration};
		FoxgloveMessage message = {"motion_profile", motion_profile};
		json j = message;

		std::cout << j << std::flush;

		pros::delay(10);
	}
}