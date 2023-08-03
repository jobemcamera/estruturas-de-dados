/*
Uma fila é uma estrutura linear na qual as inserções ocorrem no final e as exclusões ocorrem no início.
O primeiro elemento a entrar nabestrutura tem que ser o primeiro a sair.
O último elemento a entrar tem que ser o último a sair.
Comportamento parecido com a comunicação de processos ou acesso a algum recurso.
Inserções ocorrem no final e remoções ocorrem no início.
Uma fila é uma estrutura bastante útil, principalmente quando precisamos garantir que processos acessarão recursos compartilhados de uma maneira justa.
*/

#include "003_queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
  front = 0;
  back = 0;
  structure = new ItemType[MAX_ITEMS];
}

Queue::~Queue()
{
  delete[] structure;
}

bool Queue::isEmpty() const
{
  return (front == back);
}

bool Queue::isFull() const
{
  return (back - front == MAX_ITEMS);
}

void Queue::enqueue(ItemType item)
{
  if (!isFull())
  {
    structure[back % MAX_ITEMS] = item;
    back++;
  }
  else
  {
    throw "Queue is already full!";
  }
}

ItemType Queue::dequeue()
{
  if (!isEmpty())
  {
    front++;
    return structure[(front - 1) % MAX_ITEMS];
  }
  else
  {
    throw "Queue is empty!";
  }
}

void Queue::print() const
{
  cout << "Fila = ";
  for (int i = front; i < back; i++)
  {
    cout << structure[i % MAX_ITEMS];
  }
  cout << endl;
}
