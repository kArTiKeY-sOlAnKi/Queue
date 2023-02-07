#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

vector<int> greater_element(vector<int> &v)
{
	int n = v.size() ;
	vector<int> ans(n) ;

	stack<int> s ;

	for (int i = 2*n - 1; i >= 0; i--)
	{
		while (!s.empty() and v[i % n] >= s.top())
		{
			s.pop() ;
		}

		if (i < n)
		{
			if (!s.empty())
			{
				ans[i] = s.top() ;
			}

			else
			{
				ans[i] = -1 ;
			}

			s.push(v[i % n]) ;
		}
	}

	return ans ;
}

int main ()
{
	int n ;
	cin>>n ;

	vector<int> v(n) ;

	for (int i = 0; i < n; i++)
	{
		cin>>v[i] ;
	}

	vector<int> res = greater_element(v) ;

	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" " ;
	}

	return 0 ;
}