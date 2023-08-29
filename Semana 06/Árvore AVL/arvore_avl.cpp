#include <iostream>
#include <cstddef>
#include "arvore_avl.h" //modificado

using namespace std;

ArvoreAVL::ArvoreAVL() // construtor  //mudounome
{
  raiz = NULL;
}

ArvoreAVL::~ArvoreAVL() // destrutor //mudounome
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

void ArvoreAVL::inserir(Aluno aluno) // modificada
{
  bool cresceu;
  insereRecursivo(raiz, aluno, cresceu);
}

void ArvoreAVL::insereRecursivo(No *&NoAtual, Aluno aluno, bool &cresceu)
{ // novo
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
  }
  else
  {
    insereRecursivo(NoAtual->filho_direita, aluno, cresceu);
    if (cresceu)
    {
      NoAtual->fatorB += 1;
    }
  }
  realizaRotacao(NoAtual);

  if (cresceu && NoAtual->fatorB == 0)
  {
    cresceu = false;
  }
}

void ArvoreAVL::remover(Aluno aluno) // modificada
{
  bool diminuiu;
  removerBusca(aluno, raiz, diminuiu);
}

void ArvoreAVL::removerBusca(Aluno aluno, No *&NoAtual, bool &diminuiu)
{ // modificada
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

void ArvoreAVL::obterSucessor(Aluno &AlunoSucessor, No *temp)
{
  temp = temp->filho_direita;
  while (temp->filho_esquerda != NULL)
  {
    temp = temp->filho_esquerda;
  }
  AlunoSucessor = temp->aluno;
}

void ArvoreAVL::buscar(Aluno &aluno, bool &busca)
{
  busca = false;
  No *NoAtual = raiz;
  while (NoAtual != NULL)
  {
    if (aluno.obterRa() < NoAtual->aluno.obterRa())
    {
      NoAtual = NoAtual->filho_esquerda;
    }
    else if (aluno.obterRa() > NoAtual->aluno.obterRa())
    {
      NoAtual = NoAtual->filho_direita;
    }
    else
    {
      busca = true;
      aluno = NoAtual->aluno;
      break;
    }
  }
}

void ArvoreAVL::imprimirPreOrdem(No *NoAtual)
{
  if (NoAtual != NULL)
  {
    cout << NoAtual->aluno.obterNome() << ": ";
    cout << NoAtual->aluno.obterRa() << endl;

    imprimirPreOrdem(NoAtual->filho_esquerda);

    imprimirPreOrdem(NoAtual->filho_direita);
  }
}

void ArvoreAVL::imprimirEmOrdem(No *NoAtual)
{
  if (NoAtual != NULL)
  {
    imprimirEmOrdem(NoAtual->filho_esquerda);

    cout << NoAtual->aluno.obterNome() << ": ";
    cout << NoAtual->aluno.obterRa() << endl;

    imprimirEmOrdem(NoAtual->filho_direita);
  }
}

void ArvoreAVL::imprimirPosOrdem(No *NoAtual)
{
  if (NoAtual != NULL)
  {
    imprimirPosOrdem(NoAtual->filho_esquerda);

    imprimirPosOrdem(NoAtual->filho_direita);

    cout << NoAtual->aluno.obterNome() << ": ";
    cout << NoAtual->aluno.obterRa() << endl;
  }
}

void ArvoreAVL::rotacaoDireita(No *&pai) // novo
{
  No *novopai = pai->filho_esquerda;
  pai->filho_esquerda = novopai->filho_direita;
  novopai->filho_direita = pai;
  pai = novopai;
}

void ArvoreAVL::rotacaoEsquerda(No *&pai) // novo
{
  No *novopai = pai->filho_direita;
  pai->filho_direita = novopai->filho_esquerda;
  novopai->filho_esquerda = pai;
  pai = novopai;
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