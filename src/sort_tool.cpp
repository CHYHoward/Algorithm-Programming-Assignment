// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data)
{
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1;i<data.size();i++){
        int key = data[i];
        int j = i-1;
        while (j>=0&&data[j]>key){
            data[j+1]=data[j];
            j = j-1;
        }
        data[j+1] =key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data)
{
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if(low<high){
        int mid = Partition(data,low,high);
        QuickSortSubVector(data,low,mid-1);
        QuickSortSubVector(data,mid+1,high);

    }
}

int SortTool::Partition(vector<int> &data, int low, int high)
{
    // Function : Partition the vector
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int x = data[high];
    int i = low-1;
    for(int j = low;j<high;j++){
        if(data[j]<=x){
            i++;
            swap(data[i],data[j]);
        }
    }
    swap(data[i+1],data[high]);
    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data)
{
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if(low<high){
        int mid = (high+low)/2;
        MergeSortSubVector(data,low,mid);
        MergeSortSubVector(data,mid+1,high);
        Merge(data,low,mid,high);
    }
}

// Merge
void SortTool::Merge(vector<int> &data, int low,int middle, int high)
{
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int new1 = middle-low+1;
    int new2 = high-middle;
    vector<int> l;
    vector<int> r;
    for(int i = 0;i<new1;i++){
        l[i] = data[low+i];   
    }
     for(int i = 0;i<new2;i++){
        r[i] = data[middle+i];   
    }
    l[new1+1] = 100000000000;
    r[new2+1] = 100000000000;
    int i = 0;
    int j = 0;
    for(int k = low;k<high;k++){
        if(l[i]<=r[j]){
            data[k] = l[i];
            i++;
        }else{
            data[k] = r[j];
            j++;
        }
//confirm;
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int> &data)
{
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}

// Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root)
{
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int l = (root);
    int r = (root);
    //not yet implemented
}

// Build max heap
void SortTool::BuildMaxHeap(vector<int> &data)
{
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for(int i = data.size();i>0;i++){//make sure
        MaxHeapify(data,i);
    }

}
