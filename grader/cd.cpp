#include <iostream>
#include <set>

using namespace std;

const int MAX_CD = 1000010;
int main()
{
    int Jack_cd;
    int Jill_cd;
    while (true)
    {
        set<int> Jack, Jill;
        int counter = 0;
        int x = 0;

        cin >> Jack_cd >> Jill_cd;
        if (Jack_cd == 0 && Jill_cd == 0)
        {
            break;
        }
        for (int i = 0; i < Jack_cd; i++)
        {
            cin >> x;
            Jack.insert(x);
        }
        for (int i = 0; i < Jill_cd; i++)
        {
            cin >> x;
            Jill.insert(x);
        }

        for (auto i = Jack.begin(); i != Jack.end(); i++)
        {

            if (Jill.find(*i) != Jill.end())
            {
                counter += 1;
            }
        }

        cout << counter << endl;
    }
}