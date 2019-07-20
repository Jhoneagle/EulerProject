/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

bool isPalindrome(num n) {
  num rev = 0, original = n;
  int digit;
	
  while (n != 0) {
    digit = n % 10;
    rev = (rev * 10) + digit;
    n = n / 10;
  }

  return original == rev;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  num h = 0;
  
  for (int i = 100; i < 1000; i++) { 
    for (int j = 100; j < 1000; j++) { 
      if (isPalindrome(i * j)) {
        if ((i * j) > h) h = i * j;
      }
    }
  }
  
  cout << h << "\n";
  return 0;
}
