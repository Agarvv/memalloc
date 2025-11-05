#include <stdio.h>
#include <sys/mman.h>    
//#include <unistd.h>      
//#include <fcntl.h>       

struct mem_header {
  struct mem_header* next;
  int size;
  int free; // 1 for avaibable, either 0
};


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

void initmem(void* mem) {
  struct mem_header* header = (struct mem_header*)mem;  
  header->next = NULL;
  header->size = 4096 * 4;  
  header->free = 1;
  printf("Mem ready\n");  
}

// size in bytes
void* memalloc(void* size, void* heap) {
    struct mem_header* header = (struct mem_header*)heap;
    void* mem = (char*)heap + sizeof(struct mem_header);
   printf("mem adres: %p", mem);
}

int main() {
    void* memory = kernmem(4096 * 4); // 16 kb
    initmem(memory);
    memalloc(10, memory);
    
    return 0;
}

