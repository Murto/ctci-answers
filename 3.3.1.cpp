#include <iostream>
#include <stack>
#include <unordered_map>

template <typename T>
std::stack<T> sort_stack(std::stack<T> greater) {
  std::stack<T> lesser;
  auto sorted = false;
  while (!sorted) {
    while (!greater.empty()) {
      
      sorted = true;

      auto v = greater.top();
      greater.pop();

      while (!greater.empty() && v < greater.top()) {
        lesser.push(greater.top());
        greater.pop();
      }
      lesser.push(v);
    }
    
    while (!lesser.empty()) {
      
      sorted = true;

      auto v = lesser.top();
      lesser.pop();

      while (!lesser.empty() && v > lesser.top()) {
        greater.push(lesser.top());
        lesser.pop();
        sorted = false;
      }
      greater.push(v);
    }
  }
  return greater;
}

template <typename T>
void print_stack(std::stack<T> s) {
  while (!s.empty()) {
    std::cout << s.top() << '\n';
    s.pop();
  }
  std::cout << "_\n";
}

int main() {
  std::cout << "Enter a number: " << std::flush;
  int n;
  std::cin >> n;
  std::stack<int> digits;
  do {
    auto digit = n % 10;
    n = n / 10;
    digits.push(digit);
  } while (n > 0);
  print_stack(sort_stack(digits));
}
