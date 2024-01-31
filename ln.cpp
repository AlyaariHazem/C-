#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with given data and next pointer
    Node(int value)  {
	this.data = value;
	next = nullptr;
	}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a new node at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            std::cout << "Invalid position. Please provide a position greater than 0." << std::endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete the first node in the list
    void deleteAtBeginning() {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Node at the beginning deleted successfully." << std::endl;
    }

    // Function to delete the last node in the list
    void deleteAtEnd() {
        if (isEmpty()) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
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
            delete temp;
            std::cout << "Node at position " << position << " deleted successfully." << std::endl;
            return;
        }

        Node* temp = head;
        Node* previous = nullptr;

        for (int i = 1; i < position && temp != nullptr; ++i) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Invalid position. Position exceeds the size of the list." << std::endl;
            return;
        }

        previous->next = temp->next;
        delete temp;
        std::cout << "Node at position " << position << " deleted successfully." << std::endl;
    }

    // Function to check if the linked list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

bool search(int value) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true; // Value found
            }
            temp = temp->next;
        }
        return false; // Value not found
    }
    // Function to display the elements of the linked list
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
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
