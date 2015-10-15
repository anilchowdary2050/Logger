#include <stdio.h>
#include "log.h"
int main(int argc,char *argv[]){
	Initialize_Log(argv[1]);
	Handle_LogChange();
	PRINT_LOG(INFO,"Helloworld :%d",100);
	PRINT_LOG(WARNING,"Helloworld :%d",100);
	PRINT_LOG(ERROR,"Helloworld :%d",100);
	PRINT_LOG(WARNING,"Helloworld :%d",100);
	PRINT_LOG(WARNING,"Helloworld ");
	while(1){
		sleep(5);
		fprintf(stderr,"In sleep pid is :%d\n",getpid());
		PRINT_LOG(INFO,"Helloworld :%d",100);
		PRINT_LOG(WARNING,"Helloworld :%d",100);
		PRINT_LOG(ERROR,"Helloworld :%d",100);

	}
	return 0;
}
