#include <stdio.h>

int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;

	// Change the value in the ptr
	for (int i = 0; i < 5; i++) {
		*ptr += 2;
		ptr++;
	}

	for (int i = 0; i < 5; i++) {
		printf("Result: %d\n", arr[i]);
	}
	
	return 0;
}

/*
Declare an int type array that length is 5, and then initialize the array to 1, 2, 3, 4, 5.
Declares the pointer variable ptr that points to the first element of this array.
Then increase the value of all array elements by 2 
as you approach the array elements based on an operation that increases the value stored in the pointer variable ptr, 
and make sure that the increase has been achieved normally.

���̰� 5�� int�� �迭 arr�� �����ϰ� �̸� 1, 2, 3, 4, 5 �� �ʱ�ȭ �� ����, �� �迭�� ù ��° ��Ҹ� ����Ű�� ������ ���� ptr�� �����Ѵ�.
�� �迭�� ù ��° ��Ҹ� ����Ű�� ������ ���� ptr�� �����Ѵ�.
�� ���� ������ ���� ptr�� ����� ���� ������Ű�� ������ ������ ������� �迭��ҿ� �����ϸ鼭 ��� �迭����� ���� 2�� ������Ű��, ���������� ������ �̷�� ������ Ȯ���϶�.
*/