/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int proper[20] = {
  0, strlen("one"),
  strlen("two"),
  strlen("three"),
  strlen("four"),
  strlen("five"),
  strlen("six"),
  strlen("seven"),
  strlen("eight"),
  strlen("nine"),
  strlen("ten"),
  strlen("eleven"),
  strlen("twelve"),
  strlen("thirteen"),
  strlen("fourteen"),
  strlen("fifteen"),
  strlen("sixteen"),
  strlen("seventeen"),
  strlen("eighteen"),
  strlen("nineteen")
};

int tenth[8] = {
  strlen("twenty"),
  strlen("thirty"),
  strlen("forty"),
  strlen("fifty"),
  strlen("sixty"),
  strlen("seventy"),
  strlen("eighty"),
  strlen("ninety")
};

int addWords[6] = {
  0, strlen("thousand"), 
  strlen("million"),
  strlen("billion"),
  strlen("trillion"),
  strlen("quadrillion")
};

int noAdditionInName(int n) {
  if (n < 20) {
    return proper[n];
  } else {
    return tenth[n / 10 - 2 | 0] + proper[n % 10];
  }
}

int numberLength(int n) {
  if (n < 100) return noAdditionInName(n);

  string r = to_string(n);
  vector<int> pieces;
  
  int i;
  for (i = r.size() - 3; i >= 0; i -= 3) { 
    pieces.push_back(stoi(r.substr(i, 3)));
  }
  
  i += 3;
  if (i != 0) pieces.push_back(stoi(r.substr(0, i)));
  
  int res = 0;
  int prefix = 0;
  
  for (int i = pieces.size() - 1; i >= 0; i--) {
    int c = pieces[i];
    int h = (int) floor(c / 100) % 10;
    int s = c % 100;
    
    res += addWords[prefix];
    prefix++;
    
    if (h != 0) res += proper[h] + strlen("hundred");
    
    if (s != 0) res += noAdditionInName(s);
    
    if (s != 0 && h != 0) res += strlen("and");
  }	  
  
  return res;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int l = 0;
  
  for (int i = 1; i <= 1000; i++) {
    l += numberLength(i);
  }
  
  cout << l << "\n";
  return 0;
}
