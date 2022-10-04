#include <iostream>

using namespace std;

int main()
{
    int first = 0;
    int second = 0;

    cin >> first >> second;

    int min = first;

    if (first > second)
    {
        min = second;
    }

    int i = 2;

    while (i < min)
    {
        if (first % i == 0 && second % i == 0)
        {
            first = first / i;
            second = second / i;
            i = 1;
        }
        i++;
    }
    
    cout << first << '/' << second;
}
