//fcfs
#include<iostream>
using namespace std;

int main()
{
	int n,i;
	cout<<"Enter the number of processes : ";
	cin>>n;
	cout<<"Enter the arrivial time of "<<endl;
	int AT[n];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>AT[i]; 
	}
	cout<<"Enter the burst time of   "<<endl;
	int BT[n];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>BT[i];
	}
	int CT[n];
	CT[1]=BT[1];
	for(i=2; i<=n; i++)
	{
		CT[i]=BT[i]+CT[i-1];
	}
	int TAT[n];
	float ATAT=0;
	for(i=1; i<=n; i++)
	{
		TAT[i]=CT[i]-AT[i];
		ATAT+=TAT[i];
	}
	int WT[n];
	float AWT=0;
	for(i=1; i<=n; i++)
	{
		WT[i]=TAT[i]-BT[i];
		AWT+=WT[i];
	}
	
	cout<<endl<<endl<<"Ghant chart is as following "<<endl<<endl;
	for(i=1; i<=n; i++)
	    cout<<CT[i]<<"    ";
	
	cout<<"\n\nAverage value of turn around time is : "<<ATAT/n;
	cout<<"\nAverage value of waiting time is     : "<<AWT/n;
	return 0;
}
