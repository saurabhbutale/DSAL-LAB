#include<iostream>
#include<string>
using namespace std;

struct node
{
    char label[10];
    int ch_cnt;
    struct node *child[10];
}*root;

class booktree
{
    public:
    void create_tree();
    void display(node *r);
    booktree()
    {
        root=NULL;
    }
};

void booktree::create_tree()
{
    int tch,i,j;
    root=new node;
    cout<<"enter a name of book"<<endl;
    cin>>root->label;
    cout<<"enter a number of chapter in a book:"<<endl;
    cin>>tch;
    root->ch_cnt=tch;
    for(i=0;i<tch;i++)
    {
        root->child[i]=new node;
        cout<<"enter a chapter name:"<<endl;
        cin>>root->child[i]->label;
        cout<<"enter a number of section:"<<endl;//<<root->child[i]->label;
        cin>>root->child[i]->ch_cnt;
        for (j=0;j<root->child[i]->ch_cnt;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"enter a name of  section"<<endl;
            cin>>root->child[i]->child[j]->label; 
            cout<<"enter a number of subsection:"<<endl; 
            cin>>root->child[i]->child[j]-> ch_cnt;
            for (int k=0;k<root->child[i]->child[j]-> ch_cnt;k++)
            {
                root->child[i]->child[j]->child[k]= new node;
                cout<<"enter a name of subsection: "<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
                
            }
        }
    }
}
void booktree::display(node *r)
{
    int i,j,tch;
    if(r!=NULL)
    {
        cout<<"***BOOK TREE HIERARCY***"<<endl;
        cout<<"THE TITLE OF THE BOOK:"<<root->label<<endl;
        tch=r->ch_cnt;
        for(i=0;i<tch;i++)
        {
            cout<<"CHAPTER"<<i+1<<endl;
            cout<<" "<<r->child[i]->label<<endl;
            cout<<"SECTION"<<endl;
            for (j= 0; j <r->child[i]->ch_cnt; j++)
            {
                cout<<"\n"<<r->child[i]->child[j]->label<<endl;
                cout<<"SUBSECTION"<<endl;
                for (int k= 0; k <r->child[i]->child[j]->ch_cnt; k++)
                {
                cout<<"\n"<<r->child[i]->child[j]->child[k]->label<<endl;
                }
            }
            
        }
    }
};

int main()
{
    int choice;
    booktree bt;
    do
    {
        cout<<"MAIN MENU"<<endl;
        cout<<"\n1.create a booktree"<<endl;
        cout<<"\n2.display a booktree"<<endl;
        cout<<"\n3.exit"<<endl;
        cout<<"\nEnter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: bt.create_tree();
            case 2: bt.display(root);
            case 3: exit(1);
            default:cout<<"wrong choice.";
        }

    } while(choice!=4);
    return 0;
    
}
