#include <iostream>

using namespace std;

int count_char(char* st, char c) {
    int n_c = 0;
    while (*st != '\0'){
        if (*st == c){
            n_c++;
        };
        
        st++;
    }
    return n_c;
}

int main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}

