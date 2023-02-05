#include <iostream>
#include <deque>
using namespace std ;

int main ()
{
	int n ;
	int a[100000] ;
	int k, i = 0 ;

	cin>>n ;
	for (i = 0; i < n; i++)
	{
		cin>>a[i] ;
	}

	cin>>k ;

	// We have to separate first k elements separately
	deque<int> q ;

	for (i = 0; i < k; i++)
	{
		while (!q.empty() and a[i] > a[q.back()])
		{
			q.pop_back() ;
		}

		q.push_back(i) ;
	}

	// Process the remaining elements
	for (; i < n; i++)
	{
		cout<<a[q.front()]<<" " ;

		// 1. Remove the elements which are not the part of the window (Contraction)
		while ((!q.empty()) and (q.front() <= i - k))
		{
			q.pop_front() ;
		}

		//2. Remove the elements which are not useful but are present in the window
		while ((!q.empty()) and (a[i] >= a[q.back()]))
		{
			q.pop_back() ;
		}

		//3. Add the new elements (Expansion)
		q.push_back(i) ;
	}

	cout<<a[q.front()] ;

	return 0 ;
}