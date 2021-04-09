#include <stdio.h>

int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;

	// No Change the value in the ptr
	for (int i = 0; i < 5; i++) {
		* (ptr + i) += 2;
	}

	for (int i = 0; i < 5; i++) {
		printf("Result: %d\n", arr[i]);
	}

	return 0;
}

/*
In question 1, the array elements should be approached by changing the values stored in the pointer variable ptr.
However, this time, do not change the value stored in the pointer variable ptr, but add operations on the ptr.

���� 1������ ������ ���� ptr�� ����� ���� ������Ѱ��鼭 �迭��ҿ� �����϶�� �Ͽ���.
�׷��� �̹����� ������ ���� ptr�� ����� ���� �����Ű�� �ʰ�, ptr�� ������� ���������� �Ͽ�,
�� ����� ��ȯ�Ǵ� �ּ� ���� ���ؼ� ��� �迭 ��ҿ� �����Ͽ� ���� 2�� ������Ű�� ������ �ۼ��غ���.
*/