#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_NODE 200


typedef int HNode;
#define Key(n) (n)

HNode heap[MAX_HEAP_NODE];
int heap_size;

#define Parent(i) (heap[i / 2]) // i�� �θ� ���
#define Left(i) (heap[i * 2]) // i�� ���� �ڽ� ���
#define Right(i) (heap[i * 2 + 1]) // i�� ������ �ڽ� ���

void init_heap() { heap_size = 0; } // ���� �ʱ�ȭ�ϴ� �Լ�
int is_empty_heap() { return heap_size == 0; } // ������� �˻� �Լ�
int is_full_heap() { return (heap_size == MAX_HEAP_NODE - 1); } // ��ȭ���� �˻� �Լ�
HNode find_heap() { return heap[1]; } // ������ ��Ʈ ��� ��ȯ �Լ�

void insert_heap(HNode n) // ��Ʈ���� ���ο� ��� n�� �����ϴ� �Լ�
{
	int i;
	if (is_full_heap()) return; // ��ȭ������ ���
	i = ++(heap_size); //������� ����
	while (i != 1 && Key(n) > Key(Parent(i)))  //i�� ��Ʈ��尡 �ƴϰ�,n�� key�� i�� �θ𺸴� ū ���
	{
		heap[i] = Parent(i); //�θ��带 heap��ġ�� �����
		i /= 2; // �θ��� = �ڽĳ��/2
	}
	heap[i] = n; //���� ��ġ�� �����͸� ������
}

HNode delete_heap() // ��Ʈ���� �����Լ�
{
	HNode hroot, last; //������ ��Ʈ�� ������ ������ ���ο� ��Ʈ���� ������ ���� ����
	int parent = 1, child = 2; //parent�� ��Ʈ ��ġ��. child�� parent�� ���� �ڽ����� �ʱ�ȭ

	if (is_empty_heap()) //���� ��������� ���
		printf("�� Ʈ�� ���� ����");

	hroot = heap[1]; // ���� ���꿡���� ��Ʈ��带 ��ȯ�ϹǷ� ��Ʈ�� hroot�� ����
	last = heap[heap_size--]; // ���� ������ ��Ҹ� last�� ����

	while (child <= heap_size) { // ��Ʈ���� ����� �ʴ� ���� �ݺ�
		if (child < heap_size && Key(Left(parent)) < Key(Right(parent)))
			child++;
		if (Key(last) >= Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
		
	}
	heap[parent] = last; // ������ ��带 ������ġ(��Ʈ)�� ����
	return hroot; // ������ ��Ʈ�� ��ȯ
}

void print_heap() // ���� ���������� �����
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

