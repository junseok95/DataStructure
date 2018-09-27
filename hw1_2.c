#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7

int bSearch(const int* arr, int arrSize, int target, int * idx)
{
	if (arr == NULL)
		return -1;

	int start = 0;
	int end = MAX_SIZE - 1;
	int mid = (start + end) / 2;

	while (start <= end)
	{
		// �߰����� Ÿ�ٰ� ��ġ�� ��
		if (arr[mid] == target)
		{
			// �� �ε����� ���� ���� ������ ���� �ݺ�
			while (arr[mid] == arr[mid - 1])
			{
				mid--;
			}
			*idx = mid;
			return 0;
		}
		// �߰����� Ÿ�ٺ��� ���� ��
		else if (arr[mid] < target)
		{
			start = mid + 1;
		}
		// �߰����� Ÿ�ٺ��� Ŭ ��
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}

	return -1;
}

int main()
{
	int arr[MAX_SIZE];
	printf("<<<�迭�� ���� ���� %d���� �Է��ϼ���.>>> \n", MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	// target�� �����Ͽ� ã�� ���� ���Ͻÿ�.
	int target = 4;
	int index = -1;
	if (bSearch(arr, MAX_SIZE, target, &index) == 0)
	{
		printf("target�� index�� %d�Դϴ�.\n", index);
	}
	else
		printf("ã���ô� ���ڰ� �����ϴ�.\n");
}