#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
typedef long long int ll;

class node
{
  public:
	string key;
	string value;
	node *prev;
	node *next;

	node(string k, string v)
	{
		key=k;
		value=v;
		prev=NULL;
		next=NULL;
	}
};


class lrucache
{
   public:
   	int capacity;
   	int count=0;
	node *front,*rear;
	unordered_map<string,node*>mapvalues;

	lrucache()
	{
		capacity=0;
		front=NULL;
		rear=NULL;
	}


	lrucache(int cap)
	{
		capacity=cap;
		front=NULL;
		rear=NULL;
	}

	void display()
	{
		node *n1=front;
		while(n1!=NULL)
		{
			cout<<n1->value<<" ";
			n1=n1->next;
		}
	}


	
	void deletenode(node *n1)
	{
		count--;
		mapvalues.erase(n1->key);
		if(n1==NULL)
			return;

		if(front==rear)
		{
			front=NULL;
			rear=NULL;
			return;
		}

		if(rear==n1)
		{
			n1->prev->next=NULL;
			rear=n1->prev;
			free(n1);
			return;
		}

		n1->prev->next=n1->next;
		n1->next->prev=n1->prev;
		free(n1);

		

	}

	void pushfront(string k,string v)
	{
				count++;
			if(front==NULL)
			{
				node *n1=new node(k,v);
				mapvalues[k]=n1;
				front=n1;
				rear=n1;
				return;
			}

			node *n1=new node(k,v);
				mapvalues[k]=n1;
				n1->next=front;
				front->prev=n1;
				front=n1;


	}


	void movetohead(node *n1)
	{
		if(n1==front)
			return;

		if(rear->prev==NULL)
		{
			rear->prev=n1;
			n1->next=front;
			n1->prev=NULL;
			front=n1;
		}

		if(n1==rear)
		{
			rear=n1->prev;
			n1->prev->next=NULL;
		n1->next=front;
		n1->prev=NULL;
		front->prev=n1;
		front=n1;
		return;
		}

		n1->next->prev=n1->prev;
		n1->prev->next=n1->next;
		n1->next=front;
		n1->prev=NULL;
		front->prev=n1;
		front=n1;


	}


	void set(string k,string v)
	{
		if(capacity==0)
		{
			//cout<<"NO CACHE SPACE\n";
			return;
		}

		 if(mapvalues.find(k)==mapvalues.end())
			{
				if(count<capacity)
					{
						pushfront(k,v);
					}

					else 
					{
						
						deletenode(rear);
						pushfront(k,v);
					}
			}

			else if(mapvalues.find(k)!=mapvalues.end())

			{
				node *n2=mapvalues[k];

				if(n2->value.compare(v)!=0)
				{
					n2->value=v;
				}

				movetohead(n2);
			}	
	

	}


	string get(string k)
	{
		if(capacity==0)
		{return "-1";}


		if(mapvalues.find(k)==mapvalues.end())
		{return "-1";}

		else
		{
				node *n1=mapvalues[k];
				string s=n1->value;
				movetohead(n1);
				return s;
		}
	}
	

};


int main()

{

	ll cap,q;
	cin>>cap;
	cin>>q;
	lrucache c1(cap);
	while(q--)
	{
		string f;
		cin>>f;

		if(f=="G")
		{
			string s;
			cin>>s;
			cout<<c1.get(s)<<"\n";

		}

		if(f=="S")
		{
			string s,g;
			cin>>s>>g;
			c1.set(s,g);
		}
	}
}
