#include<iostream>
#include<cstdlib>
#include<ctime>
#include<omp.h>
using namespace std;


void merge(int arr[], int start, int end){
	int mid = (start+end)/2;
	
	int firstArrayLength = mid - start + 1;
	int secondArrayLength = end - mid;
	
	int *firstArray = new int[firstArrayLength];
	int *secondArray = new int[secondArrayLength];
	
	int mainArrayIndex = start;
	for(int i=0; i<firstArrayLength ;i++)
		firstArray[i] = arr[mainArrayIndex++];

	mainArrayIndex = mid + 1;
	for(int i=0; i<secondArrayLength; i++)
		secondArray[i] = arr[mainArrayIndex++];
	
	//merge two arrays
	int index1 = 0;
	int index2 = 0;
	mainArrayIndex = start;
	
	while(index1 < firstArrayLength && index2 < secondArrayLength){
		if(firstArray[index1] < secondArray[index2])
			arr[mainArrayIndex++] = firstArray[index1++];
		else
			arr[mainArrayIndex++] = secondArray[index2++];
	}
	
	while(index1 < firstArrayLength)
		arr[mainArrayIndex++] = firstArray[index1++];
	while(index2 < secondArrayLength)
		arr[mainArrayIndex++] = secondArray[index2++];

	
}

void mergeSort(int arr[], int start, int end){
	if(start >= end)
		return;
	
	int mid = (start+end)/2;
	//left part 
	#pragma omp task shared(arr)
	mergeSort(arr, start, mid);

	//right part
	#pragma omp task shared(arr)
	mergeSort(arr, mid+1, end);

	//merge
	#pragma omp taskwait
	merge(arr, start, end);
}

void printArray(int arr[], int size){
	for(int i=0; i<size ; i++){
		cout<< arr[i] << " ";
	}
	cout<<endl;	
}

int main(){
	int size;
	cout<<"Enter the size of an array : ";
	cin>>size;
	
	int *arr = new int[size];
        int end = size;
	srand(time(0));
	for(int i=0;i<size;i++)	
		arr[i] = rand() % 100;

	
	
 
	cout<<"Before Sorting : "<<endl;
	printArray(arr,size);
    
    clock_t starttime = clock();
 #pragma omp parallel
    {
        #pragma omp single
        {
            mergeSort(arr, 0, size - 1);
        }
    }
   clock_t endtime = clock();
   
   double time = double(endtime - starttime) / CLOCKS_PER_SEC;
    
	cout<<"After Sorting : "<<endl;
	printArray(arr,size);
	
	cout<<"Parallel time : "<<time<<endl;
	
	return 0;
	
}	