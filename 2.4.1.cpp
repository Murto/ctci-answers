#include <iostream>
#include <queue>
#include <tuple>

template <typename T>
struct Node {

  Node(T value, Node* next = nullptr)
  : value{std::move(value)}, next{next} {}

  T value;
  Node* next;

};

template <typename T>
std::pair<Node<T>*, Node<T>*> partition(Node<T>* head, const T& value) {
  Node<T>* less_than = nullptr;
  auto** less_than_last = &less_than;
  Node<T>* not_less_than = nullptr;
  auto** not_less_than_last = &not_less_than;
  while (head != nullptr) {
    if (head->value < value) {
      *less_than_last = new Node<T>(head->value);
      less_than_last = &(*less_than_last)->next;
    } else {
      *not_less_than_last = new Node<T>(head->value);
      not_less_than_last = &(*not_less_than_last)->next;
    }
    head = head->next;
  }
  return {less_than, not_less_than};
}

template <typename T>
void print_list(Node<T>* head) {
  while (head != nullptr) {
    std::cout << head->value << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

int main() {
  std::cout << "Enter a number: " << std::flush;
  int n;
  std::cin >> n;
  std::cout << "Enter " << n << " numbers: " << std::flush;
  Node<int>* head = nullptr;
  Node<int>** last = &head;
  for (auto i = 0; i < n; ++i) {
    int value;
    std::cin >> value;
    auto* node = new Node<int>(value);
    *last = node;
    last = &(*last)->next;
  }
  std::cout << "Enter a number: " << std::flush;
  int k;
  std::cin >> k;
  auto [less_than, not_less_than] = partition(head, k);
  std::cout << "Less than:\n";
  print_list(less_than);
  std::cout << "Not less than:\n";
  print_list(not_less_than);
}
