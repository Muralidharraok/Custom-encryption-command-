#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
      
	char message[100], ch;
	int i, key;
        if(argc != 2)
        {
          printf("IN valid arguements \n");
          exit(0);
        }
         
        if (strcmp( argv[1], "-e" ) == 0 )
        {
	printf("Enter a message to encrypt: ");
        gets(message);
	printf("Enter key: ");
	scanf("%d", &key);
	
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
	
	printf("Encrypted message: %s", message);
	}
        else if (strcmp( argv[1], "-d" ) == 0 )
        { 
          printf("Enter a message to decrypt: ");
	  gets(message);
	  printf("Enter key: ");
	  scanf("%d", &key);
	
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
	
	  printf("Decrypted message: %s", message);
        }
        else 
        {
           printf("not valid");
        }
	return 0;
}
