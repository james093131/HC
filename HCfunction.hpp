#include "normal.hpp"

void Enumnext(vector<char> &arr,int len){
	int i=len-1;
	int ran=rand()%2;
	if (ran==1)
	{
		add(arr,len);
	}
	else{
		sub(arr,len);
	}
	
}
void NeighborSelection(vector<char> &arr,int size){
	int ran=rand()%size;
	if(arr[ran]=='1')
		arr[ran]='0';
	else
		arr[ran]='1';
    
}
void ITER(int iteration,int len,string method)
{
	onemax.resize(len);
	create(onemax,len);
	opt=Evaluate(onemax,len);
	int k=0;
	while(k<iteration)
		{
			vector <char>  temp;
			temp.resize(len);
			temp.assign(onemax.begin(),onemax.end());
			if(method == std::string("r"))
				NeighborSelection(temp,len);
			else 
				Enumnext(temp,len);
			int curropt=Evaluate(temp,len);
			compare(onemax,temp,len,opt,curropt);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
			if(opt==len)
				break;			
			k++;
		}
}
void RUN(int run,int len ,string method,int iteration)
{
	int r=0;
	while(r<run){
		ITER(iteration,len,method);
		runresult[r]=opt;
		r++;
	}
	avgiteration=avg(runresult,r);
	cout<<"Average Optima :"<<avgiteration<<endl;
	Read_File(iteration,avgiteration,method);
}
