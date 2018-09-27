#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7

int bSearch(const int* arr, int arrSize, int target, int * idx, char* arr1)
{
	if (arr == NULL)
		return -1;

	int start = 0;
	int end = MAX_SIZE - 1;
	int mid = (start + end) / 2;

	while (start <= end)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			arr1[i] = ' ';
		}
		// �߰����� Ÿ�ٰ� ��ġ�� ��
		if (arr[mid] == target)
		{
			//start = <-; mid = +; end = ->;
			//ã�� �� ���빰
			arr1[start] = '<';
			arr1[end] = '>';
			arr1[mid] = '+';

			printf("  �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%c ", arr1[i]);
			}
			printf("\n");
			printf("%d", arr[mid]);
			printf(" �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%d ", arr[i]);
			}
			

			*idx = mid;
			return 0;
		}
		// �߰����� Ÿ�ٺ��� ���� ��
		else if (arr[mid] < target)
		{
			//start = <-; mid = +; end = ->;
			//ã�� �� ���빰
			arr1[start] = '<';
			arr1[end] = '>';
			arr1[mid] = '+';


			printf("  �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%c ", arr1[i]);
			}
			printf("\n");
			printf("%d", arr[mid]);
			printf(" �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%d ", arr[i]);
			}

			start = mid + 1;
		}
		// �߰����� Ÿ�ٺ��� Ŭ ��
		else
		{
			
			arr1[start] = '<';
			arr1[end] = '>';
			arr1[mid] = '+';

			printf("  �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%c ", arr1[i]);
			}
			printf("\n");
			printf("%d", arr[mid]);
			printf(" �� ");
			for (int i = 0; i < MAX_SIZE; i++)
			{
				printf("%d ", arr[i]);
			}
			end = mid - 1;
		}
		mid = (start + end) / 2;
		printf("\n");
	}
	
	return -1;
}

int main()
{
	int arr[MAX_SIZE];
	char arr1[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr1[i] = ' ';
	}
	printf("  �� ");
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", i);
	}
	printf("\n---+-----------------------\n");
	int target = 1;
	int index = -1;
	if (bSearch(arr, MAX_SIZE, target, &index, arr1) == 0)
	{
		/*printf("  �� ");
		for (int i = 0; i < MAX_SIZE; i++)
		{
			printf("%s", arr1[i]);
		}
		printf("\n");
		printf("%d", arr[mid]);
		printf("   �� ");
		for (int i = 0; i < MAX_SIZE; i++)
		{
			printf("%d ", arr[i]);
		}*/
		//printf("index : %d\n", index);

		printf("\n\n%d�� arr[%d]�� �ֽ��ϴ�.\n", target, index);
	}
}