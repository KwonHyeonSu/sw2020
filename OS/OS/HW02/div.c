//div

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int div1, div2;

	//�Ķ���� 2���� div�� ������ �� ���� ������ 3���� �ƴ� ��� 2���� ���ڰ� �ʿ��ϴٰ� ������ش�.
	if(argc != 3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}
	
	//div�Լ� ���� �κ�.
	div1 = (atoi)(argv[1])/(atoi)(argv[2]);
	div2 = (atoi)(argv[1])%(atoi)(argv[2]);

	printf("\nQuotient : %d\nremainder : %d\n", div1, div2);

	return 0;
}
