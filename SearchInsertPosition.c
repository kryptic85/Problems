#include "int.h"

int searchInsert(int* nums, int numsSize, int target)
{
    int i, fIdx = 0;

    if (nums[numsSize - 1] < target)
    {
        return numsSize;
    }

    for (i = 0; i < numsSize; i ++)
    {
        if (nums[i] >= target)
        {
            fIdx = i;
            break;
        }
    }

    return fIdx;
}
