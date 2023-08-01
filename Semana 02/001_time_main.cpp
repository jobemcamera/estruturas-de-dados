// Para compilar: g++ 001_time.cpp 001_time_main.cpp -o 001_time
// Para executar: ./001_time

#include <iostream>
#include "001_time.h"

using namespace std;

int main()
{
  // Neste primeiro objeto, passamos todos os parâmetros. Em outras palavras, nenhum valor padrão foi usado.

  Time t1(23, 59, 59);
  t1.print();       // 23:59:59
  t1.setHour(12);
  t1.setMinute(30);
  t1.setSecond(15);

  t1.print();       // 12:30:15
  cout << "Hour:    " << t1.getHour() << endl;
  cout << "Minute:  " << t1.getMinute() << endl;
  cout << "Second:  " << t1.getMinute() << endl;

  cout << "\n" << endl;

  // Nesta segunda instância, usamos o padrão apenas para minutos e segundos

  Time t2(12);
  t2.print();     // 12:00:00

  cout << "\n" << endl;

  // No terceiro objeto, vamos utilizar o método nextSecond

  Time t3(23, 59, 58);
  t3.print();     // 23:59:58
  t3.nextSecond();
  t3.print();     // 23:59:59
  t3.nextSecond();
  t3.print();     // 00:00:00
}