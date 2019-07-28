/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n = 20;
  int g[n + 1][n + 1];
  
  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    g[i][0] = 1;
    g[0][i] = 1;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = g[i - 1][j] + g[i][j - 1];
    }
  }
  
  cout << g[n][n] << "\n";
  return 0;
}
