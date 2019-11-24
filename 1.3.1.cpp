#include <iostream>
#include <regex>
#include <string>

std::string URLify(const std::string& url) {
  std::regex pattern{" "};
  return std::regex_replace(url, pattern, "%20");
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string input;
  std::getline(std::cin, input);
  std::cout << URLify(input) << '\n';
}
