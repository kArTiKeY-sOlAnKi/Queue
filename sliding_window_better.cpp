#include <iostream>
#include <deque>
#include <vector>
using namespace std ;

vector<int> sliding_window(vector<int> &nums, int k)
{
	vector<int> ans ;
	deque<int> dq ;

	// iterating over the original vector
	// 0 1 2  3 4 5 6 7
    // 1 3 1 -3 5 3 6 7
	for (int i = 0; i < nums.size(); i++)
	{
		// if the element is out of the current window, take it out
		if (!dq.empty() and dq.front() == i - k)
		{
			dq.pop_front() ;
		}

		// if encountered element is max then empty the queue
		while (!dq.empty() and nums[dq.back()] <= nums[i])
		{
			dq.pop_back() ;
		}

		dq.push_back(i) ;

		if (i >= k - 1)
		{
			ans.push_back(nums[dq.front()]) ;
		}
	}

	return ans ;
}

int main ()
{
	int n, k ;
	cin>>n ;

	vector<int> nums ;

	for (int i = 0; i < n; i++)
	{
		int ele ;
		cin>>ele ;
		nums.push_back(ele) ;
	}

	cin>>k ;

	vector<int> ans = sliding_window(nums,k) ;

	// displaying the final vector
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" " ;
	}

	return 0 ;
}