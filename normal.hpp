#include<stdio.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include <vector>
#include<time.h>
using namespace std;


vector<int> runresult;
vector <char>  onemax;
int opt;
int avgiteration;


void create(vector<char> &arr,int size)
{
	for(int i=0;i<size;i++)
	{
  	int a=rand()%2;
    char c =a+'0';
    arr[i]=c;
    }
}
 void Print(vector<char> &arr,int size){
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
} 
int Evaluate(vector<char> &arr,int size)
{
	int optimal=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]=='1')
			optimal++;
	}
	return optimal;
}
void add(vector<char> &arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			i--;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			chc=0;
			break;
		}
	} 
}
void sub (vector<char> &arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			chc=0;
			break;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			i--;
		}
	} 
}
int avg(vector<int> arr,int len)
{
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
		cout<<"Run"<<i+1<<':'<<arr[i]<<endl;
	}
	int avg=sum/len;
	return avg;
}
void compare(vector<char> &arr,vector<char> &temp,int len,int &opt,int curropt)
{
	if(curropt>=opt)
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=temp[i];
		}
		opt=curropt;
	}

	
}
void Read_File(int iteration,int avgiteration,string method)
{
	fstream file;//寫檔
	file.open("Result.txt",ios::app);
	file<<"Iteration :"<<iteration<<' '<<"Optima :"<<avgiteration<<' ';
	if(method == std::string("r"))
	{
		file<<"Using Function :"<<"random"<<endl;
	}
	else
		file<<"Using Function :"<<"leftright"<<endl;
}

