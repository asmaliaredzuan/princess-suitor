#include "Suitor.h"
#include <iostream>
using namespace std;
void linkedlist(int number);

int main()
{
	int suitors;
	
	cout << "Enter the number of suitors: ";
	cin >> suitors;
		
	if (suitors==1)
		cout << suitors << " is the lucky winner!" << endl;
	else 
	{
		Suitor princessSuitor;
		princessSuitor.linkedlist(suitors);
		princessSuitor.~Suitor();
	}
	
	system("pause");	
	return 0;
}
