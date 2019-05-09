#include <stdio.h>
#include <unistd.h>	

int main(){
	printf(" before fork\n");
	  int pid = fork();
	  
	  if (pid == 0){
	  	
		printf("i am child 1 after fork() \n");
	    char *args[]={"/bin/ps","-ef",NULL};
	    execvp("/bin/ps",args);
	    printf("finished ps -ef\n");

	     }
    else 
       {
    	int pid1 = fork();
	  		if(pid1==0){
	  			printf("i am child 2 after fork() \n");
	            char *args[]={"/usr/bin/free","-h",NULL};
	    		execvp("/usr/bin/free",args);
	    		printf("finished free -h\n");


	  		}
	  		else 
	  			printf("i am parent, child is %d\n",pid1 );
	  	}
    	
    	printf("i am parent, child is %d\n",pid );
	return 0;
		}
