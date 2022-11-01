#include <iostream>

using namespace std;

bool check_pair(int p1, int p2, int pro_price, int max)
{
    int sum_p = p1 + p2;
    int diff_p = abs(p1 - p2);
    if (sum_p >= pro_price && diff_p <= max)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, pro_price, max;
    int counter = 0;
    int a[n];
    cin >> n >> pro_price >> max;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check_pair(a[i], a[j], pro_price, max))
            {
                counter++;
            }
        }
    }
    cout << counter << endl;
}