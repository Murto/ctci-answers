#include <array>
#include <algorithm>
#include <iostream>


bool is_permutation(std::string left, std::string right) {
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());
  return left == right;
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string left;
  std::cin >> left;
  std::cout << "Enter a string: " << std::flush;
  std::string right;
  std::cin >> right;
  std::cout << (is_permutation(left, right) ? "PERMUTATION\n" : "NOT PERMUTATION\n");
}
