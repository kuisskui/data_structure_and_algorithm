#include <iostream>

using namespace std;

int main()
{
    int score = 0;
    cin >> score;
    if (score >= 80)
    {
        cout << "Excellent job." << endl;
    }
    else if (score >= 50)
    {
        cout << "Okay." << endl;
    }
    else
    {
        cout << "Please try harder." << endl;
    }
}
