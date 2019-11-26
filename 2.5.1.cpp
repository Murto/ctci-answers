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
Node<T>* sum_lists(Node<T>* left, Node<T>* right) {
  Node<T>* head = nullptr;
  auto** last = &head;
  auto carry = 0;
  while (left || right || carry) {
    auto sum = 0;
    if (left) {
      sum += left->value;
      left = left->next;
    }
    if (right) {
      sum += right->value;
      right = right->next;
    }
    sum += carry;
    carry = sum / 10;
    *last = new Node<T>(sum % 10);
    last = &(*last)->next;
  }
  return head;
}

template <typename T>
void print_list(Node<T>* head) {
  while (head != nullptr) {
    std::cout << head->value << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

template <typename T>
Node<T>* to_linked_list(T n) {
  Node<T>* head = nullptr;
  auto** last = &head;
  while (n > 0) {
    auto digit = n % 10;
    n /= 10;
    *last = new Node<T>(digit);
    last = &(*last)->next;
  }
  return head;
}

int main() {
  std::cout << "Enter a number: " << std::flush;
  int n;
  std::cin >> n;
  auto* n_list = to_linked_list(n);
  print_list(n_list);
  std::cout << "Enter a number: " << std::flush;
  int m;
  std::cin >> m;
  auto* m_list = to_linked_list(m);
  print_list(n_list);
  auto* result = sum_lists(n_list, m_list);
  print_list(result);
}
