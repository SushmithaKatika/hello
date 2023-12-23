#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int* Intvector;
void bar(void){
	printf("augh i ve beenhacked\n");
}
void insert(unsigned long index,unsigned long value){
	printf("writing memory at %p\n",&(Intvector[index]));
	Intvector[index]=value;
}
bool Initvector(int size){
	Intvector =(int*)malloc(sizeof(int)*size);
	printf("address of intvector is %p\n",Intvector);
	if(Intvector==NULL)
	return false;
	return true;
}
int main(int argc,char* argv[]){
	unsigned long index,value;
	if(argc!=3){
		printf("usage is %s[index][value]\n",argv[0]);
		return -1;
	}
	printf("Address of bar is %p\n",bar);
	if(!Initvector(0xffff))
	{
	printf("cannot intialize vector!\n");
	return -1;
	}
	index=atol(argv[1]);
	value=atol(argv[2]);
	insert(index,value);
	return 0;
}
