#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef float value_type_t;

void printArry(value_type_t arr[], uint32_t size)
{
    for (uint32_t i = 0u; i < size; i++)
    {
        if (i < size - 1u)
        {
            printf("%f, ", arr[i]);
        }
        else
        {
            printf("%f\n", arr[i]);
        }
    }
}

void merge(value_type_t arr[], uint32_t start, uint32_t mid, uint32_t end)
{
    uint32_t num1 = mid - start + 1u;
    uint32_t num2 = end - mid; // berechnung wie viele teilelemente beide teile habe die man mergen will

    value_type_t *arr1 = (value_type_t *)malloc(num1 * sizeof(value_type_t));
    value_type_t *arr2 = (value_type_t *)malloc(num2 * sizeof(value_type_t));

    for (uint32_t i = 0u; i < num1; i++)
    {
        arr1[i] = arr[start + i];
    }
    // beide Teil arrays
    for (uint32_t i = 0u; i < num2; i++)
    {
        arr2[i] = arr[mid + 1u + i];
    }

    uint32_t i = 0u;
    uint32_t j = 0u;
    uint32_t k = start;

    while (i < num1 && j < num2)
    {
        if (arr1[i] <= arr2[j]) // welcer ist kleiner
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[i];
            j++;
        }

        k++; // elemnte gesamt aberbietet
    }

    while (i < num1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    // wenn eine Liste abgeabrbietet kann man die andere dran kopieren
    while (j < num2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}

void divide(value_type_t arr[], uint32_t start, uint32_t end)
{
    if (start < end) // aufteilen
    {
        uint32_t mid = (start + end) / 2u;
        divide(arr, start, mid);
        divide(arr, mid + 1u, end);
        merge(arr, start, mid, end);
    }
}

void mergeSort(value_type_t arr[], uint32_t size)
{
    divide(arr, 0u, size - 1u);
}

int main(void)
{
    value_type_t data[] = {-10, 20, -20, 40, 12};

    printArry(data, 5u);
    mergeSort(data, 5u);
    printArry(data, 5u);
}
