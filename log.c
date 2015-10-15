#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <signal.h>
#include "log.h"
int current_log_level=3;
//int log_level_id=3;
FILE *fp;
char Initial_File[100];
char *time_buff;
void Current_Time();
void Compose_FileName(char*);
void change_log_level();
//void Handle_Signal();
void print_log (char *File,int line_number,char *function_name,int level,char *fmt,...){
	if(current_log_level == DEBUG || current_log_level == level){
		va_list args,myargs;
		Current_Time();
		fprintf(fp,"[%s]  \t",Log[level]);
		fprintf(fp,"[TIME:%s]\t[MESSAGE]  ",time_buff);
		va_start(args, fmt);
		va_copy(myargs,args);
		vfprintf(fp,fmt,myargs);

		//      vprintf(fmt, args);
		va_end(args);
		//fprintf(fp,"\tFILE:%s\t,Line:%d\t,Function:%s\n",File,line_number,function_name);
		fprintf(fp,"\tFILE:%s\tFunction:%s\tLine:%d\n",File,function_name,line_number);
	}
	else {
		return ;

	}


}
void Initialize_Log(char *file_name){
	char filename[100];
	time_buff=(char*)malloc(100*sizeof(char));
	memset(time_buff,0,sizeof(100*sizeof(char)));
	//current_log_level = level;
	if(file_name!=NULL){
		if(file_name==NULL){
			fprintf(stderr,"Please Provide file name You selected FILE mode\n");
			exit(0);

		}
		strncpy(Initial_File,file_name,strlen(file_name));
		Compose_FileName(filename);
		fp=NULL;
		fp=fopen(filename,"w");
		if(fp==NULL){
			fprintf(stderr,"Failed to open file :%s\n",filename);
			free(time_buff);
			exit(0);

		}

	}
	else 
	{

		fp=stderr;
	}
	/*if(level >= 0){
		fprintf(stderr,"Provided level is :%d\n",level);

	}
	else {
	//	PRINT_LOG(WARNING,"Level provided is Not on limits continuing with Default [  DEBUG ] Level\n");

	}*/
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
void change_log_level(){
	if(current_log_level == DEBUG)
	{
		current_log_level = ERROR;
		return ;

	}
	current_log_level++;

}
void Handle_LogChange(){
	struct sigaction act;
//	sigset_t sigmask;
	memset(&act,0,sizeof(act));
	/*sigemptyset(&sigmask);
	  sigaddset(&sigmask,SIGUSR1);
	  act.sa_handler=change_log_level;
	  act.sa_mask=sigmask;*/
	act.sa_handler=change_log_level;
	if(sigaction(SIGUSR1,&act,NULL) < 0) { 
		perror("Sigaction failed ");
		exit(0);

	}
}
