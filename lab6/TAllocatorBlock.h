#ifndef TALLOCATORBLOCK_H
#define TALLOCATORBLOCK_H

#include "TVector.h"
#include <memory>

class TAllocatorBlock {
    public:
        TAllocatorBlock(const size_t& size, const size_t count){
            this->size = size;
            for(int i = 0; i < count; ++i){
                unused_blocks.push_back(malloc(size));
            }
        }
        void* Allocate(const size_t& size){
            if(size != this->size){
                std::cout << "Error during allocation\n";
            }
            if(unused_blocks.size()){
                for(int i = 0; i < 5; ++i){
                    unused_blocks.push_back(malloc(size));
                }
            }
            void* tmp = unused_blocks.Get_first()->Get_data();
            used_blocks.push_back(unused_blocks.Get_first()->Get_data());
            unused_blocks.erase(0);
            return tmp;
        }
        void Deallocate(void* ptr){
            unused_blocks.push_back(ptr);
        }
    ~TAllocatorBlock(){
        while(used_blocks.size()){
            try{
                free(used_blocks.Get_first()->Get_data());
                used_blocks.erase(0);
            } catch(...){
                used_blocks.erase(0);
            }
        }
        while(unused_blocks.size()){
            try{
                free(unused_blocks.Get_first()->Get_data());
                unused_blocks.erase(0);
            } catch(...){
                unused_blocks.erase(0);
            }
        }
    }

    private:
        size_t size;
        Vector<void*> used_blocks;
        Vector<void*> unused_blocks;
};

#endif