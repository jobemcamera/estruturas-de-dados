#include <iostream>
#include "fila_dinamica.h"
#include <cstddef> //NULL
#include <new>

using namespace std;

filadinamica::filadinamica()
{
  primeiro = NULL;
  ultimo = NULL;
}

filadinamica::~filadinamica()
{
  No *temp;
  while (primeiro != NULL)
  {
    temp = primeiro;
    primeiro = primeiro->proximo;
    delete temp;
  }
  ultimo = NULL;
}

bool filadinamica::isEmpty()
{
  return (primeiro == NULL);
}

bool filadinamica::isFull()
{
  No *temp;
  try
  {
    temp = new No;
    delete temp;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void filadinamica::push(TipoItem item) // enqueue
{
  if (isFull())
  {
    cout << "A fila esta cheia!" << endl;
    cout << "Nao foi possivel inserir este elemento..." << endl;
  }
  else
  {
    No *NoNovo = new No;
    NoNovo->valor = item;
    NoNovo->proximo = NULL;

    if (primeiro == NULL)
    {
      primeiro = NoNovo;
    }
    else
    {
      ultimo->proximo = NoNovo;
    }
    ultimo = NoNovo;
  }
}

TipoItem filadinamica::pop() // dequeue
{
  if (isEmpty())
  {
    cout << "A fila esta vazia." << endl;
    cout << "Nao tem elemento a ser removido!" << endl;
    return 0;
  }
  else
  {
    No *temp = primeiro;
    TipoItem item = primeiro->valor;
    primeiro = primeiro->proximo;
    if (primeiro == NULL)
    {
      ultimo = NULL;
    }
    delete temp;
    return item;
  }
}

void filadinamica::print()
{
  No *temp = primeiro;
  cout << "Fila: [ ";
  while (temp != NULL)
  {
    cout << temp->valor << " ";
    temp = temp->proximo;
  }
  cout << "]" << endl;
}