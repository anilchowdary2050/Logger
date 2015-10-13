This is a simple Logger which  print messages in to 4 different categories() to a file

ERROR
WARNING
DEBUG
INFO

In this code I took Circular linked list as a base code  and added this logging API's to it

Featurs

1.)Print Log times
2.)Print the name of the function from whome th elog call is made
3.)Print the line number of the code from where the call is made
4.)Print the File name from which the call is made

Added a system call to kernel that filter The File log messages of Desired  level to Terminal

By default the Log level is WARNING,if you set the Log level as DEBUG it print all Level  messages ,otherwise only the set Level messages are printed 
The programmer has the flexibility to print the messages either to terminal or to a file,by default it print Log messages to terminal 

