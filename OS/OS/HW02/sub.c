//sub

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int sub = 0;
	
	//파라미터 2개와 sub을 포함한 총 인자 갯수가 3개가 아닐 경우 2개의 인자가 필요하다고 명시해준다.
	if(argc!=3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}

	//sub함수 실행부분
	sub = (atoi)(argv[1])-(atoi)(argv[2]);

	printf("\nsub : %d\n",sub);

	return 0;

}
