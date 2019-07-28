/*
The following iterative sequence is defined for the set of positive numegers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

unordered_map<num, num> p;

num collatz(num n) {
  if (p[n] > 0) {
    return p[n];
  } else {
    num v = (n % 2 == 0) ? (collatz(n / 2) + 1) : (collatz(3 * n + 1) + 1);
    p[n] = v;
    return v;
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  p[1] = 1;
  p[2] = 2;
  p[3] = 8;
  p[4] = 3;
  p[5] = 6;
  p[6] = 9;
  
  num l = 0;
  for (num i = 1; i < 1000000; i++) {
    num t = collatz(i);
    if (t > l) l = t;
  }
  
  cout << l << "\n";
  return 0;
}
