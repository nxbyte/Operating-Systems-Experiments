/*
 Developer : Warren Seto
 Lab       : 8
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Macros */
#define OFFSET_MASK 0xfff
#define PAGE_SHIFT 12


/* Data structure to hold address properties */
typedef struct
{
    uint32_t addr;
    uint32_t pageNum;
    uint32_t offset;
} RAM_attr;


/* Function prototype */
RAM_attr convertVirtualAddr(uint32_t input);


int main(int argc, const char * argv[])
{
    /* Check if a value is inputted to prevent segmentation fault */
    if (argc < 2)
    {
        printf("Please enter a numeric value.\n");
        return 0;
    }
    
    
    /* Creates a RAM_attr instance to hold RAM properties */
    RAM_attr addrData = convertVirtualAddr(atoi(argv[1]));

    
    /* Outputs the address and its properties to the console */
    printf("The address %u contains: \n", addrData.addr);
    printf("page number = %u\n", addrData.pageNum);
    printf("offset = %u\n", addrData.offset);
    
    return 0;
}


/* Performs shifting and masking to find the page nuber and offset */
RAM_attr convertVirtualAddr(uint32_t input)
{
    return (RAM_attr){ .addr = input, .pageNum = input >> PAGE_SHIFT, .offset = input & OFFSET_MASK };
}
