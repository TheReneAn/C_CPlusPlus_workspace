#include <stdio.h>

int main() {

	int arr[6] = { 1, 2, 3, 4, 5, 6};
	int* ptrFront = arr;
	int* ptrEnd = &arr[5];
	int temp;

	for (int i = 0; i < 3; i++) {
		temp = *ptrEnd;
		*ptrEnd = *ptrFront;
		*ptrFront = temp;

		ptrEnd--;
		ptrFront++;
	}	

	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

/*
���̰� 6�� int�� �迭�� arr�� �����ϰ� �̸� 1, 2, 3, 4, 5, 6 ���� �ʱ�ȭ�� ����,
�迭�� ����� ���� ������ 6, 5, 4, 3, 2, 1�� �ǵ��� �����ϴ� ������ �ۼ��غ���.
��, �迭�� �հ� �ڸ� ����Ű�� ������ ���� �� ���� �����ؼ� �̸� Ȱ���Ͽ� ����� ���� 
������ �ڹٲ�� �Ѵ�.
*/