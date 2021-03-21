#include<iostream>
#include <stdio.h>
#include<fstream>
#include <cstring>
#include <bits/stdc++.h>
#define m 100
using namespace std;
string line[m];
int k=0;
int Number[100];
struct phnBook{
	int num;
	string name;
	phnBook *next;
};
phnBook *phnNumber_H[100];
phnBook *phnNumber_T[100];

int h(int O){
	//cout<<"h[O]"<<(34*O+2)%10001%m<<endl;
	return (34*O+2)%10001%m;
}

void Append(int O){
	struct phnBook* L = new phnBook();
	L->num= O;
	L->name = line[k++];
	//cout<<"hi there";
	L->next = NULL;
	if(phnNumber_H[h(O)] == NULL){
		phnNumber_H[h(O)] = L;
	}
	else{
		phnNumber_T[h(O)]->next = L;
	}
	phnNumber_T[h(O)] = L;
	
}


 phnBook* Get(int O){
	struct phnBook* L = phnNumber_H[h(O)];
	while(L!=NULL){
		if(O == L->num)
			return L;
		L=L->next;
	}
	return NULL ; // it shows that there is no entry for the phnNumber.
}

int Set(int O){
	struct phnBook* L = phnNumber_H[h(O)];
	while(L!=NULL){	
		if(O == L->num){
			return -1; // the phnNumber is already exits
		}
		L = L->next;
	}
	Append(O);
}

void UpdateAccessList(){
	int i = 0;
	while (i<100){
		//cout<<Number[i];
		Set(Number[i]);
		i++;
	}
}
//Creating new array with double size
int* resize(int size, int* arr){
    int* temp = new int[size];
    for(int i=0;i<size;i++){
        temp[i] = arr[i]; 
    }
    arr = new int [2*size];
    for(int i=0;i<2*size;i++){
        if(i<size)
            arr[i]= temp[i];
        else
            arr[i]= -1;
    }
    delete[] temp;
    return arr;
}

int main()
{   
	string myFile = "first_name.txt";
	fstream file;
	file.open(myFile.c_str());
	int i =0;
	while(file>>line[i]){
		i++;	
	}
	
	/*+++++++++++++++++++++++++++++++ phone book ++++++++++++++++++++++++++++++++*/ 
	
	for(int i=0;i<m;i++){
		phnNumber_H[i]=NULL;
		phnNumber_T[i]=NULL;
	}
	for(int i=0;i<m;i++){
		Number[i]=10000-i*2-2;
		cout<<Number[i]<<endl;	
	}
	UpdateAccessList();
	for(int i=0;i<m;i++){ 
		struct phnBook* L = phnNumber_H[i];
		while(L!=NULL){
			cout<<i<<"  "<<L->name<<"->"<<L->num<<endl;
			L = L->next;
		}		
	}
	cout<<"+++++++++++++++++++++++++++++++"<<endl;
	cout<<Get(9850)->name<<endl;
	cout<<Get(9876)->name<<endl;
	cout<<Get(9882)->name<<endl;
	cout<<Get(9832)->name<<endl;
	//Set the name or change the phn no
	Get(9850)->name = "Suraj";
	Get(9876)->name = "Neeraj";
	Get(9882)->name = "Brijesh";
	Get(9832)->name = "Durgesh";
	UpdateAccessList();
	for(int i=0;i<m;i++){
		struct phnBook* L = phnNumber_H[i];
		while(L!=NULL){
			cout<<i<<"  "<<L->name<<"->"<<L->num<<endl;
			L = L->next;
		}		
	}
//    int size;
//    cout<<"size";
//    cin>>size;
//    int* arr = new int[size];
//    for(int i =0;i<size;i++){
//        arr[i] = i*i;
//    }
//    for(int i =0;i<size;i++){
//        cout<<"arr["<<i<<"]"<<arr[i]<<endl;
//    }
//    arr = resize(size, arr);
//    size = 2*size;
//    for(int i =0;i<size;i++){
//        cout<<"arr["<<i<<"]"<<arr[i]<<endl;
//    }
//    delete[] arr;
    return 0;
}

