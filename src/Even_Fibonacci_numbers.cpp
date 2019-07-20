/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int sum = 2;
  int size = 6000;
  int fibNums[size] = {1, 2};
  int i = 2;
  
  while (i < size) {
    fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
    
    if (fibNums[i] > 4000000) break;
    if (fibNums[i] % 2 == 0) sum += fibNums[i];
    
    i++;
  }	  
  
  cout << sum << "\n";
  return 0;
}
