#include <iostream>
#include <queue>
using namespace std ;

int main ()
{
	queue<char> q ;
	int freq[27] = {0} ;

	char ch ;
	cin>>ch ;

	while (ch != '.')
	{
		// logic will start in this loop
		// insert in the queue and freq array
		q.push(ch) ;
		freq[ch - 'a']++ ;

		// query
		while (!q.empty())
		{
			int index = q.front() - 'a' ;
			if (freq[index] > 1)
			{
				q.pop() ;
			}

			else
			{
				cout<<q.front()<<endl ;
				break ;
			}
		}

		if (q.empty())
		{
			cout<<"-1"<<endl ;
		}

		cin>>ch ;
	}

	return 0 ;
}