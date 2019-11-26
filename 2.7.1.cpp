#include <iostream>
#include <unordered_set>

template <typename T>
struct Node {

  Node(T value, Node* next = nullptr)
  : value{std::move(value)}, next{next} {}

  T value;
  Node* next;

};

template <typename T>
Node<T>* intersect(Node<T>* left, Node<T>* right) {
  std::unordered_set<Node<T>*> seen;
  while (left != nullptr) {
    seen.insert(left);
    left = left->next;
  }
  while (right != nullptr) {
    if (seen.find(right) != seen.end()) {
      return right;
    }
    right = right->next;
  }
  return nullptr;
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

  auto* node = intersect(n_list, m_list);
  std::cout << (node ? "INTERSECT AT " + std::to_string(node->value) + '\n' : "NO INTERSECT\n");
}
