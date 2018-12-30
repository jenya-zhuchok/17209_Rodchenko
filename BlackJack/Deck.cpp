

#include "Deck.h"


Deck::Deck() : size(SizeOfDeck), num(0)
{
  list = new Card[SizeOfDeck];
  imply();
  shuffle();
}
Deck::~Deck() { delete[] list;  }

void Deck::imply()
{
  if(!list) return;
  for (int i = 0; i < 10; i++)
  {
      list[i].imply(i + 1);
      list[i + 13].imply(i + 1);
      list[i + 26].imply(i + 1);
      list[i + 39].imply(i + 1);
  }
//  for (int i = 0; i < 3; i++)
//  {
//      list[i + 10].imply(10);
//      list[i + 13 + 10].imply(10);
//      list[i + 26 + 10].imply(10);
//      list[i + 39 + 10].imply(10);
//  }
}

void Deck::shuffle()
{
  srand( time( 0 ));
  int count = 10 + rand()  % 100; // перетосовать от 10 до 110 раз

  for(int i = 0; i < count; i++)
  {
  int val_1 = rand() % (int)size;
  int val_2 = rand() % (int)size;

  list[val_1].swap(list[val_2]);
  }
}

bool Deck::IsEmpty() {  return !(num < size);   }

Card Deck::DrawACard()
{
  num++;
  list[num - 1].UseOn();
  return list[num - 1];
}
