//sum

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int i, sum=0;

	//�Ķ���� 2���� sum�� ������ �� ���� ������ 3���� �ƴ� ��� 2���� ���ڰ� �ʿ��ϴٰ� ������ش�.
	if(argc != 3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}

	//sum �Լ� �����
	for(i=0;i<argc;i++) sum+=(atoi)(argv[i]);
	
	printf("\nsum : %d\n",sum);

	return 0;
}
