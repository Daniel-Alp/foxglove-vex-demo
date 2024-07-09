#include <string>
#include "json.hpp"

using json = nlohmann::json;


/**
 * Every message sent to Foxglove is a JSON string with two attributes:
 *      - The topic is a string describing the data you are sending 
 *        (e.g. "left_motion_profile" or "flywheel_velocity")
 *      - The payload is an object containing the actual data.
 * 
 * Messages sent to the same topic name must follow the same structure. 
 */
struct Message {
    std::string topic;
    json payload;
};

inline void to_json(json& j, const Message& msg) {
    j = json{{"topic", msg.topic}, {"payload", msg.payload}};
}

struct MotionProfile {
    double pos;
    double vel;
    double accel;
};

inline void to_json(json& j, const MotionProfile& msg) {
    j = json{{"pos", msg.pos}, {"vel", msg.vel}, {"accel", msg.accel}};
}

struct Odometry {
    double x;
    double y;
    double theta;
};

inline void to_json(json& j, const Odometry& msg) {
    j = json{{"x", msg.x},{"y", msg.y},{"theta", msg.theta}};
}