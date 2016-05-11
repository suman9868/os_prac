//priority preemetive 
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
	int BT[n],BT_dupli[n],total=0;
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>BT[i];
		BT_dupli[i]=BT[i];
		total+=BT[i];
	}
	cout<<endl<<"Higher the value, Higher the priority "<<endl;
	cout<<"Enter the priority value of "<<endl;
	int PT[n];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>PT[i]; 
	}
	
	
	int CT[n];
	int pre=0,pri=-1,pos;// pri for priority comparison 
	//for(i=1; i<=n; i++)
	  // CT[i]=-1;
    
	while(total--)
	{
		for(i=1; i<=n; i++)
		{
			if(AT[i]<=pre)
			{
				if(PT[i]>pri && BT_dupli[i]!=0)
				{
					pri=PT[i];
					pos=i;
				}
			}
		}
		CT[pos]=1+pre;
		pre=CT[pos];
	
		pri=-1;
		BT_dupli[pos]--;
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
	
	//cout<<endl<<endl<<"Ghant chart is as following "<<endl<<endl;
	//int temp_ct[n],j;
	//for(i=1; i<=n; i++)
	//    temp_ct[i]=CT[i];
	/*
	for(i=1; i<=n; i++)
	{
		for(j=1; j<n; j++)
		{
			if(temp_ct[j]>temp_ct[j+1])
			{
				int temp=temp_ct[j];
				temp_ct[j]=temp_ct[j+1];
				temp_ct[j+1]=temp;
			}
		}
	}
	*/
	//for(i=1; i<=n; i++)
	  //  cout<<temp_ct[i]<<"    ";
	    
	cout<<"\n\nAT\tBT\tCT\tTAT\tWT\n";
	for(i=1; i<=n; i++)
	{
		cout<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;
	}
	
	cout<<"\n\nAverage value of turn around time is : "<<ATAT/n;
	cout<<"\nAverage value of waiting time is     : "<<AWT/n;
	return 0;
}
