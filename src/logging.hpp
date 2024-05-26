#include "json.hpp"

using json = nlohmann::json;

struct MotionProfile {
    double position;
    double velocity;
    double acceleration;

    MotionProfile(double p, double v, double a) {
        position = p;
        velocity = v;
        acceleration = a;
    }
};

inline void to_json(json& j, const MotionProfile& mp) {
    j = json{{"position", mp.position}, {"velocity", mp.velocity}, {"acceleration", mp.acceleration}};
}