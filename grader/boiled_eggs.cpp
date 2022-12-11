#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n_testcases, n_eggs, m_eggs, m_weight, temp, counter_eggs, counter_weight;
    vector<int> weight_eggs;
    cin >> n_testcases;
    for (int i = 0; i < n_testcases; i++)
    {
        counter_eggs = 0;
        counter_weight = 0;
        weight_eggs.clear();
        cin >> n_eggs >> m_eggs >> m_weight;
        for (int j = 0; j < n_eggs; j++)
        {
            cin >> temp;
            weight_eggs.push_back(temp);
        }
        sort(weight_eggs.begin(), weight_eggs.end());
        for (int j = 0; j < n_eggs; j++)
        {
            if (counter_eggs >= m_eggs)
            {
                break;
            }
            if (counter_weight + weight_eggs[j] > m_weight)
            {
                break;
            }
            counter_weight += weight_eggs[j];
            ++counter_eggs;
        }
        cout << "Case " << i + 1 << ": " << counter_eggs << endl;
    }
}