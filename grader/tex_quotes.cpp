#include <iostream>
#include <string>
using namespace std;

void tex_quotes(string text, int N, int *p)
{
    for (int i = 0; i < N; i++)
    {
        if (text[i] == '"')
        {
            ++*p;
            int t = *p;
            if (t % 2 == 0)
            {
                cout << "``";
            }
            else
            {
                cout << "\'\'";
            }
        }
        else
        {
            cout << text[i];
        }
    }
}

int main()
{
    int c = 1;
    int *p = &c;
    string string_text;
    while (getline(cin, string_text))
    {
        int N = string_text.length();
        tex_quotes(string_text, N, p);
        cout << endl;
    }
}
