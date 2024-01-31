#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;-


    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    
    LinkedList() : head(NULL) {}


    bool isEmpty() const {
        return head == NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            std::cout << "Invalid position. Please provide a position greater than 0." << std::endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            if (head != NULL) {
                head->prev = newNode;
            }
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }

        if (temp == NULL) {
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        std::cout << "Node at the beginning deleted successfully." << std::endl;
    }

    // Function to delete the last node in the list
    void deleteAtEnd() {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        std::cout << "Node at the end deleted successfully." << std::endl;
    }

    // Function to delete a node at a specific position in the list
    void deleteAtPosition(int position) {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        if (position <= 0) {
            std::cout << "Invalid position. Please provide a position greater than 0." << std::endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            std::cout << "Node at position " << position << " deleted successfully." << std::endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position && temp != NULL; ++i) {
            temp = temp->next;
        }

        if (temp == NULL) {
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        std::cout << "Node at position " << position << " deleted successfully." << std::endl;
    }

    bool search(int value) const {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true; // Value found
            }
            temp = temp->next;
        }
        return false; // Value not found
    }
      void display() const {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, const char** argv) {


 LinkedList myList;

    std::cout << "Is the linked list empty? " << (myList.isEmpty() ? "Yes" : "No") << std::endl;

    myList.insertAtEnd(1);
    myList.insertAtBeginning(2);
    myList.insertAtEnd(3);
    myList.insertAtBeginning(4);

    std::cout << "Linked List: ";
    myList.display();

    std::cout << "Is the linked list empty? " << (myList.isEmpty() ? "Yes" : "No") << std::endl;

    myList.deleteAtBeginning();
    std::cout << "Linked List after deleting at the beginning: ";
    myList.display();

    myList.insertAtPosition(5, 2);
    myList.insertAtEnd(6);

    std::cout << "Linked List after insertion: ";
    myList.display();

    myList.deleteAtEnd();
    std::cout << "Linked List after deleting at the end: ";
    myList.display();

    myList.deleteAtPosition(2);
    std::cout << "Linked List after deleting at position 2: ";
    myList.display();

    return 0;
}
