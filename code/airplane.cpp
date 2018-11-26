#include<bits/stdc++.h>
using namespace std;
struct node{
	int passengerNumber;
	struct node *next;
};
struct node *headAisle = NULL;
struct node *headWindow = NULL;
struct node *headMiddle = NULL;
int numOfWindow = 0;
int numOfAisle = 0;
int numOfMiddle = 0;
struct node* insert(struct node *head,int key)
{
	struct node *temp,*var;
	temp = head;
	var = (struct node*)malloc(sizeof(struct node));
	var->passengerNumber = key;
	var->next = NULL;
	if(temp == NULL){
		head = var;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = var;
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->passengerNumber<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int mat[n][2];
	int row,col;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		mat[i][0] = a;
		mat[i][1] = b;
		row = max(row,b);
		col = col + a;
		if(i==1||i==n)
		{
			numOfWindow += b;
			numOfAisle += b;
			numOfMiddle += a*b - 2*b;
		}
		else
		{
			numOfAisle += b*2;
			numOfMiddle += a*b - 2*b;
		}
	}
	int numOfPassengers;
	cin>>numOfPassengers;
	int count = 1;
	while(numOfPassengers>0)
	{
		if(numOfAisle>0)
		{
			headAisle = insert(headAisle,count);
			count++;
			numOfAisle--;
		}
		else if(numOfWindow>0)
		{
			headWindow = insert(headWindow,count);
			count++;
			numOfWindow--;
		}
		else if(numOfMiddle>0)
		{
			headMiddle = insert(headMiddle,count);
			count++;
			numOfMiddle--;
		}
		numOfPassengers--;
	}
	cout<<"Passenger Ids At Aisle Seats--> ";
	display(headAisle);
	cout<<"Passenger Ids At Window Seats--> ";
	display(headWindow);
	cout<<"Passenger Ids At Middle Seats--> ";
	display(headMiddle);
}