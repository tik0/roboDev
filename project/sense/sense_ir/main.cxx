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
#include <boost/thread.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <getopt.h>
#include <vector>

using namespace std;

int main (int argc, const char **argv){

<<<<<<< HEAD
	CFlags flags(argc,argv,AMOUNT_PERIODS,AMOUNT_LISTENER,AMOUNT_INFORMER,AMOUNT_REMOTEPROCEDURE,AMOUNT_ARBITRARY);
	//	std::cout << flags.g_sLScope.at(0) << std::endl;
//	INFO_MSG("Start sending ir information in " << flags.g_sIScope.at(0))
=======
	// Listener scopes
	extern std::vector<std::string> g_sLScope;
	// Informer scopes
	extern std::vector<std::string> g_sIScope;
	// Remote Procedure scopes
	extern std::vector<std::string> g_sRScope;
	// Frequencies
	extern std::vector<int> g_uiFreq;

>>>>>>> ab67fab5a27d83d7100fe47ec5b5fac908fa590c

	// Get one informer scope
	readFlags(argc,argv,1,0,1,0);

	// Calculate the period
	int fPeriod = (int)(1 / ( g_uiFreq.at(0) )) / 1000;

	INFO_MSG( "Start sending IR information in " << g_sIScope.at(0) )

	//Start up with initializing the robot
	struct bebot BEBOT;
	bebot_init(&BEBOT);


	SensorInformer::InfraRed myIR(&BEBOT);


	for(;;) {
//		myIR.sendIRData();
		ERROR_MSG("This is some variable")
		boost::this_thread::sleep( boost::posix_time::milliseconds(fPeriod) );
	}

	return EXIT_SUCCESS;
}
