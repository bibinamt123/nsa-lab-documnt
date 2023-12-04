#include <stdio.h> 

int main()
 {  
// Starting the main function.
    int a[50], b[50], merged[100], n1, n2, i;

    // Asking user to input the size and elements of the first array.
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements for the first array:\n", n1);
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    // Asking user to input the size and elements of the second array.
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements for the second array:\n", n2);
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Merging the two arrays.
    for(i = 0; i < n1; i++) {
        merged[i] = a[i];  // First array elements.
    }
    for(i = 0; i < n2; i++) {
        merged[n1+i] = b[i];  // Second array elements.
    }

    // Displaying the merged array.
    printf("Merged array is:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;  // Ending the program.
}
