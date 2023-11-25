#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    // Test
    int nums1_1[] = {1, 2, 3, 0, 0, 0};
    int m_1 = 3;
    int nums2_1[] = {2, 5, 6};
    int n_1 = 3;
    merge(nums1_1, m_1, nums2_1, n_1);

    // Output
    printf("[");
    for (int i = 0; i < m_1 + n_1; i++) {
        printf("%d", nums1_1[i]);
        if (i < m_1 + n_1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}