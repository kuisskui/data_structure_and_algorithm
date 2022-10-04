#include <iostream>

using namespace std;

main()
{
    int n;
    cin >> n;
    int hp = 100; // initial HP
    int max_hp = hp;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        hp += a;
        if (hp <= 0)
        {
            break;
        }
        if (hp > 0)
        {
            if (hp > max_hp)
            {
                max_hp = hp;
            }
        }
    }
    cout << max_hp << endl;
}
