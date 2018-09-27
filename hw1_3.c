#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	// 채운 용량
	int count;
	// 스택 크기
	int max;
    // 꼭대기
    int top;
    int top1;
    // 스택배열
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max)
{
   s->top = 0;
   s->top1 = max-1;
   s->count = 0;
   if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL)
   {
      s->max = 0;
      return -1;
   }
   s->max = max;
   return 0;
}

int Push(IntStack *s, int x)
{
   if (s->top == s->top1+1)
	   return -1;
   s->stk[s->top++] = x;
   s->count++;
   return 0;
}

int Push1(IntStack *s, int x)
{
	if (s->top1 == s->top - 1)
		return -1;
	s->stk[s->top1--] = x;
	s->count++;
	return 0;
}

int Pop(IntStack *s, int *x)
{
   if (s->top <= 0)
      return -1;
   *x = s->stk[--s->top];
   s->count--;
   return 0;
}

int Pop1(IntStack *s, int *x)
{
	if (s->top1 >= s->max-1)
		return -1;
	*x = s->stk[++s->top1];
	s->count--;
	return 0;
}

int Peek(const IntStack *s, int *x)
{
   if (s->top <= 0)
      return -1;
   *x = s->stk[s->top - 1];
   return 0;
}

int Peek1(const IntStack *s, int *x)
{
	if (s->top1 <= 0)
		return -1;
	*x = s->stk[s->top1 + 1];
	return 0;
}

void Clear(IntStack *s)
{
   s->top = 0;
   s->top1 = s->max-1;
}

int Capacity(const IntStack *s)
{
   return s->max;
}

int Size(const IntStack *s)
{
   return s->count;
}

int IsEmpty(const IntStack *s)
{
   return s->top <= 0;
}

int IsFull(const IntStack *s)
{
   return s->top >= s->max;
}

int Search(const IntStack *s, int x)
{
   for (int i = s->top - 1; i >= 0; i--)
      if (s->stk[i] == x)
         return i;
   return -1;
}

void Print(const IntStack *s)
{
   for (int i = 0; i < s->top; i++)
      printf("%d ", s->stk[i]);
   for (int i = s->max-1; i > s->top1; i--)
	   printf("%d ", s->stk[i]);
   putchar('\n');
}

void Terminate(IntStack *s)
{
   if (s->stk != NULL)
   {
      free(s->stk);
      s->stk = NULL;
   }

   s->max = s->top = 0;

   if (s != NULL)
   {
      free(s);
      s = NULL;
   }
}

int main(void)
{
   
   IntStack *s = (IntStack *)malloc(sizeof(IntStack));


   if (Initialize(s, 10) == -1)
   {
      puts("스택 생성에 실패하였습니다");
      return -1;
   }

   while (1)
   {
	   int totalMenu = 0;
	   int menu = 0;
	   int x = 0;
	   printf("현재 데이터 수 : %d / %d\n", Size(s), Capacity(s));
	   printf("(1)앞 (2)뒤 (0)종료 : ");
	   scanf("%d",&totalMenu);
	   if (totalMenu == 1)
	   {
		   printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
		   scanf("%d", &menu);
		   if (menu == 0) break;
		   switch (menu) {
		   case 1:
			   printf("데이터 : ");
			   scanf("%d", &x);
			   if (Push(s, x) == -1)
				   puts("\a오류 : 푸시에 실패하였습니다.");
			   break;

		   case 2:
			   if (Pop(s, &x) == -1)
				   puts("\a오류 : 팝에 실패하였습니다.");
			   else
				   printf("팝 데이터는 %d입니다.\n", x);
			   break;
		   case 3:
			   if (Peek(s, &x) == -1)
				   puts("\a오류 : 피크에 실패하였습니다.");
			   else
				   printf("피크 데이터는 %d입니다.\n", x);
			   break;
		   case 4:
			   Print(s);
			   break;
		   }
	   }
	   else if (totalMenu == 2)
	   {
		   printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
		   scanf("%d", &menu);
		   if (menu == 0) break;
		   switch (menu) {
		   case 1:
			   printf("데이터 : ");
			   scanf("%d", &x);
			   if (Push1(s, x) == -1)
				   puts("\a오류 : 푸시에 실패하였습니다.");
			   break;

		   case 2:
			   if (Pop1(s, &x) == -1)
				   puts("\a오류 : 팝에 실패하였습니다.");
			   else
				   printf("팝 데이터는 %d입니다.\n", x);
			   break;
		   case 3:
			   if (Peek1(s, &x) == -1)
				   puts("\a오류 : 피크에 실패하였습니다.");
			   else
				   printf("피크 데이터는 %d입니다.\n", x);
			   break;
		   case 4:
			   Print(s);
			   break;
		   }
	   }
	   else if (totalMenu == 0)
		   break;
	   else
		   printf("잘못입력하였습니다. 다시 입력해주세요.\n");
	}
   Terminate(s);
   return 0;
}