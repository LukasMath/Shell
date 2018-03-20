#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>

int menu(){
int opcao = 0;
printf("\nDeseja executar um comando? \n1 - sim\n2 - nao \n");
scanf("%d",&opcao);
return opcao;
};

int main(void){

int opcao;
int value;
pid_t pid;
pid = fork();
uid_t uid;
struct passwd *pwd;
char *endptr;

if(pid == 0){

printf("pid do filho %d",getpid()); 
opcao = menu();

	while(opcao != 2){ // chama a função para execução do comando
		if(opcao == 1){
		printf("\nDigite o comando que deseja executar: 1- ls , 2 - mkdir, 3 - rm, 4 - chmod, 5 - cd, 6 - exit \n");
    scanf("%d", &value);
	 switch(value){
	   case 1:
	   system("ls");
	   break;
	   
	   case 2:
	    mkdir("testes", S_IRUSR | S_IWUSR | S_IXUSR);
      system("ls");
       break;
         case 3:
	    system("ls -al testes"); 
        rmdir("./testes"); 
        system("ls");
        break;
         case 4:
	    system("ls -al testes"); 
        rmdir("./testes"); 
        system("ls");
         break;
         case 5:
	     if (chdir("/boot") == -1)
            {
                  printf("Erro chdir(/etc) %d: %s\n", errno, strerror(errno));
                  return 1;
                }
              system("pwd");

              if (chdir("grub") == -1)
                {
                  printf("Erro chdir(grub) %d: %s\n", errno, strerror(errno));
                  return 1;
                }
              system("pwd");

              if (chdir(getenv("HOME")) == -1)
                {
                  printf("Erro chdir(HOME) %d: %s\n", errno, strerror(errno));
                  return 1;
                }
              system("pwd");
            break;
         
         case 6:
           exit(0);
               
    default:
    printf("valor invalido");
    break;

	 }
		opcao = menu();
		}
		else{
		printf("Opcao invalida");
		opcao = menu();
		}
	}
}
else if(pid<0){
	printf("Erro");
	exit(1);
}
else{
	printf("pid do Pai: %d\n", getpid());
	int status;
	(void)waitpid(pid, &status, 0);
}

return 0;

}
