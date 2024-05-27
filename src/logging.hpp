#include <string>
#include "json.hpp"

using json = nlohmann::json;

struct FoxgloveMessage {
    std::string topic;
    json payload;
};

inline void to_json(json& j, const FoxgloveMessage& msg) {
    j = json{{"topic", msg.topic}, {"payload", msg.payload}};
}

struct MotionProfile {
    double pos;
    double vel;
    double accel;
};

inline void to_json(json& j, const MotionProfile& profile) {
    j = json{{"pos", profile.pos}, {"vel", profile.vel}, {"accel", profile.accel}};
}