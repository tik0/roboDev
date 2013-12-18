//============================================================================
// Name        : sense_ir.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define INFO_MSG_
#define DEBUG_MSG_
#define SUCCESS_MSG_
#define WARNING_MSG_
#define ERROR_MSG_
#include <MSG.h>

#include <FLAGS.h>

#include "infraRed.h"
#include <bebot.h>
#include <iostream>

using namespace std;

int main (int argc, const char **argv){

	INFO_MSG("Start sending ir information in ")

//	std::cout << "[sense IR] Start sending ir information in '/sense/ir'" << std::endl;

	//Start up with initializing the robot
	struct bebot BEBOT;
	bebot_init(&BEBOT);


	SensorInformer::InfraRed myIR(&BEBOT);

	// This loop needs to be parameterized regarding the update-frequency
	for(;;) {
//		myIR.sendIRData();
		ERROR_MSG("This is some variable")
		sleep(1);
	}

	return EXIT_SUCCESS;
}
