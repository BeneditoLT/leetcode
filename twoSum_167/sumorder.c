#include <stdio.h>
#include <stdlib.h>

int* tsum(int* nums, int target, int numsLength, int* returSize) {
    int* indices = (int*)malloc(2 * sizeof(int));
    int left = 0;
    int right = numsLength - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (target == sum) {
            indices[0] = left +1;
            indices[1] = right +1;
            *returSize = 2;
            return indices;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returSize = 0;
    free(indices);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int *result;
    int returSize;
    int numsLength;

    numsLength = sizeof(nums) / sizeof(nums[0]);

    result = tsum(nums, target, numsLength, &returSize);

    if (returSize == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
    } else {
        printf("Nenhum par encontrado.\n");
    }

    free(result);

    return 0;
}
