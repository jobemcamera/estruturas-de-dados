#include <iostream>
#include <cstddef>
#include "arvore_binaria.h"
using namespace std;

ArvoreBinariaBusca::ArvoreBinariaBusca() // construtor
{
  raiz = NULL;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca() // destrutor
{
}

void ArvoreBinariaBusca::deletarArvore(No *NoAtual)
{
}

No *ArvoreBinariaBusca::obterRaiz()
{
  return raiz;
}

bool ArvoreBinariaBusca::estaVazio()
{
  return (raiz == NULL);
}

bool ArvoreBinariaBusca::estaCheio()
{
  try
  {
    No *temp = new No;
    delete temp;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void ArvoreBinariaBusca::inserir(Aluno aluno)
{
}
void ArvoreBinariaBusca::remover(Aluno aluno)
{
}
void ArvoreBinariaBusca::buscar(Aluno &aluno, bool &busca)
{
}
void ArvoreBinariaBusca::imprimirPreOrdem(No *NoAtual)
{
}
void ArvoreBinariaBusca::imprimirEmOrdem(No *NoAtual)
{
}
void ArvoreBinariaBusca::imprimirPosOrdem(No *NoAtual)
{
}