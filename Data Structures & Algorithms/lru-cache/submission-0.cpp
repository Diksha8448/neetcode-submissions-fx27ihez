class LRUCache {
public:
   class Node {

    public:
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {

            key = k;
            value = v;

            prev = next = nullptr;
        }
    };
    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }
    // remove node
    void remove(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // insert after head
    void insert(Node* node) {

        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {

            remove(mp[key]);
        }

        Node* node = new Node(key, value);

        mp[key] = node;

        insert(node);

        // remove LRU
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);
        }
    }
};
