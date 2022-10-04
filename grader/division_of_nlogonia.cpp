#include <iostream>
#include <string>

using namespace std;

string string_location(int n, int m, int x, int y)
{
    int x_axis = 0;
    int y_axis = 0;
    string text;
    x_axis = n - x;
    y_axis = m - y;

    if (x_axis == 0 || y_axis == 0)
    {
        text = "divisa";
    }
    else if (x_axis > 0 and y_axis > 0)
    {
        text = "NE";
    }
    else if (x_axis > 0 and y_axis < 0)
    {
        text = "SE";
    }
    else if (x_axis < 0 and y_axis < 0)
    {
        text = "SO";
    }
    else if (x_axis < 0 and y_axis > 0)
    {
        text = "NO";
    }
    return text;
}

int main()
{
    int r, n, m, x, y, rr;
    rr = 0;
    string a;
    string b[100];
    cin >> r;
    while (r > 0)
    {
        rr += r;
        cin >> x >> y;
        for (int i = rr-r; i < rr; i++)
        {
            cin >> n >> m;
            cout << string_location(n, m, x, y)<< endl;
            
        }
        cin >> r;
    }
}
