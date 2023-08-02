/*
Uma pilha é uma estrutura linear na qual inserções e remoções ocorrem no topo da pilha.
O primeiro elemento a entrar na estrutura tem que ser o último a sair.
O último elemento a entrar tem que ser o primeiro a sair.
Inserções e remoções ocorrem no topo.

Uma pilha é uma estrutura bastante útil, principalmente quando precisamos garantir alinhamento de componentes em processos.
  - Chamada de funções na execução de programas;
  - Análise de sintaxe de linguagens de programaçãp;
  - Verificação de alinhamento de parênteses em strings.
*/

#include "002_stack.h"
#include <iostream>
using namespace std;

// ItemType == char
Stack::Stack()
{
  length = 0;
  structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack()
{
  delete[] structure;
}

bool Stack::isEmpty() const
{
  return (length == 0);
}

bool Stack::isFull() const
{
  return (length == MAX_ITEMS);
}

void Stack::push(ItemType item)
{
  if (!isFull())
  {
    structure[length] = item;
    length++;
  }
  else
  {
    throw "Stack is already full!";
  }
}

ItemType Stack::pop()
{
  if (!isEmpty())
  {
    ItemType aux = structure[length - 1];
    length--;
    return aux;
  }
  else
  {
    throw "Stack is empty!";
  }
}

void Stack::print() const
{
  cout << "Pilha = ";
  for (int i = 0; i < length; i++)
  {
    cout << structure[i];
  }
  cout << endl;
}