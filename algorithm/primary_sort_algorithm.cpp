#include <iostream>
#include <algorithm>

// 选择排序
// 外层每趟循环就位一个最小值，前半部分默认有序
void selectSort(int arr[], int length)
{
	// int length = (sizeof arr)/(sizeof arr[0]);
	int minIndex;

	for(int i = 0; i < length - 1; i++)
	{
		minIndex = i;
		// 循环边界取数据规模减一，因为外层遍历到倒数第二个时，此时的排序已经包含到了最后元素的排序，
		// 即倒数第二个跟最后一个进行排序，排序只对2个及以上的数据规模有意义，最后一趟只剩一个元素自身排序无意义
		for(int j = i + 1; j < length; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

// 插入排序
// 从前到后逐步构建有序序列；对于未排序数据，
// 在已排序序列中从后向前扫描，找到相应位置并插入
// 类似打扑克牌
void insertSort(int arr[], int length)
{
	int orderIndex; // 有序序列索引
	int current; // 从无需序列中遍历到的元素（即摸到的牌）

	for(int i = 1; i < length; i++)
	{
		orderIndex = i - 1;
		current = arr[i];
		// 若当前元素大于有序序列末尾元素则直接插入，否则移动插入	
		if(current < arr[orderIndex])
		{
			// 注意学习移动元素的写法，移动元素从序列最后面开始移
			// orderIndex >= 0 不能缺省，当当前元素比有序序列中所有元素都小时会发生数组非法访问arr[-1]
			while(current < arr[orderIndex] && orderIndex >= 0)
			{
				arr[orderIndex + 1] = arr[orderIndex];
				orderIndex--;
			}
			arr[orderIndex + 1] = current;
		}
	}
}

// 冒泡排序
// 注意边界条件必须为length-1，考虑最后只剩一个待排序元素的情况，内层循环计数为-1
// 外层每一趟循环就位最大元素，默认后半部分有序(和选择排序相反)
void bubbleSort(int arr[], int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - 1 - i; j++)
			if(arr[j] > arr[j+1])
			{
				std::swap(arr[j], arr[j+1]);
			}
	}
}

// 希尔排序
void shellSort(int arr[], int length)
{
	for(int gap = int(length >> 1); gap > 0; gap = int(gap >> 1))
	{
		// 间隔后面的元素，按照间隔往前进行插入排序
		// 以下代码参照插入排序进行理解
		for(int i = gap; i < length; i++)
		{
			int j = i;
			int current = arr[i];
			if(current < arr[j - gap])
			{
				while(current < arr[j - gap] && j - gap >= 0)
				{
					arr[j] = arr[j - gap];
					j = j - gap;
				}
				arr[j] = current;
			}
		}
	}
}



int main()
{
	int arr[] = {3,8,6,9,5,1,4,2,7,0};
	int len = (sizeof arr)/(sizeof arr[0]);
	
	// 选择排序测试
	// selectSort(selection_arr, len);
	
	// 插入排序测试
	// insertSort(arr, len);
	
	// 冒泡排序测试
	// bubbleSort(arr, len);
	
	//希尔排序测试
	shellSort(arr, len);

	for(int elem:arr)
	{
		std::cout<< elem <<" "<<std::endl;
	}

}
