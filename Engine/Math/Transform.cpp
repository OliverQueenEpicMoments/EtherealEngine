#include "Transform.h"

bool Ethrl::Transform::Write(const rapidjson::Value& value) const {
    return true;
}

bool Ethrl::Transform::Read(const rapidjson::Value& value) {
    READ_DATA(value, Position);
    READ_DATA(value, Scale);
    READ_DATA(value, Rotation);

    return true;
}
