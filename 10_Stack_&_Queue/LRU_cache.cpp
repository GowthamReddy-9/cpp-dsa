#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail;
    int cap;
    unordered_map<int, Node*> mp;

    void insertAfterHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            insertAfterHead(node);
        } else {
            if ((int)mp.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }
};

int main() {
    LRUCache cache(2); // capacity = 2
    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << "\n"; // returns 10
    cache.put(3, 30);             // evicts key 2
    cout << cache.get(2) << "\n"; // returns -1 (not found)
    cache.put(4, 40);             // evicts key 1
    cout << cache.get(1) << "\n"; // returns -1 (not found)
    cout << cache.get(3) << "\n"; // returns 30
    cout << cache.get(4) << "\n"; // returns 40
}

