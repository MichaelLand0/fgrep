#include <stdio.h>
#include <stdlib.h>
#include "include/main.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


//TODO:
// line num & file name if more than one

int is_in_str(char *str1, char * str2)
{
	int match=0;
	int temp=0;
	int j=0;
	for(int i=0; str1[i]!='\0'; i++)
	{
		if(str1[i] == str2[j])
		{	
			match =1;
			temp=i;
			while(str2[j]!='\0')
			{
				if(str1[temp]!=str2[j])
				{
					match =0;
					break;
				}
				temp +=1;
				j+=1;
			}
		if(match==1)
			return 1;
		j=0;
		}
	
	}
	return 0;
}

void read_file(int argc,char * file, char *keyword)
{
	unsigned int i=0;
	char singleLine[600];
	FILE *p=NULL;
	p=fopen(file,"r");
	while(fgets(singleLine,600,p)!=NULL)
		{
			i++;
			if(is_in_str(singleLine,keyword))
			{
				if(argc > 3)
					printf("File: %s: Line: %i: %s",file,i,singleLine);

				else		
					printf("Line: %i: %s",i,singleLine);
			}	
		}
fclose(p);
}

void read_stdin(char * keyword)
{
	char buffer[400];
	while(fgets(buffer,400,stdin) !=NULL)
	{
	if(is_in_str(buffer,keyword))
		printf("%s",buffer);
	}

}




void read_lines(int argc, char *argv[])
{

	for(int i=2; i<argc; i++)
		read_file(argc,argv[i],argv[1]);

	return;
}




int main(int argc, char *argv[])
{	
	if(argv[1]==NULL)
	{
		printf("Error: no pattern or word\n");
		exit(0);
	}
	else if (argv[2]==NULL)
	{
				read_stdin(argv[1]);
	}
	else
		{
			read_lines(argc,argv);
		}
return 0;
}



