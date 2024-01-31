#include <iostream>
using namespace std;
template <class t>
class  list{
	struct node {
		t item;
		node* next;
	};
	node* top;
	stack() {
		top = NULL;
	}
public:
	void push(t newitem) {
		node*newItemPtr = new node;
		if (newItemPtr == NULL)
			cout << "stack push can't allocate the memory ! " << endl;
		else{
		newItemPtr->item = newitem;
		newItemPtr->next = top;
		top = newItemPtr;
		}
	} 
	bool isEmpty() {
		return top == NULL;
	}
	void pop() {
		if (isEmpty())
			cout << "sorry a List is Empty! " << endl;
		else {
			node* temp = new node;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}

	}
};

main() {

}