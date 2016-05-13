//fcfs
#include<iostream>
using namespace std;

int sumArray(int arr[], int n ){
    int sum = 0 , i ;
    for(i = 0 ; i< n ; i++){
        sum += arr[i] ; 
    }
    return sum ;
}

int findProcess(int arrival[], int burst[], int n){
            int i, index ; 
            index = 0 ;
            for(i = 1 ; i <= n; i++){
                // check the arrival time is less thant the previoush process whose arrival is assumed
                // if it is the first process to be checked then simply assign it as it is
                if((i == 1) || (burst[i] != 0 && arrival[i] < arrival[index])){
                    index = i ; 
                }
            }
    return index; 
}


int main()
{
	int n,i;
    float  ATAT, AWT ; // average waiting time and average turnaround time
	cout<<"Enter the number of processes : ";
	cin>>n;
	cout<<"Enter the arrival time of "<<endl;
	int AT[n+1];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>AT[i]; 
	}
	cout<<"Enter the burst time of   "<<endl;
	int BT[n+1];
	for(i=1; i<=n; i++)
	{
		cout<<"Process ["<<i<<" ]  :  ";
		cin>>BT[i];
	}
	int CT[n];
    int time =  0 ; 
    int TAT[n+1], WT[n+1] ;
    for(i= 1 ; i<=n ;i++){
        // ex denotes the process which is to be executed
        int ex  =  findProcess(AT, BT,  n) ;  // find the process which is to be executed
        time += BT[ex]; 
        CT[ex] = time ; 
        BT[ex] = 0  ; 
        TAT[ex] = CT[ex] - AT[ex] ;
        WT[ex] = TAT[ex] - BT[ex] ; 
        AWT += WT[i] ; 
        ATAT += TAT[ex];
    }

    cout<<endl<<endl<<"Ghant chart is as following "<<endl<<endl;
    for(i=1; i<=n; i++)
        cout<<CT[i]<<"    |";
    
    cout<<"\n\nAverage value of turn around time is : "<<ATAT/n;
    cout<<"\nAverage value of waiting time is     : "<<AWT/n;

	return 0;
}
