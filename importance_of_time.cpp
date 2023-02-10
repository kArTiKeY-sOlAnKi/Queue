#include <iostream>
#include <queue>
#include <deque>
using namespace std ;

int calc_time(deque<int> &process, queue<int> &ideal)
{
	int count = 0, temp ;

	while (!process.empty())
	{
		if (process.front() == ideal.front())
		{
			count++ ;
			process.pop_front() ;
			ideal.pop() ;
		}

		else
		{
			temp = process.front() ;
			process.pop_front() ;
			process.push_back(temp) ;
			count++ ;
		}
	}

	return count ;
}

int main ()
{
	int n, element ;
	deque<int> process ;
	queue<int> ideal ; 

	cin>>n ;

	// taking input for process_id 
	for (int i = 0; i < n; i++)
	{
		cin>>element ;
		process.push_back(element) ;
	}

	// taking input for the ideal process order
	for (int i = 0; i < n; i++)
	{
		cin>>element ;
		ideal.push(element) ;
	}

	int value = calc_time(process,ideal) ;

	cout<<value ;

	return 0 ;
}