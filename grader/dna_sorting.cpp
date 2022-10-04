#include <iostream>
#include <string>

using namespace std;

struct dna
{
    int val;
    string dna_string;
    dna(int val = 0, string dna_string = "")
        : val(val), dna_string(dna_string) {}
};

void bubble_sort(dna a[], int n)
{
    while (true)
    {
        bool changed = false;
        for (int i = 0; i < n - 1; i++)
        {
            // compares a[i] with a[i+1]
            if (a[i].val > a[i + 1].val)
            {
                // wrong order, swap them;  don't forget to update changed variable
                swap(a[i], a[i + 1]);
                bubble_sort(a, n);
            }
        }
        if (!changed)
            break;
    }
}

int main()
{
    int n_data_set = 0;
    int length = 0;
    int n_line = 0;
    cin >> n_data_set;
    for (int i = 0; i < n_data_set; i++)
    {
        dna array_dna[100];
        cin >> length >> n_line;
        for (int j = 0; j < n_line; j++)
        {
            cin >> array_dna[j].dna_string;
            for (int k = 0; k < length - 1; k++)
            {
                for (int o = k + 1; o < length; o++)
                    if (array_dna[j].dna_string[k] > array_dna[j].dna_string[o])
                    {
                        array_dna[j].val += 1;
                    }
            }
        }
        bubble_sort(array_dna, n_line);
        for (int j = 0; j < n_line; j++)
        {
            for (int k = 0; k < length; k++)
            {
                cout << array_dna[j].dna_string[k];
            }
            cout << endl;
        }

        if (i != n_data_set - 1)
        {
            cout << endl;
        }
    }
}
