#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

heap_t *createHeap()
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));

    if (NULL == heap)
    {
        return NULL;
    }
    // Array deshalb speicher resavieren
    size_t data_size = DEFAULT_CAPACITY * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data) // wenn keine data
    {
        free(heap);

        return NULL;
    }
    // hat geklappt
    heap->capacity = DEFAULT_CAPACITY;
    heap->size = 0u;
    heap->data = data;

    return heap;
}

heap_t *freeHeap(heap_t *heap)
{
    if (NULL != heap->data)
    {
        free(heap->data);
    }

    if (NULL != heap)
    {
        free(heap);
    }

    return NULL;
}

uint32_t parentNode(uint32_t idx)
{
    return (idx - 1u) / 2u;
}

uint32_t leftChildNode(uint32_t idx)
{
    return (idx * 2u) + 1u;
}

uint32_t rightChildNode(uint32_t idx)
{
    return (idx * 2u) + 2u;
}

void swap(value_type_t *a, value_type_t *b)
{
    value_type_t temp = *a;
    *a = *b;
    *b = temp;
}

void insertValue(heap_t *heap, value_type_t value)
{
    if (NULL == heap) // checken ob gueltig
    {
        return;
    }

    if (heap->size == heap->capacity) // darf nicht bigger sein
    {
        return;
    }

    heap->size++;
    uint32_t idx = heap->size - 1u;
    heap->data[idx] = value; // fuegen erstmal am naechsten freien feld wert ein

    // es kann sein dass root nicht mehr kliener ist also neu strukturieren
    while (0u != idx && heap->data[parentNode(idx)] > heap->data[idx]) // solange elternknoten > als neue knoten
    {
        swap(&heap->data[idx], &heap->data[parentNode(idx)]);
        idx = parentNode(idx);
    }
}

value_type_t removeMinimum(heap_t *heap)
{
    if (NULL == heap)
    {
        return NO_VALUE;
    }
    // wenn es nur 1 einement gibt ist es das minimum
    if (heap->size == 1u) 
    {
        heap->size--;

        return heap->data[0];
    }

    // wenn das minumum weg ist muss man den baum auch neu strukturieren
    uint32_t root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// wird geguckt ob eins der beiden kinder kleiner ist wenn ja dann tasuchen
// ruft dann rekusiv auf falls kinderbaum faslch ist
void heapify(heap_t *heap, uint32_t idx)
{
    if (NULL == heap)
    {
        return;
    }

    uint32_t left_idx = leftChildNode(idx);
    uint32_t right_idx = rightChildNode(idx);
    uint32_t smallest = idx;

    // checkt zuerst ob inbounds && links kleiner smallest
    if (left_idx < heap->size && heap->data[left_idx] < heap->data[smallest])
    {
        smallest = left_idx;
    }

    if (right_idx < heap->size && heap->data[right_idx] < heap->data[smallest])
    {
        smallest = right_idx;
    }

    // tauschen wenn nicht gleich und weider neu strukturieren
    if (smallest != idx)
    {
        swap(&heap->data[idx], &heap->data[smallest]);
        heapify(heap, smallest);
    }
}

void printHeap(heap_t *heap)
{
    if (NULL == heap)
    {
        return;
    }

    uint32_t num_visited_nodes = 0u;
    uint32_t depth = (u_int32_t)floor(log2(heap->size)) + 1u;

    for (uint32_t i = 0u; i < depth; i++) // in ebene i hat man 2^i nodes
    {
        uint32_t num_layer_nodes = (uint32_t)pow(2.0, i);

        printf("Layer: %u\n", i);

        for (uint32_t j = 0u; j < num_layer_nodes; j++)
        {
            uint32_t current_idx = num_visited_nodes + j;

            if (current_idx < heap->size)
            {
                printf("Node: %u, Value: %f\n", j, heap->data[current_idx]);
            }
            else
            {
                break;
            }

            num_visited_nodes += num_layer_nodes;
        }
    }
}
