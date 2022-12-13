#include "BMS_checker.hpp"

bool bms::BatteryHealth::checkRange(float actualValue, float minValue, float maxValue) 
{
    return (actualValue <= minValue || actualValue > maxValue);
}

void bms::BatteryHealth::checkBreachLow(float actualValue, float minValue, float maxValue, BATTERY_PARAMETER parameter)
{
    float tolerance = (maxValue * 5) / 100;
    if (actualValue > minValue && actualValue < (minValue + tolerance))
    {
        printWarnMessage(parameter, bms::LOW);
    }
}

void bms::BatteryHealth::checkBreachHigh(float actualValue, float maxValue, BATTERY_PARAMETER parameter) 
{
    float tolerance = (maxValue * 5) / 100;
    if (actualValue >= (maxValue - tolerance) && actualValue <= maxValue)
    {
        printWarnMessage(parameter, bms::HIGH);
    }
}

void bms::BatteryHealth::printWarnMessage(BATTERY_PARAMETER parameter, PARAMETER_BREACH_TYPE breachType)
{
    std::cout << messageWarn[breachType] << "_" << messageFactor[languageOption][parameter] << "_WARN\n";
}

void bms::BatteryHealth::printErrorMessage(BATTERY_PARAMETER messageKey)
{
    std::cout << messageFactor[languageOption][messageKey] << " " << messageTrailing[languageOption] << "\n";
}

bool bms::BatteryHealth::batteryTemperatureIsOk(float temperature) 
{
	bool result = true;
	checkBreachLow(temperature, temperature_min, temperature_max, bms::BATTERY_TEMPERATURE);
	checkBreachHigh(temperature, temperature_max, bms::BATTERY_TEMPERATURE);
	if (checkRange(temperature, temperature_min, temperature_max))
	{
        printErrorMessage(bms::BATTERY_TEMPERATURE);
		result = false;
	}
	return result;
}

bool bms::BatteryHealth::batterySocIsOk(float soc) 
{
	bool result = true;
	checkBreachLow(soc, soc_min, soc_max, bms::BATTERY_SOC);
	checkBreachHigh(soc, soc_max, bms::BATTERY_SOC);
	if (checkRange(soc, soc_min, soc_max))
	{
        printErrorMessage(bms::BATTERY_SOC);
		result = false;
	}
	return result;
}

bool bms::BatteryHealth::batteryChargeRateIsOk(float chargeRate) 
{
	bool result = true;
	checkBreachLow(chargeRate, chargeRate_min, chargeRate_max, bms::BATTERY_CHARGE_RATE);
	checkBreachHigh(chargeRate,chargeRate_max, bms::BATTERY_CHARGE_RATE);
	if (checkRange(chargeRate, chargeRate_min, chargeRate_max))
	{
        printErrorMessage(bms::BATTERY_CHARGE_RATE);
		result = false;
	}
	return result;
}

bool bms::BatteryHealth::batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (batteryTemperatureIsOk(temperature) && batterySocIsOk(soc) && batteryChargeRateIsOk(chargeRate));
}
