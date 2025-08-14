#include<bits/stdc++.h>
using namespace std;
class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct List {
        int size;
        Node* head;
        Node* tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addfront(Node* node) {
            node->next = head->next;
            node->next->prev = node;
            node->prev = head;
            head->next = node;
            size++;
        }
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        Node* removeLast() {
            if (size == 0) return nullptr;
            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    unordered_map<int, Node*> keynode;
    unordered_map<int, List*> freqlist;
    int cap, minfreq;

    void updateFreq(Node* node) {
        int oldfreq = node->freq;
        freqlist[oldfreq]->remove(node);
        if (oldfreq == minfreq && freqlist[oldfreq]->size == 0) {
            minfreq++;
        }
        node->freq++;
        if (freqlist.find(node->freq) == freqlist.end()) {
            freqlist[node->freq] = new List();
        }
        freqlist[node->freq]->addfront(node);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minfreq = 0;
    }

    int get(int key) {
        if (cap == 0 || keynode.find(key) == keynode.end()) return -1;
        Node* node = keynode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if ((int)keynode.size() == cap) {
                Node* toRemove = freqlist[minfreq]->removeLast();
                keynode.erase(toRemove->key);
                delete toRemove;
            }
            Node* node = new Node(key, value);
            minfreq = 1;
            if (freqlist.find(1) == freqlist.end()) {
                freqlist[1] = new List();
            }
            freqlist[1]->addfront(node);
            keynode[key] = node;
        }
    }
};

// Example usage
int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n"; // 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << "\n"; // -1
    cout << cache.get(3) << "\n"; // 3
}

