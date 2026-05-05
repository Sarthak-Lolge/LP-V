#include<iostream>
#include<climits>
#include<omp.h>
#include<ctime>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size : ";
	cin>>n;
	
	int *arr = new int[n];
	
	srand(time(0));
	for(int i=0 ; i<=n ;i++)
		arr[i] = rand() % 10;
	
	for(int i=0 ; i<=n ;i++)
		cout<<arr[i]<<" ";	
	
	int sum = 0;
	int min = INT_MAX;
	int max = INT_MIN;

	 #pragma omp parallel for reduction(+:sum) reduction(min:min_val) reduction(max:max_val)
	for(int i=0;i<=n;i++){
		sum+=arr[i];
		if(arr[i] < min)		
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	double avg = (double)sum/n;
	cout << "\nResults:\n";
    cout << "Sum = " << sum << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << "Average = " << avg << endl;	
return 0;
		
}