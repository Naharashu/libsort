#include "libsort.h"

namespace libsort {

// BubbleSort

template<typename T>
void BubbleSort(T array[], uint64_t n) {
        bool swapped = true;
        while(swapped) {
                swapped = false;
                for(uint64_t i=1;i<n;i++) {
                        if(array[i-1]>array[i]) {
                                std::swap(array[i-1], array[i]);
                                swapped = true;
                        }
                }
        }
}

// Insertion sort

template<typename T>
void InsertionSort(T array[],uint64_t n) {
        int64_t j = 0;
        for(uint64_t i=1;i<n;i++) {
                T El = array[i];
                j = i-1;
                while(j>=0&&array[j]>El) {
                        array[j+1] = array[j];
                        j = j-1;
                }
                array[j+1] = El;
        }
}

// Selection sort

template<typename T>
void SelectionSort(T array[], uint64_t n) {
        uint64_t min = 0;
        for(uint64_t i=0;i<n-1;i++) {
                min = i;
                for(uint64_t j=i+1;j<n;j++) {
                        if(array[j]<array[min]) min=j;
                }
                std::swap(array[i], array[min]);
        }
}

// QuickSort
template<typename T>
int64_t partition_quicksort(T array[],int64_t low,int64_t high) {
        T pivot = array[high];
        int64_t i = low-1;
        for(int64_t j=low;j<high;j++) {
                if(array[j] <= pivot) {
                        i = i+1;
                        std::swap(array[i], array[j]);
                }
        }
        std::swap(array[i+1], array[high]);
        return i+1;
}

template<typename T>
void QuickSort(T array[], int64_t low, int64_t high) {
        if(low<high) {
                int64_t index = partition_quicksort<T>(array, low, high);
                QuickSort(array, low, index-1);
                QuickSort(array, index+1, high);
        }
}



// ShellSort

template<typename T>
void ShellSort(T array[], uint64_t n) {
        uint64_t gap = n/2;
        T temp;
        uint64_t j = 0;
        while(gap>0) {
                for(uint64_t i=gap;i<n;i++) {
                        temp = array[i];
                        j = i;
                        while(j>=gap&&array[j-gap]>temp) {
                                array[j] = array[j-gap];
                                j-=gap;
                        }
                        array[j] = temp;
                }
                gap /= 2;
        }
}

// CountingSort

template<typename T>
void CountingSort(T array[], uint64_t n) {
        T min = array[0];
        T max = array[0];
        for(uint64_t i=0;i<n;i++) {
                if(min>array[i]) min = array[i];
                if(array[i]>max) max = array[i];
        }

        int64_t range = (int64_t)max - (int64_t)min + 1;
        if (range <= 0 || range > 10000000) {
                std::cerr << "Range too large: " << range << std::endl;
                return;
        }
        std::vector<uint64_t> count(range, 0);

        for(uint64_t i=0;i<n;i++) {
                count[array[i] - min]++;
        }
        uint64_t index = 0;
        for(uint64_t i=0;i<range;i++) {
                while(count[i]>0) {
                        array[index] = i+min;
                        count[i]--;
                        index++;
                }
        }
}

// Cocktail shaker sort

template<typename T>
void CocktailShakerSort(T array[], uint64_t n) {
        bool swapped = true;
        while(swapped) {
                swapped = false;
                for(uint64_t i=0;i<n-2;i++) {
                        if(array[i]>array[i+1]) {
                                swapped = true;
                                std::swap(array[i], array[i+1]);
                        }
                }
                if(!swapped) break;
                for(uint64_t i=n-2;i>0;i--) {
                        if(array[i]>array[i+1]) {
                                swapped = true;
                                std::swap(array[i], array[i+1]);
                        }
                }
        }
        return;
}

// Heap sort

template<typename T>
void HeapSort(T array[], uint64_t n) {
	for(int64_t i=floor(n/2)-1;i>=0;i--) {
		Heapify<T>(array,n,i);
	}

	for(uint64_t i=n-1;i>0;i--) {
		std::swap(array[0], array[i]);
		Heapify<T>(array,i,0);
	}
}

template<typename T>
void Heapify(T array[], uint64_t heap_size, uint64_t rootIndex) {
	uint64_t larg = rootIndex;
	uint64_t left = 2*rootIndex+1;
	uint64_t right = 2*rootIndex+2; // left+1
	

	if(left<heap_size&&array[left]>array[larg]) larg = left;
	if(right<heap_size&&array[right]>array[larg]) larg = right;
	
	if(larg != rootIndex) {
		std::swap(array[rootIndex], array[larg]);
		Heapify<T>(array, heap_size, larg);
	}
}

// IntroSort

template<typename T>
void IntroSort(T array[], uint64_t n) {
	uint32_t max = floor(log2(n))*2;
	Helper<T>(array,0, n-1, max);
}

template<typename T>
void Helper(T array[],uint64_t s, uint64_t n, uint32_t depth) {
	uint64_t a = n-s+1;
	if(a<16) {
		InsertionSort<T>(array+s, a);
		return;
	}

	if(depth==0) {
		HeapSort<T>(array+s, a);
		return;
	}
	uint64_t indx = partition_quicksort<T>(array, s, n);
	
	Helper<T>(array, s, indx-1, depth-1);
	Helper<T>(array, indx+1,n,depth-1);
}

// DualSort

template<typename T>
void DualSort(T array[], uint64_t n) {
	bool swapped = true;
	while(swapped) {
		swapped = false;
		for(int64_t i=n-1;i>=2;i--) {
			uint64_t gap = i/2+1;
			T temp = array[i];
			if(temp<array[i-1]){
				std::swap(array[i], array[i-1]);
				swapped = true;
			}
			else if(temp<array[gap]) {
				std::swap(array[i], array[gap]);
				swapped = true;
			}
		}
		if(!(swapped)) break;
		for(uint64_t i=0;i<n-2;i++) {
			const uint64_t temp = array[i];
			if(temp>array[i+1]){
				std::swap(array[i], array[i+2]);
				swapped = true;
			}
			else if(temp>array[i+2]){
				std::swap(array[i], array[i+2]);
				swapped = true;
			}
		}
	}
}

}
