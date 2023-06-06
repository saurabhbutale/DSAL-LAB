/*A Dictionary stores keywords and its meanings. Provide facility for adding new 
keywords, deleting keywords, updating values of any entry. Provide facility to display 
whole data sorted in ascending/ Descending order. Also find how many maximum 
comparisons may require for finding any keyword. Use Height balance tree and find the 
complexity for finding a keyword*/
/*#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;
    int height;

    Node(string key, string value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rotateRight(Node* node) {
    Node* left = node->left;
    Node* right = left->right;
    left->right = node;
    node->left = right;
    node->height = 1 + max(height(node->left), height(node->right));
    left->height = 1 + max(height(left->left), height(left->right));
    return left;
}

Node* rotateLeft(Node* node) {
    Node* right = node->right;
    Node* left = right->left;
    right->left = node;
    node->right = left;
    node->height = 1 + max(height(node->left), height(node->right));
    right->height = 1 + max(height(right->left), height(right->right));
    return right;
}

Node* insert(Node* root, string key, string value) {
    if (root == nullptr)
        return new Node(key, value);
    if (key < root->key)
        root->left = insert(root->left, key, value);
    else if (key > root->key)
        root->right = insert(root->right, key, value);
    else {
        cout << "Keyword already exists." << endl;
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, string key) {
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
           root->key = temp->key;
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == nullptr)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void update(Node* root, string key, string value) {
    if (root == nullptr) {
        cout << "Keyword not found." << endl;
        return;
    }
    if (key < root->key)
        update(root->left, key, value);
    else if (key > root->key)
        update(root->right, key, value);
    else {
        root->value = value;
        cout << "Keyword updated successfully." << endl;
    }
}

void traverseInOrder(Node* root) {
    if (root != nullptr) {
        traverseInOrder(root->left);
        cout << root->key << " : " << root->value << endl;
        traverseInOrder(root->right);
    }
}

void traversePreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " : " << root->value << endl;
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traversePostOrder(Node* root) {
    if (root != nullptr) {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->key << " : " << root->value << endl;
    }
}

Node* search(Node* root, string key, int& comparisons) {
    if (root == nullptr) {
        comparisons++;
        return nullptr;
    }
    comparisons++;
    if (key == root->key)
        return root;
    if (key < root->key)
        return search(root->left, key, comparisons);
    return search(root->right, key, comparisons);
}

int main() {
    Node* root = nullptr;
    int choice, comparisons;
    string key, value;
    Node* result;

    do {
        cout << "\n----DICTIONARY MENU----\n";
        cout << "1. Add new keyword\n";
        cout << "2. Delete keyword\n";
        cout << "3. Update value of a keyword\n";
        cout << "4. Display dictionary (in ascending order)\n";
        cout << "5. Display dictionary (in descending order)\n";
        cout << "6. Search for a keyword\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, value);
                root = insert(root, key, value);
                cout << "Keyword added successfully." << endl;
                break;
              case 2:
                cout << "Enter keyword to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                if (root != nullptr)
                    cout << "Keyword deleted successfully." << endl;
                break;

            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, value);
                update(root, key, value);
                break;

            case 4:
                cout << "\nDICTIONARY (in ascending order):\n";
                traverseInOrder(root);
                break;

            case 5:
                cout << "\nDICTIONARY (in descending order):\n";
                traversePostOrder(root);
                break;

             case 6:
                cout << "Enter keyword to search: ";
                cin >> key;
                comparisons = 0;
                result = search(root, key, comparisons); // remove the declaration here
                if (result == nullptr)
                    cout << "Keyword not found." << endl;
                else
                    cout << "Keyword found with meaning: " << result->value << endl;
                cout << "Maximum comparisons required: " << comparisons << endl;
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}    */

#include<iostream>
using namespace std;

class node
{
public:
	string key;
	string meaning;
	node *left;
	node *right;
};

class AVL
{
	node *root;
        public:
            	AVL()
            	{
            		root=NULL;
            	}
            	
	            void create();
	            node* insert(node *cur,node *temp);
            	node* balance(node *temp);
            	int dif(node *temp);
            	int height(node *temp);
            	int maximum(int a,int b);
            	
            	node* LL(node *par);
            	node* RR(node *par);
            	node* LR(node *par);
            	node* RL(node *par);
            	
            	void ascending(node *temp);
            	node* delete_n(node *root,string key1);
            	void deleten();
            	
            	node* extractmin(node *t);
                void descending(node *temp);
                void display();
                bool search(node *cur,string key1);
                void search_value();
};

void AVL::create()
{
	char answer;
	node *temp;
	do
	{
		temp=new node();
		cout<<"\n Enter the keyword:";
		cin>>temp->key;
		cout<<"\n Enter the meaning:";
		cin>>temp->meaning;
		temp->left=temp->right=NULL;

			root=insert(root,temp);

		cout<<"\n Do you want to add another word?(y/n)";
		cin>>answer;
	}
	while(answer=='y'||answer=='Y');
}


node* AVL::insert(node *cur,node *temp)
{
	if(cur==NULL)
	{
		return temp;
	}
	if(temp->key<cur->key)
	{
		cur->left=insert(cur->left,temp);
		cur=balance(cur);
	}
	else if(temp->key>cur->key)
	{
		cur->right=insert(cur->right,temp);
		cur=balance(cur);
	}
	return cur;
}

node* AVL::balance(node *temp)
{
	int bal;
	bal=dif(temp);
	
	if(bal>=2)
	{
		if(dif(temp->left)<0)
			temp=LR(temp);
		else
			temp=LL(temp);
	}
	else if(bal<=-2)
	{
		if(dif(temp->right)<0)
			temp=RR(temp);
		else
			temp=RL(temp);
	}
	return temp;
}


int AVL::dif(node *temp)
{
	int l,r;
	l=height(temp->left);
	r=height(temp->right);
	return(l-r);
}

int AVL::height(node *temp)
{
	if(temp==NULL)
		return(-1);
	else
		return(max(height(temp->left),height(temp->right))+1);
}

int AVL::maximum(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

node* AVL::LL(node *par)
{
	node *temp,*temp1;
	temp=par->left;
	temp1=temp->right;
	temp->right=par;
	par->left=temp1;
	return temp;
}

node* AVL::RR(node *par)
{
	node *temp,*temp1;
	temp=par->right;
	temp1=temp->left;
	temp->left=par;
	par->right=temp1;
	return temp;
}

node* AVL::LR(node *par)
{
	par->left=RR(par->left);
	return(LL(par));
}

node* AVL::RL(node *par)
{
	par->right=LL(par->right);
	return(RR(par));
}

void AVL::ascending(node *temp)
{
        if(temp!=NULL)
        {
                ascending(temp->left);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                ascending(temp->right);
        }
}

void AVL::descending(node *temp)
{
        if(temp!=NULL)
        {
                descending(temp->right);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                descending(temp->left);
        }
}


void AVL::display()
{
        cout<<"\n The keywords in ascending order are : \n";
        ascending(root);
        cout<<"\n The keywords in descending order are : \n";
        descending(root);
}

bool AVL::search(node *cur,string key1)
{
	if(cur)
	{
		if(cur->key==key1)
			return true;
		if(cur->key>key1)
			return search(cur->left,key1);
		else
			return search(cur->right,key1);
	}
	return false;
}

void AVL::search_value()
{
	string key2;
        cout<<"\n Enter the keyword you wish to search : ";
        cin>>key2;
        if(search(root,key2))
                cout<<"\n The entered keyword is present in the AVL tree";
        else
                cout<<"\n The entered keyword is not present in the AVL tree";
}


node* AVL::delete_n(node* cur,string key1)
{
    if ( !cur)
    	return cur;
    if ( key1 < cur->key )
        cur->left = delete_n(cur->left, key1);

    else if( key1 > cur->key )
        cur->right = delete_n(cur->right, key1);

    else
    {
        node *l = cur->left;
        node *r = cur->right;
        delete cur;
        if ( !r )
        	return l;
        node *m=r;
        
        while(m->left)
        	m=m->left;
        m->right = extractmin(r);
        m->left = l;
        return balance(m);
    }
    return balance(cur);
}

    node* AVL::extractmin(node *t)
    {
        if ( !t->left ) 
        return t->right;
        t->left = extractmin(t->left);
        return balance(t);
    }

void AVL::deleten()
{
	string key;
	cout<<"\n Enter the keyword to be deleted : ";
	cin>>key;
	root=delete_n(root,key);
}

int main()
{
  char c;
  int ch;
  AVL a;
  do
  {
      cout<<"*********************************";
	  cout<<"\n 1.Insert a keyword in AVL tree.";
	  cout<<"\n 2.Display the AVL tree.";
	  cout<<"\n 3.Search a keyword";
	  cout<<"\n 4.Delete a keyword.";
	  cout<<"\n Enter your choice : ";
	  cin>>ch;
	  switch(ch)
	  {
      	  case 1 : a.create();
               break;
      	  case 2 : a.display();
               break;
      	  case 3 : a.search_value();
               break;
      	  case 4 : a.deleten();
               break;
      	  default : cout<<"\n Wrong choice ! ";
	  }
	  cout<<"\n Do you want to continue? (y/n): ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');
  return 0;
}



