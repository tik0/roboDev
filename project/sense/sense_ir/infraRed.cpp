/*
 * infraRed.cpp
 *
 *  Created on: 26.11.2013
 *      Author: andreas
 */

#include "infraRed.h"


SensorInformer::InfraRed::InfraRed(struct bebot* bebot) {
  this->bebot = bebot;
  irSensors = new std::vector<int>();
  for (unsigned int i = 0; i < BEBOT_BRIGHTNESS_COUNT; i++)
    irSensors->push_back(0);
}

SensorInformer::InfraRed::~InfraRed() {

}

/**
 * Get infrared data from the bebot and stores it at irSensors.
 */
void SensorInformer::InfraRed::getIRData() {

  int value = bebot_update(bebot);
  //std::cout << "bebot update = " << value << std::endl;

  if (value >= 0) {
    std::cout << "IR-Sensors: ";

    for (int i = 0; i < BEBOT_BRIGHTNESS_COUNT; i++) {
      irSensors->at(i) = bebot_get_brightness(bebot, i);
      std::cout << irSensors->at(i) << " ";
    }
    std::cout << std::endl;
  }

}

/**
 * Sends the infrared data to our specific IR scope, if there is new data.
 */
void SensorInformer::InfraRed::sendIRData() {

  //TODO check if the sending of an array is working. Maybe the datatype is declared wrong.
  SensorInformer::rsbInformer* info = new SensorInformer::rsbInformer();  // for std::string -> your type
  info->setup_vec(Constants::RSB_SCOPE_SENSE_BEHAVIOUR);
  //std::cout << "try to get IR data" << std::endl;

//	while(bebot_poll(bebot, -1) > 0) {

  //		if (bebot_update(bebot) > 0) {
  this->getIRData();
  //		std::cout << "try to publish IR data" << std::endl;
  //everytime when getting data send it to our scope.
  info->publish(*irSensors);
  //	}
//	}

}
