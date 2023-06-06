/**
Experiment 7 : Construct an expression tree from the given prefix and traverse it using post order traversal
 and then delete the entire tree.*/

#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};
class tree
{
    char prefix[20];

public:
    node *top;
    void expression(char[]);
    void display(node *);
    void non_rec_postorder(node *);
    void del(node *);
};
class stack1
{
    node *data[30];
    int top;

public:
    stack1()
    {
        top = -1;
    }
    int empty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    void push(node *p)
    {
        data[++top] = p;
    }
    node *pop()
    {
        return (data[top--]);
    }
};
void tree::expression(char prefix[])
{
    stack1 s;
    node *t1, *t2;
    int len, i;
    len = strlen(prefix);
    for (i = len - 1; i >= 0; i--)
    {
        top = new node;
        top->left = NULL;
        top->right = NULL;
        if (isalpha(prefix[i]))
        {
            top->data = prefix[i];
            s.push(top);
        }
        else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' || prefix[i] == '/')
        {
            t2 = s.pop();
            t1 = s.pop();
            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
    top = s.pop();
}
void tree::display(node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        display(root->left);
        display(root->right);
    }
}
void tree::non_rec_postorder(node *top)
{
    stack1 s1, s2; /*stack s1 is being used for flag . A NULL data implies that the right subtree has not been visited*/ 
    node *T = top;
    cout << "\n";
    s1.push(T);
    while (!s1.empty())
    {
        T = s1.pop();
        s2.push(T);
        if (T->left != NULL)
            s1.push(T->left);
        if (T->right != NULL)
            s1.push(T->right);
    }
    while (!s2.empty())
    {
        top = s2.pop();
        cout << top->data;
    }
}
void tree::del(node *node)
{
    if (node == NULL)
        return;
    /* first delete both subtrees*/ 
    del(node->left);
    del(node->right);
    /* then delete the node */
    cout <<endl<<"Deleting node : " << node->data<<endl;
    free(node);
}
int main()
{
    char expr[20];
    tree t;

    cout <<"Enter prefix Expression : ";
    cin >> expr;
    cout << expr;
    t.expression(expr);
    //t.display(t.top);
    cout<<endl;
    t.non_rec_postorder(t.top);
    t.del(t.top);
    
}

/*2nd code:*/

/*Construct an expression tree from the given prefix expression eg. +--a*bc/def
and traverse it using post order traversal (non recursive) and then delete the entire tree.



#include <iostream>
#include <stack>
#include <string>

using namespace std;

class node
{
public:
	char data;
	node *left, *right;
	node(char val) : data(val), left(NULL), right(NULL) {}
};

string acceptExpression()
{
	string expression;
	cout << "Enter the Expression : ";
	cin >> expression;
	return expression;
}

node *convertExpressionIntoTree(string expression)
{
	// int len = expression.size();
	stack<node *> s;
	for (auto i = expression.rbegin(); i != expression.rend(); i++)
	{
		// char ch = expression[i];
		// cout << *i << endl;
		if ((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z') || (*i >= '0' && *i <= '9'))
		{
			node *temp = new node(*i);
			s.push(temp);
		}
		else
		{
			node *op = new node(*i);
			op->left = s.top();
			s.pop();
			op->right = s.top();
			s.pop();
			s.push(op);
		}
	}

	return s.top();
}

// non rec post order
void nonRecPostOrder(node *root)
{
	stack<node *> s1, s2;

	node *temp = root;

	s1.push(temp);

	while (!s1.empty())
	{

		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if (temp->left != nullptr)
			s1.push(temp->left);
		if (temp->right != nullptr)
			s1.push(temp->right);
	}
	while (!s2.empty())
	{
		cout << s2.top()->data;
		s2.pop();
	}
}

void postorder(node *root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}
int main()
{

	string expression = "+--a*bc/def";
	node *root = convertExpressionIntoTree(expression);
	cout << expression << endl;
	postorder(root);
	cout << endl;
	nonRecPostOrder(root);

	return 0;
}*/