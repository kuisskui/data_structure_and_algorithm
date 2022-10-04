#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = a+1; i <= b; i++)
    {
        a += i;
    }
    cout << a;
}

