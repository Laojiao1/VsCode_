#include <stdio.h>
int removeDuplicate(int *nums, int numsSize) {
    if(numsSize == 0) {
        return 0;
    }
    int fast = 1;
    int slow = 1;
    while(fast < numsSize) {
        if(nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            slow ++;
        }
        fast ++;
    }
    return slow;
}
int main() {
    int nums[1001];
    int i = 0;
    char ch;
    while(ch = getchar() != '\n') {
        scanf("%d", &nums[i]);
        i++;
    }
    int Size = i;
    int newsnumsSize = removeDuplicate(nums, Size);
    printf("%d\n", newsnumsSize);
    printf("[ ");
    for(i = 0; i < newsnumsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("]");
    return 0;
}