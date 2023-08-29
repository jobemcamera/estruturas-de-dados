#include <iostream>
#include "aluno.h"

struct No
{
  Aluno aluno; // informação = objeto Aluno
  No *filho_esquerda;
  No *filho_direita;

  int fatorB; // fator de balanceamento
};

class ArvoreAVL
{
private:
  No *raiz;

public:
  ArvoreAVL();
  ~ArvoreAVL();
  void deletarArvore(No *NoAtual); // chamar deletarArvore dentro do destrutor
  No *obterRaiz();
  bool estaVazio();
  bool estaCheio();
  void inserir(Aluno aluno);                                      // chamar novos métodos (rotacoes)
  void remover(Aluno aluno);                                      // chamar removerBusca()
  void removerBusca(Aluno aluno, No *&NoAtual, bool &diminuiu);   // chamar no remover()
  void deletarNo(No *&NoAtual, bool &diminuiu);                   // chamar no remover()
  void obterSucessor(Aluno &alunoSucessor, No *temp);             // chamar no remover()
  void buscar(Aluno &aluno, bool &busca);
  void imprimirPreOrdem(No *NoAtual);
  void imprimirEmOrdem(No *NoAtual);
  void imprimirPosOrdem(No *NoAtual);

  // Novos métodos
  void rotacaoDireita(No *&tree);
  void rotacaoEsquerda(No *&tree);
  void rotacoesEsquerdaDireita(No *&tree);
  void rotacoesDireitaEsquerda(No *&tree);
  void realizaRotacao(No *&tree);
  void insereRecursivo(No *&NoAtual, Aluno aluno, bool &cresceu);
};