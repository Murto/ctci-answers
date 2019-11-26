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
bool is_palindrome(Node<T>* head) {
  auto* curr = head;
  std::stack<Node<T>*> reversed;
  while (curr != nullptr) {
    reversed.push(curr);
    curr = curr->next;
  }
  curr = head;
  while (curr != nullptr) {
    if (curr->value != reversed.top()->value) {
      return false;
    }
    reversed.pop();
    curr = curr->next;
  }
  return true;
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
  std::cout << (is_palindrome(n_list) ? "IS PALINDROME\n" : "IS NOT PALINDROME\n");
}
