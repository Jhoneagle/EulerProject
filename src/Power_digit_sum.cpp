/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  int max = 500, s = 0;
  int ar[max];
  ar[0] = 1;
  
  for(int j = 1; j < max; j++) ar[j] = 0;
  
  for(int i = 0; i < 1000; i++) {
    ar[0] = 2 * ar[0];
    
    for(int k = 1; k < max; k++) ar[k] = 2 * ar[k] + ar[k - 1] / 10;
    
    for(int j = 0; j < max; j++) ar[j] = ar[j] % 10;
  }
  
  for(int i = 0; i < max; i++) s += ar[i];
  
  cout << s << "\n";
  return 0;
}
