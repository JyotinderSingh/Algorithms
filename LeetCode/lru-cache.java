// https://leetcode.com/problems/lru-cache/
// https://leetcode.com/problems/lru-cache/discuss/45911/Java-Hashtable-%2B-Double-linked-list-(with-a-touch-of-pseudo-nodes)

class LRUCache {
  class DLinkedNode {
    int key;
    int value;
    DLinkedNode prev;
    DLinkedNode next;
  }

  /**
   * Adds a new node right after head.
   */
  private void addNode(DLinkedNode node) {
    // Wire the node to the head and the current first element.
    node.prev = head;
    node.next = head.next;

    // Update head pointer;
    head.next.prev = node;
    head.next = node;
  }

  /**
   * Removes the given node from the linked list.
   */
  private void removeNode(DLinkedNode node) {
    DLinkedNode prev = node.prev;
    DLinkedNode next = node.next;

    prev.next = next;
    next.prev = prev;
  }

  /**
   * Moves a given node to the head of the list.
   */
  private void moveToHead(DLinkedNode node) {
    removeNode(node);
    addNode(node);
  }

  /**
   * Removes the oldest (node at tail) node from the list.
   */
  private DLinkedNode popTail() {
    DLinkedNode res = tail.prev;
    removeNode(res);
    return res;
  }

  private Map<Integer, DLinkedNode> cache = new HashMap<>();
  private int capacity;
  private DLinkedNode head, tail;

  public LRUCache(int capacity) {
    this.capacity = capacity;

    head = new DLinkedNode();
    // head.prev = null;

    tail = new DLinkedNode();
    // tail.next = null;

    // Wire up the head and tail pointers.
    head.next = tail;
    tail.prev = head;
  }

  public int get(int key) {
    DLinkedNode node = cache.get(key);

    if (node == null)
      return -1;

    // move accessed node to head.
    moveToHead(node);

    return node.value;
  }

  public void put(int key, int value) {
    DLinkedNode node = cache.get(key);

    if (node == null) {
      // Instantiate a new node object.
      DLinkedNode newNode = new DLinkedNode();
      newNode.key = key;
      newNode.value = value;

      // Add the node both to the linked list and the hashmap.
      cache.put(key, newNode);
      addNode(newNode);

      // Check if we exceeded capacity.
      if (cache.size() > capacity) {
        // pop the tail.
        DLinkedNode tail = popTail();
        cache.remove(tail.key);
      }
    } else {
      // update the value.
      node.value = value;
      moveToHead(node);
    }
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */