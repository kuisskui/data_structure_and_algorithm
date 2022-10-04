#include <iostream>
using namespace std;

void check_tt(int a[], int *tt, int n)
{
  if (*tt >= n)
  {
    *tt %= n;
  }
  while (a[*tt] == 0)
  {
    (*tt)++;
    if (*tt >= n)
    {
      *tt %= n;
    }
  }
}
int main()
{
  int n, t, tt;
  cin >> n >> t;
  int a[n];
  int i = 0;
  while (i < n)
  {
    i++;
    a[i] = i;
  }
  a[0] = i;
  // a[7] = {7, 1, 2, 3, 4, 5, 6}
  tt = t;
  for (i = 0; i < n-1; i++)
  {
    check_tt(a, &tt, n);
    a[tt] = 0;
    for (int j = 0; j < t; j++)
    {
      tt++;
      check_tt(a, &tt, n);
    }
  }
  cout << a[tt] << endl;
}

