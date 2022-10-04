#include <iostream>

using namespace std;

int main(){
    int n;
    int array[100];
    cin >> n;

    int i = 0;
    while (i < n){
        int tall;

        cin >> tall;
        array[i] = tall;
        i++;
    }
    i = 0;
    int count;
    int j;
    while (i < n)
    {
        count = 0;
        j = 0;
        while (j < n)
        {
            if (array[j] > array[i]){
                count++;
            }
            j++;
        }
        cout << count << endl;
        i++;
    }
}