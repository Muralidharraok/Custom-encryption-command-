#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
      
	char message[10], ch;
	int i, key;
	int sfd=open(argv[3],O_RDONLY|O_EXCL,0);
	int dfd=open(argv[4],O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);
	key=atoi(argv[2]);
        if(argc != 5)
        {
          printf("Not enough arguements \n");
          exit(0);
        }
         
        if (strcmp( argv[1], "-e" ) == 0 )
        {
	
	while(read(sfd,message,sizeof(message))>0)
	{
	for(i = 0; message[i] != '\0'; ++i)
          {
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	    }
	 write(dfd,message,sizeof(message));
	}
	close(sfd);
	close(dfd);
	}
        else if (strcmp( argv[1], "-d" ) == 0 )
        { 
          while(read(sfd,message,sizeof(message))>0)
	  {
	
	  for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	  }
	   write(dfd,message,sizeof(message));
	 }
	close(sfd);
	close(dfd);
        }
        else 
        {
           printf("not valid");
	   close(sfd);
	   close(dfd);
        }
	return 0;
}
