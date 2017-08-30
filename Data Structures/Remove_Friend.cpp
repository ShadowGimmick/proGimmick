#include <iostream>
using namespace std;

struct node{
  int val;
  struct node* next;
};

node* head;
int t,n,k;
bool flag = false;

void getPopularityList(){
    int x;cin>>x;
    head = new node;
    head->val = x;
    head->next = NULL;
    node* pf = head;
    for(int i=1 ; i<n ; i++){
        cin>>x;
        node* temp = new node;
        temp->val = x;
        temp->next = NULL;
        pf->next = temp;
        pf = pf->next;
    }
}

void printList(){
	node *tp = head;
	while(tp->next!=NULL){
		cout<<tp->val<<" ";
		tp = tp->next;
	}
	cout<<tp->val<<endl;
	
}

void deleteLastNode(){
	node* c = head;
	if(head == NULL) return ;
	if(head->next == NULL) {
		head = NULL; return;
	}
	while(c->next->next!=NULL) c=c->next;
	c->next = NULL;
	return;
}

void append(){
	flag = false;
	if(head==NULL) return;
	if(head->next == NULL) {
		return;
	}
	
	node* c=head;
	node* n=head->next;
	while(n->next!=NULL){
		if(c->val < n->val) {
			c->val = n->val;
			c->next = n->next;
			flag = true;
			return;
		}
		c = c->next; n = n->next; 	
	}
	if(c->val < n->val) {
		c->val = n->val;
		c->next = n->next;
		flag = true;
		return;
	}
	return ;
}

int main()
{
    cin>>t;
    int no,dl;
    while(t--){
        cin>>n>>k;no=n;dl=k;
        getPopularityList();
        //printLL();
        while(dl--){
        	append();
        	if(flag==false) deleteLastNode();
		}
		printList();  
    }
    return 0;
}
