#include<iostream>
#include <stdio.h>
#include <math.h> 
#include<fstream>
#include <cstring>
#include <bits/stdc++.h>
#define m 100
using namespace std;
string line[m];
string name_tmp[m];
int k=0;
int Number[m];
struct phnBook{
	int num;
	string name;
	phnBook *next;
};
phnBook *phnNumber_H[m];
phnBook *phnNumber_T[m];

int h(string O){
	int Hk =0;
	for(int l=O.length()-1;l>=0;l--){
		Hk = Hk+(int)O[l]*pow(5,l);
		//Hk = (Hk*5+(int)O[l])%m00000019;
	}
//	cout<<Hk<<endl;
	return Hk%1019%m;
//	return Hk%m;
}

void Append(string O){
	struct phnBook* L = new phnBook();
	L->num= Number[k++];
	L->name = O;
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


 phnBook* Get(string O){
	struct phnBook* L = phnNumber_H[h(O)];
	while(L!=NULL){
		if(O == L->name)
			return L;
		L=L->next;
	}
	return NULL ; // it shows that there is no entry for the phnNumber.
}

int Set(string O){
	//cout<<"hi"<<endl;
	struct phnBook* L = phnNumber_H[h(O)];
	while(L!=NULL){	
		if(O == L->name){
			return -1; // the phnNumber is already exits
		}
		L = L->next;
	}
	Append(O);
}

void UpdateAccessList(){
	int i = 0;
	while (i<m){
		//cout<<Number[i];
		Set(name_tmp[i]);
		i++;
	}
}

int main()
{   
	string myFile = "first_name.txt";
	fstream file;
	file.open(myFile.c_str());
	int i =0;
	while(file>>line[i]){
		name_tmp[i] = line[i];
		i++;	
	}
	
	/*+++++++++++++++++++++++++++++++ phone book ++++++++++++++++++++++++++++++++*/ 
	
	for(int i=0;i<m;i++){
		phnNumber_H[i]=NULL;
		phnNumber_T[i]=NULL;
	}
	for(int i=0;i<m;i++){
		Number[i]=10000-i*2-2;	
	}
	UpdateAccessList();
	for(int i=0;i<m;i++){
		struct phnBook* L = phnNumber_H[i];
		while(L!=NULL){
			cout<<i<<"  "<<L->name<<"->"<<L->num<<endl;
			L = L->next;
		}		
	}
    return 0;
}

