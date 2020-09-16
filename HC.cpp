#include "HCfunction.hpp"
//cmd執行方式 ./HC 100(bit數)  1000(iteration) 20(run) r(方法)


int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int iteration = atoi(argv[2]);
	int run = atoi(argv[3]);
	string method =argv[4];
	runresult.resize(run);
	RUN(run,len ,method,iteration);
	

}





