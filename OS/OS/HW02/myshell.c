#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //fork(), execvp()
#include <wait.h> //wait()
#include <string.h> //strcmp(), strtok()


int main(){
	//pid => fork()�Լ��� ���ϰ��� ��ȯ�Ѵ�.
	//_exec => �ڽ� �Լ��� ã�� �����μ�, ��ã���� ��� -1�� ��ȯ���� �����ϱ� ����.
	//count => �� _input���� ���� ���� input�� ���� ��, input[0]���� ���ʴ�� ���� ����.
	int pid=0, _exec, count=0; 
	

	//input => execvp�� ���ڷμ� �ֱ� ���� _input�� strtok�Լ��� Ȱ���� ���� ���� �ϳ��ϳ� ������.
	//_input => ����Ű�� ������ ��� �Է� ���� �� ���� �����ϱ� ����.
	//temp => strtok�� ����� ��, _input���� input�� �ֱ� ���� �ӽ÷� ����� �� ����.
	char* input[100]; 
	char _input[30];
	char* temp;
	
	//���α׷� ���� ���.
	printf("\ntest.c processing!\n");
	printf("\n-----How to Use-----\n");
	printf("\n0 : Quit\n\n");
	printf("sum -> ./sum arg1 arg2\n");
	printf("sub -> ./sub arg1 arg2\n");
	printf("fac -> ./fact arg1\n");
	printf("div -> ./div arg1 arg2\n");
	printf("\n-----How to Use-----\n");
	
	//myshell�� �ݺ��Ͽ� �����ϱ� ���� �ݺ���.
	while(1){
		printf("\ninput : ");

		scanf("%[^\n]s",_input); //����Ű�� ������ �� �� ��ü�� _input�� ����.
		getchar(); //���۸� �������μ�, scanf�� ������ �ʴ� ���� �ԷµǴ� ���� ���´�.

		if(strcmp(_input,"0")==0) break; //"0"�� �Է����� ��, while���� ���������鼭 ���α׷� �����Ѵ�.
		
		//�Ʒ� while������ �Ͽ��� input���� ���� �������� �ܾ�� �����Ѵ�.
		temp = strtok(_input," ");

		while(temp != NULL){
			input[count] = temp;
			temp = strtok(NULL, " ");
			count++;
		}

		input[count] = NULL; //input �迭�� ���κ��� NULL�� �����Ͽ� execvp�Լ��� ���� ������ ������Ų��.

		pid = fork(); //�ڽ� ���α׷��� �ϳ� ����.
		
		//�ڽ��� �������� �ʾ��� ���, Fork Failed�� ����ϰ� �ý��� ����.
		if(pid<0){
			fprintf(stderr, "\nFork Failed\n");
			exit(-1);	
		}
		
		//�ڽ����α׷��� �д� �κ����μ�, ���ϴ� �Լ��� �����Ѵ�. ���� ã�� ���ϸ�(execvp�� ���ϰ��� -1�̸�)Cannot find function!�� ����ϰ�, �ڽ� ���α׷��� �����Ѵ�.
		else if(pid==0){
			_exec = execvp(input[0], input);
			if(_exec == -1){
				printf("\nCannot find function!\n");
			}
			exit(-1);
		}
		
		//�θ� ���α׷��� �д� �κ����μ�, �ڽ� ���α׷��� ���� �� ���� ����Ų��. (���α׷� �ߺ� ����)
		else{
			wait(NULL);
		}
		count = 0; //count�� 0���� ����� �����μ�, ���α׷��� �ݺ����� ���� ó������ ���ư��� �� input[0]���� ���ʴ�� ���� �Ѵ�.
	}

	//����ڰ� "0"�� �Է��Ͽ� �ݺ����� ���������� ��� ����Ǵ� �κ��̴�.
	printf("\nexit myshell Program\n\n");
	exit(0);
	return 0;
}

