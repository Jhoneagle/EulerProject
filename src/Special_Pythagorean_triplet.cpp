/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

bool isPythagorean(int a, int b, int c) {
  return (pow(a, 2) + pow(b, 2)) == pow(c, 2);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  
  for (int iA = 1; iA <= 332; iA++) {
    for (int iB = iA + 1; (iA + iB) <= 665; iB++) {
      for (int iC = iB + 1; (iA + iB + iC) <= 1000; iC++) {
        if ((iA + iB + iC) == 1000) {
	  if (isPythagorean(iA, iB, iC)) {
	    a = iA;
	    b = iB;
	    c = iC;
	  }
	}
      }
    }
  }
  
  cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";
  return 0;
}
