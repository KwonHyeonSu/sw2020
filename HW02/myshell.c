#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //fork(), execvp()
#include <wait.h> //wait()
#include <string.h> //strcmp(), strtok()


int main(){
	//pid => fork()함수의 리턴값을 반환한다.
	//_exec => 자식 함수를 찾는 변수로서, 못찾았을 경우 -1의 반환값을 저장하기 위함.
	//count => 이 _input으로 받은 값을 input에 넣을 때, input[0]부터 차례대로 들어가기 위함.
	int pid=0, _exec, count=0; 
	

	//input => execvp의 인자로서 넣기 위해 _input을 strtok함수를 활용해 나눈 값을 하나하나 저장함.
	//_input => 엔터키를 제외한 모든 입력 값을 한 번에 저장하기 위함.
	//temp => strtok를 사용할 때, _input값을 input에 넣기 위해 임시로 만들어 둔 변수.
	char* input[100]; 
	char _input[30];
	char* temp;
	
	//프로그램 사용법 명시.
	printf("\ntest.c processing!\n");
	printf("\n-----How to Use-----\n");
	printf("\n0 : Quit\n\n");
	printf("sum -> ./sum arg1 arg2\n");
	printf("sub -> ./sub arg1 arg2\n");
	printf("fac -> ./fact arg1\n");
	printf("div -> ./div arg1 arg2\n");
	printf("\n-----How to Use-----\n");
	
	//myshell을 반복하여 실행하기 위한 반복문.
	while(1){
		printf("\ninput : ");

		scanf("%[^\n]s",_input); //엔터키를 제외한 한 줄 전체를 _input에 저장.
		getchar(); //버퍼를 지움으로서, scanf에 원하지 않는 값이 입력되는 것을 막는다.

		if(strcmp(_input,"0")==0) break; //"0"을 입력했을 때, while문을 빠져나가면서 프로그램 종료한다.
		
		//아래 while문까지 하여서 input값을 띄어쓰기 기준으로 단어별로 저장한다.
		temp = strtok(_input," ");

		while(temp != NULL){
			input[count] = temp;
			temp = strtok(NULL, " ");
			count++;
		}

		input[count] = NULL; //input 배열의 끝부분을 NULL로 설정하여 execvp함수의 실행 조건을 만족시킨다.

		pid = fork(); //자식 프로그램을 하나 생성.
		
		//자식이 생성되지 않았을 경우, Fork Failed를 출력하고 시스템 종료.
		if(pid<0){
			fprintf(stderr, "\nFork Failed\n");
			exit(-1);	
		}
		
		//자식프로그램이 읽는 부분으로서, 원하는 함수를 실행한다. 만약 찾지 못하면(execvp의 리턴값이 -1이면)Cannot find function!을 출력하고, 자식 프로그램을 종료한다.
		else if(pid==0){
			_exec = execvp(input[0], input);
			if(_exec == -1){
				printf("\nCannot find function!\n");
			}
			exit(-1);
		}
		
		//부모 프로그램이 읽는 부분으로서, 자식 프로그램이 끝날 때 까지 대기시킨다. (프로그램 중복 방지)
		else{
			wait(NULL);
		}
		count = 0; //count를 0으로 만들어 줌으로서, 프로그램이 반복문을 통해 처음으로 돌아갔을 때 input[0]부터 차례대로 들어가게 한다.
	}

	//사용자가 "0"을 입력하여 반복문을 빠져나왔을 경우 실행되는 부분이다.
	printf("\nexit myshell Program\n\n");
	exit(0);
	return 0;
}

