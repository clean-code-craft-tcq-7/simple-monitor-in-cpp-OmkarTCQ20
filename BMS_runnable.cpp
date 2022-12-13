#include "bms_checker.hpp"

int main()
{
    bms::BatteryHealth batteryStatus;
    assert(batteryStatus.batteryIsOk(25, 70, 0.7) == true);
    assert(batteryStatus.batteryIsOk(50, 85, 0) == false);
    assert(batteryStatus.batteryIsOk(30, 70, 0.1) == true);
    assert(batteryStatus.batteryIsOk(30, 70, 0.9) == false);
    assert(batteryStatus.batteryIsOk(1, 70, 0.7) == true);
    assert(batteryStatus.batteryIsOk(25, 78, 0.7) == true);
    assert(batteryStatus.batteryIsOk(25, 70, 0.7) == true);
    assert(batteryStatus.batteryIsOk(25, 70, 0.79) == true);
    return 0;
}
