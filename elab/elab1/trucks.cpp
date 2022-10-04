#include <iostream>

using namespace std;

int main()
{
    int packages = 0;

    cin >> packages;

    int i = 1;
    int load = 0;
    int truck = 1;
    int weight = 0;

    while (i <= packages)
    {
        cin >> weight;
        load = load + weight;
        
        if (load > 1000)
        {
            truck++;
            load = weight;
        }
        i++;
    }

    cout << truck;
}
