#include <array>
#include <bitset>
#include <unordered_set>
#include <iostream>


bool is_unique(const std::string& s) {
  for (auto outer = s.begin(); outer != s.end(); ++outer) {
    for (auto inner = outer + 1; inner != s.end(); ++inner) {
      if (*inner == *outer) {
        return false;
      }
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
