#include <iostream>
using namespace std;

int main(){
    int n_box;
    int dumb;
    int green_ball;
    int black_ball;
    cin >> n_box;
    cin >> dumb;
    int array_sum[n_box];

    for (int i = 0; i < n_box;i++){
        cin >> green_ball;
        cin >> black_ball;
        array_sum[i] = green_ball - black_ball;
    }
    
    int index_value;
    int min_value;

    for (int j = 0; j < dumb;j++){
        index_value = 0;
        min_value = array_sum[0];
        for (int i = 0; i < n_box; i++)
        {
            if (array_sum[i] < min_value)
            {
                min_value = array_sum[i];
                index_value = i;
            }
        }
        if (min_value<0){
            array_sum[index_value] = 0;
        }
    }
    int total = 0;
    for (int i = 0; i < n_box; i++){
        total += array_sum[i];
    }
    cout << total;
}