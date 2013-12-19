#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <getopt.h>
using namespace std;

std::vector<std::string> g_sLScope;
std::vector<std::string> g_sIScope;
std::vector<std::string> g_sRScope;
std::vector<size_t> g_uiFreq;

//extern char * __progname;

int readFlags(int argc, char **argv, size_t numFreq, size_t numList, size_t numInfo, size_t numRem)
{
        extern char *optarg;
        extern int optind;
        int c, err = 0;
        size_t numFlags = numFreq + numList + numInfo + numRem;
        size_t fflag=0, lflag=0, iflag=0, rflag=0, hflag=0, eflag=0;
        char *sname = "default_sname", *fname;

        std::string usage("usage: %s  ");
        for ( size_t idx = 0; idx < numFreq; idx++)  usage.append("-f frequency ");
        for ( size_t idx = 0; idx < numList; idx++)  usage.append("-l listenerscope ");
        for ( size_t idx = 0; idx < numInfo; idx++)  usage.append("-i informerscope ");
        for ( size_t idx = 0; idx < numRem; idx++)   usage.append("-r remoteprocedurescope ");
        usage.append("[-e] [-h] \n\t-h\tPrint this help\n\t-e\tExecute without any flags\n");

        while ((c = getopt(argc, argv, "f:l:i:r:hn")) != -1)
                switch (c) {
                case 'f':
                        fflag++;
                        g_uiFreq.push_back(atoi(optarg));
                        break;
                case 'l':
                        lflag++;
                        g_sLScope.push_back(optarg);
                        break;
                case 'i':
                        iflag++;
                        g_sIScope.push_back(optarg);
                        break;
                case 'r':
                        rflag++;
                        g_sRScope.push_back(optarg);
                        break;
                case 'h':
                        hflag = 1;
                        break;
                case 'e':
                        eflag = 1;
                        sname = optarg;
                        break;
                case '?':
                        err = 1;
                        break;
                }
        if (hflag == 1 || argc <= (1 + numFlags)) {
                fprintf(stderr, "%s: missing -f option\n", argv[0]);
                fprintf(stderr, usage.c_str(), argv[0]);
                exit(1);
        } else if ((optind+1) > argc) {
                /* need at least one argument (change +1 to +2 for two, etc. as needeed) */

                printf("optind = %d, argc=%d\n", optind, argc);
                fprintf(stderr, "%s: missing name\n", argv[0]);
                fprintf(stderr, usage.c_str(), argv[0]);
                exit(1);
        } else if (err) {
                fprintf(stderr, usage.c_str(), argv[0]);
                exit(1);
        }
        /* see what we have */
        printf("lflag = %d\n", lflag);
        printf("Iflag = %d\n", fflag);
        printf("g_sLScope = \"%s\"\n", g_sLScope.at(1).c_str());
        printf("g_sIScope = \"%s\"\n", g_sIScope.at(1).c_str());

        if (optind < argc)        /* these are the arguments after the command-line options */
                for (; optind < argc; optind++)
                        printf("argument: \"%s\"\n", argv[optind]);
        else {
                printf("no arguments left to process\n");
        }
        exit(0);
}

int main(int argc, char **argv)
{
//    readFlags(argc, argv);
    readFlags(argc,argv,0,1,1,0);
}
