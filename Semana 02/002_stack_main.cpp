// Compilar: g++ 002_stack_vetor.cpp 002_stack_main.cpp -o 002_stack
// Executar: ./002_stack

#include "002_stack.h"
#include <iostream>
using namespace std;

int main()
{
  ItemType character;
  Stack stack;
  ItemType stackItem;

  cout << "Adicione uma String ou pressione ENTER para sair. " << endl;
  cin.get(character);

  while (character != '\n')
  {
    stack.push(character);
    cin.get(character);
  }

  cout << "A String invertida: ";

  while (!stack.isEmpty())
  {
    stackItem = stack.pop();
    cout <<  stackItem;
  }

  cout << endl;
}