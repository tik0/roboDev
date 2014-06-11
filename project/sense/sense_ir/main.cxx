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
#define AMOUNT_PERIODS 0
#define AMOUNT_LISTENER 1
#define AMOUNT_INFORMER 2
#define AMOUNT_REMOTEPROCEDURE 0
#define AMOUNT_ARBITRARY 1

#include "infraRed.h"
#include <bebot.h>
#include <iostream>

using namespace std;

int main (int argc, const char **argv){

	CFlags flags(argc,argv,AMOUNT_PERIODS,AMOUNT_LISTENER,AMOUNT_INFORMER,AMOUNT_REMOTEPROCEDURE,AMOUNT_ARBITRARY);
	//	std::cout << flags.g_sLScope.at(0) << std::endl;
//	INFO_MSG("Start sending ir information in " << flags.g_sIScope.at(0))

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
