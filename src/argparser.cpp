/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  argparser.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#include "argparser.hpp"

using namespace std;

int safeStoi(char *optarg) {
	int result;
	try {
		result = stoi(optarg);
	} catch (const exception& e) {
		cerr << "Invalid option parameter, rerun with -h for help" << endl;
		exit(1);
	}
	return result;
}

void argparse(int argc, char** argv, int *malfunction, int *tankerC, int *USterminalC, int *GEterminalC, int *maintenanceInterval, int *fuelInterval) {

    int opt;
    int option_index = 0;

    struct option long_options[] = 
    {
		{"help",			no_argument,			NULL, 'h'},
		{"malfunction",		required_argument,		NULL, 'm'},
		{"tankers",			required_argument,		NULL, 't'},
		{"usterminals",		required_argument,		NULL, 'U'},
		{"geterminals",		required_argument,		NULL, 'G'},
		{"maintenance",		required_argument,		NULL, 'n'},
		{"fueling",			required_argument,		NULL, 'f'},
		{0, 0, 0, 0}  // ukoncovaci prvek
	};

	while ((opt = getopt_long(argc, argv, ":m:t:U:G:n:f:h", long_options, &option_index)) != -1)
	    {
	        switch (opt)
	        {
	            case 'h':
	                cout <<" Simulator of IMS project: LNG infrastruktura\n\
	                    usege: ims [args]\n\
	                    args:\n\
	                    -h (--help)			: help\n\
	                    -m (--malfunction)		: malfuction of tankers, 0 disables malfunctions\n\
	                    -t (--tankers)		: tankers count\n\
	                    -U (--usterminals)		: US count of terminals\n\
	                    -G (--geterminals)		: German count of terminals\n\
	                    -n (--maintenance)		: maintenance interval of tankers, 0 disables maintenance\n\
	                    -f (--fueling)		: fueling interval of tankers, 0 disables fueling\n"; 
	                exit(0);
	                //TODO malfunction of tankers, allow to change from exponential?
	            break;
	            case 'm':
	                *malfunction = safeStoi(optarg);
	            break;
	            case 't':
	                *tankerC = safeStoi(optarg);
	            break;
	            case 'U':
	                *USterminalC = safeStoi(optarg);
	            break;
	            case 'G':
	                *USterminalC = safeStoi(optarg);
	            break;
	            case 'n':
	                *maintenanceInterval = safeStoi(optarg) * DAY;
	            break;
	            case 'f':
	                *fuelInterval = safeStoi(optarg) * DAY;
	            break;
	            default:
	            	cerr << "Invalid input options, rerun with -h for help" << endl;
	          		exit(1);
	            break;
	        }
	    }
}
