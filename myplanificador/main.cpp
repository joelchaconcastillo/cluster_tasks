//#include <bits/stdc++.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
using namespace std;
void runplaner1()
{
   int totalMachines = 2;
   int totalTasks = 10;
   int stat;
   pid_t ppid;

     bool flagParent =true; //Flag to identify between a parent and a child
	 for( int i = 0; i < totalMachines && i < totalTasks; i++)
	{
		totalTasks--;
		   if ((ppid = fork()) == 0) 
		   {
			flagParent=false;
			printf("child %d working\n", totalTasks);
			sleep(2);
			break;
		   }
	}	
      while(totalTasks>0 && flagParent)
	{ 
	    wait(NULL);
	    totalTasks--;
	    if ((ppid = fork()) == 0) 
	    {
		flagParent=false;
	        printf("child %d working\n", totalTasks);
		sleep(2);
	     }
        }
	
	if(flagParent)
	{

	  for(int i = 0; i < totalMachines ;i++) //wait until all the childe process ended
		  wait(NULL);
	  printf("Principal %d ending \n", getpid());
	}
	
}
void runplaner2()
{
   int availableMachines = 2;
   int totalMachines = 2;
   int totalTasks = 10;
   int stat;
   pid_t ppid;

	 for( int i = 0; i < totalMachines; i++)
	{
		availableMachines--;
		totalTasks--;
		   if ((ppid = fork()) == 0) 
		   {
			printf("child %d working\n", availableMachines);
			sleep(random()%3);
			exit(0);
		   }
	}	
      while(totalTasks>0)
	{ 
	    wait(NULL);
	    if ((ppid = fork()) == 0) 
	    {
	        printf("child %d working\n", availableMachines);
		sleep(4);
		exit(0);
	     }
	   totalTasks--;
        }
	  for(int i = 0; i < totalMachines ;i++) //wait until all the childre process ended
	    wait(NULL);
	  printf("Principal %d ending \n", getpid());
}

int main(int argc, char *argv[])
{

   //Loading Taskfile..

   //Loading Machinefile..

   //Executing taks...
   runplaner1();	
//   runplaner2();	

	
   return 0;
}
