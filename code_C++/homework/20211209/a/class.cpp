#include "class.h"

Thermometer::Thermometer() {}
Thermometer::~Thermometer() {}
Thermometer::Thermometer(double temp) { SetTempCelsius(temp); }

void Thermometer::SetTempCelsius(double tempCelsius) {
	this->tempCelsius = tempCelsius;
	this->tempFahrenheit = tempCelsius * 1.8 + 32;
}

void Thermometer::SetTempFahrenheit(double tempFahrenheit) {
	this->tempFahrenheit = tempFahrenheit;
	this->tempCelsius = (tempFahrenheit - 32) / 1.8;
}

double Thermometer::GetTempCelsius() {
	return tempCelsius;
}

double Thermometer::GetTempFahrenheit() {
	return tempFahrenheit;
}
