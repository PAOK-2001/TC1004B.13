#include <unistd.h>
#include <ctype.h>
#include<stdio.h>
#include<signal.h>

void handle(int numsignal){
    printf("xD %d", numsignal);
}

int main(){
    signal(2, handle);
    while (1){
        printf("Trabajando\n");
        sleep(1);
    }
    
    return 0;
}