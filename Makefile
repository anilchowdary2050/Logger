CC	= gcc
CFLAGS	=-Wall
EXE_OUT	=liblogger
FILES	=log.c
HEADER_FILES	=log.h
Build:
	$(CC) -c $(FILES) $(CFLAGS) -fPIC -o $(EXE_OUT).o
	$(CC) -shared -o $(EXE_OUT).so $(EXE_OUT).o
	cp $(EXE_OUT).so /usr/local/lib/	
	cp $(EXE_OUT).so /usr/lib/
	cp $(HEADER_FILES) /usr/local/include/
clean:
	rm -rm $(EXE_OUT).so
	rm -rm $(EXE_OUT).o		
