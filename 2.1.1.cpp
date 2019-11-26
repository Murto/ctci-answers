#include <iostream>
#include <unordered_set>

template <typename T>
struct Node {

  Node(T value, Node* next = nullptr)
  : value{std::move(value)}, next{next} {}

  T value;
  Node* next;

};

Node<int>* remove_duplicates(Node<int>* head) {
  std::unordered_set<int> seen;
  auto* curr = head;
  Node<int>* copy_head = nullptr;
  auto** last = &copy_head;
  while (curr != nullptr) {
    if (seen.find(curr->value) == seen.end()) {
      *last = new Node<int>(curr->value);
      last = &(*last)->next;
      seen.insert(curr->value);
    }
    curr = curr->next;
  }
  return copy_head;
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
  auto* unique = remove_duplicates(head);
  auto* curr = unique;
  while (curr != nullptr) {
    std::cout << curr->value << ',';
    curr = curr->next;
  }
  std::cout << '\n';
}
