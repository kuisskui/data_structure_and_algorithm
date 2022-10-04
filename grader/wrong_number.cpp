#include <iostream>
using namespace std;

int sum_row(int array[], int size)
{
    int total = 0;
    int i = 0;
    while (i < size)
    {
        total += array[i];
        i++;
    }
    return total;
}

int main()
{
    int size;
    cin >> size;
    int nested_array[size][size];
    int nested_array_for_column[size][size];
    int real_value_row;
    int real_value_column;
    int target_row;
    int target_column;

    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            cin >> nested_array[i][j];
            nested_array_for_column[j][i] = nested_array[i][j];
            j++;
        }
        i++;
    }

    // cout << nested_array[0][0] << ' ' << nested_array[0][1] << ' ' << nested_array[0][2] << endl;
    // cout << nested_array[1][0] << ' ' << nested_array[1][1] << ' ' << nested_array[1][2] << endl;
    // cout << nested_array[2][0] << ' ' << nested_array[2][1] << ' ' << nested_array[2][2] << endl;

    if (sum_row(nested_array[0], size) == sum_row(nested_array[1], size))
    {
        real_value_row = sum_row(nested_array[0], size);
    }
    else if (sum_row(nested_array[0], size) == sum_row(nested_array[2], size))
    {
        real_value_row = sum_row(nested_array[0], size);
    }else{
        real_value_row = sum_row(nested_array[1], size);
    }

    if (sum_row(nested_array_for_column[0], size) == sum_row(nested_array_for_column[1], size))
    {
        real_value_column = sum_row(nested_array_for_column[0], size);
    }
    else if (sum_row(nested_array_for_column[0], size) == sum_row(nested_array_for_column[2], size))
    {
        real_value_column = sum_row(nested_array_for_column[0], size);
    }else{
        real_value_column = sum_row(nested_array_for_column[1], size);
    }

    for (int i = 0; i < size;i++){
        if (sum_row(nested_array[i],size)!=real_value_row){
            target_row = i;
        }
    }

    for (int i = 0; i < size;i++){
        if (sum_row(nested_array_for_column[i],size)!=real_value_column){
            target_column = i;
        }
    }
    cout << nested_array[target_row][target_column] << endl;

    // cout << real_value_row << endl;
    // cout << real_value_column << endl;


    // cout << sum_row(nested_array[0], size) << endl;
    // cout << sum_row(nested_array_for_column[0], size) << endl;
    // cout << sum_row(nested_array[1], size) << endl;
    // cout << sum_row(nested_array_for_column[1], size) << endl;
}