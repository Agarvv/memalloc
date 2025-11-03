#include <stdio.h>
#include <sys/mman.h>    
//#include <unistd.h>      
//#include <fcntl.h>       

void* kernmem(int size) {
      if(size > 0) {
          void* memory = mmap(
          NULL,                      
          size,                        
          PROT_READ | PROT_WRITE,   
          MAP_PRIVATE | MAP_ANONYMOUS, 
        -1,                        
        0                          
      );

      return memory;
    }
}

int main() {
    void* memory = kernmem(4096 * 4); // 16 kb
    printf("%p", memory);
    return 0;
}

