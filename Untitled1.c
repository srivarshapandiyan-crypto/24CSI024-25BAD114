#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], ans[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int left = 0, right = n - 1, pos = n - 1;

    while(left <= right) {
        if(abs(arr[left]) > abs(arr[right])) {
            ans[pos] = arr[left] * arr[left];
            left++;
        } else {
            ans[pos] = arr[right] * arr[right];
            right--;
        }
        pos--;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}

