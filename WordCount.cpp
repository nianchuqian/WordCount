#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024
/*
	���建��������ַ���ΪMAXSIZE=1024 
	������һ�����ʷָ���֮ǰ�Ѿ�����һ�������ˣ�����WordCount=1 
	argv[2]Ϊ�������Ҫͳ�Ƶ��ı������� 
*/

int main(int argc, char** argv) {
	
	int CharCount = 0;	   //�ַ���
	int WordCount = 1;     //������
	char buf[MAXSIZE];	  //�������� 
	FILE *fp;	//�ļ�ָ�� 
	
	if((fp = fopen(argv[2],"r")) == NULL){
		printf("");
		exit(1);
	} 
	
	if(strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-C") == 0){
		while(fgetc(fp) != EOF){
			CharCount++;
		}
		printf("�ַ���Ϊ��%d",CharCount);
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
		printf("������Ϊ��%d",WordCount);
	}
	
	return 0;
}
