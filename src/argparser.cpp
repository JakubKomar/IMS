/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  argparser.cpp
 *
 * @authors Jakub Komarek (xkomar33)
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

double safeStod(char *optarg) {
	int result;
	try {
		result = stod(optarg);
	} catch (const exception& e) {
		cerr << "Invalid option parameter, rerun with -h for help" << endl;
		exit(1);
	}
	return result;
}

void argparse(int argc, char** argv) {

    int opt;
    int option_index = 0;

    struct option long_options[] = 
    {
		{"help",			no_argument,			NULL, 'h'},
		{"malfunction",		required_argument,		NULL, 'm'},
		{"tankers",			required_argument,		NULL, 't'},
		{"usterminals",		required_argument,		NULL, 'U'},
		{"geterminals",		required_argument,		NULL, 'G'},
		{"TRMP",	required_argument,		NULL, 'R'},
		{"TFMP",	required_argument,		NULL, 'F'},
		{"simTime",	required_argument,		NULL, 's'},
		{"tankerCapacity",	required_argument,		NULL, 'c'},
		{0, 0, 0, 0}  // ukoncovaci prvek
	};

	while ((opt = getopt_long(argc, argv, ":mt:U:G:F:R:s:c:h", long_options, &option_index)) != -1)
	    {
	        switch (opt)
	        {
	            case 'h':
	                printf("Simulator of IMS project: LNG infrastruktura\n\
usege: ims [args]\n\
args:\n\
-h (--help)				: help\n\
-m (--malfunction)		: malfuction , 0 disables malfunctions\n\
-t (--tankers)			: tankers count\n\
-U (--usterminals)		: US count of terminals\n\
-G (--geterminals)		: German count of terminals\n\
-R (--TRMP)				: propability of reapaireble mallfuction on every tanker\n\
-F (--TFMP)				: propability of fatal mallfuction on every tanker \n\
-s (--simTime)			: sim time in years\n\
-c (--tankerCapacity)	: capacity of single tanker\n");
	                exit(0);
	                //TODO malfunction of tankers, allow to change from exponential?
	            break;
	            case 'm':
	                malfuctionGeneralSwich=true;
	            break;
	            case 't':
	                tankerC = safeStoi(optarg);
	            break;
	            case 'U':
	                USterminalC = safeStoi(optarg);
	            break;
	            case 'G':
	            	GEterminalC = safeStoi(optarg);
	            break;
				case 'R':
	               	repairebleMallfunctionPropability = safeStod(optarg) ;
					repairebleMallfucntion=true;
	            break;
				case 'F':
	                fatalMallfunctionPropability = safeStod(optarg) ;
					fatalMallfunction=true;
	            break;
				case 's':
	                duration = safeStoi(optarg);
	            break;
				case 'c':
	                tankerCapacity = safeStoi(optarg) ;
	            break;
	            default:
	            	cerr << "Invalid input options, rerun with -h for help" << endl;
	          		exit(1);
	            break;
	        }
	    }
}
