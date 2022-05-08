#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024
/*
	定义缓冲区最大字符数为MAXSIZE=1024 
	在数第一个单词分隔符之前已经存在一个单词了，所以WordCount=1 
	argv[2]为传入的需要统计的文本的名称 
*/

int main(int argc, char** argv) {
	
	int CharCount = 0;	   //字符数
	int WordCount = 1;     //单词数
	char buf[MAXSIZE];	  //缓冲数组 
	FILE *fp;	//文件指针 
	
	if((fp = fopen(argv[2],"r")) == NULL){
		printf("");
		exit(1);
	} 
	
	if(strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-C") == 0){
		while(fgetc(fp) != EOF){
			CharCount++;
		}
		printf("字符数为：%d",CharCount);
	}
	
	if(strcmp(argv[1],"-w") == 0 || strcmp(argv[1],"-W") == 0){
		while(!feof(fp)){
			if(fgets(buf, MAXSIZE, fp)){
				int len = strlen(buf);
				for(int i = 0; i < len; i++){
					if(buf[i] == ' '){
						WordCount++;
					}
				}
			}
		}
		printf("单词数为：%d",WordCount);
	}
	
	return 0;
}
