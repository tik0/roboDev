//#include <c++/iostream>
#include <c++/iostream>

void main(void){
	std::cout << "test";
}

/*
//============================================================================
// Name        : sense_ir.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "infraRed.h"

//#include <stdio.h>
#include <bebot.h>
#include <iostream>

//using namespace std;

#define DEBUG

//#ifdef DEBUG
//#define DEBUG_MSG(str) { std::cout << argv[0] << ": str " << std::endl; }
//#else
//#define DEBUG_MSG(str) {}
//#endif


int main (int argc, const char **argv){

//	DEBUG_MSG(Start sending ir information in )
//	std::cout << "[sense IR] Start sending ir information in '/sense/ir'" << std::endl;

	//Start up with initializing the robot
	struct bebot BEBOT;
	bebot_init(&BEBOT);


	SensorInformer::InfraRed myIR(&BEBOT);
	std::cout << "test" << std::endl;

	std::cout << "test" << std::endl;

	// This loop needs to be parameterized regarding the update-frequency
	for(;;) {
		myIR.sendIRData();
		sleep(1);
	}

//	DEBUG_MSG(Stop sending ir information)
//	std::cout << "[HardwareInterface] Ending HardwareInterface" << std::endl;

	return EXIT_SUCCESS;
}


*/
