#include <iostream>
using namespace std ;

class node
{
	public:
		int data ;
		node *next ;

		node (int d)
		{
			data = d ;
			next = NULL ;
		}
};

class Queue
{
	private:
		node *front ;
		node *rear ;

	public:
		Queue()
		{
			front = NULL ;
			rear = NULL ;
		}

		void push(int data)
		{
			node *n = new node(data) ;

			if (front == NULL)
			{
				front = n ;
				rear = n ;
				return ;
			}

			rear -> next = n ;
			rear = rear -> next ;
		}

		void pop()
		{
			// Corner Case
			if (front == NULL)
			{
				cout<<"Queue Underflow"<<endl ;
				return ;
			}

			node *to_delete = front ;
			front = front -> next ;
			delete to_delete ;
		}

		int peek()
		{
			// corner case
			if (front == NULL)
			{
				cout<<"No element in the queue"<<endl ;
				return -1 ;
			}

			return front -> data ;
		}

		bool empty()
		{
			if (front == NULL)
			{
				return true ;
			}

			return false ;
		}	
};

int main ()
{
	Queue q ;
	q.push(1) ;
	q.push(2) ;
	q.push(3) ;
	q.push(4) ;

	cout<<q.peek()<<endl ;
	q.pop() ;
	cout<<q.peek()<<endl ;
	q.pop() ;
	cout<<q.peek()<<endl ;
	q.pop() ;
	cout<<q.peek()<<endl ;
	q.pop() ;

	if (q.empty())
	{
		cout<<"Queue is empty now"<<endl ;
	}

	else
	{
		cout<<"Queue is not empty"<<endl ;
	}

	return 0 ;
}