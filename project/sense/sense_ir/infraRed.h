/*
 * infraRed.h
 *
 *  Created on: 26.11.2013
 *      Author: andreas
 */

#ifndef INFRARED_H_
#define INFRARED_H_

#include <stdio.h>
#include <bebot.h>
#include <vector>

#include "rsbInformer.h"
#include "../Constants.h"

namespace SensorInformer{
class InfraRed{

public:

	InfraRed(struct bebot* bebot);

	~InfraRed();

	/**
	 * Gets the infrared data from bebot and saves it to the sensor array.
	 */
	void getIRData();

	void sendIRData();

private:
	std::vector<int>* irSensors;//[BEBOT_BRIGHTNESS_COUNT];
	struct bebot* bebot;

};
}
#endif /* INFRARED_H_ */
