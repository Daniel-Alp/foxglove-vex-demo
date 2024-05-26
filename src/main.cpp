#include "main.h"
#include "json.hpp"
#include "globals.hpp"
#include "logging.hpp"

using json = nlohmann::json;

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	double position = 0;
	double velocity = 0;
	double acceleration = 2;

	double i = 0;
	while(true) {
		velocity += acceleration * LOOP_DELAY_SEC;
		position += velocity * LOOP_DELAY_SEC;

		MotionProfile motion_profile{position, velocity, acceleration};
		json j = motion_profile;

		std::cout << j << std::endl;
		
		pros::delay(LOOP_DELAY_MS);
	}
}