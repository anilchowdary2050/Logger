#include <stdio.h>
#include "log.h"
int main(int argc,char *argv[]){
Initialize_Log(0,3,argv[1]);
PRINT_LOG(INFO,"Helloworld :%d",100);

return 0;
}
