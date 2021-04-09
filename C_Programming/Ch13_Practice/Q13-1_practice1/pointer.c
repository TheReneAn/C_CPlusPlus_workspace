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

길이가 5인 int형 배열 arr을 선언하고 이를 1, 2, 3, 4, 5 로 초기화 한 다음, 이 배열의 첫 번째 요소를 가리키는 포인터 변소 ptr을 선언한다.
이 배열의 첫 번째 요소를 가리키는 포인터 변수 ptr을 선언한다.
그 다음 포인터 변수 ptr에 저장된 값을 증가시키는 형태의 연산을 기반으로 배열요소에 접근하면서 모든 배열요소의 값을 2씩 증가시키고, 정상적으로 증가가 이루어 졌는지 확인하라.
*/