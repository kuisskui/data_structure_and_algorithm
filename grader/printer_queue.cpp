#include <iostream>

using namespace std;

int main()
{
    int rounds, items, position;
    cin >> rounds;
    while (rounds--)
    {
        cin >> items >> position;
        int array[items];

        for (int i = 0; i < items; i++)
        {
            cin >> array[i];
        }

        int self, result;
        self = array[position];
        result = 0;
        for (int i = 0; i < items; i++)
        {
            if (array[i] > self){
                result++;
            }
        }
        for (int i = 0; i < items; i++)
        {
            if (array[i] > self){
                result++;
            }
        }
        cout << result << endl;
    }
}