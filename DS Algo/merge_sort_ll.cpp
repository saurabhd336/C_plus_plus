#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};

void insert(node ** head, int data)
{
	node * newnode = new node;
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

void print_list(node * head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"\n";
}

node * merge(node * h1, node * h2)
{
	node * ans = NULL;
	node * temp = new node;
	temp->data = -1;
	temp->next = NULL;
	ans = temp;
	node * temp_head = ans;
	
	while(h1 && h2)
	{
		if(h1->data < h2->data)
		{
			node * newnode = new node;
			newnode->data = h1->data;
			newnode->next = NULL;
			temp_head->next = newnode;
			h1 = h1->next;
		}
		else
		{
			node * newnode = new node;
			newnode->data = h2->data;
			newnode->next = NULL;
			temp_head->next = newnode;
			h2 = h2->next;
		}
		
		temp_head = temp_head->next;
	}
	
	while(h1)
	{
		node * newnode = new node;
		newnode->data = h1->data;
		newnode->next = NULL;
		temp_head->next = newnode;
		temp_head = temp_head->next;
		h1 = h1->next;
	}

	while(h2)
	{
		node * newnode = new node;
		newnode->data = h2->data;
		newnode->next = NULL;
		temp_head->next = newnode;
		temp_head = temp_head->next;
		h2 = h2->next;	
	}
	
	return ans->next;
}

node * sort(node * head)
{
	if(head == NULL || head->next == NULL)
		return head;
	//Find middle;
	node * slow, *fast;
	slow = head;
	fast = head->next->next;
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	node * next = slow->next;
	slow->next = NULL;

	head = sort(head);
	next = sort(next);
	return merge(head, next);
}

int main()
{
	node * head = NULL;
	insert(&head, 9);
	insert(&head, 3);
	insert(&head, 1);
	insert(&head, 8);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 10);
	insert(&head, 12);
	
	print_list(head);
	head = sort(head);
	cout<<"After sorting\n";
	print_list(head);
	return 0;
}
