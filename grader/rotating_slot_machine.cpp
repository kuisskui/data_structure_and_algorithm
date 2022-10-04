#include <iostream>
using namespace std;

void rotating_array(int a[])
{
    swap(a[0], a[1]);
    swap(a[1], a[2]);
    swap(a[2], a[3]);
}

int main()
{
    int column1[4];
    int column2[4];
    int column3[4];
    int column4[4];

    for (int i = 0; i < 4; i++)
    {
        cin >> column1[i];
        cin >> column2[i];
        cin >> column3[i];
        cin >> column4[i];
    }

    int max_score = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    int score = 0;
                    for (int a = 0; a < 4; a++)
                    {
                        if (column1[a]==column2[a]&&column1[a]==column3[a]&&column1[a]==column4[a]){
                            score++;
                        }
                    }
                    if (score>max_score){
                        max_score = score;
                        if (max_score==4){
                            cout << 4;
                            return 0;
                        }
                    }
                    rotating_array(column4);
                }
                rotating_array(column3);
            }
            rotating_array(column2);
        }
        rotating_array(column1);
    }

    cout << max_score;
}