#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> x, y;
    int n, m, input;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        x.insert(input);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        y.insert(input);
    }
    
}