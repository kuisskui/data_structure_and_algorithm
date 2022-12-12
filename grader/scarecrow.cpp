#include <iostream>

using namespace std;

const int MAX_ROW = 1;
const int MAX_COLUMN = 110;

int row = 1;
int column;
int n_testcases;
int n_scarecrow;
char *map = new char[MAX_COLUMN];

int main()
{
    cin >> n_testcases;
    for (int i = 0; i < n_testcases; i++)
    {
        n_scarecrow = 0;
        cin >> column;
        cin >> map;
        for (int j = 0; j < column; j++)
        {
            if (map[j] == '.')
            {
                j += 2;
                ++n_scarecrow;
            }
        }

        // print_map();
        // cout << "Front hash: " << front_hash << endl;
        // cout << "Back hash: " << back_hash << endl;
        // cout << "Multiple hash: " << multiple_hash << endl;
        // cout << "Reserved hash: " << reserved_hash << endl;
        // // cout << "number of scarecrow: ";
        cout << "Case " << i + 1 << ": " << n_scarecrow << endl;
    }
}