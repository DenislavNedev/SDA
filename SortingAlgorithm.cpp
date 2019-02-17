#include <iostream>
using namespace std;

void quicksort(int * arr, int low, int high)
{
	if (low < high)
	{
		int q = partition(arr, low, high);
		quicksort(arr, low, q - 1);
		quicksort(arr, q + 1, high);
	}
}

int partition(int * arr, int low, int high)
{
	int x = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);

	return i;

}

void mergeSort(int * arr, int left, int right)
{
	long long inversions = 0;
	int mid = 0;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge(int * arr, int left, int mid, int right)
{
	int size_left = mid - left + 1;
	int* arr_left = new int[size_left];

	for (int i = 0; i < size_left; i++)
	{
		arr_left[i] = arr[i + left];
	}

	int size_right = right - mid;
	int* arr_right = new int[size_right];

	for (int i = 0; i < size_right; i++)
	{
		arr_right[i] = arr[i + mid + 1];
	}

	int l = 0;
	int r = 0;
	int k = left;

	while ((l < size_left) && (r < size_right))
	{
		if (arr_left[l] <= arr_right[r])
		{
			arr[k++] = arr_left[l++];

		}
		else
		{
			arr[k++] = arr_right[r++];
		}
	}

	while (l <size_left)
	{
		arr[k++] = arr_left[l++];
	}

	while (r <size_right)
	{
		arr[k++] = arr_right[r++];
	}
}

void insertionSort(int * masiv, int size)
{
	for (int j = 1; j < size; j++)
	{
		int key = masiv[j];
		int i = j - 1;
		while (i >= 0 && masiv[i]>key)
		{
			masiv[i + 1] = masiv[i];
			i--;
		}
		masiv[i + 1] = key;
	}
}