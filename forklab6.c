#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask()
{
	char name [40];

	printf("Please enter your name:");
	fgets(name,40, stdin);
	printf("Your name is %s", name);
	exit(0);
}

void parentTask()
{
	printf("Waiting for child process to finish......\n");
	printf("Job is done.\n");
}

int main(void)
{
	for(int i=0; i<4; i++)
	{
	  int pid=fork();

	  if(pid == 0)
	  {
		childTask();
		wait(NULL);
	  }
	  else
	  {
		wait(NULL);
	  }
	}
	parentTask();

	return 0;
}
