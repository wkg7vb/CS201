using namespace std;

template <class T>
void mySwap(T arr[], int size, int pos1, int pos2)
{
	T temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

template <class T>
T myMin(T arr[], int size)
{
	T min = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

template <class T>
T myMax(T arr[], int size)
{
	T max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template <class T>
int mySearch(T arr[], int size, T toFind)
{
	int index = -1;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == toFind)
		{
			index = i;
		}
	}
	return index;
}