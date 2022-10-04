#include <iostream>
#include <string>

using namespace std;

int main()
{
    int members = 1;
    int groups = 1;
    string text;
    while (true)
    {
        cin >> groups;
        if (groups == 0){
            break;
        }
        cin >> text;
        members = text.length() / groups;
        for (int i = 0; i < text.length(); i += members)
        {
            for (int j = i + members-1; j >= i; j--)
            {
                cout << text[j];
            }
        }
        cout << endl;
    }
}