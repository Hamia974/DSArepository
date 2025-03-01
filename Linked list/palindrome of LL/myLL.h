#include "LinkedList.h"
template<typename T>
class myLL :public LinkedList<T>
{	
public:
	void insertAtTail(T);
	void insertAtHead(T);
	void display();
	T deleteFromHead();
	T deleteFromTail();
	bool isEmpty();
	bool deleteValue(T);
	void insertSorted(T);
	//check if palindrome
	bool ispalindrome(){
		while (1){
			if (deleteFromHead() == deleteFromTail()){
				if (head == tail || head == nullptr&& tail == nullptr){
					return true;
				}
			}
			else{
				return false;
			}
		}
	}
	
};
template<typename T>
void myLL<T>::insertSorted(T value)
{
	if (head == nullptr && tail == nullptr) //Empty LL
	{
		Node<T>* nn = nullptr;
		nn = new Node<T>;
		nn->next = nullptr;
		nn->data = value;
		head = nn;
		tail = nn;
	}

	else if (value <= head->data)
	{
		insertAtHead(value);
	}

	else if (value >= tail->data)
	{
		insertAtTail(value);
	}

	else
	{
		Node<T>* nn = nullptr;
		nn = new Node<T>;
		nn->next = nullptr;
		nn->data = value;

		Node<T>* t = head;

		while (true)
		{
			if (t->data < value && t->next->data >= value)
				break;

			else
				t = t->next;

		}

		nn->next = t->next;
		t->next = nn;


	}
}
template<typename T>
bool myLL<T>::deleteValue(T value)
{
	if (head == nullptr && tail == nullptr)
		return false;

	else if (value == head->data)
	{
		deleteFromHead();
		return true;
	}

	else if (value == tail->data)
	{
		deleteFromTail();
		return true;
	}

	else
	{
		Node<T>* t = head;

		while (true)
		{
			if (t->next->data == value)
				break;

			else
				t = t->next;

			if (t->next == tail)
				return false;
		}

		Node<T>* d = t->next;
		t->next = d->next;
		delete d;
		d = nullptr;

		return true;
	}

}
template<typename T>
bool myLL<T>::isEmpty()
{
	return (head == nullptr && tail == nullptr);
}

template<typename T>
T myLL<T>::deleteFromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	//Single node case:
	else if (head == tail)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = tail->data;

		Node<T>* t = head;

		while (1)
		{
			if (t->next->next == nullptr)
				break;//yes you are 2nd last node.

			else
				t = t->next;
		}

		delete tail;

		tail = t;
		t->next = nullptr;


		return returningValue;
	}
}
template<typename T>

T myLL<T>::deleteFromHead()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	//Single node case:
	else if (head == tail)
	{
		int returningValue = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		int returningValue = head->data;

		Node<T>* temp = head;
		head = head->next;

		delete temp;
		temp = nullptr;


		return returningValue;
	}
}

template<typename T>
void myLL<T>::display()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node<T>* t = head;
		while (true)
		{
			cout << t->data << " ";
			t = t->next;

			if (t == nullptr)
				break;
		}

	}
}
template<typename T>
void myLL<T>::insertAtTail(T value)
{
	Node<T>* nn = nullptr;
	nn = new Node<T>;
	nn->next = nullptr;
	nn->data = value;

	if (head == nullptr && tail == nullptr) //Empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty Linked List
	{
		tail->next = nn;
		tail = nn;
	}
}

template<typename T>
void myLL<T>::insertAtHead(T value)
{
	Node<T>* nn = nullptr;
	nn = new Node<T>;
	nn->next = nullptr;
	nn->data = value;

	if (head == nullptr && tail == nullptr)
	{
		head = nn;
		tail = nn;
	}

	else
	{
		nn->next = head;
		head = nn;
	}

}