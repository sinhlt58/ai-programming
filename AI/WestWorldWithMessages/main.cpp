#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "Kitty.h"
#include "Mouse.h"

std::ofstream os;

int main()
{
//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
  os.open("output.txt");
#endif

  //seed random number generator
  srand((unsigned) time(0));

  //create a miner
  Miner* Bob = new Miner(ent_Miner_Bob);

  //create his wife
  MinersWife* Elsa = new MinersWife(ent_Elsa);

  //create a kitty
  Kitty *kitty = new Kitty(ent_Cute_Kitty);

  Mouse *mouse = new Mouse(ent_Mouse);

  //register them with the entity manager
  EntityMgr->RegisterEntity(Bob);
  EntityMgr->RegisterEntity(Elsa);
  EntityMgr->RegisterEntity(kitty);
  EntityMgr->RegisterEntity(mouse);

  //run Bob and Elsa through a few Update calls
  for (int i=0; i<30; ++i)
  { 
    //Bob->Update();
    //Elsa->Update();
	  mouse->Update();
	  kitty->Update();
    //dispatch any delayed messages
    Dispatch->DispatchDelayedMessages();

    Sleep(800);
  }

  //tidy up
  delete Bob;
  delete Elsa;

  //wait for a keypress before exiting
  PressAnyKeyToContinue();


  return 0;
}






