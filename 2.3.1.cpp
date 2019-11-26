#include <iostream>
#include <queue>

template <typename T>
struct Node {

  Node(T value, Node* next = nullptr)
  : value{std::move(value)}, next{next} {}

  T value;
  Node* next;

};

void delete_middle_node(Node<int>* node) {
  node->value = node->next->value;
  node->next = node->next->next;
}

Node<int>* kth_to_last(Node<int>* head, int k) {
  std::queue<Node<int>*> history;
  while (head != nullptr) {
    history.push(head);
    if (history.size() > k) {
      history.pop();
    }
    head = head->next;
  }
  if (history.size() == k) {
    return history.front();
  } else {
    return nullptr;
  }
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
  auto* result = kth_to_last(head, k);
  if (!result) {
    std::cout << "NO SUCH ELEMENT\n";
    return 1;
  }
  delete_middle_node(result);
  auto* curr = head;
  while (curr != nullptr) {
    std::cout << curr->value << ' ';
    curr = curr->next;
  }
}
