#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <climits>

// 快排辅助函数
int partition(int arr[], int begin, int end)
{
	// pivot 标杆位置，counter：小于pivot的元素个数
	int pivot = end, counter = begin;
	for(int i = begin; i < end; i++)
	{
		if(arr[i] < arr[pivot])
		{
			std::swap(arr[i], arr[counter]);
			counter++;
		}
	}
	std::swap(arr[pivot], arr[counter]);
	
	return counter;
}

// 快速排序
void quickSort(int arr[], int begin, int end)
{
	if(end <= begin) return;
	int pivot = partition(arr, begin, end);
	quickSort(arr, begin, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

//归并排序辅助函数
void merge(int arr[], int left, int mid, int right)
{
    int temp[right - left + 1] = {0};
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right)
    {
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= right)
    {
        temp[k++] = arr[j++];
    }

    for(int p = 0; p < right - left + 1; p++)
    {
        arr[left + p] = temp[p];
    }
}
// 归并排序
void mergeSort(int arr[], int left, int right)
{
	if(right <= left) return;
	int mid = (left + right) >> 1;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

// 堆排序
void heapSort(int arr[], int length)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	for(int i = 0; i < length; i++)
	{
		q.push(arr[i]);
	}

	for(int j = 0; j < length; j++)
	{
		arr[j] = q.top();
		q.pop();
	}
}

// 计数排序
void countSort(int arr[], int length, int maxValue)
{
	int bucket[maxValue + 1] = {0};
	int sortIndex = 0;
	int bucketLen = maxValue + 1;

	for(int i = 0; i < length; i++)
	{
		if(!bucket[arr[i]])
		{
			bucket[arr[i]] = 0;
		}
		bucket[arr[i]]++;
	}

	for(int j = 0; j < bucketLen; j++)
	{
		while(bucket[j] > 0)
		{
			arr[sortIndex++] = j;
			bucket[j]--;
		}
	}
}

// 桶排序
void bucketSort(std::vector<int>& arr)
{
	int MAX = INT_MIN;
	int MIN = INT_MAX;

	for(int i = 0; i < arr.size(); i++)
	{
		MAX = std::max(MAX, arr[i]);
		MIN = std::min(MIN, arr[i]);
	}

	int bucketNum = (MAX - MIN) / arr.size() + 1;
	std::vector<std::vector<int>> bucketArr(bucketNum);

	for(int j = 0; j < arr.size(); j++)
	{
		int num = (arr[j] - MIN) / arr.size();
		bucketArr[num].push_back(arr[j]);
	}

	int cnt = 0;
	for(int p = 0; p < bucketNum; p++)
	{
		std::sort(bucketArr[p].begin(), bucketArr[p].end());
		for(int q = 0; q < bucketArr[p].size(); q++)
		{
			arr[cnt++] = bucketArr[p][q];
		}
	}
}

// 基数排序
void radixSort(std::vector<int>& arr)
{
	int length = arr.size(), MAX = INT_MIN, count = 0, bucketNum = 10;
	
	if(length < 2)
	{
		return;
	}

	for(int elem:arr)
	{
		MAX = std::max(MAX, elem);
	}

	while(MAX > 0)
	{
		count++;
		MAX /= 10;
	}

	std::vector<std::vector<int>> buckets(bucketNum);// 0~9十个数，每数一桶
	int radix = 0;

	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < length; j++)
		{
			radix = static_cast<int>(arr[j]/std::pow(10, i - 1)) % 10;
			buckets[radix].push_back(arr[j]);
		}

		int k = 0;
		for(int p = 0; p < bucketNum; p++)
		{
			for(int elem:buckets[p])
			{
				arr[k++] = elem;
			}
			// 元素取完立即清空桶
			buckets[p].clear();
		}
	}
}

int main()
{
	int arr[] = {3,8,6,9,5,1,4,2,7,0};
	int len = (sizeof arr)/(sizeof arr[0]);
	
	// 快速排序测试
	// quickSort(arr, 0, len);

	// 归并排序测试
	// mergeSort(arr, 0, len);
	
	// 堆排序测试
	// heapSort(arr, len);

	// 计数排序测试
    // countSort(arr, len, 9);
	
	/*for(int elem:arr)
	{
		std::cout<< elem <<" "<<std::endl;
	}*/

	std::vector<int> vec(arr, arr+len);
	
	// 桶排序测试
	bucketSort(vec);

	// 基数排序
	radixSort(vec);
	for(auto elem:vec)
	{
		std::cout<< elem <<" "<<std::endl;
	}
}
