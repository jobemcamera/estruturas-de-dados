#include <iostream>
#include <cstddef>
#include "arvore_avl.h"
using namespace std;

ArvoreAVL::ArvoreAVL() // construtor
{
  raiz = NULL;
}

ArvoreAVL::~ArvoreAVL() // destrutor
{
  deletarArvore(raiz);
}

void ArvoreAVL::deletarArvore(No *NoAtual)
{
  if (NoAtual != NULL)
  {
    deletarArvore(NoAtual->filho_esquerda);
    deletarArvore(NoAtual->filho_direita);

    delete NoAtual;
  }
}

No *ArvoreAVL::obterRaiz()
{
  return raiz;
}

bool ArvoreAVL::estaVazio()
{
  return (raiz == NULL);
}

bool ArvoreAVL::estaCheio()
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

void ArvoreAVL::inserir(Aluno aluno)
{
  bool cresceu;
  insereRecursivo(raiz, aluno, cresceu);
}

void ArvoreAVL::insereRecursivo(No *&NoAtual, Aluno aluno, bool &cresceu)
{
  if (NoAtual == NULL)
  {
    NoAtual = new No;
    NoAtual->filho_direita = NULL;
    NoAtual->filho_esquerda = NULL;
    NoAtual->aluno = aluno;
    NoAtual->fatorB = 0;
    cresceu = true;
    return;
  }

  if (aluno.obterRa() < NoAtual->aluno.obterRa())
  {
    insereRecursivo(NoAtual->filho_esquerda, aluno, cresceu);
    if (cresceu)
    {
      NoAtual->fatorB -= 1;
    }
    else
    {
      insereRecursivo(NoAtual->filho_direita, aluno, cresceu);
      if (cresceu)
      {
        NoAtual->fatorB += 1;
      }
    }
  }
  realizaRotacao(NoAtual);

  if (cresceu && NoAtual->fatorB == 0)
  {
    cresceu = false;
  }
}

void ArvoreAVL::remover(Aluno aluno)
{
  bool diminuiu;
  removerBusca(aluno, raiz, diminuiu);
}

void ArvoreAVL::removerBusca(Aluno aluno, No *&NoAtual, bool &diminuiu)
{
  if (aluno.obterRa() < NoAtual->aluno.obterRa())
  {
    removerBusca(aluno, NoAtual->filho_esquerda, diminuiu);
    if (diminuiu)
    {
      NoAtual->fatorB += 1;
    }
  }
  else if (aluno.obterRa() > NoAtual->aluno.obterRa())
  {
    removerBusca(aluno, NoAtual->filho_direita, diminuiu);
    if (diminuiu)
    {
      NoAtual->fatorB -= 1;
    }
  }
  else
  {
    deletarNo(NoAtual, diminuiu);
  }
  if (NoAtual != NULL)
  {
    realizaRotacao(NoAtual);
    if (diminuiu && NoAtual->fatorB != 0)
    {
      diminuiu = false;
    }
  }
}

void ArvoreAVL::deletarNo(No *&NoAtual, bool &diminuiu)
{
  No *temp = NoAtual;
  if (NoAtual->filho_esquerda == NULL)
  {
    NoAtual = NoAtual->filho_direita;
    diminuiu = true;
    delete temp;
  }
  else if (NoAtual->filho_direita == NULL)
  {
    NoAtual = NoAtual->filho_esquerda;
    diminuiu = true;
    delete temp;
  }
  else
  {
    Aluno AlunoSucessor;
    obterSucessor(AlunoSucessor, NoAtual);
    NoAtual->aluno = AlunoSucessor;
    removerBusca(AlunoSucessor, NoAtual->filho_direita, diminuiu);
    if (diminuiu)
    {
      NoAtual->fatorB -= 1;
    }
  }
}

void ArvoreAVL::obterSucessor(Aluno &alunoSucessor, No *temp)
{
  // da um passo a direita e depois sempre a esquerda (menor valor a direita)
  temp = temp->filho_direita;

  // chegar no menor valor
  while (temp->filho_esquerda != NULL)
  {
    temp = temp->filho_esquerda;
  }

  alunoSucessor = temp->aluno; // manda o valor do sucessor para o deletarNo
}

void ArvoreAVL::buscar(Aluno &aluno, bool &busca)
{
  busca = false;
  No *NoAtual = raiz;

  while (NoAtual != NULL)
  {
    // procura se esta a esquerda da raiz
    if (aluno.obterRa() < NoAtual->aluno.obterRa())
    {
      NoAtual = NoAtual->filho_esquerda; // proximo laço
    }
    // procura se esta a direita da raiz
    else if (aluno.obterRa() > NoAtual->aluno.obterRa())
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

void ArvoreAVL::imprimirPreOrdem(No *NoAtual)
{
  // Raiz é a primeira a ser impressa
  // Imprime todos os pais antes dos filhos

  if (NoAtual != NULL)
  {
    cout << "Nome: " << NoAtual->aluno.obterNome() << " RA: ";
    cout << NoAtual->aluno.obterRa() << endl;

    imprimirPreOrdem(NoAtual->filho_esquerda);
    imprimirPreOrdem(NoAtual->filho_direita);
  }
}
void ArvoreAVL::imprimirEmOrdem(No *NoAtual)
{
  // Sequência crescente

  if (NoAtual != NULL)
  {
    imprimirEmOrdem(NoAtual->filho_esquerda);

    cout << "Nome: " << NoAtual->aluno.obterNome() << " RA: ";
    cout << NoAtual->aluno.obterRa() << endl;

    imprimirEmOrdem(NoAtual->filho_direita);
  }
}
void ArvoreAVL::imprimirPosOrdem(No *NoAtual)
{
  // Raiz é a ultima a ser impressa
  // Imprime todos os filhos antes dos pais

  if (NoAtual != NULL)
  {
    imprimirPosOrdem(NoAtual->filho_esquerda);
    imprimirPosOrdem(NoAtual->filho_direita);

    cout << "Nome: " << NoAtual->aluno.obterNome() << " RA: ";
    cout << NoAtual->aluno.obterRa() << endl;
  }
}

void ArvoreAVL::rotacaoDireita(No *&pai)
{
  No *novoPai = pai->filho_esquerda;
  pai->filho_esquerda = novoPai->filho_direita;
  novoPai->filho_direita = pai;
  pai = novoPai;
}

void ArvoreAVL::rotacaoEsquerda(No *&pai)
{
  No *novoPai = pai->filho_direita;
  pai->filho_direita = novoPai->filho_esquerda;
  novoPai->filho_esquerda = pai;
  pai = novoPai;
}

void ArvoreAVL::rotacoesEsquerdaDireita(No *&pai)
{
  No *filho = pai->filho_esquerda;
  rotacaoEsquerda(filho);
  pai->filho_esquerda = filho;
  rotacaoDireita(pai);
}

void ArvoreAVL::rotacoesDireitaEsquerda(No *&pai)
{
  No *filho = pai->filho_direita;
  rotacaoDireita(filho);
  pai->filho_direita = filho;
  rotacaoEsquerda(pai);
}

void ArvoreAVL::realizaRotacao(No *&pai)
{
  No *filho;
  No *neto; // Caso precise da rotação dupla

  if (pai->fatorB == -2)
  { // rotaciona para a direita

    filho = pai->filho_esquerda;

    if (filho->fatorB == -1)
    { // Simples para a direita
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaoDireita(pai);
    }
    else if (filho->fatorB == 0)
    { // Simples para a direita
      pai->fatorB = -1;
      filho->fatorB = 1;
      rotacaoDireita(pai);
    }
    else if (filho->fatorB == 1)
    { // Rotação dupla
      neto = filho->filho_direita;
      if (neto->fatorB == -1)
      {
        pai->fatorB = 1;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 0)
      {
        pai->fatorB = 0;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 1)
      {
        pai->fatorB = 0;
        filho->fatorB = -1;
      }
      neto->fatorB = 0;
      rotacoesDireitaEsquerda(pai);
    }
  }
  else if (pai->fatorB == 2)
  { // rotaciona para a esquerda
    filho = pai->filho_direita;
    if (filho->fatorB == 1)
    { // Simples para a esquerda
      pai->fatorB = 0;
      filho->fatorB = 0;
      rotacaoEsquerda(pai);
    }
    else if (filho->fatorB == 0)
    { // Simples para a esquerda
      pai->fatorB = 1;
      filho->fatorB = -1;
      rotacaoEsquerda(pai);
    }
    else if (filho->fatorB == -1)
    { // Rotacao dupla
      neto = filho->filho_esquerda;
      if (neto->fatorB == -1)
      {
        pai->fatorB = 0;
        filho->fatorB = 1;
      }
      else if (neto->fatorB == 0)
      {
        pai->fatorB = 0;
        filho->fatorB = 0;
      }
      else if (neto->fatorB == 1)
      {
        pai->fatorB = -1;
        filho->fatorB = 0;
      }
      neto->fatorB = 0;
      rotacoesDireitaEsquerda(pai);
    }
  }
}