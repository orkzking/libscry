//Simple example
//License is available at
//https://github.com/EmperorPenguin18/libscry/blob/main/LICENSE

#include <dlfcn.h>
#include <iostream>
//#include <scry/scry.h>
#include <scry.h>

using namespace std;

int main(int argc, char **argv)
{
  string lqueryrare, lquerymythic, lset;
  if(argc > 1)
  {
    lqueryrare = "set:";
    lqueryrare += argv[1];
    lqueryrare += " r:r";
    
    lquerymythic = "set:";
    lquerymythic += argv[1];
    lquerymythic += " r:m";
    lset = argv[1];
  }
  else
  {
    lqueryrare = "set:mh2 r:r";
    lquerymythic = "set:mh2 r:m";
    lset = "MH2"
  }
  
  /* This block is what allows the library to be dynamic. */
  void* handle = dlopen("libscry.so", RTLD_LAZY);
  Scry* (*create)();
  void (*destroy)(Scry*);
  create = (Scry* (*)())dlsym(handle, "create_object");
  destroy = (void (*)(Scry*))dlsym(handle, "destroy_object");

  /* Create an instance of the Scry class.
     This class handles all of the API calls and cacheing. */
  Scry* scry = (Scry*)create();
  
  List* searchRes = scry->cards_search(lquerymythic);
  vector<Card*> mythicsCards = searchRes->cards();
  cout << "price of all mythics from " << lset << "\n";
  for (i = 0; i < mythicsCards.size(); i++)
  {
    cout << mythicsCards[i]->name() << " price: " << mythicsCards[i]->priceEUR() << " Euro\n";
  }
  searchRes = scry->cards_search(lqueryrare);
  vector<Card*> raresCards = searchRes->cards();
  cout << "price of all rares from " << lset << "\n";
  for (i = 0; i < raresCards.size(); i++)
  {
    cout << raresCards[i]->name() << " price: " << raresCards[i]->priceEUR() << " Euro\n";
  }  
  
  /* Prevents memory leaks.
     Without this line std::bad_alloc will be thrown. */
  destroy(scry);
}
