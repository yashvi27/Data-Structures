#include<iostream>

using namespace std;

class node
{
	/*
	Objective: Create a class for a Node for binary search trees
	Approach: Class defines data item is names element with datatype interger and link is named next pf node type
	Input Parameters: none
	Return Value: none
	Description: node class defines the node structure
	*/

	int info;
	node *left, *right;
	public :
		node(int ele,node *l=0,node * r=0)
		{
			info =ele;
			left=l;
			right=r;
		}
		friend class BST;
};

class BST
{
	/*
	objective: Create a binary search tree class
	input parameters: none
	output value: none
	side effects: Class BST defines binary search tree class
	approach: Class definition
	*/

	node *root;
    public:	void insert(int);
	node * deleteByCopy(node *,int);
	node * findmin(node *);
	int search(int,node *);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	node *getroot();
	BST()
	{
		root=0;
	}
};
void BST::insert( int el)
{
	/*
	Objective: function aims at inserting elements to the binary search tree
	Approach: self implementation of binary search trees is being used
	Input Parameters:
		el: element to be inserted as entered by the user
	Return Values: None
	*/

	node *p=root, *prev=0;
	while(p!=0)
	{
		prev=p;
		if(p->info<el)
			p=p->right;
		else
			p=p->left;
	}
	if(root==0)
		root=new node(el);
	else if(prev->info<el)
		prev->right=new node(el);
	else
		prev->left=new node(el);
}

node * BST::deleteByCopy(node *p, int value )
{

	/*
	Objective: function aims at deleting elements from the binary search tree
	Approach: self implementation of binary search trees is being used, deletion by copy is used
	Input Parameters:
        node *: root of the tree
		value: value to be deleted as entered by the user
	Return Values:
        node *:node deleted
	*/


        if (p==NULL)
            {cout<<"\nEmpty Tree!!\n";
            return p;
            }
        else if (p->info<value)
            p->right=deleteByCopy(p->right,value);
        else if (p->info>value)
            p->left=deleteByCopy(p->left,value);
        else{
            if (p->left==NULL)
            {
                node *temp =p->right;
                delete p;
                return temp;

            }
            else if (p->right==NULL)
            {
                node *temp=p->left;
                delete p;
                return temp;
            }

            node *temp=findmin(p->right);
            p->info=temp->info;              //using copying method

            p->right=deleteByCopy(p->right,temp->info);
        }
        return p;
}

node * BST::findmin(node *p)
{
    /*
    Objective: function aims at finding the successor of the node to be deleted
    Approach: self implementation of binary search trees is used
    Input Paramters:
        node *p: node whose successor needs to be find out
    Return Value:
        node *: successor node is returned
    */

    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}


void BST::inorder(node *ptr)
{
	/*
	Objective: function aims at inorder traversal of the binary search tree
	Approach: self implementation of inorder traversal is being used
	Input Parameters:
		*ptr: starting pointer that is the root node
	Return Values: None
	*/

	if(ptr)
	{
	    inorder(ptr->left);
	    cout<<ptr->info<<" ";
	    inorder(ptr->right);
	}
}

void BST::preorder(node *ptr)
{

	/*
	Objective: function aims at preorder traversal of the binary search tree
	Approach: self implementation of preorder traversal is being used
	Input Parameters:
		*ptr: starting pointer that is the root node
	Return Values: None
	*/

	if(ptr)
	{
		cout<<ptr->info<<" ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BST::postorder(node *ptr)
{

	/*
	Objective: function aims at post order traversal of the binary search tree
	Approach: self implementation of post order traversal is being used
	Input Parameters:
		*ptr: starting pointer that is the root node
	Return Values: None
	*/

	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->info<<" ";
	 }
}


node *BST::getroot()
{
	/*
	Objective: function aims at returning the root of the tree
	Approach: self implementation of binary search trees is being used
	Input Parameters: None
	Return Values:
		   node *: root of the tree
	*/
	return root;
}

int BST::search(int ele,node *ptr)
{
	/*
	Objective: function aims at searching elements from the binary search tree
	Approach: self implementation of binary search trees is being used
	Input Parameters:
		ele: element to be searched as entered by the user
		node * ptr: root of the tree
	Return Values: None
	*/

	if(ptr)
	{

	if(ptr->info==ele)

		return 1;
	 else
	       if(ptr->info>ele)

			search(ele,ptr->left);
	       else
			search(ele,ptr->right);
	 }
	return 0;
}

int main()
{
	BST t;
	node *n, *p;
	int ch,x,res;
	char ch1;
	do
	{
		cout<<"\nBINARY SEARCH TREE:";
		cout<<"\nChoose from the following operation:";

		cout<<"\n1.Insertion\n2.Deletion by copy\n3.Search\n4.Display preorder,postorder and inorder traversals\n";
		cout<<"\nEnter your choice:";
		cin>>ch;
		n=t.getroot();
		switch(ch)
		{
			case 1:
					cout<<"\nEnter the element you want to insert in a tree:";
					cin>>x;
					t.insert(x);
					break;
			case 2:cout<<"\nEnter the element you want to delete :";
				cin>>x;
				t.deleteByCopy(n,x);
				break;
			 case 3:cout<<"\nEnter the element to search : ";
				cin>>x;
				res=t.search(x,n);
				if(res==1)
					cout<<'\n'<<x<<" Found ";
				else
					cout<<'\n'<<x<<" Not Found ";
				break;
			 case 4:cout<<"\nINORDER\n";
				t.inorder(n);
				cout<<"\nPREORDER\n";
				t.preorder(n);
				cout<<"\nPOSTORDER\n";
				t.postorder(n);
				break;
		}
		cout<<"\nWant to proceed?(y/n): ";
		cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
	return 0;
}




