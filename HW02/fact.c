//fact

#include <stdio.h>
#include <stdlib.h>

//fact�Լ�
int fact(int a){
	if(a==1) return 1;
	return a*fact(a-1);
}

int main(int argc, char* argv[]){
	int re=0;

	//�Ķ���� 1���� fact�� ������ �� ���� ������ 2���� �ƴ� ��� 1���� ���ڰ� �ʿ��ϴٰ� ������ش�.
	if(argc != 2){
		printf("\nNeed 1 argument!\n");
		return 0;
	}

	//fact�Լ� ����κ�
	re = fact((atoi)(argv[1]));
	printf("\nfact : %d\n", re);

	return 0;
}
