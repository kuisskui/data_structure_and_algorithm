#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n_rock, stack;
    int rock;
    cin >> n_rock >> stack;
    vector<int> array_rock;
    for (int i = 0; i < n_rock; i++)
    {
        cin >> rock;
        array_rock.push_back(rock);
    }
    for (int j = 0; j < array_rock.size(); j++){
        cout << array_rock[j] << ' ';
    }
    for (int i = 0; i < n_rock-stack+1; i++)
    {
        bool destroy = true;
        for (int j = i + 1; j < i + stack; j++)
        {
            if (array_rock[i] != array_rock[j])
            {
                destroy = false;
            }
        }
        if (destroy)
        {
            for (int k = 0; k < stack; k++)
            {
                array_rock.erase(array_rock.begin() + i);
            }
            n_rock -= stack;
            i = 0;
        }
    }
    cout << array_rock.size();
}