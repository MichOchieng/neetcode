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

        void setNext(Node* node)
        {
            next = node;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList()
    {
        // Create empty list
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index)
    {
        int count = 0;
        Node* current = head; // start at list head

        // Return -1 if index out of the bounds of the list
        if (index >= size)
        {
            return -1;
        }

        // While there are more nodes in the list
        while (current != nullptr)
        {
            // if the currnent index is the target return this nodes value
            if (count == index)
            {
                return current->getValue();
            }
            // otherwise keep searching for target
            count++;
            current = current->getNext();
        }

        // Return val of ith node
    }

    void insertHead(int val)
    {
        // insert node with val at head
        if (size == 0)
        {
            head = new Node(val);
            tail = head;
            size++;
        }
        else
        {
            Node* newNode = new Node(val);
            newNode->setNext(head);
            head = newNode;
            size++;
        }
    }

    void insertTail(int val)
    {
        // insert node with val at tail
        if (size == 0)
        {
            head = new Node(val);
            tail = head;
            size++;
        }
        else
        {
            Node* newNode = new Node(val);
            tail->setNext(newNode);
            tail = newNode;
            size++;
        }
    }

    bool remove(int index)
    {
        int count = 0;
        Node* current = head; // start at list head

        if (index >= size) // if out of bounds return false
        {
            return false;
        }

        else if (index == 0) // if removing head
        {
            Node* temp = head;
            head = head->getNext();
            size--;
            return true;
        }
        else if (index == size-1) // if removing tail
        {
            while (current->getNext() != tail) // find the tail
            {
                current = current->getNext();
            }  
            current->setNext(nullptr);
            tail = current; // reassign the tail
            size--;
            return true;
        }
        else
        {
            // While there are more nodes in the list
            while (current != nullptr)
            {
                // if the currnent index is the target return this nodes value
                if (count == index-1)
                {
                    Node* temp = current->getNext();
                    current->setNext(temp->getNext());
                    size--;
                    return true;
                }
                // otherwise keep searching for target
                count++;
                current = current->getNext();
            }
        }
    }

    std::vector<int> getValues()
    {
        // Return an array of all values in the list (Head to Tail)
        Node* current = head; // start at list head
        std::vector<int> values;
        // While there are more nodes in the list
        while (current != nullptr)
        {
            values.push_back(current->getValue());
            current = current->getNext();
        }
        return values;
    }
};