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
  No *temp = NoAtual; // NoAtual é o ponteiro apontando para o item que vou deletar

  if (NoAtual->filho_esquerda == NULL)
  {
    NoAtual = NoAtual->filho_direita;
    delete temp;
  }
  else if (NoAtual->filho_direita == NULL)
  {
    NoAtual = NoAtual->filho_esquerda;
    delete temp;
  }
  else // no tem 2 filhos
  {
    Aluno alunoSucessor; // (ra = -1, aluno = " ")
    obterSucessor(alunoSucessor, NoAtual);
    NoAtual->aluno = alunoSucessor; // so pega o valor, nao mudamos os ponteiros dele
    removerBusca(alunoSucessor, NoAtual->filho_direita); // remover o valor que ficou igual 
  }
}

void ArvoreBinariaBusca::obterSucessor(Aluno &alunoSucessor, No *temp)
{
  // da um passo a direita e depois sempre a esquerda (menor valor a direita)
  temp = temp->filho_direita;

  // chegar no menor valor
  while (temp->filho_esquerda != NULL)
  {
    temp = temp->filho_esquerda;
  }

  alunoSucessor = temp->aluno;  // manda o valor do sucessor para o deletarNo
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
  // Raiz é a primeira a ser impressa
  // Imprime todos os pais antes dos filhos

  if (NoAtual != NULL)
  {
    cout <<"Nome: " << NoAtual->aluno.obterNome() << "/ RA: ";
    cout << NoAtual->aluno.obeterRa() << endl;

    imprimirPreOrdem(NoAtual->filho_esquerda);
    imprimirPreOrdem(NoAtual->filho_direita);
  }
}
void ArvoreBinariaBusca::imprimirEmOrdem(No *NoAtual)
{
  // Sequência crescente

  if (NoAtual != NULL)
  {
    imprimirEmOrdem(NoAtual->filho_esquerda);

    cout <<"Nome: " << NoAtual->aluno.obterNome() << "/ RA: ";
    cout << NoAtual->aluno.obeterRa() << endl;
    
    imprimirEmOrdem(NoAtual->filho_direita);
  }
}
void ArvoreBinariaBusca::imprimirPosOrdem(No *NoAtual)
{
}