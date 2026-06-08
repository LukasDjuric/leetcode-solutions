/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {

    int* ptrG = calloc(numsSize, sizeof(int));
    int* ptrL = calloc(numsSize, sizeof(int));
    int* ptr = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int countG = 0, countL = 0, i, countE = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == pivot){
            countE++;
        }else if(nums[i] > pivot){
            ptrG[countG] = nums[i];
            countG++;
        }else{
            ptrL[countL] = nums[i];
            countL++;
        }
    }
    for(i = 0; i < countL; i++){
        ptr[i] = ptrL[i];
    }
    for(i = 0; i < countE; i++){
        ptr[i + countL] = pivot;
    }
    for(i = 0; i < countG; i++){
        ptr[i + countL + countE] = ptrG[i];
    }

    free(ptrL);
    free(ptrG);

    return ptr;

}
