#include <iostream>

std::string compress_string(const std::string& s) {
  if (s.empty()) {
    return "";
  }
  std::string result;
  char prev = s[0];
  auto count = 1;
  for (auto i = 1; i < s.size(); ++i) {
    auto curr = s[i];
    if (prev == curr) {
      ++count;
    } else {
      result += prev + std::to_string(count);
      count = 1;
    }
    prev = curr;
  }
  result += prev + std::to_string(count);
  return result;
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string input;
  std::getline(std::cin, input);
  std::cout << compress_string(input) << '\n';
}
