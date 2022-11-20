#include <iostream>
#include <set>
using namespace std;
int main()
{
  std::set<int> Set;
  std::set<int>::iterator one, end;
  for (int i = 1; i < 10; i++)
    Set.insert(i * 10);
  int value = 25;
  one = Set.lower_bound(100);
  end = Set.upper_bound(100);
  cout << "Elements are: ";
  for (std::set<int>::iterator i = Set.begin(); i != Set.end(); ++i)
    std::cout << ' ' << *i;
  std::cout << ' ' << endl;
  cout << "lower: " << *one << endl;
  cout << "upper: " << *end << endl;
  return 0;
}