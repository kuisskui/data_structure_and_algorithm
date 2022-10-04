#include <iostream>

using namespace std;

int main()
{
    int digits;
    cin >> digits;
    
    int n_digit = 0;
    int array[100];
    while (digits > 0)
    {
        array[n_digit] = digits % 10;
        digits /= 10;
        n_digit++;
    }
    
    int i = 0;
    int j = n_digit-1;
    while (i < n_digit && j >= 0)
    {
        if (array[i] != array[j])
        {
            cout << "no";
            return 0;
        }
        j--;
        i++;
    }
    cout << "yes";
}