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
    double position;
    double velocity;
    double acceleration;
};

inline void to_json(json& j, const MotionProfile& mp) {
    j = json{{"position", mp.position}, {"velocity", mp.velocity}, {"acceleration", mp.acceleration}};
}