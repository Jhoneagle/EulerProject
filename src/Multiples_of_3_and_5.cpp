/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int sum = 0;
	
  for (num  i = 3; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) sum += i;
  }  
  
  cout << sum << "\n";
  return 0;
}
