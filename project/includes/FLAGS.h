#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <getopt.h>

std::vector<size_t> g_uiFreq; // Stores the periods
std::vector<std::string> g_sLScope; // Stores the listener scopes
std::vector<std::string> g_sIScope; // Stores the informer scopes
std::vector<std::string> g_sRScope; // Stores the remoteprocedurecall scopes
std::vector<std::string> g_sAScope; // Stores arbitrary strings defined by user

//extern char * __progname; // Stores the programs name (Only UNIX)

int getOpt(int argc,
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

// Read the flags but with user defined flags
int readFlags(int argc,
        const char **argv,
        size_t p_uiNumPeriod_ms, // Amount of periods
        size_t p_uiNumList, // Amount of listener scopes
        size_t p_uiNumInfo, // Amount of informer scopes
        size_t p_uiNumRem, // Amount of remoteprocedure scopes
        size_t p_uiNumArb, // Amount of arbitrary scopes
        std::vector<std::string> p_vString) // Stores the user defined strings
{
	std::string usage(helpString(p_uiNumPeriod_ms,p_uiNumList,p_uiNumInfo,p_uiNumRem,p_uiNumArb,p_vString));
	return getOpt(argc,argv, p_uiNumPeriod_ms, p_uiNumList, p_uiNumInfo, p_uiNumRem, p_uiNumArb, usage);
}

int readFlags(int argc,
              const char **argv,
              size_t p_uiNumPeriod_ms, // Amount of periods
              size_t p_uiNumList, // Amount of listener scopes
              size_t p_uiNumInfo, // Amount of informer scopes
              size_t p_uiNumRem, // Amount of remoteprocedure scopes
              size_t p_uiNumArb) // Amount of arbitrary scopes
{
	    std::string usage(helpString(p_uiNumPeriod_ms,p_uiNumList,p_uiNumInfo,p_uiNumRem,p_uiNumArb));
        return getOpt(argc,argv, p_uiNumPeriod_ms, p_uiNumList, p_uiNumInfo, p_uiNumRem, p_uiNumArb, usage);
}


// Example with user defined help
//int main(int argc,const char **argv)
//{
//	std::vector<std::string> usersHelpString;
//	usersHelpString.push_back("Listener Scope");
//	usersHelpString.push_back("Informer Scope");
//	usersHelpString.push_back("Some Arbitrary Stuff");
//    readFlags(argc,argv,0,1,1,0,1,usersHelpString);
//
//}

// Example with generic help
//int main(int argc,const char **argv)
//{
//    readFlags(argc,argv,0,1,1,0,0);
//}
