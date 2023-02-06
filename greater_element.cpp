
#include <iostream>
using namespace std ;

class Queue
{
	private:
		int *arr ;
		int front, rear, current_size, max_size ;

	public:
		// parameterized constructor
		Queue(int n)
		{
			arr = new int(n) ;
			current_size = 0 ;
			max_size = n ;
			front = 0 ;
			rear = max_size - 1 ;
		}

		bool full()
		{
			return current_size==max_size ;
		}

		void push(int data)
		{
			if (!full())
			{
				rear = (rear + 1) % max_size ;
				arr[rear] = data ;
				current_size++ ;
			}
		}

		bool empty()
		{
			return current_size == 0 ;
		}

		void pop()
		{
			if (!empty())
			{
				front = (front + 1) % max_size ;
				current_size-- ;
			}
		}

		int head()
		{
			return arr[front] ;
		}

		~Queue()
		{
			delete [] arr ;
			arr = NULL ;
		}
};

int main ()
{
	int n, element ;
	cin>>n ;

	Queue q(n) ;

	for (int i = 0; i < n; i++)
	{
		cin>>element ;
		q.push(element) ;
	}

	// now the elements are inserted in the queue
	// now to check if the next element is greater than the current element
	for (int i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			cout<<"-1" ;
			break ;
		}
		else
		{
			int temp = q.head() ; // temp will store the front element of the queue
			q.pop() ;
			if (temp > q.head())
			{
				cout<<"-1"<<" " ;
				continue ;
			}
			else
			{
				cout<<q.head()<<" " ;
				continue ;
			}
		}
	}

	return 0 ;
}