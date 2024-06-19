#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // Fork a child process
    if (fork() == 0)
    {
        // Child process
        if (fork() == 0)
        {
            // Grandchild process
            while (1)
            {
                // Grandchild process prints "mary!" with its PID
                printf("%-5d: mary!\n", getpid());
                sleep(1);
            }
        }
        else
        {
            // Child process (parent of the grandchild)
            while (1)
            {
                // Child process prints a separator line
                printf("----------------\n");
                sleep(1);
            }
        }
    }
    else
    {
        // Parent process
        while (1)
        {
            // Parent process prints "George" with its PID
            printf("%-5d: George\n", getpid());
            sleep(1);
        }
    }

    return 0;
}
