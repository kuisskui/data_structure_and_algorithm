#include <iostream>

using namespace std;

bool check_prime(int p)
{
  if (p <= 1)
  {
    return false;
  }
  if (p == 2 || p == 3)
  {
    return true;
  }
  for (int i = 2; i < p; i++)
  {
    if (p % i == 0)
    {
      return false;
    }
  }
  return true;
}

int next_prime(int t)
{
  while (true)
  {
    ++t;
    if (check_prime(t))
    {
      return t;
    }
  }
}

int main()
{
  int p;

  cin >> p;

  cout << next_prime(p);
}