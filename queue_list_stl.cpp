#include <iostream>
#include <list>
using namespace std ;

class Queue
{
	private:
		int current_size ;
		list<int> l ;

	public:
		Queue()
		{
			current_size = 0 ;
		}

		bool is_empty()
		{
			return current_size==0 ;
		}

		void push(int data)
		{
			l.push_back(data) ;
			current_size++ ;
		}

		void pop()
		{
			if (!is_empty())
			{
				current_size-- ;
				l.pop_front() ;
			}

			else
			{
				cout<<"Queue Underflow"<<endl ;
			}
		}

		int front()
		{
			return l.front() ;
		}
};

int main ()
{
	Queue q ;
	for (int i = 1; i <= 10; i++)
	{
		q.push(i) ;
	}

	while (!q.is_empty())
	{
		cout<<q.front()<<endl ;
		q.pop() ;
	}

	return 0 ;
}