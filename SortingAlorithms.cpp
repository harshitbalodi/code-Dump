#include <iostream>
#include<vector> 
#include<time.h>
using namespace std;
void Display(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Merge Sort
void Merge(int* arr,int l,int mid,int h){
  int n1 = mid - l + 1;
  int n2 = h - mid;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int j = 0; j < n2; j++) M[j] = arr[mid + 1 + j];
  int i = 0,j = 0,k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j])  arr[k++] = L[i++];
      else arr[k++] = M[j++];
  }
  while (i < n1) arr[k++] = L[i++];
  while (j < n2)arr[k++] = M[j++];
}
void MergeSort(int *arr,int l,int h){
    if(l<h){
        int mid=l+(h-l)/2;//mid is the at which the array will be divided into to
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        Merge(arr,l,mid,h);//merging two sorted arrays
    }
}
//Quick Sort
int Partition(int *arr,int l,int h){
    int pivot=arr[l];//choosing first element as a pivot
    int i=l;
    int j=h;
    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[l]);
    return j;
}
void QuickSort(int *arr,int l,int h){
    if(l<h){
        int pivot=Partition(arr,l,h);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,h);
    }
}
//Bubble Sort
void BubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
//Bucket Sort
void BucketSort(int *arr,int n){
    int maxele=-1e7;
    for(int i=0;i<n;i++){
        maxele=max(maxele,arr[i]);
    }
    vector<vector<int>>bucket(maxele+1);
    for(int i=0;i<n;i++){
        bucket[arr[i]].push_back(arr[i]);
    }
    int i=0;
    for(int k=0;k<=maxele;k++){
        for(auto x:bucket[k]){
            arr[i++]=x;
        }
    }
}
//Radix Sort
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
  
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
   
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void RadixSort(int *arr,int n){ 
        int m=-1e7;
    for(int i=0;i<n;i++){
        m=max(m,arr[i]);
    }
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
//shell Sort
void ShellSort(int *arr,int n){
     for (int gap = n/2; gap > 0; gap /= 2)
    {
       
        for (int i = gap; i < n; i += 1)
        {
           
            int temp = arr[i];
  
            
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            arr[j] = temp;
        }
    }
}
//Selection Sort
void SelectionSort(int *arr,int n){
    int i,j,k;
    for(int i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k])
                k=j;
        }
        swap(arr[i],arr[k]);
    }
    
}
//Heap Sort
void heapify(int arr[], int N, int i)
{
 
    int largest = i;// Initialize largest as root
 
    int l = 2 * i + 1; // left = 2*i + 1
 
    int r = 2 * i + 2;// right = 2*i + 2
    
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    if (r < N && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
         heapify(arr, N, largest);
    }
}
void HeapSort(int *arr,int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
 
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
int main() {
    int size=0;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int choice;
    cout<<"choose one of the Sorting technique and Find out the Time taken by the following Sorting.\n1. Merge sort \n2. Quick sort \n3. Bubble sort \n4. Bucket sort \n5. Radix sort \n6. Shell sort \n7. Selection sort \n8. Heap sort"<<endl;
    cin>>choice;
    switch(choice){
        case 1:{
            int start=clock();
            MergeSort(arr,0,size-1);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Merge sort "<<end-start<<" millisecond"<<endl;
            break;
        }
        case 2:{
          int start=clock();
            QuickSort(arr,0,size-1);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Quick sort "<<end-start<<" millisecond"<<endl;
          break;  
        }
        case 3:{
           int start=clock();
            BubbleSort(arr,size);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Bubble sort "<<end-start<<" millisecond"<<endl;
           break; 
        }
        case 4:{
        int start=clock();
            BucketSort(arr,size);
            int end=clock();
           Display(arr,size);
            cout<<"Time Taken by Bucket sort "<<end-start<<" millisecond"<<endl;
            break;
        }
        case 5:{
         int start=clock();
         RadixSort(arr,size);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Radix sort "<<end-start<<" millisecond"<<endl;
            break;  
        }
        case 6:{
              int start=clock();
              ShellSort(arr,size);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Shell sort "<<end-start<<" millisecond"<<endl;
            break;
        }
        case 7:{
         int start=clock();
            SelectionSort(arr,size);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Selection sort "<<end-start<<" millisecond"<<endl;
            break;   
        }
        case 8:{
            int start=clock();
            HeapSort(arr,size);
            int end=clock();
            Display(arr,size);
            cout<<"Time Taken by Heap sort "<<end-start<<" millisecond"<<endl;
            break;
        }
        default: 
        cout<<"Not a valid Choice"<<endl;
    }
    return 0;
}