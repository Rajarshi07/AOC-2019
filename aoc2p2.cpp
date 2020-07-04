#include<iostream>
using namespace std;
long long int backup[]={1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,19,9,23,1,23,13,27,1,10,27,31,2,31,13,35,1,10,35,39,2,9,39,43,2,43,9,47,1,6,47,51,1,10,51,55,2,55,13,59,1,59,10,63,2,63,13,67,2,67,9,71,1,6,71,75,2,75,9,79,1,79,5,83,2,83,13,87,1,9,87,91,1,13,91,95,1,2,95,99,1,99,6,0,99,2,14,0,0};
long long int a[]={1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,19,9,23,1,23,13,27,1,10,27,31,2,31,13,35,1,10,35,39,2,9,39,43,2,43,9,47,1,6,47,51,1,10,51,55,2,55,13,59,1,59,10,63,2,63,13,67,2,67,9,71,1,6,71,75,2,75,9,79,1,79,5,83,2,83,13,87,1,9,87,91,1,13,91,95,1,2,95,99,1,99,6,0,99,2,14,0,0};

long long int Calc(long long int n){
	long long int len = sizeof(a)/sizeof(a[0]);
	for(int noun=0;noun<100;noun++){
		for(int verb=0;verb<100;verb++){
			for(long long int i=0;i<len;i++)a[i]=backup[i];	//restoring values of working array a from backup
			a[1]=noun;a[2]=verb;	//bruteforcing
			for(long long int i=0;i<len;i+=4){	//intcode calculation
				if(a[i]==1)a[a[i+3]]=a[a[i+2]]+a[a[i+1]];
				else if(a[i]==2)a[a[i+3]]=a[a[i+2]]*a[a[i+1]];
				else if(a[i]==99)break;
				else break;
			}
			if(a[0]==n){
				cout<<noun<<"  "<<verb<<"  "<<a[0]<<'\n';
				break;
			}
		}
	}	
}
int main(){
	Calc(19690720);
}
