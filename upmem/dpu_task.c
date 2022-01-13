#include <stdio.h>
#include <mram.h>
#include <stdint.h>

__host uint64_t table_no;
__host uint64_t placeholder;

int main() {
    printf("STARTING DPU\n");

    uint64_t thread_no = table_no;
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum = 0;
        for (int j = 0; j < 10000000; j++) {
            sum += j;
        }
        if (i % 10 == 0) printf("DPU exec stage @ %lu ... %d\n", thread_no, i / 10 + 1);
    }
    
    printf("DPU DONE\n");
    return 0;
}
