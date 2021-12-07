/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  main.cpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */
#include "main.hpp"

using namespace std;

Store TerminalUS("Terminals of USA", 6);
Store TerminalGE("Terminals of Germany", 2);

class Ship : public Process{
    void Behavior()
    {

    }
};

class externShip : public Process{
    public:
    void Behavior()
    {
        Print("Extern ship: Start at time %g\n", Time);

        Enter(TerminalUS, 1);
        Wait(20); //TODO add interval
        Leave(TerminalUS, 1);

        Print("Extern ship: End at time %g\n", Time);

    }
  externShip()  { Print("new extern ship: %g \n",  Time); }
  ~externShip() { Print("delete extern ship: %g \n",  Time); }    
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

class externShipGenerator : public Event {
    void Behavior() {
        (new externShip)->Activate();
        Activate(Time+50); //TODO change generation time
    }
};


int main(int argc, char** argv)
{
    int opt;
    bool mallfunction=false;
    int tankerC=10;
    int USterminalC=6;
    int GEterminalC=2;

    Init(0, 1000); //TODO change end time
    (new externShipGenerator)->Activate(Time+50); //TODO change generation time
    Run();

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