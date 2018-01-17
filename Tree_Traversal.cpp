#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
using namespace std;
int randInt(int,int);
void strwhereSS(const char*,int,int);
void strwhere(const char*,int,int);
void cadr_dash(int);
void space(int);
int ndigits(int);
int limit=0;
struct node{
	node *right;
	node *left;
	char data[25];
	node(){
		right=0;
		left=0;
		strcpy(data,"NULL");
	}
};
class Tree{
	public:
	node root;
	node *temp;
	public:
	Tree(){}
	void random_append(const char* str){
		int rand;
		temp=&root;
		if(!temp->right && !temp->left){
			if(!strcmp(temp->data,"NULL")){
				strcpy(temp->data,str);
				return;
			}
			rand=randInt(1,2);
			if(rand==1){
				temp->left=new node;
				temp=temp->left;
			}
			else if(rand==2){
				temp->right=new node;
				temp=temp->right;
			}
			strcpy(temp->data,str);
			return;
		}
		while(temp->right || temp->left){
			rand=randInt(1,2);
			if(rand==1){
				if(temp->left){ temp=temp->left;}
				else{
					temp->left=new node;
					temp=temp->left;
				}
			}
			else if(rand==2){
				if(temp->right){ temp=temp->right;}
				else{
					temp->right=new node;
					temp=temp->right;
				}
			}
		}
		if(!strcmp(temp->data,"NULL")){strcpy(temp->data,str);}
		else{
			rand=randInt(1,2);
			if(rand==1){
				temp->left=new node;
				temp=temp->left;
			}
			else if(rand==2){
				temp->right=new node;
				temp=temp->right;
			}
			strcpy(temp->data,str);
		}
	}
	void show_full(){
		int j,k;
		temp=&root;
		node* tmp[128];
		stringstream temp[7];
		//for(int i=0; 20>i; i++) line[i]=new char[80];
		j=0;
		tmp[0]=&root;
		if(tmp[0]) temp[0]<<"|"<<BOLDGREEN<<"*"<<RESET<<"|"; else temp[0]<<"| |";
		for(int i=1; 7>i; i++){
			temp[i]<<"|";
			for(j=pow(2,i)-1,k=pow(2,i-1)-1; pow(2,i+1)-1>j; j=j+2,k++){
				if(tmp[k]){
					tmp[j]=tmp[k]->left;
					tmp[j+1]=tmp[k]->right;
				} 
				else{
					tmp[j]=0;
					tmp[j+1]=0;
				}
				if(tmp[j] && strcmp(tmp[j]->data,"NULL")) temp[i]<<BOLDGREEN<<"*"<<RESET<<"|"; else temp[i]<<" |";
				if(tmp[j+1] && strcmp(tmp[j+1]->data,"NULL")) temp[i]<<BOLDGREEN<<"*"<<RESET<<"|"; else temp[i]<<" |";
			}
		}
		for(; 70>j; j++) tmp[j]=0;
		cout<<endl;
		cadr_dash(200);
		for(int i=0; 7>i; i++){
			strwhereSS(temp[i].str().c_str(),i,200);
			cout<<endl;
			cadr_dash(200);
		}
	}
	void show_tree(){
		int j,k,resume;
		temp=&root;
		node* tmp[60000];
		stringstream temp[20];
		//for(int i=0; 20>i; i++) line[i]=new char[80];
		j=0;
		tmp[0]=&root;
		if(tmp[0]) temp[0]<<"| "<<BOLDGREEN<<tmp[0]->data<<RESET<<" |"; else temp[0]<<"| NULL |";
		resume=1;
		for(int i=1; 20>i && resume==1; i++){
			int bgr,del;
			bgr=0; del=0;
			resume=0;
			temp[i]<<"| ";
			for(j=pow(2,i)-1,k=pow(2,i-1)-1; pow(2,i+1)-1>j; j=j+2,k++){
				if(tmp[k]){
					tmp[j]=tmp[k]->left;
					tmp[j+1]=tmp[k]->right;
				} 
				else{
					tmp[j]=0;
					tmp[j+1]=0;
				}
				if(tmp[j]){
					if(temp[i].str().size()-(bgr*13)-del+strlen(tmp[j]->data)+8+ndigits(i)<=75){ temp[i]<<BOLDGREEN<<tmp[j]->data<<RESET<<" | "; bgr++;}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=1;
						del= temp[i].str().size();
						temp[i]<<BOLDGREEN<<tmp[j]->data<<RESET<<" | ";
					}
				}
				else{
					if(temp[i].str().size()-(bgr*13)-del+6+8+ndigits(i)<=75){ temp[i]<<"NULL | ";}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=0;
						del= temp[i].str().size();
						temp[i]<<"NULL | ";
					}
				}
				if(tmp[j+1]){
					if(temp[i].str().size()-(bgr*13)-del+strlen(tmp[j+1]->data)+8+ndigits(i)<=75){ temp[i]<<BOLDGREEN<<tmp[j+1]->data<<RESET<<" | "; bgr++;}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=1;
						del= temp[i].str().size();
						temp[i]<<BOLDGREEN<<tmp[j+1]->data<<RESET<<" | ";
					}
				}
				else{
					if(temp[i].str().size()-(bgr*13)-del+6+8+ndigits(i)<=75){ temp[i]<<"NULL | ";}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=0;
						del= temp[i].str().size();
						temp[i]<<"NULL | ";
					}
				}
			}
			for(j=pow(2,i)-1; pow(2,i+1)-1>j; j++) if(tmp[j] && strcmp(tmp[j]->data,"NULL")) resume=1;
			if(!resume) temp[i].str("");
		}
		cout<<endl;
		cadr_dash(80);
		for(int i=0; temp[i].str().size(); i++){
			cout<<"Depth "<<i<<": "<<temp[i].str()<<endl;
			cadr_dash(80);
		}
	}
	void show_depth_traversal(){
		int j,k,resume;
		temp=&root;
		node* tmp[60000];
		stringstream temp[20];
		//for(int i=0; 20>i; i++) line[i]=new char[80];
		j=0;
		tmp[0]=&root;
		if(tmp[0] && strcmp(tmp[0]->data,"NULL")) temp[0]<<"| "<<BOLDGREEN<<tmp[0]->data<<RESET<<" |";
		resume=1;
		for(int i=1; 20>i && resume==1; i++){
			int bgr,del;
			bgr=0; del=0;
			resume=0;
			temp[i]<<"| ";
			for(j=pow(2,i)-1,k=pow(2,i-1)-1; pow(2,i+1)-1>j; j=j+2,k++){
				if(tmp[k]){
					tmp[j]=tmp[k]->left;
					tmp[j+1]=tmp[k]->right;
				} 
				else{
					tmp[j]=0;
					tmp[j+1]=0;
				}
				if(tmp[j] && strcmp(tmp[0]->data,"NULL")){
					if(temp[i].str().size()-(bgr*13)-del+strlen(tmp[j]->data)+8+ndigits(i)<=75){ temp[i]<<BOLDGREEN<<tmp[j]->data<<RESET<<" | "; bgr++;}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=1;
						del= temp[i].str().size();
						temp[i]<<BOLDGREEN<<tmp[j]->data<<RESET<<" | ";
					}
				}
				if(tmp[j+1] && strcmp(tmp[0]->data,"NULL")){
					if(temp[i].str().size()-(bgr*13)-del+strlen(tmp[j+1]->data)+8+ndigits(i)<=75){ temp[i]<<BOLDGREEN<<tmp[j+1]->data<<RESET<<" | "; bgr++;}
					else{
						temp[i]<<endl;
						for(int l=0; 8+ndigits(i)>l; l++) temp[i]<<" ";
						temp[i]<<"| ";
						bgr=1;
						del= temp[i].str().size();
						temp[i]<<BOLDGREEN<<tmp[j+1]->data<<RESET<<" | ";
					}
				}
			}
			for(j=pow(2,i)-1; pow(2,i+1)-1>j; j++) if(tmp[j] && strcmp(tmp[j]->data,"NULL")) resume=1;
			if(!resume) temp[i].str("");
		}
		cout<<endl;
		cadr_dash(80);
		for(int i=0; temp[i].str().size(); i++){
			cout<<"Depth "<<i<<": "<<temp[i].str()<<endl;
			cadr_dash(80);
		}
	}
	void show_preorder(node subtree){
		if(strcmp(subtree.data,"NULL")) cout<<"| "<<subtree.data<<" ";
		if(subtree.left) show_preorder(*(subtree.left));
		if(subtree.right) show_preorder(*(subtree.right));
	}
	void show_postorder(node subtree){
		if(subtree.left) show_preorder(*(subtree.left));
		if(subtree.right) show_preorder(*(subtree.right));
		if(strcmp(subtree.data,"NULL")) cout<<"| "<<subtree.data<<" ";
	}
	void show_inorder(node subtree){
		if(subtree.left) show_preorder(*(subtree.left));
		if(strcmp(subtree.data,"NULL")) cout<<"| "<<subtree.data<<" ";
		if(subtree.right) show_preorder(*(subtree.right));
	}
					
};
Tree tree_random_generate(void);


int main(){
	srand ( time(NULL) );
	Tree t1;
	t1=tree_random_generate();
	cout<<endl;
	cout<<BOLDRED<<"Preorder Traversal: "<<RESET<<endl;
	t1.show_preorder(t1.root);
	cout<<endl<<endl;
	cout<<BOLDRED<<"Postorder Traversal:"<<RESET<<endl;
	t1.show_postorder(t1.root);
	cout<<endl<<endl;
	cout<<BOLDRED<<"Inorder Traversal:"<<RESET<<endl;
	t1.show_inorder(t1.root);
	cout<<endl<<endl;
	cout<<BOLDRED<<"Depth Traversal:"<<RESET<<endl;
	t1.show_depth_traversal();
	cout<<endl<<endl;
	cout<<BOLDRED<<"Show Tree:"<<RESET<<endl;
	t1.show_tree();
	return 0;
}
int randInt(int min,int max){
	int rnd;
	rnd=(rand()%(int)(max - min+1)+min);
	return rnd;
}
void strwhere(const char *a,int zarf,int halat=0){
	int len=strlen(a);
	int s=(zarf-len)/2;
	if(halat==0) cout<<RESET;
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}
void strwhereSS(const char *a,int satr,int zarf){
	int len;
	len=pow(2,satr+1)+1;
	int s=(zarf-len)/2;
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}
void cadr_dash(int tul){
	for(int i=0; tul>i; i++) cout<<"-";
	cout<<endl;
}
void space(int s){
	if(s>0) for(int i=0; s>i; i++) cout<<" ";
}
int ndigits(int number){
	int n=0;
	while(number>0){
		n++;
		number=number/10;
	}
	return n;
}	
Tree tree_random_generate(void){
	Tree t1;
	int tedad;
	cout<<"Chand 10 Gereh Be Surate Tasadofi Tolid Shavad? (Hade Aksar 200) "<<endl;
	cin>>tedad;
	while(tedad<1 || tedad>200){
		cout<<endl<<"Error! Vorudi Namotabar"<<endl;
		cout<<"Chand 10 Gereh Be Surate Tasadofi Tolid Shavad? (Hade Aksar 200) "<<endl;
		cin>>tedad;
	}
	for(int i=0; tedad>i; i++){
		t1.random_append("Sadegh");
		t1.random_append("Reza");
		t1.random_append("Vahid");
		t1.random_append("Ali");
		t1.random_append("Karim");
		t1.random_append("Azim");
		t1.random_append("Farid");
		t1.random_append("Mohammad");
		t1.random_append("Hesam");
		t1.random_append("Navid");
	}
	return t1;
}	
