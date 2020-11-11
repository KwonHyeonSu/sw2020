//fact

#include <stdio.h>
#include <stdlib.h>

//fact함수
int fact(int a){
	if(a==1) return 1;
	return a*fact(a-1);
}

int main(int argc, char* argv[]){
	int re=0;

	//파라미터 1개와 fact를 포함한 총 인자 갯수가 2개가 아닐 경우 1개의 인자가 필요하다고 명시해준다.
	if(argc != 2){
		printf("\nNeed 1 argument!\n");
		return 0;
	}

	//fact함수 실행부분
	re = fact((atoi)(argv[1]));
	printf("\nfact : %d\n", re);

	return 0;
}
