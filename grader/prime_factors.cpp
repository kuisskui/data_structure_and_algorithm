#include <iostream>
using namespace std;

int main()
{
    int prime_number = 1;
    int total = 0;
    int number;
    cin >> number;
    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            number /= i;
            if (prime_number != i){
                total += 1;
                prime_number = i;
            }
            i--;
        }
    }
    cout << total << endl;
}
