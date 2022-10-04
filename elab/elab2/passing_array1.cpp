#include <iostream>
using namespace std;

void find_max_min(int b[], int n,
int *mn
,
int*mx
)
{
  
*mn=b[0];
*mx=b[0];
int i =0;
while(i<n){
if (b[i]<*mn){*mn=b[i];}
if (b[i]>*mx) {*mx=b[i];}
i++;
}

}

main()
{
  int a[1000];
  int n;

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int mx,mn;
  find_max_min(
a
,n,
&mn
,
&mx
);

  cout << "max = " << mx << endl;
  cout << "min = " << mn << endl;
}
