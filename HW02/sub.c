//sub

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	int sub = 0;
	
	//�Ķ���� 2���� sub�� ������ �� ���� ������ 3���� �ƴ� ��� 2���� ���ڰ� �ʿ��ϴٰ� ������ش�.
	if(argc!=3){
		printf("\nNeed 2 argument!\n");
		return 0;
	}

	//sub�Լ� ����κ�
	sub = (atoi)(argv[1])-(atoi)(argv[2]);

	printf("\nsub : %d\n",sub);

	return 0;

}
