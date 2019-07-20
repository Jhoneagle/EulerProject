/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

bool prime(int n) {
  if (n <= 3) return (n > 1);
  if (((n % 2) == 0) || ((n % 3) == 0)) return false;
  
  int i = 5;
  while ((i * i) <= n) {
      if (((n % i) == 0) || ((n % (i + 2)) == 0)) return false;

      i += 6;
  }
  
  return true;
}

vector<int> getFactors(num n) {
  vector<int> f;
  
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  
  if (n > 1) {
    f.push_back(n);
  }
  
  return f;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  int h = 0;
  vector<int> f = getFactors(600851475143);
  
  for (auto v : f) if (prime(v) && h < v) h = v; 
  
  cout << h << "\n";
  return 0;
}
