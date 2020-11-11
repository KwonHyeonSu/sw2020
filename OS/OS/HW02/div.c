//div

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int div1, div2;

	//파라미터 2개와 div을 포함한 총 인자 갯수가 3개가 아닐 경우 2개의 인자가 필요하다고 명시해준다.
	if(argc != 3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}
	
	//div함수 수행 부분.
	div1 = (atoi)(argv[1])/(atoi)(argv[2]);
	div2 = (atoi)(argv[1])%(atoi)(argv[2]);

	printf("\nQuotient : %d\nremainder : %d\n", div1, div2);

	return 0;
}
