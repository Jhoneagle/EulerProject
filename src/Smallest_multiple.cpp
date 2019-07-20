/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int range = 20;
  num i = range;
  
  while (true) {
    bool is = true;
    
    for (int j = 2; j <= range; j++) {
      if (i % j != 0) {
        is = false;
        break;
      }
    }
    
    if (is) break;
    
    i += range;
  }
  
  cout << i << "\n";
  return 0;
}
