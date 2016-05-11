//round robin scheduling  
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
	int BT[n],total=0,BT_dupli[n];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>BT[i];
		BT_dupli[i]=BT[i];
		total+=BT[i];
	}
	int TQ;
	cout<<"Enter the time quantum : ";
	cin>>TQ;
		
	int CT[n];
	int pre=0,flag; 
	//for(i=1; i<=n; i++)
	  // CT[i]=-1;
    
	do
	{
		for(i=1; i<=n; i++)
		{
			if(AT[i]<=pre && BT[i]!=0)
			{
				if(BT[i]<=TQ)
				{
					CT[i]=pre+BT[i];
					BT[i]=0;
					pre=CT[i];
				}
				else
				{
					CT[i]=pre+TQ;
					BT[i]-=TQ;
					pre=CT[i];
				}
			}
		}
		flag=0;
		for(i=1; i<=n; i++)
		    if(BT[i]!=0)
		        flag=1; 
	}while(flag);
	
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
		WT[i]=TAT[i]-BT_dupli[i];
		AWT+=WT[i];
	}
	
	    
	cout<<"\n\nAT\tBT\tCT\tTAT\tWT\n";
	for(i=1; i<=n; i++)
	{
		cout<<AT[i]<<"\t"<<BT_dupli[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;
	}
	
	cout<<"\n\nAverage value of turn around time is : "<<ATAT/n;
	cout<<"\nAverage value of waiting time is     : "<<AWT/n;
	return 0;
}
