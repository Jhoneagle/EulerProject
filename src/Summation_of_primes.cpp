/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
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

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  num sum = 0;
  
  for (int i = 1; i < 2000000; i++) {
    if (prime(i)) sum += i;
  }
  
  cout << sum << "\n";
  return 0;
}
