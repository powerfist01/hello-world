#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter "<<n<<" numbers: ";
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int m;
	cout<<"Enter no. of rotations: ";
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<n; j++)
		{
			int temp = a[j];
			a[j] = a[0];
			a[0] = temp;
		}
	}
	cout<<"After "<<m<<" rotations, array is: ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}