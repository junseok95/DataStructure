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
		// 중간값이 타겟과 일치할 때
		if (arr[mid] == target)
		{
			// 앞 인덱스와 값이 같지 않을때 까지 반복
			while (arr[mid] == arr[mid - 1])
			{
				mid--;
			}
			*idx = mid;
			return 0;
		}
		// 중간값이 타겟보다 작을 때
		else if (arr[mid] < target)
		{
			start = mid + 1;
		}
		// 중간값이 타겟보다 클 때
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
	printf("<<<배열에 넣을 숫자 %d개를 입력하세요.>>> \n", MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	// target을 수정하여 찾을 값을 정하시오.
	int target = 4;
	int index = -1;
	if (bSearch(arr, MAX_SIZE, target, &index) == 0)
	{
		printf("target의 index는 %d입니다.\n", index);
	}
	else
		printf("찾으시는 숫자가 없습니다.\n");
}