#include <iostream>
#include <vector>

std::vector<std::vector<int>> rotate_matrix(const std::vector<std::vector<int>>& matrix) {
  auto n = matrix.size();
  std::vector<std::vector<int>> rotated(n);
  for (auto i = 0; i < n; ++i) {
    auto& row = rotated[i];
    row.resize(n);
    for (auto j = 0; j < n; ++j) {
      row[j] = matrix[n - j - 1][i];
    }
  }
  return rotated;
}

int main() {
  int n;
  std::cout << "Enter a number: " << std::flush;
  std::cin >> n;
  std::cout << "Enter " << (n * n) << " numbers: " << std::flush;
  std::vector<std::vector<int>> matrix(n);
  for (auto i = 0; i < n; ++i) {
    auto& row = matrix[i];
    row.resize(n);
    for (auto j = 0; j < n; ++j) {
      std::cin >> row[j];
    }
  }
  auto rotated = rotate_matrix(matrix);
  std::cout << "ROTATED:\n";
  for (auto i = 0; i < n; ++i) {
    std::cout << '\t';
    for (auto j = 0; j < n; ++j) {
      std::cout << rotated[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
