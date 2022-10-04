#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    cin >> n;
    
    int l = n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {
            if (j < l)
            {
                cout << " ";
            } else{
                cout << "*";
            }
        }
        l--;
        cout << "" << endl;
    }
}