#include <iostream>
using namespace std;

void dosomething(int *a, int b, int *c)
{

    *a += 10;

    b += 100;

    *c += 1000;
}

int main()
{
    int x = 1;
    int z = 3;
    int y = 2;

    dosomething(&x, y, &z);

    cout << x << " " << y << " " << z << endl;
}

