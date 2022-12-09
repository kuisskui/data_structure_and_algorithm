#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n_books, price, money, min_range, first, second;
    vector<int> book_price;

    while (cin >> n_books)
    {
        min_range = 1000001;
        book_price.clear();
        for (int i = 0; i < n_books; i++)
        {
            cin >> price;
            book_price.push_back(price);
        }
        sort(book_price.begin(), book_price.end());
        cin >> money;
        for (int i = 0; i < n_books ; i++)
        {
            for (int j = i+1; j < n_books; j++)
            {
                if (book_price[i] + book_price[j] == money && abs(book_price[i] - book_price[j]) < min_range)
                {
                    first = book_price[i];
                    second = book_price[j];
                }
            }
        }
        cout << "Peter should buy books whose prices are " << first << " and " << second << '.' << endl;
        cout << endl;
    }

}