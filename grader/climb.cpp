#include <iostream>
using namespace std;

int main()
{
    int n_event;
    int stack = 0;
    int energy = 0;
    int current_position = 0;
    int previous_position = 0;
    int position = 0;
    int difference_position = 0;

    cin >> n_event;
    while (n_event--)
    {
        cin >> position;
        previous_position = current_position;
        current_position = position;
        difference_position = current_position - previous_position;
        if (difference_position <= 0){
            stack = 0;
        }else{
            energy += stack;
            energy += difference_position;
            stack += 1;
        }
    }
    cout << energy;
}