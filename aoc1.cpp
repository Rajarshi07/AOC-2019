#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
int fuel(float k){
	return floor(k/3)-2;
}
int modfuel(float k,int totsum=0){
	int l=fuel(k);
	if(l>0)modfuel(l,totsum+l);
	else return totsum;
}
int main(){
	fstream fin;
	float f;int sum=0;
	fin.open("aoc1.txt");
	while(fin>>f){
		//sum+=fuel(f)		//step1
		sum+=modfuel(f);	
	}
	fin.close();
	cout<<sum;
	return 0;
}
