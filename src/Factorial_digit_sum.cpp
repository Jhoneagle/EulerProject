/*
n! means n × (n - 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  int max = 5000, sum = 0;
  int ar[max];
  ar[0] = 1;
  
  for(int j = 1; j < max; j++) ar[j] = 0;
  
  for(int i = 2; i <= 100; i++) {
    ar[0] = i * ar[0];
    
    for(int k = 1; k < max; k++) ar[k] = i * ar[k] + ar[k - 1] / 10;
    
    for(int j = 0; j < max; j++) ar[j] = ar[j] % 10;
  }
  
  for(int i = 0; i < max; i++) sum += ar[i];
  
  cout << sum << "\n";
  return 0;
}
