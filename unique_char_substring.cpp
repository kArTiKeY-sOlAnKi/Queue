#include <iostream>
#include <string.h>
using namespace std ;

int main ()
{
	char a[] = "abccdefghi" ;
	// char a[] = "abcdefcghijkzyxz" ;
	int n = strlen(a) ;
	int current_len = 1 ;
	int max_len = 1 ;

	int visited[256] ;

	for (int i = 0; i < 256; i++)
	{
		visited[i] = -1 ;
	}

	visited[a[0]] = 0 ;

	for (int i = 1; i < n; i++)
	{
		int last_occ = visited[a[i]] ; // to check wheather the element has occured prev or not
		
		// Expansion
		if (last_occ == -1 or i - current_len > last_occ)
		{
			current_len++ ;
		}	

		// Expansion + Contraction
		else
		{
			if (current_len > max_len)
			{
				max_len = current_len ;
			}
			current_len = i - last_occ ;
		}
		visited[a[i]] = i ;
	}

	if (current_len > max_len)
	{
		max_len = current_len ;
	}

	cout<<max_len<<endl ;

	return 0 ;
}