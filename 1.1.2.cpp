#include <array>
#include <bitset>
#include <unordered_set>
#include <iostream>


bool is_unique(const std::string& s) {
  std::unordered_set<char> seen;
  for (auto c : s) {
    if (seen.find(c) != seen.end()) {
      return false;
    } else {
      seen.insert(c);
    }
  }
  return true;
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string input;
  std::cin >> input;
  std::cout << (is_unique(input) ? "UNIQUE\n" : "NOT UNIQUE\n");
}
