/* 加一题作业提交； date:2021-10-05；v1.0 */
/**
 *  
 * Note: The returned array must be malloced, assume caller calls free().
 *  
 **/
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i=0, carray=0, j=0;
    if ( NULL == digits || NULL == returnSize || 0 >= digitsSize)  return NULL;
    
    int* ret = (int* )malloc((sizeof(int) * digitsSize));
    *returnSize = digitsSize;
    

    for (i=digitsSize-1; i>=0; i--) {
        if (i == digitsSize-1) {
            ret[i] = (digits[i] + 1 + carray) % 10;
            carray = (digits[i] + 1) / 10;
        } else {
            ret[i] = (digits[i] + carray) % 10;
            carray = (digits[i] + carray) / 10;
        }
    }
     
    /* if num has carry :relloac  */
    if (carray) {
        int* tmp = (int* )malloc(sizeof(int) * (digitsSize + 1));
        for (i=1; i<digitsSize+1; i++) {
            tmp[i] = ret[i-1];
        }
        free(ret);
        ret = tmp;
        
        *returnSize = digitsSize + 1;
        ret[0] = carray;
    }

    return ret;
}
