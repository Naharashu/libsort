#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

namespace libsort {

template<typename T>
void BubbleSort(T array[], uint64_t n);

template<typename T>
void InsertionSort(T array[], uint64_t n);

template<typename T>
void SelectionSort(T array[], uint64_t n);

template<typename T>
int64_t partition_quicksort(T array[], int64_t low, int64_t high);

template<typename T>
void QuickSort(T array[], int64_t low, int64_t high);

template<typename T>
void ShellSort(T array[], uint64_t n);

template<typename T>
void CountingSort(T array[], uint64_t n);

template<typename T>
void HeapSort(T array[], uint64_t n);

template<typename T>
void Heapify(T array[], uint64_t heap_size, uint64_t rootIndex);

template<typename T>
void IntroSort(T array[], uint64_t n);


template<typename T>
void Helper(T array[], uint64_t s, uint64_t n, uint32_t depth);

template<typename T>
void DualSort(T array[], uint64_t n);
}
#include "libsort.tpp" 
