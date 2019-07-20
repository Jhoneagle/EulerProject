/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

bool prime(long long n) {
  if (n <= 3) return (n > 1);
  if (((n % 2) == 0) || ((n % 3) == 0)) return false;
  
  long i = 5;
  
  while ((i * i) <= n) {
      if (((n % i) == 0) || ((n % (i + 2)) == 0)) return false;

      i += 6;
  }
  
  return true;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  num i = 0;
  int l = 10001;
  
  while (l > 0) {
    i++;
    
    if (prime(i)) l--;
  }
  
  cout << i << "\n";
  return 0;
}
