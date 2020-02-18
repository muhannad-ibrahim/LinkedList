#include<iostream>
#include<string>
using namespace std;
struct etype 
{
	string name;
	int age;
};
struct node
{
	etype e;
	node* next;
};
node* NEW(etype x)//create new node for x and return its pointer
{
	node* p=new node;
	p->e=x;
	p->next=NULL;
	return p;
}
void InsertFirst(node* head ,etype x)
{
	head->e=x;
	head->next=NULL;
}
void Insert(node *head,etype x)//insert in last
{
	node* p=NEW(x);
	node* cur = head;
	while(cur)//when we reach the NULL we finished
	{
		if (cur->next == NULL)
		{
			//insertion at cur->next
			cur->next =new node; 
			cur->next = p;
			break;//the insertion is done
		}
		else
		{
			cur= cur->next ; //traversing the linkedlist untill NULL
		}
	}
}
void InsertRec(node* head , etype x)
{
	node* cur= head;
	if(cur->next == NULL)
	{
		//insertion at cur->next
			cur->next =new node; 
			cur->next = NEW(x);
			
	}
	else
	{
		cur=cur->next;
		InsertRec(cur , x);
	}
}
node* Search(node* head,etype x)
{
	//bool found =false;//it does not exist untill we prove the convers 
	node* cur = head;
	//traversing Linked list for search
	while(cur)//loop untill you reach the end of linked list or finding the element
	{
		if((cur->e.name == x.name)&&(cur->e.age == x.age))
		{
			//found = true;
			return cur;
		}
		else
		{
			cur= cur->next;
		}
	}
	return NULL;//flag for not finding the element
}
bool Delete(node* &head,node* p)//delete the element with pointer p
{
	if (p == head)//p is pointer of first element in the linked list
	{
		head = head->next;
		//head changed so call by refrence
		return true;
	}
	else
	{
		node* cur = head;
		while(cur)
		{
			if (cur->next == p)
			{
				//delete the element 
				cur->next = cur->next->next;
				return true;
			}
			else
			{
				cur = cur->next;
			}
		}
		return false;
	}
}
void input(node* head)
{
	cout<<"enter number of elements : ";
	int n;
	cin>>n;
	cout<<"element 1 information : \n";
	etype temp;
	cout<<"name : ";
	cin>>temp.name;
	cout<<"age : ";
	cin>>temp.age;
	//head = NEW(temp);
	InsertFirst(head ,temp);
	if(n>1)//enter more than 1 e
	{
		for(int i=2;i<=n;i++)
		{
			cout<<"element "<<i <<" information : \n";
			cout<<"name : ";
			cin>>temp.name;
			cout<<"age : ";
			cin>>temp.age;
			Insert(head,temp);
		}
	}
	
}
void disp(node* head)
{
	node* cur =head;
	cout<<"our linked list elements : "<<endl;
	cout<<"-----------------------------"<<endl;
	while(cur != NULL)
	{
		cout<<"name : "<<cur->e.name<<" and age : "<<cur->e.age<<endl;
		cur =cur->next;
	}
}
void InsertAtFirst(node* &head,etype x)
{
	node* H=NEW(x);
	H->next =head;
	head = H;
}
void reverse(node* &head)
{
	node* head2= new node;//constructing the pointer for reversed linked list
	//traversing the original linked list
	node* cur=head;
	InsertFirst(head2,cur->e);
	cur = cur->next;
	while (cur)
	{
		InsertAtFirst(head2,cur->e);
		cur = cur->next;
	}
	head = head2;
}
void exchange(node* head)
{
	node* cur = head;
	node* last;
	while (cur)
	{
		if (cur->next == NULL)
			last = cur;
		cur = cur->next;
	}
	etype temp=head->e;
	head->e = last->e;
	last->e = temp;
}
bool comparing(node* head1,node* head2)
{
	node* cur1=head1;
	node* cur2=head2;
	bool f=true;
	while(cur1||cur2)
	{
		if(((cur1->e.name)!=(cur2->e.name))&&((cur1->e.age)!=(cur2->e.age)))
			f= false;
		cur1=cur1->next;
		cur2=cur2->next;
	}
	return f;
}
void main()
{
	node * head=new node;
	/*etype x;
	x.name="hamada";
	x.age=50;
	InsertFirst(head,x);
	cout<<"the first element in linked list is : "<< head ->e.name <<" , "<<head->e.age<<endl;
	etype y;
	y.name="donia";
	y.age=20;
	Insert(head,y);
	cout<<"the second element in linked list is : "<< head->next ->e.name <<" , "<<head->next->e.age<<endl;
	etype z;
	z.name="yasser";
	z.age=25;
	Insert(head,z);
	cout<<"the third element in linked list is : "<< head->next->next ->e.name <<" , "<<head->next->next->e.age<<endl;
	etype k;
	k.name="Mohanad";
	k.age=30;
	if(Search(head,k)== NULL)
		cout<<"not found "<<endl;
	else
		cout<<"found at "<< Search(head,k)<<endl;
	if(Search(head,y)== NULL)
		cout<<"not found "<<endl;
	else
		cout<<"found at "<< Search(head,y)<<" = "<<head->next<<endl;
	if(Delete(head,Search(head,y)))
	{
		cout<<"deleted "<<endl;
		cout<<"the second element in linked list is : "<< head->next ->e.name <<" , "<<head->next->e.age<<endl;
	}
	else
		cout<<"not found "<<endl;
	node* p=NEW(k);
	if(Delete(head,p))
	{
		cout<<"deleted "<<endl;
		cout<<"the second element in linked list is : "<< head->next ->e.name <<" , "<<head->next->e.age<<endl;
	}
	else
		cout<<"not found "<<endl;
	cout<<endl;*/
	input(head);
	disp(head);
	/*cout<<"after reversing : \n";
	reverse(head);
	disp(head);*/
	cout<<"after exchanging : \n";
	exchange(head);
	disp(head);
	system("pause");
}