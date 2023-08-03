// Compilar: g++ 003_queue_vetor.cpp 003_queue_main.cpp -o 003_queue
// Executar: ./003_queue

#include "003_queue.h"
#include <iostream>

using namespace std;

int main()
{
  char character;
  Queue queue;
  char queueChar;

  cout << "Adicione uma String ou tecle ENTER para sair." << endl;
  cin.get(character);

  cout << "Ordem de saida: ";

  while (character != '\n' and !queue.isFull())
  {
    queue.enqueue(character);
    cin.get(character);
  }
  while (!queue.isEmpty())
  {
    queueChar = queue.dequeue();
    cout << queueChar;
  }

  cout << endl;
}
