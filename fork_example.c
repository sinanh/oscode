
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Silberschatz kitabındaki fork örneği

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Oluşturulamadı");
    }
    else if (pid == 0)
    { /* çocuk process */
        execlp("/bin/ls", "ls", NULL);
        printf("burası asla yazmaz");
    }
    else
    {
        wait(NULL);
        printf("Çocuk process bitti\n");
    }
}