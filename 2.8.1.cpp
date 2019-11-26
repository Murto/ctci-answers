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
bool has_loop(Node<T>* head) {
  auto* slow = head;
  auto* fast = head;
  while (slow && fast) {
    slow = slow ? slow->next : slow;
    fast = fast ? fast->next : fast;
    fast = fast ? fast->next : fast;
    if (slow && fast && slow == fast) {
      return true;
    }
  }
  return false;
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
  
  std::cout << (has_loop(n_list) ? "HAS LOOP\n" : "DOES NOT HAVE LOOP\n");
}
