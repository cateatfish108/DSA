#include <iostream>

struct Node
{
	void* element;
	Node* next;
};

int main()
{
	//万能指针void*不能直接解引用，需要转换成具体类型才能解引用
	void* ptr=nullptr;
	int v=100;
	ptr=&v;
	std::cout<<"the value is:..."<<*(int*)ptr<<std::endl;
	
	int a=66,b=88,c=99;
	Node node0,node1,node2;
	node0.element=&a;
	node0.next=&node1;
	node1.element=&b;
    node1.next=&node2;
	node2.element=&c;
    node2.next=NULL;
	//int* ptr=(int*)node0.element; 
	//std::cout<<"node0 element: "<<*ptr<<std::endl;
	//std::cout<<"node0 element: "<<*(node0.element)<<"node0 next: "<<*(node0.next->element)<<std::endl;
}
