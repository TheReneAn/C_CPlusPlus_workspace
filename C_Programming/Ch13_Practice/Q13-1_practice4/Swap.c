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
길이가 6인 int형 배열을 arr을 선언하고 이를 1, 2, 3, 4, 5, 6 으로 초기화한 다음,
배열에 저장된 값의 순서가 6, 5, 4, 3, 2, 1이 되도록 변경하는 예제를 작성해보자.
단, 배열의 앞과 뒤를 가리키는 포인터 변수 두 개를 선언해서 이를 활용하여 저장된 값의 
순서를 뒤바꿔야 한다.
*/