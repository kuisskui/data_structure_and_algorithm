#include <iostream>
using namespace std;

int main()
{
    int coaches;
    while (true)
    {
        cin >> coaches;
        if (coaches == 0)
        {
            break;
        }

        while (true)
        {
            int array_coaches[coaches];
            int array_arrived_coaches[coaches];
            int counter_arrived = 0;
            bool state = true;
            cin >> array_coaches[0];
            if (array_coaches[0] == 0)
            {
                break;
            }
            for (int i = 1; i < coaches; i++)
            {
                cin >> array_coaches[i];
            }

            array_arrived_coaches[0] = array_coaches[0];
            counter_arrived++;
            for (int i = 0; i < coaches - 1; i++)
            {
                if (array_coaches[i + 1] > array_coaches[i])
                {
                    array_arrived_coaches[counter_arrived] = array_coaches[i + 1];
                    counter_arrived++;
                    continue;
                }
                if (array_coaches[i + 1] + 1 == array_coaches[i])
                {
                    array_arrived_coaches[counter_arrived] = array_coaches[i + 1];
                    counter_arrived++;
                }
                else if (array_coaches[i + 1] + 1 != array_coaches[i])
                {
                    bool is_in = false;
                    for (int j = 0; j < counter_arrived; j++)
                    {
                        if (array_coaches[i + 1] + 1 == array_arrived_coaches[j])
                        {
                            is_in = true;
                            break; // can omit
                        }
                    }
                    if (is_in)
                    {
                        array_arrived_coaches[counter_arrived] = array_coaches[i + 1];
                        counter_arrived++;
                    }
                    else
                    {
                        state = false;
                        break;
                    }
                }
            }
            if (state)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        // if (coaches != 0){
        //     cout << endl;

        // }
        cout << endl;
    }
}