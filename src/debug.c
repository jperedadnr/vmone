#include <stdio.h>
#include <sys/mman.h>
void* mymmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    fprintf(stderr, "MyMap, addr = %p, length = %ld, prot = %d, flags = %d, fd = %d, offset = %ld\n", addr, length, prot, flags, fd, offset);
    void* answer = mmap(addr, length, prot, flags, fd, offset);
    fprintf(stderr, "[JVDBG] MYMMAP answer = %p\n", answer);
    if (answer == MAP_FAILED) {
        fprintf(stderr, "Failed!\n");
        perror("mmap");
        fprintf(stderr, "try again\n");
        // void* answer = mmap(NULL, length, prot, flags, fd, offset);
        // answer = mmap(addr, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 
        // answer = mmap(addr, length, prot, flags, -1, 0); 
        answer = mmap(addr, length, prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 

        fprintf(stderr, "[JVDBG] MYMMAP answer2 = %p\n", answer);
    }
    return answer; 
}
void* myprint(void *addr) {
    fprintf(stderr, "PRINT: %p\n", addr);
}
void* myprinti(int val) {
    fprintf(stderr, "PRINT intval: %d\n", val);
}
