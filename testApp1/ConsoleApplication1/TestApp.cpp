// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include "math.h"
#include <iostream>
#include <iomanip>

using namespace std;

	
template <typename T, class Collection>
int getCountByPredicate( bool(*predicate)(T), Collection &v)
{ 
	int res = 0;
	for each (T t in v)
	{
		if(predicate(t))
		{
			res++;
		}
	}
	return res; 
}


bool pred(int t)
{ 
	return (t % 2); 
}

int main()
{
	vector<int> a(10);
	for(int i = 0; i <10; ++i)
	{
		a[i] = i;
	}
	cout << getCountByPredicate(pred, a)<<endl;
	system("Pause");
    return 0;
};

