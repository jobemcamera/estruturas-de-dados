// Classes em C++ - Programação Orientada a Objetos (POO)
// A unidade básica da POO é a classe, que encapsula atributos estáticos e comportamento dinâmicos em uma caixa.
// Classe é um modelo usado para criar objetos, também chamados de instâncias
// A comunicação com os objetos é feita pelo uso da interface pública do objeto
// A visão lógica de uma classe será sempre criada em um arquivo de extensão .h
// Nesse arquivo, definiremos os membros públicos e privados de uma classe
// A implementação da classe será sempre feita em um arquivo de extensão .cpp
// O arquivo .cpp deverá sempre importar o arquivo .h com a diretiva include

#include <iostream>
#include "001_time.h"

using namespace std;

// Construtor
Time::Time(int hour, int minute, int second)
{
  this->hour = hour;
  this->minute = minute;
  this->second = second;
}

// Getters
int Time::getHour() const
{
  return hour;
}

int Time::getMinute() const
{
  return minute;
}

int Time::getSecond() const
{
  return second;
}

// Setters
void Time::setHour(int hour)
{
  this->hour = hour;
}

void Time::setMinute(int minute)
{
  this->minute = minute;
}

void Time::setSecond(int second)
{
  this->second = second;
}

void Time::print() const
{
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond()
{
  second += 1;
  if (second >= 60) 
  {
    second = 0;
    minute += 1;
  }
  if (minute >= 60)
  {
    minute = 0;
    hour += 1;
  }
  if (hour >= 24) 
  {
    hour = 0;
  }
}