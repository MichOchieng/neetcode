#include <vector>
class LinkedList
{

private:
    struct Node
    {
        int value;
        Node* next;

        Node(int val) : value(val), next(nullptr) {}

        int getValue()
        {
            return value;
        }

        Node* getNext()
        {
            return next;
        }
    };

    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        // Create empty head node
    }

    int get(int index)
    {
        // Return val of ith node
        // Return -1 if index out of the bounds of the list
    }

    void insertHead(int val)
    {
        // insert node with val at head
    }

    void insertTail(int val)
    {
        // insert node with val at tail
    }

    bool remove(int index)
    {
        // Remove the ith node
            // if out of bounds return false
            // otherwise return true
    }

    std::vector<int> getValues()
    {
        // Return an array of all values in the list (Head to Tail)
    }
};