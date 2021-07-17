#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

int main() {
long setUser = syscall(448, -1, 2);
long getUser = syscall(447, -1);
    printf("Atribuindo um peso: %ld\n", setUser);
    printf("Devolvendo esse peso: %ld\n", getUser);
}
