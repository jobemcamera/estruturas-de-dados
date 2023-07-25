#include <iostream>

int main()
{
  int number1;
  int number2;

  std::cout << "Digite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "Digite o segundo numero: ";
  std::cin >> number2;

  if (number1 == number2)
  {
    std::cout << number1 << " == " << number2 << std::endl;
  }
  else if (number1 != number2)
  {
    std::cout << number1 << " != " << number2 << std::endl;
  }
  else if (number1 < number2)
  {
    std::cout << number1 << " < " << number2 << std::endl;
  }
  else if (number1 > number2)
  {
    std::cout << number1 << " > " << number2 << std::endl;
  }

  return 0;
}
