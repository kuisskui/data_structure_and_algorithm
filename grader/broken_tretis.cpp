#include <iostream>
using namespace std;

void fill_b1(int columns[], int column)
{
    // int highest_index = column;
    int highest_value = columns[column];
    for (int i = column; i < column + 4; i++){
        if (highest_value < columns[i]){
            // highest_index = i;
            highest_value = columns[i];
        }
    }
    highest_value += 1;
    for (int i = column; i < column + 4; i++)
    {
        columns[i] = highest_value;
    }
}
void fill_b2(int columns[], int column)
{
    columns[column] += 4;
}
void fill_b3(int columns[], int column)
{
    int highest_value = columns[column];
    for (int i = column; i < column + 2; i++){
        if (highest_value < columns[i]){
            // highest_index = i;
            highest_value = columns[i];
        }
    }
    highest_value += 2;
    for (int i = column; i < column + 2; i++)
    {
        columns[i] = highest_value;
    }
}

void fill_b(int columns[], char b_type, int column)
{
    if (b_type == '-')
    {
        fill_b1(columns, column);
    }
    else if (b_type == 'i')
    {
        fill_b2(columns, column);
    }
    else if (b_type == 'o')
    {
        fill_b3(columns, column);
    }
}

int main()
{
    int columns[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n_pieces;
    cin >> n_pieces;
    char b_type;
    int column;

    int i = 0;
    while (i < n_pieces)
    {
        i++;
        cin >> b_type >> column;
        fill_b(columns, b_type, column);
    }
    int highest = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (highest < columns[i]){
            highest = columns[i];
        }
    }
    cout << highest << endl;
    return 0;
}