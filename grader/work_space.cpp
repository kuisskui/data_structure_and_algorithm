#include <iostream>
using namespace std;

int main()
{
  char *text = (char*)malloc(sizeof(char)*10);
  cout << *text;
  cin >> *text;
  text++;
  cout << *text;
}
