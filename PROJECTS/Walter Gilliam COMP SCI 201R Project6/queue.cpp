#include "queue.h"
using namespace std;

queue::queue(string depName)
{
	head = NULL;
	tail = NULL;
	count = 0;
	departmentName = depName;
}

void queue::push_back(patient &pat)
{
	if (is_empty())
	{
		head = new Node(pat, NULL);
		tail = head;
	}
	else
	{
		tail->next = new Node(pat, NULL);
		tail = tail->next;
	}
	count++;
}

void queue::push_front(patient &pat)
{
	if (is_empty())
	{
		head = new Node(pat, NULL);
		tail = head;
	}
	else
	{
		Node* temp = head;
		head = new Node(pat, temp);
	}
	count++;
}

void queue::pop()
{
	if (!is_empty())
	{
		Node* curr = head;
		head = head->next;
		if (head == NULL)
		{
			tail = NULL;
		}
		delete curr;
		count--;
	}
}

void queue::erase(patient &pat) //FIX ME!!!!!!!!!!!!!
{
	if (head != NULL)
	{
		Node* prev = head;
		Node* curr = head->next;

		if (prev->data == pat)
		{
			head = curr;
			prev = NULL;
			delete prev;
			count--;
			cout << pat.firstName << " " << pat.lastName << " removed" << endl;
			return;
		}
		else
		{
			while (curr != NULL)
			{
				if (curr->data == pat)
				{
					*(prev->next) = *(curr->next);
					curr = NULL;
					delete curr;
					count--;
					cout << pat.firstName << " " << pat.lastName << " removed" << endl;
					return;
				}
				else
				{
					prev = prev->next;
					curr = curr->next;
				}
			}
		}
	}
	else
	{
		cout << "Queue for this department is empty" << endl;
		return;
	}
	cout << "Patient Not Found" << endl;
}

void queue::printAll()
{
	if (head != NULL)
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << endl << "First Name: " << curr->data.firstName << endl
				<< "Last Name: " << curr->data.lastName << endl
				<< "Social Security Number: " << curr->data.SSN << endl;
			curr = curr->next;
		}
	}
	else 
	{
		cout << "Queue for this department is empty" << endl;
	}
}

int queue::size() const
{
	return count;
}

bool queue::is_empty() const
{
	if (count == 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

string queue::getDName()
{
	return departmentName;
}