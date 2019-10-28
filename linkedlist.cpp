#include <iostream>
using namespace std;


	
class Node {
public:
	int data;
	Node* next;
	Node *prev;
	Node(int data) {
		this->data = data;
		next = NULL;
		prev=NULL;
	}
};

class Doublylinkedlist {
	private:
		Node *header;
		Node *tail;
		int size;
	public:
		Doublylinkedlist(){
			header=NULL;
			tail=NULL;
			size=0;
		}
		int getsize() {
			return size;
		}

		void append(int data) {
		//Create a new Nod
			Node *n=new Node(data);
		//Case 1:Empty List
			if (header == NULL) {
				header=n;
				tail=n;
			}
		//Case 2:List is not Empty
			else {
				tail->next=n;
				n->prev=tail;
				tail=n;
			}
		//Increment size counter
			size++;
		}

		void prepend(int data) {
		Node *n=new Node(data);
			if (header==NULL) {	
			header=n;
			tail=n;
			}
			else {
				header->prev = n;
				n->next=header;
				header=n;

			}
			size++;
		}
		void print() {
			//create a temp pointer
			Node*temp=header;
			cout<<"<";
			while (temp != NULL) {
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<">";
			cout<<endl;
		}
		void printRev() {

			Node* temp = tail;
			cout << "<";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->prev;
			}
			cout << ">";
			cout << endl;

		}

		void removeFirst() {
			if (size == 1) {
			delete header;
			header=NULL;
			tail=NULL;
			}
			else if (header!=NULL) {
				header=header->next;
				delete header->prev;
				header->prev=NULL;
				}
		size--;

		}
		void removeEnd() {
			if (header == tail) {
				void removeFirst();				
			}
			else if(header != NULL) {
			tail=tail->prev;
			delete tail->next;
			tail->next=NULL;
			}
			size--;

		}

		void removeAt(int pos) {
			if (pos<1 || pos > size) {
				return;
			}
			else if (pos == 1) {
				removeFirst();
			}
			else if (pos == size) {
				removeEnd();
			}
			else if (header != NULL) {
				Node*cur=header;
				for (int i = 1; i < pos; i++) {
					cur=cur->next;
				}
				cur->prev->next=cur->next;
				cur->next->prev=cur->prev;
				
				delete cur;
				size--;
			}
		}

		void insertAt(int pos, int data) {
		if	(pos>size+1|| pos<1){return;}
			else if (pos == 1) {
				prepend(data);
			}
			else if (pos == size+1) {
				append(data);
			}
			else if (header != NULL) {
				Node* n = new Node(data);
				Node*curr=header;
				for (int i = 1; i < pos; i++) {
					curr=curr->next;			
				}
				curr->prev->next=n;
				n->prev=curr->prev;

				n->next=curr;
				curr->prev=n;
				size++;

			}

		}
	~Doublylinkedlist() {
		Node* of=header;
		while (header != NULL) {
		of=header->next;
		delete header;
		header=of;
		}
	}
};

void linkedlistUsage(Doublylinkedlist& l1) {

	cout << l1.getsize() << endl;
	l1.prepend(2);
	cout << "Prepend 2:";
	l1.print();
	l1.prepend(7);
	cout << "Prepend 7:";
	l1.print();
	l1.append(4);
	l1.append(3);
	l1.append(9);
	cout << "append 4,3,9:";
	l1.print();
	cout << "Print Reverse:";
	l1.printRev();
	l1.insertAt(2, 5);
	cout << "insert 5 at pos(2):";
	l1.print();
	cout << "Remove First";
	l1.removeFirst();
	l1.print();
	cout << "remove END";
	l1.removeEnd();
	l1.print();
	l1.removeAt(2);
	l1.print();
	l1.insertAt(3, 89);
	l1.print();

}

class stackArr {
	private:
		int size;
		int *sArr;
		int top;
		void resize()
		{
		cout<<"resized"<<endl;
			int tempsize=2*size;
			int *temp=new int [tempsize];
				for (int i = 0; i < size; i++) 
				temp[i]=sArr[i];
			delete []sArr;
			sArr=temp;
			size=tempsize;
		}

	public:
		stackArr(int size) {
			this->size=size;
			sArr=new int [size];
			top=-1;
		}
		void push(int a) {
		if(top==size-1){resize();}
			sArr[++top]=a;
		}
		void pop() {
		if(top==-1){cout<<"Empty Stack" ;}
		else{
			cout<<sArr[top--]<<endl;
			}
		}
	public:
	~stackArr(){delete [] sArr;}
};
class Node1{
	public:
		int data;
		Node1 *next;	
		Node1(int num) {
			this->data=num;
			next=NULL;
		}

};

class Lstack {
	private:
		Node1 *top;
	public:
		Lstack() {top=NULL;}
		void push(int num){		
			Node1 *n=new Node1(num);
			if (top == NULL) {top=n;}
			else{ 
			n->next=top;
			top=n;				
			}
		}
		void pop() {
		if(top==NULL){cout<<"Empty Stack\n"; }
		else{
			cout<<top->data<<endl;
			Node1* temp = top;
			top=top->next;
			delete [] temp;
			}
		}
};

class QArr {//Uses Circular Array
private:
	int size, front, rear, numOfElements;
	int* QArray;

public:
	QArr(int size) {
		front = rear = -1;
		this->size = size;
		QArray = new int[size];
		numOfElements = 0;
	}
	void resize() {
		cout << "Resized" << endl;
		int tempsize = 2 * size;
		int* temp = new int[tempsize];
		for (int i = 0; i < size; i++)
			temp[i] = QArray[(front + i) % size];
		delete[]QArray;
		QArray = temp;
		front = 0;
		rear = size - 1;
		size = tempsize;

	}
	void enqueue(int num) {
		if (numOfElements == size) { resize(); }
		if (front == -1 && rear == -1)
			front = rear = 0;
		else rear = (rear + 1) % size;
		QArray[rear] = num;
		numOfElements++;
	}
	void dequeue() {
		if (numOfElements == 0)
		{
			cout << "empty Queue" << endl;
		}
		else {
			if (front == rear)
				front = rear = -1;
			else
				cout << QArray[front] << endl;
			front = (front + 1) % size;
			numOfElements--;
		}
	}

	~QArr() {
		delete[] QArray;
	}


};

void AstackUsage(stackArr& a1) {
	a1.pop();
	a1.push(5);
	a1.pop();
	a1.push(6);
	a1.push(9);
	a1.push(12);
	a1.pop();
	a1.pop();
	a1.pop();

}
void LstackUsage(Lstack& b1) {
	b1.pop();
	b1.push(8);
	b1.push(9);
	b1.push(3);
	b1.push(1);
	b1.pop();
	b1.pop();
	b1.pop();
	b1.pop();
}


void QArrUse(QArr a) {
	a.enqueue(2);
	a.enqueue(4);
	a.enqueue(8);
	a.enqueue(5);
	a.dequeue();
	a.dequeue();
	a.dequeue();
}

class QLL {
	private:
		Node1 *front;
		Node1 *rear;
	public:
		QLL(){front=rear=NULL;}

		void enqueue(int num)
		{	Node1 *n=new Node1(num);
			if ( rear == NULL) {
				rear=front=n;
			}
			else {
				rear->next=n;
				rear=n;
			}
		}
		void dequeue() {
			if(front==NULL){cout<<"Empty Queue"<<endl; }
			else {
			Node1 *temp=front;
			cout<<front->data<<endl;
			if (front == rear) {
				front=rear=NULL;
				}
				else{front=front->next;}
				delete temp;			
			}
		}

		~QLL() {
			Node1* next;
			while (front != NULL) {
				next=front->next;
				delete front;
				front=next;
			}
		}
};

void QLLUse(QLL a) {
	a.enqueue(2);
	a.enqueue(4);
	a.enqueue(8);
	a.enqueue(5);
	a.dequeue();
	a.dequeue();
	a.dequeue();
}

void simpleData() {
	cout << "Doubly LinkedList Implementation" << endl;
	Doublylinkedlist l1;
	linkedlistUsage(l1);

	cout << "stack implementation using Array" << endl;
	stackArr a1(2);
	AstackUsage(a1);

	cout << "stack implementation using linked list" << endl;
	Lstack b1;
	LstackUsage(b1);

	cout << "Queue implementation using circular Array" << endl;
	QArr q1(3);
	QArrUse(q1);

	cout << "Queue implementation using Linked List" << endl;
	QLL a;
	QLLUse(a);
}


class BinNode {
	public:
	int data;
	BinNode *left,*right;
	BinNode(int num) {
	this->data=num;
	left=right=NULL;}
};

class BTree {
	private:
		BinNode *root;

		BinNode* MaxLeftsTree(BinNode* root) {
			while (root->right != NULL)
				root = root->right;
			return root;
		}

		void insertPrivate(int num, BinNode *&root) {
			if (root == NULL) {
				root=new BinNode(num);
			}
			else if (num<root->data) {
				if(root->left!=NULL)
					insertPrivate(num,root->left); 
				else 
					root->left=new BinNode(num);
			}
			else if (num > root->data) {
				if(root->right!=NULL)
					insertPrivate(num,root->right);
				else
					root->right=new BinNode(num);
			}
		}
		void removePrivate(int num, BinNode*& root) {
			if(root==NULL)cout<<"Empty BST\n";
			else if(num<root->data) removePrivate(num,root->left);
			else if (num>root->data) removePrivate(num,root->right);
			else {
				if (root->left == NULL) {
					BinNode *temp=root;
					root=root->left;
					delete temp;
				}
				else if (root->right == NULL) {
					BinNode* temp=root;
					root=root->right;
					delete temp;
				}
				else {
					BinNode *temp=MaxLeftsTree(root->left);
					root->data=temp->data;
					removePrivate(temp->data,root->left);
				}
			}

		}

		void  PreOrdertransverse(BinNode* root) {
			if (root == NULL)return;
			cout << root->data << endl;
			PreOrdertransverse(root->left);
			PreOrdertransverse(root->right);
		}
	

	public:
		BTree() {root=NULL;}
		void insert(int num) {
		cout<<"Inserting: "<<num<<endl;
			insertPrivate(num,root);
		}
		void remove(int num) {
		cout<<"Deleting: "<<num<<endl;
			removePrivate(num, root);
		}
		void print() {
			PreOrdertransverse(root);
		}


};
void BTreeUse(BTree Tree1) {
	
	Tree1.insert(7);
	Tree1.insert(6);
	Tree1.insert(12);
	Tree1.insert(1);
	Tree1.insert(9);
	Tree1.insert(63);
	Tree1.insert(3);
	Tree1.print();
	Tree1.remove(12);
	Tree1.print();
}


class BinHeapMax {
	private:
		int *heap;
		int heapSize;
		int arraySize;
		int getLeftChild(int index){return 2*index+1;}
		int getRightChild(int index) {return 2*index+2;}
		int getParent(int index) {return (index-1)/2;}
		void swap(int i, int j) {
			int temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
		}
		bool hasLeft(int index){return getLeftChild(index)<heapSize ;}
		bool hasRight(int index){return getRightChild(index)<heapSize;}
	public:
		BinHeapMax(int size) {
			heap=new int[size];
			arraySize=size;
			heapSize=0;
		}
		void heapifyUp(int index) {
			if (index != 0) {
				int parent =getParent(index);
				if(heap[parent]<heap[index])
					swap(parent,index);
				heapifyUp(parent);
			}
		}
		void insert(int num) {
			if(heapSize==arraySize)
				cout<<"Heap is FUll\n";
			else {
				heapSize++;
				heap[heapSize-1]=num;
				heapifyUp(heapSize-1);
			}
		}
		void getHeap() {
			for (int i = 0; i < heapSize; i++) {
				cout<<heap[i]<<" ";
			}
		}
		void heapifyDown(int index) {
			
			int lChild=getLeftChild(index);
			int rChild=getRightChild(index);
			int Max=index;
			if(hasLeft(index)&& heap[lChild]>heap[Max] )
				Max=lChild;
			if (hasRight(index) && heap[rChild] > heap[Max])
				Max = rChild;

			if (Max != index) {
				swap(Max,index);
				heapifyDown(Max);
			}
		}
		int removeMax() {
			if(heapSize==0)return -1;
			else {
				int root=heap[0];
				heap[0]=heap[heapSize-1];
				heapSize--;
				if(heapSize>1)
					heapifyDown(0);
				return root;

			}

		}
	
		~BinHeapMax() {
			delete [] heap;
		}
};

int main() {

//simpleData();		//implements simple data structres like doubly linkedlist,
					//(using array and Linked list)queue and Stack 
//	BTree Tree1;
//BTreeUse(Tree1);
//cout<<"----Heap-----\n";
//BinHeapMax Heap1(5);
//Heap1.insert(4);
//Heap1.insert(5);
//Heap1.insert(10);
//Heap1.insert(7);
//Heap1.insert(57);
//Heap1.insert(37);
//Heap1.getHeap();
//int Max=Heap1.removeMax();
//cout<<" Max Heap"<<endl<<"Root Value: "<<Max<<endl;
//Heap1.getHeap();

int arrop[5]={1,4,5,3};
int length=sizeof(arrop)/sizeof(arrop[0]);
for (int i = 0; i < length; i++) {
	cout<<arrop[i]<<endl;
}

system("pause");
return 0;
}