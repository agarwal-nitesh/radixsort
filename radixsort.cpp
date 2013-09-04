#include<iostream>

using namespace std;



void radixSort(int list[],int n){

  int bucket[n];
	int digpos=1;
  int max=list[0];

	for(int i=1;i<n;i++){
	  if(list[i]>max)
      max=list[i];
	}

	while(max/digpos>0){
    
		int digit[10]={0};


	  for(int i=0;i<n;i++)
		  digit[(list[i]/digpos)%10]++;

	  for(int i=1;i<10;i++)
		  digit[i]+=digit[i-1];

		for(int i=n-1;i>=0;i--)
		  bucket[--digit[(list[i]/digpos)%10]]=list[i];
		
		for(int i=0;i<n;i++)
		  list[i]=bucket[i];

	  digpos*=10;
	}

}
