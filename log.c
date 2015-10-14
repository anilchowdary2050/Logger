#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#include "log.h"
FILE *fp;
char Initial_File[100];
char *time_buff;
void Current_Time();
void Compose_FileName(char*);
void print_log (char *File,int line_number,char *function_name,int level,char *fmt,...){

	va_list args,myargs;
	Current_Time();
	fprintf(fp,"[%s]\t",Log[level]);
	fprintf(fp,"[TIME:%s]\t[MESSAGE]  ",time_buff);
	va_start(args, fmt);
	va_copy(myargs,args);
	vfprintf(fp,fmt,myargs);

	//      vprintf(fmt, args);
	va_end(args);
	fprintf(fp,"\tFILE:%s\t,Line:%d\t,Function:%s\n",File,line_number,function_name);


}
void Initialize_Log(int mode,int level,char *file_name){
	char filename[100];
	time_buff=(char*)malloc(100*sizeof(char));
	memset(time_buff,0,sizeof(100*sizeof(char)));
	strncpy(Initial_File,file_name,strlen(file_name));
	Compose_FileName(filename);
	if(mode == FILE_MODE){
		fp=NULL;
		fp=fopen(filename,"w");
		if(fp==NULL){
			fprintf(stderr,"Failed to open file :%s\n",filename);
			exit(0);

		}

	}
else 
{

fp=stderr;
}
}

void Compose_FileName(char *filename){
	Current_Time();
	sprintf(filename,"%s::%s",Initial_File,time_buff);
}

void Current_Time(){

	time_t rawtime;
	struct tm *info;
	//char buffer[80];

	time( &rawtime );

	info = localtime( &rawtime );

	//strftime(buffer,80,"%x - %I:%M%p", info);
	strftime(time_buff,80,"%F %H:%M:%S ", info);
	// printf("Formatted date & time : |%s|\n", buffer );



}
