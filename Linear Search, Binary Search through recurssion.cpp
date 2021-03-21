#include<stdio.h>
#include<iostream>
using namespace std; 
int low =0; 
int k=0;
int arr[1000000];
int high = (sizeof(arr)/sizeof(int))-1;
int key =0;
int mid =0;
int count =0;
//Linear Serach 
int findTheKey(int low , int key){
	if(high<low){
	return -1;
	}
	if(arr[low]==key){
	return low;
	}
	else
    return findTheKey(low+1, key);
}

//Binary search algorithm
/*int BinarySearch(int low ,int high,int key){
	mid = low +(high - low)/2;
	if(high<low)
		return -1;
	else if(arr[mid]==key){
		return mid;
	}
	else if(arr[mid]>key){
		high = mid-1;
		return BinarySearch(low ,high,key);
	}
	else{
		low = mid+1;
		return BinarySearch(low ,high ,key);
	}
}*/

//improved Binary search algorithm
int BinarySearch(int low ,int high,int key){
	while(high>=low){
		count=count+1;
		cout<<" count "<<count<<endl;
		mid = low +(high - low)/2;
		cout<<"mid "<<mid<<endl;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			high = mid-1;
			return BinarySearch(low ,high,key);
		}
		else{
			low = mid+1;
			return BinarySearch(low ,high ,key);
		}
	} 
return -1;
}

int main(){
	for(k=1;k<=1000000;k++){
    arr[k]= k;
}
	//std::cout<<"hello!";
	//int index;
    //index = findTheKey(low ,100000);
    //cout<<index;
    index = BinarySearch(low ,high ,1);
    cout<<index;
	return 0;
}
