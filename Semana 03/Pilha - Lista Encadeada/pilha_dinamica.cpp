#include <iostream>
#include "pilha_dinamica.h"
#include <cstddef> //NULL

using namespace std;

pilhadinamica::pilhadinamica() // construtor //dynamic stack
{
  NoTopo = NULL;
}

pilhadinamica::~pilhadinamica() // destrutor
{
  No *NoTemp;
  while (NoTopo != NULL)
  {
    NoTemp = NoTopo;
    NoTopo = NoTopo->proximo;
    delete NoTemp;
  }
}

bool pilhadinamica::isEmpty() // isempty
{
  return (NoTopo == NULL);
}

bool pilhadinamica::isFull() // tem memória //isfull
{
  No *NoNovo;
  try
  {
    NoNovo = new No;
    delete NoNovo;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void pilhadinamica::push(TipoItem item) 
{
  if (isFull())
  {
    cout << "A Pilha esta cheia!\n";
    cout << "Nao foi possivel inserir este elemento!\n";
  }
  else
  {
    No *NoNovo = new No;
    NoNovo->valor = item;
    NoNovo->proximo = NoTopo;
    NoTopo = NoNovo;
  }
}

TipoItem pilhadinamica::pop() 
{
  if (isEmpty())
  {
    cout << "A Pilha esta vazia!\n";
    cout << "Nao foi possivel remover nenhum elemento!\n";
    return 0;
  }
  else
  {
    No *NoTemp;
    NoTemp = NoTopo;
    TipoItem item = NoTopo->valor;
    NoTopo = NoTopo->proximo;
    delete NoTemp;
    return item;
  }
}

void pilhadinamica::print() 
{
  No *NoTemp = NoTopo;
  cout << "Pilha: [ ";
  while (NoTemp != NULL)
  {
    cout << NoTemp->valor << " ";
    NoTemp = NoTemp->proximo;
  }
  cout << "]\n";
}
