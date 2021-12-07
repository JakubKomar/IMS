#include "main.hpp"
#include <getopt.h>
using namespace std;


class Ship : public Process{
    void Behavior()
    {

    }
};

class HarborUS : public Process{
    void Behavior()
    {

    }
};

class HarborDE : public Process{
    void Behavior()
    {

    }
};


int main(int argc, char** argv)
{
    int opt;
    bool mallfunction=false;
    int tankerC=10;
    int USterminalC=6;
    int GEterminalC=2;

    while ((opt = getopt (argc, argv, "t:U:G:hm")) != -1)
    {
        switch (opt)
        {
            case 'h':
                cout<<"Simulator of IMS project: LNG infrastruktura\n\
                    usege: ims [args]\n\
                    args:\n\
                    -h : help\n\
                    -m : mallfuction of tankers turn ON\n\
                    -t : tankers count\n\
                    -U : US count of terminals\n\
                    -G : German count of terminals\n\
                    "; 
                return 0;
            break;
            case 'm':
                mallfunction=true;
            break;
            case 't':
                tankerC=stoi(optarg);
            break;
            case 'U':
                USterminalC=stoi(optarg);
            break;
            case 'G':
                USterminalC=stoi(optarg);
            break;
        }
    }

    return 0;
}