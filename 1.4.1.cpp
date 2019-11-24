#include <bitset>
#include <iostream>

bool is_palindrome_permutation(const std::string& s) {
  std::bitset<256> counts;
  for (auto c : s) {
    if (c != ' ') {
      counts[c].flip();
    }
  }
  return counts.count() == 0 || counts.count() == 1;
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string input;
  std::getline(std::cin, input);
  std::cout << (is_palindrome_permutation(input) ? "YES\n" : "NO\n");
}
