#include <iostream>
#include <stack>
using namespace std ;

template<typename T>
class Queue
{
	private:
		stack<T> s1, s2 ;

	public:
		void push(int data)
		{
			s1.push(data) ; // data will be pushed to stack S1
		}

		void pop()
		{
			// making LIFO to FIFO
			// Stack has a value of 1 2 3 4 5
			// so need to pop in this order only i.e. 1 2 3 4 5
			if (s1.empty())
			{
				return ;
			}

			while (s1.size() > 1)
			{
				T element = s1.top() ; // element will store the topmost value
				s1.pop() ;
				s2.push(element) ;
			}

			s1.pop() ;

			// swap(s1,s2) ;

			while (s2.size() > 0)
			{
				T element = s2.top() ;
				s2.pop() ;
				s1.push(element) ;
			}
		}

		T front()
		{
			// this function will return the front element of the queue
			// Stack is 1 2 3 4 5
			while (s1.size() > 1)
			{
				T element = s1.top() ;
				s1.pop() ;
				s2.push(element) ;
			}

			// now only first element remains in stack S1
			T element = s1.top() ;
			s1.pop() ;
			s2.push(element) ;
			T x = element ;
			while (s2.size() > 0)
			{
				element = s2.top() ;
				s2.pop() ;
				s1.push(element) ;
			}

			return x ;
		}

		bool empty()
		{
			return s1.size()==0 ;
		}
};

int main ()
{
	// need to make a queue using two stacks
	// basically make LIFO to FIFO
	Queue<int> q ;
	q.push(1) ;
	q.push(2) ;
	q.push(3) ;
	q.push(4) ;
	q.push(5) ;

	// in stack the order of popping will be 5 4 3 2 1
	// but need to change this to 1 2 3 4 5
	while (!q.empty())
	{
		cout<<q.front()<<" " ;
		q.pop() ;
	}

	return 0 ;
}