#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n_testcases, n_battlefields, n_green, n_blue, x;
    cin >> n_testcases;
    while (n_testcases--)
    {
        priority_queue<int> green_lemmings, blue_lemmings;
        vector<int> green_remaining, blue_remaining;

        cin >> n_battlefields >> n_green >> n_blue;
        for (int i = 0; i < n_green; i++)
        {
            cin >> x;
            green_lemmings.push(x);
        }
        for (int i = 0; i < n_blue; i++)
        {
            cin >> x;
            blue_lemmings.push(x);
        }

        while (true)
        {
            int use_battlefields = n_battlefields;
            int green_size = green_lemmings.size();
            int blue_size = blue_lemmings.size();

            if (green_size == 0 || blue_size == 0)
            {
                break;
            }
            if (green_size < n_battlefields || blue_size < n_battlefields)
            {
                use_battlefields = min(green_size, blue_size);
            }

            for (int i = 0; i < use_battlefields; i++)
            {
                int green = green_lemmings.top();
                int blue = blue_lemmings.top();
                green_lemmings.pop();
                blue_lemmings.pop();

                if (green > blue)
                {
                    green_remaining.push_back(green - blue);
                }
                else if (green < blue)
                {
                    blue_remaining.push_back(blue - green);
                }
            }
            for (int i = 0; i < green_remaining.size(); i++)
            {
                green_lemmings.push(green_remaining[i]);
            }
            for (int i = 0; i < blue_remaining.size(); i++)
            {
                blue_lemmings.push(blue_remaining[i]);
            }
            green_remaining.clear();
            blue_remaining.clear();
        }

        if (green_lemmings.size())
        {
            cout << "green wins" << endl;
            while (!green_lemmings.empty())
            {
                cout << green_lemmings.top() << endl;
                green_lemmings.pop();
            }
        }
        else if (blue_lemmings.size())
        {
            cout << "blue wins" << endl;
            while (!blue_lemmings.empty())
            {
                cout << blue_lemmings.top() << endl;
                blue_lemmings.pop();
            }
        }
        else
        {
            cout << "green and blue died" << endl;
        }
        if (n_testcases){
            cout << endl;
        }
    }
}