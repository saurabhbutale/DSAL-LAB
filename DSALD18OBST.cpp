/*Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each 
key ki . Build the Binary search tree that has the least search cost given the access 
probability for each key*/

#include<iostream>
using namespace std;
#define SIZE 10
class OBST
{
        public:
        int p[SIZE];
        int q[SIZE];
        int a[SIZE];
        int w[SIZE][SIZE];
        int c[SIZE][SIZE];
        int r[SIZE][SIZE];
        int n; 
        
/* This function accepts the input data */
        void get_data()
        {
                int i;
                cout<<"\n OPTIMAL BINARY SEARCH TREE \n";
                cout<<"\n Enter the number of nodes:";
                cin>>n;
                for(i=1;i<=n;i++)
                {
                    cout<<"\n a["<<i<<"]::";
                    cin>>a[i];
                }
                for(i=1;i<=n;i++)
                {
                     cout<<"\n p["<<i<<"]::";
                     cin>>p[i];
                }
                for(i=0;i<=n;i++)
                {
                    cout<<"\n q["<<i<<"]::";
                    cin>>q[i];
                }
        }
        int Min_Value(int i,int j)
        {
            int m,k;
            int minimum=32000;
            for(m=r[i][j-1];m<=r[i+1][j];m++)
            {
                if((c[i][m-1]+c[m][j])<minimum)
                {
                   minimum=c[i][m-1]+c[m][j];
                   k=m;
                }
            }
            return k;
        }
        
        void build_OBST()
        {
            int i,j,k,m;
            for(i=0;i<n;i++)
            {
               for(j=0;j<n;j++)
               {
                 w[i][i]=q[i];
                r[i][i]=c[i][i]=0;
                
                w[i][i+1]=q[i]+q[i+1]+p[i+1];
                r[i][i+1]=i+1;
                c[i][i+1]=q[i]+q[i+1]+p[i+1];
               }
            }
            w[n][n]=q[n];
            r[n][n]=c[n][n]=0;
        
            for(m=2;m<=n;m++)
            {
               for(i=0;i<=n-m;i++)
               {
                    j=i+m;
                    w[i][j]=w[i][j-1]+p[j]+q[j];
                    k=Min_Value(i,j);
                    c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
                    r[i][j]=k;
                }
            }
        }
        /* This function builds the tree from the tables made by the OBST function */
        void build_tree()
        {
            int i,j,k;
            int queue[20],front=-1,rear=-1;
            cout<<"The Optimal Binary Search Tree For the Given Node Is:\n";
            cout<<"\n The Root of this OBST is ::"<<r[0][n];
            cout<<"\nThe Cost of this OBST is::"<<c[0][n];
            cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
            cout<<"\n";
            queue[++rear]=0;
            queue[++rear]=n;
            while(front!=rear)
            {
                i=queue[++front];
                j=queue[++front];
                k=r[i][j];
                cout<<"\n\t"<<k;
                if(r[i][k-1]!=0)
                {
                    cout<<"\t\t"<<r[i][k-1];
                    queue[++rear]=i;
                    queue[++rear]=k-1;
                }
                else
                cout<<"\t\t";
                if(r[k][j]!=0)
                {
                    cout<<"\t"<<r[k][j];
                    queue[++rear]=k;
                    queue[++rear]=j;
                }
                else
                cout<<"\t";
            }//end of while
            cout<<"\n";
        }
};
int main()
{
OBST obj;
int ch;
char ans;
do
{
 cout<<"*****MAIN MENUE*****"<<endl;
 cout<<"\n 1.INPUT";
 cout<<"\n 2.OUTPUT";
 cout<<"\n 3.EXIT"<<endl;
 cout<<"Enter your choice:"<<endl;
 cin>>ch;
 switch (ch)
 {
 case 1:
       obj.get_data();
       break;

  case 2: 
       obj.build_OBST();
       obj.build_tree();
       break; 

  case 3:
       exit(0);
       break;       
 
 default:
      cout<<"Enter valid input."<<endl;
       break;
 }
 cout<<"Do you want to continue::";
 cin>>ans;
} while (ans=='y' || ans=='Y');



return 0;
}
/*-------------output---------------
Optimal Binary Search Tree
Enter the number of nodes 4
Enter the data as�
a[1] 1
a[2] 2
a[3] 3
a[4] 4
p[1] 3
p[2]3
p[3]1
p[4]1
q[0]2
q[1]3
q[2]1
q[3]1
q[4]1
The Optimal Binary Search Tree For the Given Node Is
The Root of this OBST is ::2
The Cost of this OBST is::32
NODE LEFT CHILD RIGHT CHILD
2 1 3
1
3 4
4
--------------------*/


