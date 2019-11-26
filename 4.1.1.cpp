#include <array>
#include <iostream>
#include <queue>
#include <unordered_set>

struct Node {
  
  std::unordered_set<Node*> adjacent;

};

bool intersect(const std::unordered_set<Node*>& left, const std::unordered_set<Node*>& right) {
  for (auto* node : left) {
    if (right.find(node) != right.end()) {
      return false;
    }
  }
  return true;
}

std::unordered_set<Node*> difference(const std::unordered_set<Node*>& left, const std::unordered_set<Node*>& right) {
  std::unordered_set<Node*> result;
  for (auto* node : left) {
    if (right.find(node) == right.end()) {
      result.insert(node);
    }
  }
  return result;
}

bool route_between(Node* from, Node* to) {
  std::unordered_set<Node*> from_seen{from};
  std::unordered_set<Node*> to_seen{to};
  std::queue<Node*> from_next;
  from_next.push(from);
  std::queue<Node*> to_next;
  to_next.push(to);
  while (!from_next.empty()) {
    auto* curr = from_next.front();
    from_next.pop();
    auto expanded = difference(curr->adjacent, from_seen);
    for (auto node : expanded) {
      if (to_seen.find(node) != to_seen.end()) {
        return true;
      } else {
        from_seen.insert(node);
        from_next.push(node);
      }
    }
    std::swap(from_seen, to_seen);
    std::swap(from_next, to_next);
  }
  return false;
}

int main() {

  std::array<Node, 6> graph;
  graph[1].adjacent.insert(&graph[2]);
  graph[2].adjacent.insert(&graph[1]);
  graph[2].adjacent.insert(&graph[2]);
  graph[2].adjacent.insert(&graph[5]);
  graph[3].adjacent.insert(&graph[2]);
  graph[3].adjacent.insert(&graph[5]);
  graph[4].adjacent.insert(&graph[2]);
  graph[5].adjacent.insert(&graph[2]);
  graph[5].adjacent.insert(&graph[3]);
  std::cout << (route_between(&graph[0], &graph[1]) ?  "ROUTE FOUND BETWEEN 0 AND 1\n" : "NO ROUTE BETWEEN 0 AND 1\n");
  std::cout << (route_between(&graph[1], &graph[5]) ? "ROUTE FOUND BETWEEN 1 AND 5\n" : "NO ROUTE BETWEEN 1 AND 5\n");
}
