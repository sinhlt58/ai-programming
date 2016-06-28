#include <fstream>
#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "Kitty.h"


std::ofstream os;

int main()
{
//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
  os.open("output.txt");
#endif

  //create a miner
  Miner Bob(ent_Miner_Bob);

  //create his wife
  MinersWife Elsa(ent_Elsa);

  Kitty Kitty(ent_cute_kitty);

  //run Bob and Elsa through a few Update calls
  for (int i=0; i<200; ++i)
  { 
   // Bob.Update();
    //Elsa.Update();
	  Kitty.Update();
    Sleep(800);
  }

  //wait for a keypress before exiting
  PressAnyKeyToContinue();

  return 0;
}






