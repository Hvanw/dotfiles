#include <stdio.h>

// Hàm hoán đổi hai phần tử
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Hàm phân hoạch (partition)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1);     // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Thuật toán Quick Sort không đệ quy
void quickSortIterative(int arr[], int low, int high) {
    // Tạo một stack tạm thời
    int stack[high - low + 1];
    
    // Khởi tạo top của stack
    int top = -1;
    
    // Đẩy các giá trị ban đầu vào stack
    stack[++top] = low;
    stack[++top] = high;
    
    // Lặp lại cho đến khi stack rỗng
    while (top >= 0) {
        // Lấy high và low từ stack
        high = stack[top--];
        low = stack[top--];
        
        // Đặt pivot tại đúng vị trí của nó
        int p = partition(arr, low, high);
        
        // Nếu có các phần tử ở bên trái pivot, đẩy vào stack
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        
        // Nếu có các phần tử ở bên phải pivot, đẩy vào stack
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm main để kiểm tra
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: \n");
    printArray(arr, n);
    
    quickSortIterative(arr, 0, n - 1);
    
    printf("Mang sau khi sap xep: \n");
    printArray(arr, n);
    
    return 0;
}
