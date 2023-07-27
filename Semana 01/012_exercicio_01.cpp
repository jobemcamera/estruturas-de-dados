#include <iostream>
using namespace std;

int main()
{
  double Number1, Number2, Number3, Number4, Number5;
  double Average;
  cout << "Enter five numbers: ";
  cin >> Number1 >> Number2 >> Number3 >> Number4 >> Number5;
  Average = (Number1 + Number2 + Number3 + Number4 + Number5) / 5;
  cout << "Average = " << Average << endl;
  return 0;
}