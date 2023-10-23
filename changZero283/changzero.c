
#include <stdio.h>

int changzero( int nums[], int length){
    int lastzero = 0;

    for( int i =0; i < length; i++){
         if(nums[i] != 0) {
            int aux = nums[lastzero];
            nums[lastzero] = nums[i];
            nums[i] = aux;
            lastzero++;
         }


    }
    
}



int main(){
    int nums[] = {1,1,0,2,3,12};
    int length = sizeof(nums) / sizeof(nums[0]);

    int result = changzero(nums, length);
    
     for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}