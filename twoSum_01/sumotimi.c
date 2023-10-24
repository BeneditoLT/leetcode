#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int target, int numsLength, int* resulSize){
     int* result = (int*)malloc(2 * sizeof(int));

     for(int i = 0; i < numsLength; i++){
        for(int j = i+1; j < numsLength; j++){
             if((nums[i] + nums[j]) == target){
                result[0] = i;
                result[1] = j;
                *resulSize = 2;
                return result;
        

        }//if
        }//for j
       


     }//for   

    *resulSize = 0;  // Nenhum par encontrado
    free(result);    // Libere a memória alocada para "result"
    return NULL;


}//twoSum




int main(){
    int nums[] = {2,7,11,15};
    int target = 18;
    int resulSize = 0;
    int* result;

    int numsLength = sizeof(nums) / sizeof(nums[0]);
     
 
    result = twoSum(nums, target, numsLength, &resulSize);

    if(resulSize == 2){
        printf("Index %d and %d", result[0], result[1]);
        
    }//if
    else printf("Não encontrado");
return 0;
}//main