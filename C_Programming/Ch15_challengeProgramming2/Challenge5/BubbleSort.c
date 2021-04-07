#include<stdio.h>

void DesSort(int arr[], int len);
void Bubble_Sort_Big(int arr[], int len);
void Bubble_Sort_Printf(int arr[], int len);

int main()
{
    int arr[7];

    printf("*** Enter numbers ***\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d. input : ", i + 1);
        scanf_s("%d", &arr[i], sizeof(arr));
    }

    DesSort(arr, sizeof(arr) / sizeof(int)); // Descending order
    // Bubble_Sort_Big(arr, sizeof(arr)/sizeof(int)); // ascending order
    Bubble_Sort_Printf(arr, sizeof(arr) / sizeof(int));

    return 0;
}

void DesSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < (len - i) - 1; j++)
        {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Bubble_Sort_Big(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < (len - i) - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Bubble_Sort_Printf(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}