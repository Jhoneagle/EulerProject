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
  vector<int> d;
  int s = 0;
  
  
  
  for (int i = 0; i < d.size(); i++) s += d[i];
  
  cout << s << "\n";
  return 0;
}
