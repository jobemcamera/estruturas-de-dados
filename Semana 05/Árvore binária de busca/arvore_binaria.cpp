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
  if (estaCheio())
  {
    cout << "A Arvore esta cheia!\n";
    cout << "Nao foi possivel inserir aluno.\n";
  }
  else
  {
    No *NoNovo = new No;
    NoNovo->aluno = aluno;
    NoNovo->filho_direita = NULL;
    NoNovo->filho_esquerda = NULL;

    if (raiz == NULL) // arvore vazia
    {
      raiz = NoNovo;
    }
    else
    {
      No *temp = raiz;

      while (temp != NULL)
      {
        // verifica se vai inserir a esquerda
        if (aluno.obeterRa() < temp->aluno.obeterRa())
        {
          if (temp->filho_esquerda == NULL)
          {
            temp->filho_esquerda = NoNovo;
            break;
          }
          else
          {
            temp = temp->filho_esquerda; // proximo laço
          }
        }
        // verifica se vai inserir a direita
        else // aluno.obeterRa() > temp->aluno.obeterRa()
        {
          if (temp->filho_direita == NULL)
          {
            temp->filho_direita = NoNovo;
            break;
          }
          else
          {
            temp = temp->filho_direita; // proximo laço
          }
        }
      }
    }
  }
}

void ArvoreBinariaBusca::remover(Aluno aluno)
{
  removerBusca(aluno, raiz);
}

void ArvoreBinariaBusca::removerBusca(Aluno aluno, No *&NoAtual) // funcao recursiva
{
  // busca a esquerda
  if (aluno.obeterRa() < NoAtual->aluno.obeterRa())
  {
    removerBusca(aluno, NoAtual->filho_esquerda);
  }
  // busca a direita
  else if (aluno.obeterRa() > NoAtual->aluno.obeterRa())
  {
    removerBusca(aluno, NoAtual->filho_direita);
  }
  // achou aluno
  else
  {
    deletarNo(NoAtual);
  }
}

void ArvoreBinariaBusca::deletarNo(No *&NoAtual)
{
}
void ArvoreBinariaBusca::obterSucessor(Aluno &alunoSucessor, No *temp)
{
}

void ArvoreBinariaBusca::buscar(Aluno &aluno, bool &busca)
{
  busca = false;
  No *NoAtual = raiz;

  while (NoAtual != NULL)
  {
    // procura se esta a esquerda da raiz
    if (aluno.obeterRa() < NoAtual->aluno.obeterRa())
    {
      NoAtual = NoAtual->filho_esquerda; // proximo laço
    }
    // procura se esta a direita da raiz
    else if (aluno.obeterRa() > NoAtual->aluno.obeterRa())
    {
      NoAtual = NoAtual->filho_direita; // proximo laço
    }
    // valor encontrado
    else
    {
      busca = true;
      aluno = NoAtual->aluno; // aluno (por referencia) so vem com RA, agora passamos a informacao completa (NoAtual) nome e RA
      break;
    }
  }
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