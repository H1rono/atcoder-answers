#include <iostream>
#include <vector>

struct Node;

using NodePtr = Node *;
using vec_node = std::vector<NodePtr>;

struct Node
{
private:
    vec_node children;

public:
    const int id;
    Node(int id) : id(id), children() {}

    void add_child(NodePtr child) {
        if (child == nullptr) { return; }
        children.push_back(child);
    }

    int solve_query(int distance) {
        if (distance <= 0) { return 1; }
        int ans = 0, d = distance - 1;
        for (NodePtr child : children) {
            ans += child->solve_query(d);
        }
        return ans;
    }

    int solve_query(int search_id, int distance) {
        bool match_id = search_id == id;
        if (distance <= 0) { return match_id; }
        int ans = 0;
        if (match_id) {
            for (NodePtr child : children) {
                ans += child->solve_query(distance - 1);
            }
        } else {
            for (NodePtr child : children) {
                ans += child->solve_query(search_id, distance - 1);
            }
        }
        return ans;
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    vec_node nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(i + 1);
    }
    for (int i = 1; i < n; ++i) {
        int parent = 0;
        std::cin >> parent;
        nodes[parent - 1]->add_child(nodes[i]);
    }
    Node first = *nodes[0];
    int query_num = 0;
    std::cin >> query_num;
    for (int i = 0; i < query_num; ++i) {
        int s_id = 0, dist = 0;
        std::cin >> s_id >> dist;
        std::cout << first.solve_query(s_id, dist) << std::endl;
    }
}