#ifndef BMS_CHECKER
#define BMS_CHECKER

#include <iostream>
#include <assert.h>
#include "bms_param.hpp"

namespace bms
{
	class BatteryHealth
	{
	private:
        bool batteryTemperatureIsOk(float temperature);
        bool batterySocIsOk(float soc);
        bool batteryChargeRateIsOk(float chargeRate);
        bool checkRange(float actualValue, float minValue, float maxValue);
        void checkBreachLow(float actualValue, float minValue, float maxValue, BATTERY_PARAMETER parameter);
        void checkBreachHigh(float actualValue, float maxValue, BATTERY_PARAMETER parameter);
        void printWarnMessage(BATTERY_PARAMETER parameter, PARAMETER_BREACH_TYPE breachType);
        void printErrorMessage(BATTERY_PARAMETER messageKey);

	public:
		bool batteryIsOk(float temperature, float soc, float chargeRate);
	};
}

#endif 
