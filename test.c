#include <stdio.h>

char prompt();
int jump(char);

void fa(){puts("fa ()");};
void fb(){puts("fb ()");};
void fc(){puts("fc ()");};
void fd(){puts("fd ()");};
void fe(){puts("fe ()");};

void (*func[])() = {fa,fb,fc,fd,fe,NULL};

int main(){
	while(jump(prompt()))
		;
	puts("bye!");
	
	return 0;
}


#define BUF_SIZE 16
char prompt(){
	puts("1. fa()");
	puts("2. fb()");
	puts("3. fc()");
	puts("4. fd()");
	puts("5. fe()");
	puts("q. Quit");
	printf(">>> ");
	static char buf[BUF_SIZE];
	fgets(buf, BUF_SIZE, stdin);
	return buf[0];
}

int jump(char ch){
	int code = ch;
	if (code == 'q' || code =='Q')
		return 0;

	code = code - '0' - 1; // base 0
	int func_lenth = 0;
	while(func[func_lenth])
		func_lenth++;

	if(code < 0 || code >=func_lenth){
		puts("invalid number. try again...");
		return 1;
	}

	func[code]();
	return 1;
}
