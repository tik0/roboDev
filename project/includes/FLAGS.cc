#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <getopt.h>

class CFlags {

public:
std::vector<size_t> g_uiFreq; // Stores the periods
std::vector<std::string> g_sLScope; // Stores the listener scopes
std::vector<std::string> g_sIScope; // Stores the informer scopes
std::vector<std::string> g_sRScope; // Stores the remoteprocedurecall scopes
std::vector<std::string> g_sAScope; // Stores arbitrary strings defined by user

private:

// Read the given arguments
int getFlags(int argc,
              const char **argv,
              size_t p_uiNumPeriod_ms, // Amount of periods
              size_t p_uiNumList, // Amount of listener scopes
              size_t p_uiNumInfo, // Amount of informer scopes
              size_t p_uiNumRem, // Amount of remoteprocedure scopes
              size_t p_uiNumArb, // Amount of arbitrary scopes
              std::string p_sUsage) // Usage of the program
{
        extern char *optarg;
//        extern int optind;
        int flag;
        size_t numOfMandatoryFlags = p_uiNumPeriod_ms + p_uiNumList + p_uiNumInfo + p_uiNumRem + p_uiNumArb;
        size_t fFlag=0, lFlag=0, iFlag=0, rFlag=0, aFlag = 0;
        bool hFlag = false, eFlag = false;
//        char *sname = "default_sname", *fname;


        while ((flag = getopt(argc, (char *const *)argv, "f:l:i:r:a:he")) != -1) {
                switch (flag) {
                case 'f':
                        fFlag++;
                        g_uiFreq.push_back(atoi(optarg));
                        break;
                case 'l':
                        lFlag++;
                        g_sLScope.push_back(optarg);
                        break;
                case 'i':
                        iFlag++;
                        g_sIScope.push_back(optarg);
                        break;
                case 'r':
                        rFlag++;
                        g_sRScope.push_back(optarg);
                        break;
                case 'a':
						aFlag++;
						g_sAScope.push_back(optarg);
						break;
                case 'h':
                        hFlag = true;
                        break;
                case 'e':
                        eFlag = true;
                        break;
                }
        }

        // Get the number of all read in fleags
        size_t numOfReadFlags = fFlag + lFlag + iFlag + rFlag + aFlag;

        // Check the flags
        if ( ( hFlag || ( numOfMandatoryFlags != numOfReadFlags ) ) && !eFlag) {
                fprintf(stderr, p_sUsage.c_str(), argv[0]);
                exit(1);
        }
        return 0;
}


// A generic predefined help
std::string helpString(size_t p_uiNumPeriod_ms, // Amount of periods
              size_t p_uiNumList, // Amount of listener scopes
              size_t p_uiNumInfo, // Amount of informer scopes
              size_t p_uiNumRem, // Amount of remoteprocedure scopes
              size_t p_uiNumArb) // Amount of arbitrary scopes
{
	std::string usage("usage: %s  ");
	for ( size_t idx = 0; idx < p_uiNumPeriod_ms; idx++)  usage.append("-f frequency ");
	for ( size_t idx = 0; idx < p_uiNumList; idx++)  usage.append("-l listenerscope ");
	for ( size_t idx = 0; idx < p_uiNumInfo; idx++)  usage.append("-i informerscope ");
	for ( size_t idx = 0; idx < p_uiNumRem; idx++)   usage.append("-r remoteprocedurescope ");
	for ( size_t idx = 0; idx < p_uiNumArb; idx++)   usage.append("-a arbitrary ");
	usage.append("[-e] [-h] \n\t-h\tPrint this help\n\t-e\tExecute anyway\n");

	return usage;
}

// A user defined help
std::string helpString(size_t p_uiNumPeriod_ms, // Amount of periods
              size_t p_uiNumList, // Amount of listener scopes
              size_t p_uiNumInfo, // Amount of informer scopes
              size_t p_uiNumRem, // Amount of remoteprocedure scopes
              size_t p_uiNumArb, // Amount of arbitrary scopes
              std::vector<std::string> p_vString) // Stores the user defined strings
{
	// Get the number of all read in flags
	size_t numOfReadFlags = p_uiNumPeriod_ms + p_uiNumList + p_uiNumInfo + p_uiNumRem + p_uiNumArb;

	if ( p_vString.size() != numOfReadFlags ) {
		fprintf(stderr, "User defined strings missmatch\n");
        exit(1);
	}

	size_t stringIdx = 0;
	std::string usage("usage: %s ");
	for ( size_t idx = p_uiNumPeriod_ms; idx > 0; idx--)  usage.append(" -f " + p_vString.at(stringIdx++));
	for ( size_t idx = p_uiNumList; idx > 0; idx--)  usage.append(" -l " + p_vString.at(stringIdx++));
	for ( size_t idx = p_uiNumInfo; idx > 0; idx--)  usage.append(" -i " + p_vString.at(stringIdx++));
	for ( size_t idx = p_uiNumRem; idx > 0; idx--)   usage.append(" -r " + p_vString.at(stringIdx++));
	for ( size_t idx = p_uiNumArb; idx > 0; idx--)   usage.append(" -a " + p_vString.at(stringIdx++));
	usage.append(" [-e] [-h] \n\t-h\tPrint this help\n\t-e\tExecute anyway\n");

	return usage;
}

public:
// Read the flags but with user defined help
CFlags(int argc,
        const char **argv,
        size_t p_uiNumPeriod_ms, // Amount of periods
        size_t p_uiNumList, // Amount of listener scopes
        size_t p_uiNumInfo, // Amount of informer scopes
        size_t p_uiNumRem, // Amount of remoteprocedure scopes
        size_t p_uiNumArb, // Amount of arbitrary scopes
        std::vector<std::string> p_vString) // Stores the user defined strings
{
	std::string usage(helpString(p_uiNumPeriod_ms,p_uiNumList,p_uiNumInfo,p_uiNumRem,p_uiNumArb,p_vString));
	this->getFlags(argc,argv, p_uiNumPeriod_ms, p_uiNumList, p_uiNumInfo, p_uiNumRem, p_uiNumArb, usage);
}

// Read the flags with user generic flags
CFlags(int argc,
              const char **argv,
              size_t p_uiNumPeriod_ms, // Amount of periods
              size_t p_uiNumList, // Amount of listener scopes
              size_t p_uiNumInfo, // Amount of informer scopes
              size_t p_uiNumRem, // Amount of remoteprocedure scopes
              size_t p_uiNumArb) // Amount of arbitrary scopes
{
	std::string usage(helpString(p_uiNumPeriod_ms,p_uiNumList,p_uiNumInfo,p_uiNumRem,p_uiNumArb));
	this->getFlags(argc,argv, p_uiNumPeriod_ms, p_uiNumList, p_uiNumInfo, p_uiNumRem, p_uiNumArb, usage);
}


};


#define AMOUNT_PERIODS 0
#define AMOUNT_LISTENER 1
#define AMOUNT_INFORMER 2
#define AMOUNT_REMOTEPROCEDURE 0
#define AMOUNT_ARBITRARY 1

// Example with user defined help
int main(int argc,const char **argv)
{
	// Defining a user help string
	// It will be read consecutivly regarding Periods->Listener->Informer->Remote->Arbitrary
	std::vector<std::string> usersHelpString;
	usersHelpString.push_back("First Listener Scope");
	usersHelpString.push_back("First Informer Scope");
	usersHelpString.push_back("Second Informer Scope");
	usersHelpString.push_back("First Arbitrary Stuff");
	CFlags flags(argc,argv,AMOUNT_PERIODS,AMOUNT_LISTENER,AMOUNT_INFORMER,AMOUNT_REMOTEPROCEDURE,AMOUNT_ARBITRARY,usersHelpString);
	std::cout << flags.g_sLScope.at(0) << std::endl;
	std::cout << flags.g_sIScope.at(0) << std::endl;
	std::cout << flags.g_sIScope.at(1) << std::endl;
	std::cout << flags.g_sAScope.at(0) << std::endl;



}

// Example with generic help
//int main(int argc,const char **argv)
//{
//	CFlags flags(argc,argv,AMOUNT_PERIODS,AMOUNT_LISTENER,AMOUNT_INFORMER,AMOUNT_REMOTEPROCEDURE,AMOUNT_ARBITRARY);
//	std::cout << flags.g_sLScope.at(0) << std::endl;
//}
