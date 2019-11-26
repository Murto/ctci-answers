#include <iostream>
#include <stack>
#include <unordered_map>

template <typename T>
class MinStack {

public:

  T& peek() {
    return _stack.top();
  }

  void push(T value) {
    _stack.push(std::move(value));
    if (_mins.empty()) {
      _mins.push(value);
    } else if (_mins.top() > value) {
      _mins.push(value);
    } else {
      _mins.push(_mins.top());
    }
  }

  void pop() {
    _stack.pop();
    _mins.pop();
  }

  T& min() {
    return _mins.top();
  }

  bool empty() {
    return _stack.empty();
  }

private:

  std::stack<T> _stack;
  std::stack<T> _mins;

};

int main() {
  std::cout << "Enter a number: " << std::flush;
  int n;
  std::cin >> n;
  MinStack<int> digits;
  do {
    auto digit = n % 10;
    n = n / 10;
    std::cout << "PUSH " << digit << '\n';
    digits.push(digit);
    std::cout << "MIN: " << digits.min() << '\n';
  } while (n > 0);
  std::cout << '\n';
  while (!digits.empty()) {
    auto digit = digits.peek();
    std::cout << "MIN " << digits.min() << '\n';
    std::cout << "POP " << digit << '\n';
    digits.pop();
  }
}
