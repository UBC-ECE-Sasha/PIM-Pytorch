#include <stdio.h>
#include <mram.h>
#include <stdint.h>

__host uint64_t table_no;
__host uint64_t placeholder;

int main() {
    printf("STARTING DPU\n");

    uint64_t thread_no = table_no;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = 0;
        for (int j = 0; j < 1000000; j++) {
            sum += j;
        }
        printf("DPU exec stage @ %lu ... %d\n", thread_no, i + 1);
    }
    
    printf("DPU DONE\n");
    return 0;
}