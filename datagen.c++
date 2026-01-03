#include <iostream>
#include <math.h>
#include <thread>
#include <random>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>


#define MAX 20000000


int main(){
   const char* filepath ="data.bin";
    size_t fileSize = MAX *sizeof(float);
   
    int fd = open(filepath, O_RDWR | O_CREAT,0666);
    if (fd < 0) return 1;

    if(ftruncate(fd,fileSize)==-1){
        close(fd);
        return 1;
    }

   void* mappedData = mmap(NULL,fileSize,PROT_READ |PROT_WRITE,MAP_SHARED,fd,0); 
   if(mappedData ==MAP_FAILED){
    close(fd);
    return 1;
   } 

    float* data_ptr =static_cast<float*>(mappedData);

    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_real_distribution<> distribution(-1.0,1.0);
    

    for(size_t i = 0; i < MAX; ++i) {
        data_ptr[i] = distribution(rng); 
    }
   
    std::cout<<"data pushed to disk successfully"<<std::endl;
    msync(mappedData, fileSize, MS_SYNC); 
    munmap(mappedData, fileSize);
    close(fd);

    return 0;

    

        

}
