#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_NODE 200


typedef int HNode;
#define Key(n) (n)

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Parent(i) (heap[i / 2]) // i의 부모 노드
#define Left(i) (heap[i * 2]) // i의 왼쪽 자식 노드
#define Right(i) (heap[i * 2 + 1]) // i의 오른쪽 자식 노드

void init_heap() { heap_size = 0; } // 힙을 초기화하는 함수
int is_empty_heap() { return heap_size == 0; } // 공백상태 검사 함수
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); } // 포화상태 검사 함수
HNode find_heap() { return heap[1]; } // 힙에서 루트 노드 반환 함수

void insert_heap(HNode n) // 힙트리에 새로운 노드 n을 삽입하는 함수
{
	int i;
	if (is_full_heap()) return; // 포화상태인 경우
	i = ++(heap_size); //힙사이즈를 증가
	while (i != 1 && Key(n) > Key(Parent(i)))  //i가 루트노드가 아니고,n의 key가 i의 부모보다 큰 경우
	{
		heap[i] = Parent(i); //부모노드를 heap위치로 끌어내림
		i /= 2; // 부모노드 = 자식노드/2
	}
	heap[i] = n; //최종 위치에 데이터를 복사함
}

HNode delete_heap() // 힙트리의 삭제함수
{
	HNode hroot, last; //삭제할 루트를 저장할 변수와 새로운 루트값을 저장할 변수 선언
	int parent = 1, child = 2; //parent를 루트 위치로. child를 parent의 왼쪽 자식으로 초기화

	if (is_empty_heap()) //힙이 공백상태인 경우
		printf("힙 트리 공백 에러");

	hroot = heap[1]; // 삭제 연산에서는 루트노드를 반환하므로 루트를 hroot에 저장
	last = heap[heap_size--]; // 힙의 마지막 요소를 last에 복사

	while (child <= heap_size) { // 힙트리를 벗어나지 않는 동안 반복
		if (child < heap_size && Key(Left(parent)) < Key(Right(parent)))
			child++;
		if (Key(last) >= Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
		
	}
	heap[parent] = last; // 마지막 노드를 최종위치(루트)에 저장
	return hroot; // 삭제할 루트를 반환
}

void print_heap() // 힙을 레벨단위로 출력함
{
	int i, level;
	for (i = 1, level = 1; i <= heap_size; i++) {
		if (i = level) {
			printf("\n");
			level *= 2;
			
		}
		printf("%2d ", Key(heap[i]));
		
	}
	printf("\n-----------------");
 }

void main()
{
	init_heap();
	insert_heap(10);
	insert_heap(40);
	insert_heap(30);
	insert_heap(5);
	insert_heap(12);
	insert_heap(6);
	insert_heap(15);
	insert_heap(9);
	insert_heap(60);
	print_heap();
	
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	delete_heap();
	printf("\n");
	print_heap();
}

