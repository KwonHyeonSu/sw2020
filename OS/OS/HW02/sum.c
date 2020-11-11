//sum

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int i, sum=0;

	//파라미터 2개와 sum을 포함한 총 인자 갯수가 3개가 아닐 경우 2개의 인자가 필요하다고 명시해준다.
	if(argc != 3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}

	//sum 함수 수행부
	for(i=0;i<argc;i++) sum+=(atoi)(argv[i]);
	
	printf("\nsum : %d\n",sum);

	return 0;
}
