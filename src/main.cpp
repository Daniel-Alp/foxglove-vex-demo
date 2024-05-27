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
	double pos = 0;
	double vel = 0;
	double accel = 1;

	while(true) {
		vel += accel * 0.01;
		pos += pos * 0.01;
		
		MotionProfile profile{pos, vel, accel};
		FoxgloveMessage message = {"motion_profile", profile};
		json j = message;

		std::cout << j << std::flush;

		pros::delay(10);
	}
}