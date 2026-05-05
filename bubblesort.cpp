#include<iostream>
#include<cstdlib>
#include<ctime>
#include<omp.h>


using namespace std;
void bubblesort(int arr[] , int n){
	for(int i=0;i<n-1;i++){
		for(int j=0; j< n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}


void parallelBubbleSort(int arr[], int n){
	for(int i=0;i<n; i++){

		#pragma omp parallel for
		for(int j=0; j<n-1; j+=2){
			if(arr[j] > arr[j+1]){
					swap(arr[j],arr[j+1]);
			}
		}

		#pragma omp parallel for
		for(int j=1; j<n-1; j+=2){
			if(arr[j] > arr[j+1]){
					swap(arr[j],arr[j+1]);
			}
		}


	}
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
	int n;
	cout<<"Enter the size of an array : ";
	cin >> n;
	
	int *arr = new int[n];
	srand(time(0));
	for(int i = 0; i<n ;i++)
		 arr[i] = rand() % 100;
	
	 
	cout<<"Orignal array : "<<endl; 
	printArray(arr, n);
 
	bubblesort(arr, n);
	cout<<"Sorted array : "<<endl;
	printArray(arr, n);
	
	
	parallelBubbleSort(arr,n);
	cout<<"Sorted array using parallel computing  : "<<endl;
	printArray(arr, n);

	return 0;
}