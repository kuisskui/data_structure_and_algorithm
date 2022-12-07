#include <iostream>
#include <set>

using namespace std;

int main(void)
{
  set<int> m = {10, 20, 30, 40};

  int value = 5;
  // auto up = m.upper_bound(value);
  auto lo = m.lower_bound(value);

  // cout << "Upper bound of b is(>): " << *up << endl;
  cout << "Lower bound of b is(>): " << *lo << endl;
  // if (up == m.end()){
  //   cout << "it's here" << endl;
  // }
  value = 10;
  // up = m.upper_bound(value);
  lo = m.lower_bound(value);
  if ((lo--) == m.begin()){
    cout << "it's here again" << endl;
  }
  // cout << *(--up) << endl;
  // cout << *(up) << endl;

  return 0;
}