#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include "sort.h"
using namespace std;

#define Size 100
#define Range 100000
#define NumDigit numdig(Range)


int numdig(int r){
  
	int sum=0; 
	while(r>0){
	  r/=10;
		sum++;
	}
  return sum-1;
}

void print(int* list,int n){
  cout<<endl;
  for(int i=0;i<n;i++){
	  cout<<setw(NumDigit+1)<<list[i];
		if((i+1)%15==0)
		  cout<<endl;
  }
	cout<<endl;
}

int comp(const void* elem1, const void* elem2){
	if(*(int*)elem1>*(int*)elem2)//for ascending order
	  return 1;
  else
	  return -1;
  
  return 0;

}

void test(int *initarr,int *finalarr){

	qsort(initarr,Size,sizeof(*initarr),comp);

	for(int i=0;i<Size;i++){
	  if(initarr[i]!=finalarr[i]){
		  cout<<"Test not passed!..."<<endl;
	    return;		
			}
	}
  cout<<"Test Passed"<<endl;

}

int main(){

  srand(time(NULL));
	int list[Size];
  int listcopy[Size];
	for(int i=0;i<Size;i++){
	
	  list[i]=rand()%Range;
		listcopy[i]=list[i];
	}
	cout<<"Before Sorting: "<<endl;
  print(list,Size);

	radixSort(list,Size);
	cout<<"After Sorting: "<<endl;
	print(list,Size);
  test(listcopy,list);
}
