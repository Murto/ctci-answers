#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

bool is_one_deletion_away(const std::string& left, const std::string& right) {
  if (left.size() > right.size()) {
    return is_one_deletion_away(right, left);
  }
  for (auto i = 0; i < left.size(); ++i) {
    if (left[i] != right[i]) {
      return left.substr(i) == right.substr(i + 1);
    }
  }
  return true;
}

bool is_one_insertion_away(const std::string& left, const std::string& right) {
  if (left.size() > right.size()) {
    return is_one_insertion_away(right, left);
  }
  for (auto i = 0; i < left.size(); ++i) {
    if (left[i] != right[i]) {
      return left.substr(i + 1) == right.substr(i);
    }
  }
  return true;
}

bool is_one_replacement_away(const std::string left, const std::string& right) {
  for (auto i = 0; i < left.size(); ++i) {
    if (left[i] != right[i]) {
      return left.substr(i + 1) == right.substr(i + 1);
    }
  }
  return true;
}

bool is_one_away(const std::string& left, const std::string& right) {
  if (left.size() == right.size()) {
    return is_one_replacement_away(left, right);
  } else if (left.size() - right.size() == 1 || left.size() - right.size() == -1) {
    return is_one_deletion_away(left, right) || is_one_insertion_away(left, right);
  }
  return false;
}

int main() {
  std::cout << "Enter a string: " << std::flush;
  std::string left;
  getline(std::cin, left);
  std::cout << "Enter a string: " << std::flush;
  std::string right;
  getline(std::cin, right);
  std::cout << (is_one_away(left, right) ? "IS ONE (OR NONE) AWAY\n" : "IS MORE THAN ONE AWAY\n");
}
