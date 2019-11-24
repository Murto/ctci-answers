#include <array>
#include <unordered_map>
#include <iostream>


bool is_permutation(const std::string& left, const std::string& right) {
  std::unordered_map<char, int> diff;
  for (char c : left) {
    ++diff[c];
  }

  for (char c : right) {
    if (--diff[c] == 0) {
      diff.erase(c);
    }
  }

  return diff.empty();
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
