#include <array>
#include <bitset>
#include <unordered_set>
#include <iostream>


bool is_unique(const std::string& s) {
  if (s.size() <= 1) {
    return true;
  }
  if (s[0] == s[1]) {
    return false;
  }

  return is_unique(s.substr(1)) && is_unique(s[0] + s.substr(2));
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string input;
  std::cin >> input;
  std::cout << (is_unique(input) ? "UNIQUE\n" : "NOT UNIQUE\n");
}
