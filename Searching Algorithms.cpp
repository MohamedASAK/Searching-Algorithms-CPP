#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* previous;
};

node* head = NULL;
node* current = NULL;
node* tail = NULL;
node* Beg = NULL;
node* End = NULL;
node* index = NULL;

int loc = 0;
int Leanth = 0;
bool flag = false;

// Linked List Operations
void insert(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;

	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->previous = tail;
		tail->next = current;
		tail = tail->next;
	}
}
void AddToHead(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->next = head;
		head = current;
	}
}
void deleteNode(int Deldata) {
	if (head != NULL)
	{
		current = head;
		if (current->data == Deldata)
		{
			head = head->next;
			delete current;
		}
		else
		{
			while (current != NULL)
			{
				if ((current->next)->data == Deldata)
				{
					(current->next) = (current->next)->next;
					break;
				}
				else { current = current->next; }
			}
		}
	}
	else { cout << "No Data Found" << endl; }
}
void destoryList()
{
	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = NULL;
		tail = NULL;
		cout << "The list is Destroyed Successfully" << endl;
	}
	else
	{
		cout << "There is no list to be destroyed" << endl;
	}
}
void display()
{
	if (head != NULL)
	{
		current = head;
		cout << "Data:" << endl;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{
		cout << "No Data Found" << endl;
	}
}

//Sequential Search
void sequentialSearch(int item) {
	current = head;
	while (current->next != NULL)
	{
		if (current->data == item)
		{
			cout << "Search is successful\n";
			cout << "Item is: " << item << endl;
			flag = true;
		}
		current = current->next;
	}
	if (flag == false)
	{
		cout << "Search is not successful\n";
	}
}
//Binary Search
node* middle(node* start, node* last) 
{
	if (start == NULL)
		return NULL;
	node* slow = start;
	node* fast = start->next;
	while(fast != last)
	{
		fast = fast->next;
		if (fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}
node* binarySearch(node* head, int key)
{
	node* start = head;
	node* last = NULL;
	do
	{
		node* mid= middle(start, last);
		if (mid == NULL)
			return NULL;

		if (mid->data == key) {
			return mid;
		}
		else if (mid->data < key) {
			start = mid->next; 
		}
		else {
			last = mid;
		}
	} while (last == NULL || last != start);
	return NULL;
}
void location(int item) {
	current = head;
	while (current != NULL) {
		loc++;
		if (current->data == item)
			break;
		current = current->next;
	}
}
//Jump Search
int jumpSearch(int ele, int len) {
	current = head;
	int step = sqrt(len);

	while (current->next != NULL && current->data < ele)
	{
		current = current->next;
		step--;
		if (step == 0) {
			step = sqrt(len);

			if (current->data == ele)
				return 1;
		}
		while (step != 0 && current != NULL)
		{
			node* c = current;
			if (c->data == ele)
				return 1;
			else
				c = c->previous;
		}
	}
}
//Interpolation Search
void interpolationSearch(int item) {
	while (head->data <= tail->data && item >= head->data && item <=tail->data){
		if (Beg == End) {
			if (Beg->data == item)
			{
				index->data = Beg->data;
			}
		}
		index = Beg + ((End - Beg) / (End->data - Beg->data)) * (item - Beg->data);
		if (index->data == item)
		{
			flag = true;
			cout << "Number is founded at list :" << item << endl;
		}
		if (index->data < item)
			Beg->data = index->data + 1;
		else
			End->data = index->data - 1;
	}
	if (flag == false)
		cout << "Search is not successful\n";
}

void app() {
	/*
		op -> operation
		ins -> insert
		ath -> add to head
		dn -> deleted node
		c -> confirm
		ao -> another operation
		s -> starter app
	*/

	int op, ins, ath, dn, c, ao, s;
	int num;
	cout << "---* Welcome to linked list implementation with sorting algorithms *---\n";
	do {
		cout << "Choise what do you want\n";
		cout << "Insert -> (1)\n";
		cout << "Add to head -> (2)\n";
		cout << "Delete node -> (3)\n";
		cout << "Display -> (4)\n";
		cout << "Destory list -> (5)\n";
		cout << "Searching -> (6)\n";
		cout << "Exit -> (7)\n";
		cin >> op;
		if (op == 1) {
			cout << "Enter value do you want to add to head\n";
			cin >> ins;
			insert(ins);
			display();
		}
		else if (op == 2) {
			cout << "Enter value do you want to add to head\n";
			cin >> ath;
			AddToHead(ath);
			display();
		}
		else if (op == 3) {
			display();
			cout << "Choise the node \n";
			cin >> dn;
			cout << "Are you sure to delete this node\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				deleteNode(dn);
				cout << "\nCheck data of list after deleting node : \n ";
				display();
			}
			else
			{
				cout << "Delete is canceled\n";
			}
		}
		else if (op == 4) {
			cout << "\nThe Nodes of the Linked List are: \n";
			display();
		}
		else if (op == 5) {
			display();
			cout << "\nIF Destroyed the whole list\n \t The result will be: \n";
			cout << "Are you sure to destroy the whole list\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				destoryList();
				cout << "\nCheck data of list after destroying : \n ";
				display();
			}
			else
			{
				cout << "Destroy is canceled\n";
			}
		}
		else if (op == 6)
		{
			cout << "--------Searching--------\n";
			cout << "Choise what do you want\n";
			cout << "Sequential Search -> (1)\n";
			cout << "Binary Search -> (2)\n";
			cout << "Jump Search -> (3)\n";
			cout << "Interpolation Search -> (4)\n";
			cout << "Exit -> (5)\n";
			cin >> op;
			if (op == 1)
			{
				cout << "Enter any Number To found it\n";
				cin >> num;
				sequentialSearch(num);
			}
			else if (op == 2)
			{
				cout << "Enter any Number To found it\n";
				cin >> num;
				if (binarySearch(head, num) == NULL) {
					cout << "Search is not successful\n";
				}
				else {
					cout << "Search is successful\n";
					cout << "Item is: " << num << endl;
					location(num);
					cout << "Position of the item: " << loc << endl;
				}
			}
			else if (op == 3)
			{
				cout << "Enter any Number To found it\n";
				cin >> num;
				if (jumpSearch(num, Leanth) == 1) {
					cout << "Search is successful\n";
				}
				else {
					cout << "Search is not successful\n";
				}
			}
			else if (op == 4)
			{
				cout << "Enter any Number To found it\n";
				cin >> num;
				interpolationSearch(num);
			}
			else if (op == 5)
			{
				return;
			}

		}
		else if (op == 7)
		{
			return;
		}
		else { cout << "Error in entry\n"; }

		cout << "\n";

		cout << "Do you want another opration\n";
		cout << "Yes -> 1 \n";
		cout << "NO -> any key \n";
		cin >> ao;

	} while (ao == 1);
}

int main()
{
	app();
	return 0;
}