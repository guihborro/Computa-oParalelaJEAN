#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid1;
    pid = fork () ;
    
    if ( pid < 0) { // Erro
        fprintf ( stderr , " Fork falhou !\n") ;
        return 1;
    }else if ( pid == 0) { // Processo Filho
        printf("Eu sou o primeiro filho! Meu PID e %d, meu pai e %d.\n", getpid(), getppid() ) ;

    }else{
        pid1 = fork();
        if (pid1 < 0){
            fprintf ( stderr , " Fork falhou !\n") ;
            return 1;
        }
        else if(pid1 == 0){
            printf("Sou o sgundo filho! PID = %d, meu pai = %d\n", getpid(), getppid());
        }
        else{
            printf("Sou o pai! PID = %d, criei dois filhos (%d e %d)\n", getpid(), pid, pid1);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            printf("Meus filhos demoraram pra caralho, mas terminaram");
        }
    }
    return 0;
}
