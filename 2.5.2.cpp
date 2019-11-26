#include <iostream>
#include <queue>
#include <stack>
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
  std::stack<Node<T>*> left_history;
  std::stack<Node<T>*> right_history;
  
  while (left != nullptr) {
    left_history.push(left);
    left = left->next;
  }

  while (right != nullptr) {
    right_history.push(right);
    right = right->next;
  }

  Node<T>* head = nullptr;
  auto carry = 0;
  do {
    
    auto sum = carry;
    
    if (!left_history.empty()) {
      sum += left_history.top()->value;
      left_history.pop();
    }

    if (!right_history.empty()) {
      sum += right_history.top()->value;
      right_history.pop();
    }

    auto digit = sum % 10;
    carry = sum / 10;
    auto* next = head;
    head = new Node<T>(digit, next);
  } while (carry > 0 || !left_history.empty() || !right_history.empty());
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
  while (n > 0) {
    auto digit = n % 10;
    n /= 10;
    auto* next = head;
    head = new Node<T>(digit, next);
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
  print_list(m_list);
  auto* result = sum_lists(n_list, m_list);
  print_list(result);
}
