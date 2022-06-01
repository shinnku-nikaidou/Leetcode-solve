// Given an integer n, count the total number of digit 1 appearing in all
// non-negative integers less than or equal to n.

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0

// Constraints:

// 0 <= n <= 109

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

void print(const std::vector<int> &v) {
  std::cout << "[";
  for (auto x : v) {
    std::cout << x << ",";
  }
  std::cout << "]\n";
}

class Solution {
public:
  int countDigitOne(int n) {
    std::vector<int> _n;
    for (; n != 0; n /= 10)
      _n.push_back(n % 10);
    std::reverse(_n.begin(), _n.end());
    //print(_n);
    return __countDigitOne_t(_n);
  }

  int __countDigitOne_t(const std::vector<int> &n) {
    if (n.empty())
      return 0;
    auto t = n.begin();
    t++;
    int another = 0;
    int front = n.front();
    if (front == 1) {
      for (auto i = ++n.begin(); i != n.end(); ++i) {
        another *= 10;
        another += *i;
      }
      another += 1;
    };
    //printf("another is %d\n", another);
    auto next = std::vector<int>(t, n.end());
    //print(next);
    return __countDigitOne_allzero(front, n.size()) + __countDigitOne_t(next) +
           another;
  }

  int __countDigitOne_allzero(int front, int size) {
    //printf("allzero:%d,%d\n", front, size);
    int base = 1;
    if (front == 0)
      return 0;

    for (int i = 0; i < size - 2; i++)
      base *= 10;
    base *= size - 1;
    //printf("baseis %d\n", base);

    if (front == 1) {
      return base;
    } else {
      int bonus = 1;
      for (int i = 0; i < size - 1; i++)
        bonus *= 10;
      //printf("bonus is %d\n", base);
      return bonus + base * front;
    }
  }
};

int main() {
  Solution s;
  std::cout << s.countDigitOne(13);
  ;
}