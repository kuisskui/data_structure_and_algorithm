#include <iostream>

using namespace std;

int main()
{
    int array_pyramid[10][10] = {0};
    int row = 9;
    int block = 9;
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 1; i <= row; i += 2)
        {
            for (int j = 1; j <= i; j += 2)
            {
                cin >> array_pyramid[i][j];
            }
        }

        for (int i = row; i >= 1; i -= 2)
        {
            for (int j = 2; j <= i; j += 2)
            {
                array_pyramid[i][j] = (array_pyramid[i - 2][j - 1] - (array_pyramid[i][j - 1] + array_pyramid[i][j + 1])) / 2;
                array_pyramid[i - 1][j - 1] = array_pyramid[i][j] + array_pyramid[i][j - 1];
                array_pyramid[i - 1][j] = array_pyramid[i][j] + array_pyramid[i][j + 1];
            }
        }

        for (int i = 1; i <= row; i += 1)
        {
            for (int j = 1; j <= i; j += 1)
            {
                if (j == i)
                {
                    cout << array_pyramid[i][j];
                }
                else
                {
                    cout << array_pyramid[i][j] << ' ';
                }
            }
            if (i != row)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
}