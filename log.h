#include <stdio.h>
void Initialize_Log (char*);
void Handle_LogChange();
#define PRINT_LOG(num,...) print_log(__FILE__,__LINE__,__func__,num,__VA_ARGS__);
typedef  enum  {
	ERROR = 0,
	WARNING,
	INFO ,
	DEBUG

}log_level;

typedef enum {
	FILE_MODE = 0,
	TERMINAL_MODE

}log_mode;

typedef int log_t;
static const char *Log[] = {"ERROR","WARNING","INFO","DEBUG"};
