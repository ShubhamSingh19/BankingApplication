#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int fdrate=8;
int loanrate=10;
class acc_details
{
    public:
    long long ac ;
    long double bal ;
    char name[50] ;
    char add[100] ;
    int age ;
    acc_details()
    {
        ac=0;
        bal=0;
        strcpy(name,"NULL");
        strcpy(add,"NULL");
        age=0;
    }
    void setaccdata();
    void getaccdata();
} ;
void acc_details::setaccdata()
{
    cout<<"\nEnter account no :";
    cin>>ac;
    cout<<"\nEnter balance of account :";
    cin>>bal;
    cout<<"\nEnter name of account holder :";
    fflush(stdin);
    gets(name);
    cout<<"\nEnter address of account holder :";
    fflush(stdin);
    gets(add);

    cout<<"\nEnter age of account holder :";
    cin>>age;
}
void acc_details::getaccdata()
{
    cout<<"\nAccount no is :";
    cout<<ac;
    cout<<"\nAccount balnce is :";
    cout<<bal;
    cout<<"\nAccount holder's name is :";
    cout<<name;
    cout<<"\nAccount holder's address is :";
    cout<<add;
    cout<<"\nAccount holder's age is :";
    cout<<age;
}
class fixed_acc
{
    public:
    int flag ;
    long double amountf ;
    int time ;
    float rate ;
    fixed_acc()
    {
        flag=0;
        amountf=0;
        time=0;
        rate=0;
    }
    void setfixeddata();
    void getfixeddata();
} ;
void fixed_acc::setfixeddata()
{
    flag=0;
    amountf=0;
    time=0;
    rate=fdrate;
}
void fixed_acc::getfixeddata()   //doubt in the formula
{
    if(flag==1)
    cout<<"\nFixed Deposit Maturity Amount = Rs."<<amountf+amountf*rate*time*0.01 ;
}
class loan_acc
{
    public:
    int flagl ;
    long double amountl ;
    int timel ;
    float ratel ;
    loan_acc()
    {
        flagl=0;
        amountl=0;
        timel=0;
        ratel=0;
    }
    void setloandata();
    void getloandata();
} ;
void loan_acc::setloandata()
{
    flagl=0;
    amountl=0;
    timel=0;
    ratel=loanrate;
}
void loan_acc::getloandata()      //doubt in the formula
{
    if(flagl==1)
        cout<<"\nLoan Amount = Rs."<<amountl+amountl*ratel*timel*0.01;
}

class bank
{
    public:
    char bankname[50];
    long long loginid;
    char pass[50];

    acc_details ad;
    fixed_acc fd;
    loan_acc la;

    bank()
    {
        strcpy(bankname,"NULL");
    }
    void setbankdata();
    void getbankdata();
};

void bank::setbankdata()
{
    /*cout<<"\nEnter bankname : ";
    fflush(stdin);*/
    //gets(bankname);
    ad.setaccdata();
    fd.setfixeddata();
    la.setloandata();
}

void bank::getbankdata()
{
    cout<<"\nBankname is :";
    cout<<bankname;
    cout<<"\naccount no. is :";
    cout<<loginid;
    ad.getaccdata();
    fd.getfixeddata();
    la.getloandata();
}
class employee
{
    public:
    char empbank[50];
    int empid;
    char emppass[50];
    void getempdata();
};
void employee::getempdata()
{
    cout<<"\nEmployee's bank is : ";
    cout<<empbank;
    cout<<"\nEmployee's loginid is : ";
    cout<<empid;
}

class node
{
    public:
    node* left;
    node* right;
    int height;
    bank b;
    node()
    {
        height = 0 ;
    }
};

class tree
{
    public:
    int heightt(node * root)
    {
        if(root==NULL)
            return -1;
        else
            return max(heightt(root->left),heightt(root->right))+1;
    }
    node * rotate_right(node * root);
    node * rotate_left(node * root);
    node* insert(node* root,int loginid,char pass[],char bankname[]);
    node* insert1(node* root,bank b2,int loginid);
    node* getnewnode(int loginid,char pass[],char bankname[])
    {
        node *n_node=new node;
        n_node->b.loginid = loginid;
        strcpy(n_node->b.pass,pass);
        strcpy(n_node->b.bankname,bankname);
        n_node->b.setbankdata();
        n_node->left = NULL;
        n_node->right = NULL;
        return n_node;
    }
    node* getnewnode1(bank b2)
    {
        node *n_node=new node;
        /*n_node->b.loginid = loginid;
        strcpy(n_node->b.pass,pass);*/
        n_node->b = b2;
        n_node->left = NULL;
        n_node->right = NULL;
        return n_node;
    }
    void inorder(node *root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        root->b.getbankdata();
        cout<<endl<<endl;
        inorder(root->right);
    }
   node *search(node *root,int loginid,char pass[],char bankname[]);
   node *searchforemp(node *root,int loginid,char bankname[]);
   node *searchaccount(node *root,int loginid);
   node *deletee(node *root,int loginid);
   node *findmin(node *root);
};
int flag=0;
node* tree::insert(node* root,int loginid,char pass[],char bankname[])
{
    if(root == NULL)
    {
        root = getnewnode(loginid,pass,bankname);
        return root;
    }
    else if(loginid < root->b.loginid)
    {
        root->left = insert(root->left,loginid,pass,bankname);
    }
    else if(loginid > root->b.loginid)
    {
        root->right = insert(root->right,loginid,pass,bankname);
    }
    else
    {
        flag=1;
        cout<<"\nAccount already exists :"<<"\n";
        return root;
    }
    return root;
}

node* tree::insert1(node* root,bank b2,int loginid)
{
    if(root == NULL)
    {
        root = getnewnode1(b2);
        return root;
    }
    else if(loginid < root->b.loginid)
    {
        root->left = insert1(root->left,b2,loginid);
    }
    else //(loginid > root->b.loginid)
    {
        root->right = insert1(root->right,b2,loginid);
    }
    /*
    else
    {
        cout<<"\nLogin Id already exists :"<<"\n";
        return root;
    }*/
    return root;
}
node *tree::search(node *root,int loginid,char pass[],char bankname[])
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->b.loginid==loginid&&(strcmp(root->b.pass,pass)==0)&&(strcmp(root->b.bankname,bankname)==0))
    return root;
    else if(loginid < root->b.loginid)
    return search(root->left,loginid,pass,bankname);
    else
    return search(root->right,loginid,pass,bankname);
}
node *tree::searchforemp(node *root,int loginid,char bankname[])
{
    if(root==NULL)
        return NULL;
    else if(root->b.loginid==loginid&&(strcmp(root->b.bankname,bankname)==0))
        return root;
    else if(loginid < root->b.loginid)
        return searchforemp(root->left,loginid,bankname);
    else
        return searchforemp(root->right,loginid,bankname);
}
node *tree::searchaccount(node *root,int loginid)
{
    if(root==NULL)
        return NULL;
    else if(root->b.loginid==loginid)
        return root;
    else if(loginid < root->b.loginid)
        return searchaccount(root->left,loginid);
    else
        return searchaccount(root->right,loginid);
}
node *tree::findmin(node *root)
{
    if(root==NULL)
        return NULL;
    else if(root->left==NULL)
        return root;
    else
        return findmin(root->left);
}
node *tree::deletee(node *root,int loginid)
{
    if(root==NULL)
        return NULL;
    else if(loginid < root->b.loginid)
        root->left=deletee(root->left,loginid);
    else if(loginid > root->b.loginid)
        root->right=deletee(root->right,loginid);
    else
    {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                root=NULL;
            }
            else if(root->left==NULL)
            {
                node *temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL)
            {
                node *temp=root;
                root=root->left;
                delete temp;
            }
            else
            {
                node *temp=findmin(root->right);
                root->b=temp->b;
                root->right=deletee(root->right,temp->b.loginid);
            }
    }
    return root;
}
node* tree::rotate_right(node * root)
{
    node * newroot=root->left;
    root->left=newroot->right;
    newroot->right=root;
    root->height=max(heightt(root->left),heightt(root->right))+1;
    newroot->height=max(heightt(root->left),heightt(root->right))+1;
    return newroot;
}
node* tree::rotate_left(node * root)
{
    node * newroot=root->right;
    root->right=newroot->left;
    newroot->left=root;
    root->height=max(root->left->height,root->right->height)+1;
    newroot->height=max(root->left->height,root->right->height)+1;
    return newroot;
}
class enode
{
public:
    enode* left;
    enode* right;
    int height;
    employee e;
};
class etree
{
    public:
    int eheightt(enode * root)
    {
        if(root==NULL)
            return -1;
        else
            return max(eheightt(root->left),eheightt(root->right))+1;
    }
    enode * erotate_right(enode * root);
    enode * erotate_left(enode * root);
    enode *empinsert(enode *root,int empid,char emppass[],char empbank[]);
    enode *getnode(int empid,char emppass[],char empbank[])
    {
        enode *n_node=new enode;
        n_node->e.empid=empid;
        strcpy(n_node->e.emppass,emppass);
        strcpy(n_node->e.empbank,empbank);
        n_node->left=NULL;
        n_node->right=NULL;
        return n_node;
    }
    enode* empinsert1(enode* root,employee b2,int empid);
    enode* getnode1(employee e2)
    {
        enode *n_node=new enode;
        /*n_node->b.loginid = loginid;
        strcpy(n_node->b.pass,pass);*/
        n_node->e = e2;
        n_node->left = NULL;
        n_node->right = NULL;
        return n_node;
    }
    void einorder(enode *root)
    {
        if(root==NULL)
            return;
        einorder(root->left);
        root->e.getempdata();
        cout<<endl<<endl;
        einorder(root->right);
    }
    enode* empsearch(enode *root,int empid,char emppass[],char empbank[]);
};
enode* etree::empinsert(enode *root,int empid,char emppass[],char empbank[])
{
    if(root == NULL)
    {
        root = getnode(empid,emppass,empbank);
        return root;
    }
    else if(empid < root->e.empid)
    {
        root->left = empinsert(root->left,empid,emppass,empbank);
    }
    else if(empid > root->e.empid)
    {
        root->right = empinsert(root->right,empid,emppass,empbank);
    }
    else
    {
        cout<<"\nEmployee Id already exists :"<<"\n";
        return root;
    }
    return root;
}

enode* etree::empinsert1(enode* root,employee e2,int empid)
{
    if(root == NULL)
    {
        root = getnode1(e2);
        return root;
    }
    else if(empid < root->e.empid)
    {
        root->left = empinsert1(root->left,e2,empid);
    }
    else  //(empid > root->e.empid)
    {
        root->right = empinsert1(root->right,e2,empid);
    }
    /*
    else
    {
        cout<<"\nLogin Id already exists :"<<"\n";
        return root;
    }*/
    return root;
}

enode* etree::empsearch(enode *eroot,int empid,char emppass[],char empbank[])
{
    if(eroot==NULL)
    {
        return NULL;
    }
    else if(eroot->e.empid==empid&&(strcmp(eroot->e.emppass,emppass)==0)&&(strcmp(eroot->e.empbank,empbank)==0))
        return eroot;
    else if(empid < eroot->e.empid)
        return empsearch(eroot->left,empid,emppass,empbank);
    else
        return empsearch(eroot->right,empid,emppass,empbank);
}
enode* etree::erotate_right(enode * root)
{
    enode * newroot=root->left;
    root->left=newroot->right;
    newroot->right=root;
    root->height=max(eheightt(root->left),eheightt(root->right))+1;
    newroot->height=max(eheightt(root->left),eheightt(root->right))+1;
    return newroot;
}
enode* etree::erotate_left(enode * root)
{
    enode * newroot=root->right;
    root->right=newroot->left;
    newroot->left=root;
    root->height=max(root->left->height,root->right->height)+1;
    newroot->height=max(root->left->height,root->right->height)+1;
    return newroot;
}


void serialize(node *root,fstream &fp)
{
    if(root==NULL)
    {
        return;
    }
    fp.write((char*)&(root->b),sizeof(bank));
    serialize(root->left,fp);
    serialize(root->right,fp);
}
void eserialize(enode *eroot,fstream &efp)
{
    if(eroot==NULL)
    {
        return;
    }
    efp.write((char*)&(eroot->e),sizeof(employee));
    eserialize(eroot->left,efp);
    eserialize(eroot->right,efp);
}
void getpass(char pass[20])
{
    int k=0 ;
    char c ;
    while(c=getch())
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        {
            pass[k] = c;
            cout<<"*";
            k++;
        }
        else
        {
            pass[k]='\0' ;
            break ;
        }
    }
}
void select1();
void select2();
void select3();
int bankk, user, service, bemp ;

int main()
{
    tree t1;

    //sbi customer file

    node* root1 = NULL;

    fstream fpp1;
    fpp1.open("csbi.dat",ios::in|ios::binary);

    bank b1;
    if(fpp1==NULL)
    {
        cout<<"\nempty file";
    }
    else
        {
    while(!fpp1.eof())
    {

        fpp1.read((char*)&b1,sizeof(bank));
        if(!fpp1.eof())
        {
        root1 = t1.insert1(root1,b1,b1.loginid);
        }
    }
    }
    fpp1.close();

    // pnb customer file

    node* root2 = NULL;

    fstream fpp2;
    fpp2.open("cpnb.dat",ios::in|ios::binary);

    bank b2;
    if(fpp2==NULL)
    {
        cout<<"\nempty file";
    }
    else
        {
    while(!fpp2.eof())
    {

        fpp2.read((char*)&b2,sizeof(bank));
        if(!fpp2.eof())
        {
        root2 = t1.insert1(root2,b2,b2.loginid);
        }
    }
    }
    fpp2.close();


    //axis customer file

    node* root3 = NULL;

    fstream fpp3;
    fpp3.open("caxis.dat",ios::in|ios::binary);

    bank b3;
    if(fpp3==NULL)
    {
        cout<<"\nempty file";
    }
    else
        {
    while(!fpp3.eof())
    {

        fpp3.read((char*)&b3,sizeof(bank));
        if(!fpp3.eof())
        {
        root3 = t1.insert1(root3,b3,b3.loginid);
        }
    }
    }
    fpp3.close();


    etree t2;

    // sbi employee file


    enode* eroot1 = NULL;
    fstream efpp1;
    efpp1.open("esbi.dat",ios::in|ios::binary);

    employee e1;
    if(efpp1==NULL)
    {
        cout<<"\nempty file";
    }
    else
    {
    while(!efpp1.eof())
    {

        efpp1.read((char*)&e1,sizeof(employee));
        if(!efpp1.eof())
        {
        eroot1 = t2.empinsert1(eroot1,e1,e1.empid);
        }
    }
    }
    efpp1.close();

    // pnb employee file

    enode* eroot2 = NULL;
    fstream efpp2;
    efpp2.open("epnb.dat",ios::in|ios::binary);

    employee e2;
    if(efpp2==NULL)
    {
        cout<<"\nempty file";
    }
    else
    {
    while(!efpp2.eof())
    {

        efpp2.read((char*)&e2,sizeof(employee));
        if(!efpp2.eof())
        {
        eroot2 = t2.empinsert1(eroot2,e2,e2.empid);
        }
    }
    }
    efpp2.close();


    // axis employee file

    enode* eroot3 = NULL;
    fstream efpp3;
    efpp3.open("eaxis.dat",ios::in|ios::binary);

    employee e3;
    if(efpp3==NULL)
    {
        cout<<"\nempty file";
    }
    else
    {
    while(!efpp3.eof())
    {

        efpp3.read((char*)&e3,sizeof(employee));
        if(!efpp3.eof())
        {
        eroot3 = t2.empinsert1(eroot3,e3,e3.empid);
        }
    }
    }
    efpp3.close();

     t2.einorder(eroot1);
     cout<<endl;
     t2.einorder(eroot2);
     cout<<endl;
     t2.einorder(eroot3);
     cout<<endl;
     t1.inorder(root1);
     cout<<endl;
     t1.inorder(root2);
     cout<<endl;
     t1.inorder(root3);
     cout<<endl;


    startofprog :
	cout<<"******** WELCOME TO BANKING SYSTEM ***********" ;
	cout<<"\nEnter 1 For State Bank Of India" ;
	cout<<"\nEnter 2 For Punjab National Bank" ;
	cout<<"\nEnter 3 For AXIS BANK" ;
	cout<<"\nEnter 4 To Exit" ;
	cout<<"\nEnter Your Choice : " ;
	cin>>bankk ;
	switch(bankk)
	{
		case 1 : goto startofsbi ;
				 break ;
		case 2 : goto startofpnb ;
				 break ;
		case 3 : goto startofaxis ;
				 break ;
		case 4 : goto endofprog ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto startofprog ;
				  break ;
	}
    startofsbi :
	cout<<"******** WELCOME TO STATE BANK OF INDIA ***********" ;
	select1() ;
	switch(user)
	{
		case 1 : goto empofsbi ;
				 break ;
		case 2 : goto userofsbi ;
				 break ;
		case 3 : goto enterempofsbi;
				 break ;
		case 4 : goto startofprog ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto startofsbi ;
				  break ;
	}

	empofsbi :
    int empid;
    char emppass[20];
    char empbank[40];
	cout<<"\nEnter employee id : ";
	cin>>empid;
	cout<<"\nEnter employee password : ";
	/*fflush(stdin);
	gets(emppass);*/
	(emppass);
	strcpy(empbank,"sbi");
	enode *ecurr1;
	ecurr1=t2.empsearch(eroot1,empid,emppass,empbank);
	if(ecurr1==NULL)
           {
               cout<<"\nInvalid employee id or password ";
               cout<<endl;
               goto startofsbi;
           }
    else
    {empofsbi1:
        cout<<endl<<endl;
	cout<<"******** WELCOME TO STATE BANK OF INDIA ***********" ;
	select2() ;
	switch(bemp)
	{
		case 1 : goto empopenaccountsbi ;
				 break ;
		case 2 : goto empshowaccountsbi ;
				 break ;
		case 3 : goto empdepositsbi ;
				 break ;
		case 4 : goto empwithdrawlsbi;
				 break ;
		case 5 : goto empopenfdsbi ;
				 break ;
		case 6 : goto empopenloansbi ;
				 break ;
		case 7 : goto empneftsbi ;
				 break ;
	    case 8 : goto empdeletesbi;
	             break;
	    case 9 :goto empupdatesbi;
	             break;
		case 10 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofsbi ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto empofsbi ;
				  break ;
	}
    }

	empopenaccountsbi :
    int loginid;
    char pass[50],bname[50];
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bname,"sbi");
    root1=t1.insert(root1,loginid,pass,bname);
    if(flag==0)
    {
        cout<<"\nRecord Successfully added";
        fstream fp1;
    fp1.open("csbi.dat",ios::out|ios::binary);

    serialize(root1,fp1);
    fp1.close();
    }
    goto empofsbi1;

    empshowaccountsbi :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    char bankname[50];
    strcpy(bankname,"sbi");
    node *curr1;
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists";
        goto empofsbi1;
    }
    else
    {
        curr1->b.getbankdata();
        goto empofsbi1;
    }

    empdepositsbi :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be deposited : ";
        cin>>bal;
        if(bal>0)
        {
          curr1->b.ad.bal=curr1->b.ad.bal+bal;
          cout<<"\nAnmount Deposited successfully ";
          cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofsbi1;
    }

    empwithdrawlsbi:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be withdrawl : ";
        cin>>bal;
        if(bal>0)
        {
            if(curr1->b.ad.bal>bal)
            {
          curr1->b.ad.bal=curr1->b.ad.bal-bal;
          cout<<"\nAmount successfully withdrawl";
          cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofsbi1;
    }

    empopenfdsbi:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(curr1->b.ad.bal > bal)
            {
          curr1->b.ad.bal=curr1->b.ad.bal-bal;
          curr1->b.fd.amountf=bal;
          curr1->b.fd.flag=1;
          curr1->b.fd.time=t;
          curr1->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofsbi1;
    }

    empopenloansbi:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*curr1->b.ad.bal))
            {
          curr1->b.ad.bal=curr1->b.ad.bal+bal;
          curr1->b.la.amountl=bal;
          curr1->b.la.flagl=1;
          curr1->b.la.timel=t;
          curr1->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofsbi1;
    }

    empneftsbi:

    cout<<"\nEnter account no. of sender's account : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. of receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"sbi")==0)
        {
            node *curr4;
           curr4=t1.searchaccount(root1,rloginid);
        if(curr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofsbi1;
          }
          else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto empofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr1->b.ad.bal)
            {
              curr1->b.ad.bal=curr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
              curr4->b.ad.bal=curr4->b.ad.bal+bal;
             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofsbi1;
            }
         }
        }

        else if(strcmp(bname,"pnb")==0)
        {
            node *curr5;
           curr5=t1.searchaccount(root2,rloginid);
        if(curr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr1->b.ad.bal)
            {
              curr1->b.ad.bal=curr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
              curr5->b.ad.bal=curr5->b.ad.bal+bal;

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofsbi1;
            }
         }
        }

        else if(strcmp(bname,"axis")==0)
        {
            node *curr6;
           curr6=t1.searchaccount(root3,rloginid);
        if(curr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr1->b.ad.bal)
            {
              curr1->b.ad.bal=curr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr1->b.ad.bal;
              curr6->b.ad.bal=curr6->b.ad.bal+bal;

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofsbi1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto empofsbi1;
         }

         goto empofsbi1;
    }

    empdeletesbi:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {

          root1=t1.deletee(root1,loginid);
          cout<<"\nAccount successfully Deleted ";

          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();

          goto empofsbi1;
    }

    empupdatesbi:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"sbi");
    curr1=t1.searchforemp(root1,loginid,bankname);
    if(curr1==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofsbi1;
    }
    else
    {
          char ch;

          cout<<"\nWant to Change Name of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char name[50];
          cout<<"\nEnter new Name of Account holder : ";
          fflush(stdin);
          gets(name);
          strcpy(curr1->b.ad.name,name);
          }

          cout<<"\nWant to Change Address of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char add[100];
          cout<<"\nEnter new Address of Account holder : ";
          fflush(stdin);
          gets(add);
          strcpy(curr1->b.ad.add,add);
          }
          cout<<"\nWant to Change Age of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           int age;
          cout<<"\nEnter new age of Account holder : ";
          cin>>age;
          curr1->b.ad.age=age;
          }
          cout<<"\nAccount successfully Updated ";

          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();

          goto empofsbi1;
    }



    endofprog :
        exit(0);

   userofsbi :
    {
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bankname,"sbi");
    node *ccurr1=t1.search(root1,loginid,pass,bankname);
    if(ccurr1==NULL)
    {
        cout<<"\nInvalid account no. or password ";
        cout<<endl;
        goto startofsbi;
    }
    else
    {userofsbi1 :
        cout<<endl<<endl;
	cout<<"******** WELCOME TO STATE BANK OF INDIA ***********" ;
	select3() ;
	switch(service)
	{
		case 1 : goto usershowsbi ;
				 break ;
		case 2 : goto usershowbalsbi ;
				 break ;
		case 3 : goto useropenfdsbi ;
				 break ;
        case 4 : goto useropenloansbi ;
                 break ;
        case 5 : goto userneftsbi ;
                  break;
		case 6 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofsbi ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto userofsbi ;
				  break ;
	}
    }

    usershowsbi:
        ccurr1->b.getbankdata();
        goto userofsbi1;

    usershowbalsbi:
        cout<<"\nBalance in Account = "<<ccurr1->b.ad.bal;
        goto userofsbi1;

    useropenfdsbi :

        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(ccurr1->b.ad.bal > bal)
            {
          ccurr1->b.ad.bal=ccurr1->b.ad.bal-bal;
          ccurr1->b.fd.amountf=bal;
          ccurr1->b.fd.flag=1;
          ccurr1->b.fd.time=t;
          ccurr1->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<ccurr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofsbi1;

    useropenloansbi :

        //int bal,t;
        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*ccurr1->b.ad.bal))
            {
          ccurr1->b.ad.bal=ccurr1->b.ad.bal+bal;
          ccurr1->b.la.amountl=bal;
          ccurr1->b.la.flagl=1;
          ccurr1->b.la.timel=t;
          ccurr1->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<ccurr1->b.ad.bal;
          fstream fp1;
          fp1.open("csbi.dat",ios::out|ios::binary);

          serialize(root1,fp1);
          fp1.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofsbi1;

   userneftsbi :


        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"sbi")==0)
        {
            node *ccurr4;
           ccurr4=t1.searchaccount(root1,rloginid);
        if(ccurr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofsbi1;
          }
          else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto userofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr1->b.ad.bal)
            {
              ccurr1->b.ad.bal=ccurr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr1->b.ad.bal;
              ccurr4->b.ad.bal=ccurr4->b.ad.bal+bal;
             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofsbi1;
            }
         }
        }

        else if(strcmp(bname,"pnb")==0)
        {
            node *ccurr5;
           ccurr5=t1.searchaccount(root2,rloginid);
        if(ccurr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr1->b.ad.bal)
            {
              ccurr1->b.ad.bal=ccurr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr1->b.ad.bal;
              ccurr5->b.ad.bal=ccurr5->b.ad.bal+bal;

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofsbi1;
            }
         }
        }

        else if(strcmp(bname,"axis")==0)
        {
            node *ccurr6;
           ccurr6=t1.searchaccount(root3,rloginid);
        if(ccurr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofsbi1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr1->b.ad.bal)
            {
              ccurr1->b.ad.bal=ccurr1->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr1->b.ad.bal;
              ccurr6->b.ad.bal=ccurr6->b.ad.bal+bal;

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofsbi1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto userofsbi1;
         }

         goto userofsbi1;
    }

     enterempofsbi:
         {
             cout<<"\nEnter employeeid : ";
         cin>>empid;
         cout<<"\nEnter employee password : ";
         getpass(emppass);
         strcpy(empbank,"sbi");
         eroot1=t2.empinsert(eroot1,empid,emppass,empbank);
         fstream efp1;
         efp1.open("esbi.dat",ios::out|ios::binary);

         eserialize(eroot1,efp1);
         efp1.close();
         goto startofsbi;
         }

     startofpnb :
	cout<<"******** WELCOME TO PUNJAB NATIONAL BANK OF INDIA ***********" ;
	select1() ;
	switch(user)
	{
		case 1 : goto empofpnb ;
				 break ;
		case 2 : goto userofpnb ;
				 break ;
		case 3 : goto enterempofpnb;
				 break ;
		case 4 : goto startofprog ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto startofpnb ;
				  break ;
	}

    empofpnb :
    //int empid;
    //char emppass[20];
    //char empbank[40];
	cout<<"\nEnter employee id : ";
	cin>>empid;
	cout<<"\nEnter employee password : ";
	getpass(emppass);
	strcpy(empbank,"pnb");
	enode *ecurr2;
	ecurr2=t2.empsearch(eroot2,empid,emppass,empbank);
	if(ecurr2==NULL)
           {
               cout<<"\nInvalid employee id or password ";
               cout<<endl;
               goto startofpnb;
           }
    else
    {empofpnb1:
        cout<<endl<<endl;
	cout<<"******** WELCOME TO PUNJAB NATIONAL BANK OF INDIA ***********" ;
    select2() ;
	switch(bemp)
	{
		case 1 : goto empopenaccountpnb ;
				 break ;
		case 2 : goto empshowaccountpnb ;
				 break ;
		case 3 : goto empdepositpnb ;
				 break ;
		case 4 : goto empwithdrawlpnb;
				 break ;
		case 5 : goto empopenfdpnb ;
				 break ;
		case 6 : goto empopenloanpnb ;
				 break ;
		case 7 : goto empneftpnb ;
				 break ;
	    case 8 : goto empdeletepnb ;
	             break;
	    case 9 :goto empupdatepnb ;
	             break;
		case 10 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofpnb ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto empofpnb ;
				  break ;
	}
    }

	empopenaccountpnb :
    //int loginid;
    //char pass[50],bname[50];
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bname,"pnb");
    root2=t1.insert(root2,loginid,pass,bname);
    if(flag==0)
    {
        cout<<"\nRecord Successfully added";
        fstream fp2;
    fp2.open("cpnb.dat",ios::out|ios::binary);

    serialize(root2,fp2);
    fp2.close();
    }
    goto empofpnb1;

    empshowaccountpnb :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    //char bankname[50];
    strcpy(bankname,"pnb");
    node *curr2;
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists";
        goto empofpnb1;
    }
    else
    {
        curr2->b.getbankdata();
        goto empofpnb1;
    }

    empdepositpnb :

    cout<<"\nEnter account no. ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be deposited : ";
        cin>>bal;
        if(bal>0)
        {
          curr2->b.ad.bal=curr2->b.ad.bal+bal;
          cout<<"\nAnmount Deposited successfully ";
          cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofpnb1;
    }

    empwithdrawlpnb:

    cout<<"\nEnter account no. ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be withdrawl : ";
        cin>>bal;
        if(bal>0)
        {
            if(curr2->b.ad.bal>bal)
            {
          curr2->b.ad.bal=curr2->b.ad.bal-bal;
          cout<<"\nAmount successfully withdrawl ";
          cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofpnb1;
    }

    empopenfdpnb:

     cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(curr2->b.ad.bal > bal)
            {
          curr2->b.ad.bal=curr2->b.ad.bal-bal;
          curr2->b.fd.amountf=bal;
          curr2->b.fd.flag=1;
          curr2->b.fd.time=t;
          curr2->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofpnb1;
    }

    empopenloanpnb:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*curr2->b.ad.bal))
            {
          curr2->b.ad.bal=curr2->b.ad.bal+bal;
          curr2->b.la.amountl=bal;
          curr2->b.la.flagl=1;
          curr2->b.la.timel=t;
          curr2->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofpnb1;
    }

    empneftpnb:

    cout<<"\nEnter account no. of sender's account ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. of receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"pnb")==0)
        {
            node *curr5;
           curr5=t1.searchaccount(root2,rloginid);
        if(curr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofpnb1;
          }
        else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto empofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr2->b.ad.bal)
            {
              curr2->b.ad.bal=curr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
              curr5->b.ad.bal=curr5->b.ad.bal+bal;
             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofpnb1;
            }
         }
        }

        else if(strcmp(bname,"sbi")==0)
        {
            node *curr4;
           curr4=t1.searchaccount(root1,rloginid);
        if(curr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr2->b.ad.bal)
            {
              curr2->b.ad.bal=curr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
              curr4->b.ad.bal=curr4->b.ad.bal+bal;

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofpnb1;
            }
         }
        }

        else if(strcmp(bname,"axis")==0)
        {
            node *curr6;
           curr6=t1.searchaccount(root3,rloginid);
        if(curr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr2->b.ad.bal)
            {
              curr2->b.ad.bal=curr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr2->b.ad.bal;
              curr6->b.ad.bal=curr6->b.ad.bal+bal;

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofpnb1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto empofpnb1;
         }

         goto empofpnb1;
    }

    empdeletepnb:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {

          root2=t1.deletee(root2,loginid);
          cout<<"\nAccount successfully Deleted ";

          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();

          goto empofpnb1;
    }

    empupdatepnb:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"pnb");
    curr2=t1.searchforemp(root2,loginid,bankname);
    if(curr2==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofpnb1;
    }
    else
    {
          char ch;

          cout<<"\nWant to Change Name of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char name[50];
          cout<<"\nEnter new Name of Account holder : ";
          fflush(stdin);
          gets(name);
          strcpy(curr2->b.ad.name,name);
          }

          cout<<"\nWant to Change Address of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char add[100];
          cout<<"\nEnter new Address of Account holder : ";
          fflush(stdin);
          gets(add);
          strcpy(curr2->b.ad.add,add);
          }
          cout<<"\nWant to Change Age of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           int age;
          cout<<"\nEnter new age of Account holder : ";
          cin>>age;
          curr2->b.ad.age=age;
          }
          cout<<"\nAccount successfully Updated ";

          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();

          goto empofpnb1;
    }

   userofpnb :
    {
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bankname,"pnb");
    node *ccurr2=t1.search(root2,loginid,pass,bankname);
    if(ccurr2==NULL)
    {
        cout<<"\nInvalid account no. or password ";
        cout<<endl;
        goto startofpnb;
    }
    else
    {userofpnb1:
        cout<<endl<<endl;
	cout<<"******** WELCOME TO PUNJAB NATIONAL BANK OF INDIA ***********" ;
	select3() ;
	switch(service)
	{
		case 1 : goto usershowpnb ;
				 break ;
		case 2 : goto usershowbalpnb ;
				 break ;
		case 3 : goto useropenfdpnb ;
				 break ;
        case 4 : goto useropenloanpnb ;
                 break ;
        case 5 : goto userneftpnb ;
                  break;
		case 6 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofpnb ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto userofpnb ;
				  break ;
	}
    }

    usershowpnb:
        ccurr2->b.getbankdata();
        goto userofpnb1;

    usershowbalpnb:
        cout<<"\nBalance in Account = "<<ccurr2->b.ad.bal;
        goto userofpnb1;

    useropenfdpnb :

        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(ccurr2->b.ad.bal > bal)
            {
          ccurr2->b.ad.bal=ccurr2->b.ad.bal-bal;
          ccurr2->b.fd.amountf=bal;
          ccurr2->b.fd.flag=1;
          ccurr2->b.fd.time=t;
          ccurr2->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<ccurr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofpnb1;

    useropenloanpnb :


        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*ccurr2->b.ad.bal))
            {
          ccurr2->b.ad.bal=ccurr2->b.ad.bal+bal;
          ccurr2->b.la.amountl=bal;
          ccurr2->b.la.flagl=1;
          ccurr2->b.la.timel=t;
          ccurr2->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<ccurr2->b.ad.bal;
          fstream fp2;
          fp2.open("cpnb.dat",ios::out|ios::binary);

          serialize(root2,fp2);
          fp2.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofpnb1;

   userneftpnb :


        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. of receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"pnb")==0)
        {
            node *ccurr5;
           ccurr5=t1.searchaccount(root2,rloginid);
        if(ccurr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofpnb1;
          }
          else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto userofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr2->b.ad.bal)
            {
              ccurr2->b.ad.bal=ccurr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr2->b.ad.bal;
              ccurr5->b.ad.bal=ccurr5->b.ad.bal+bal;

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

             serialize(root2,fp2);
             fp2.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofpnb1;
            }
         }
        }

        else if(strcmp(bname,"sbi")==0)
        {
            node *ccurr4;
           ccurr4=t1.searchaccount(root1,rloginid);
        if(ccurr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr2->b.ad.bal)
            {
              ccurr2->b.ad.bal=ccurr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr2->b.ad.bal;
              ccurr4->b.ad.bal=ccurr4->b.ad.bal+bal;

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofpnb1;
            }
         }
        }

        else if(strcmp(bname,"axis")==0)
        {
            node *ccurr6;
           ccurr6=t1.searchaccount(root3,rloginid);
        if(ccurr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofpnb1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr2->b.ad.bal)
            {
              ccurr2->b.ad.bal=ccurr2->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr2->b.ad.bal;
              ccurr6->b.ad.bal=ccurr6->b.ad.bal+bal;

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofpnb1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto userofpnb1;
         }

         goto userofpnb1;
    }


     enterempofpnb:
         {
         cout<<"\nEnter employeeid : ";
         cin>>empid;
         cout<<"\nEnter employee password : ";
         getpass(emppass);
         strcpy(empbank,"pnb");
         eroot2=t2.empinsert(eroot2,empid,emppass,empbank);
         fstream efp2;
         efp2.open("epnb.dat",ios::out|ios::binary);

         eserialize(eroot2,efp2);
         efp2.close();
         goto startofpnb;
         }


       startofaxis :
	cout<<"******** WELCOME TO AXIS BANK OF INDIA ***********" ;
	select1() ;
	switch(user)
	{
		case 1 : goto empofaxis ;
				 break ;
		case 2 : goto userofaxis ;
				 break ;
		case 3 : goto enterempofaxis;
				 break ;
		case 4 : goto startofprog ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto startofaxis ;
				  break ;
	}

    empofaxis :
    //int empid;
    //char emppass[20];
    //char empbank[40];
	cout<<"\nEnter employee id : ";
	cin>>empid;
	cout<<"\nEnter employee password : ";
	getpass(emppass);
	strcpy(empbank,"axis");
	enode *ecurr3;
	ecurr3=t2.empsearch(eroot3,empid,emppass,empbank);
	if(ecurr3==NULL)
           {
               cout<<"\nInvalid employee id or password ";
               cout<<endl;
               goto startofaxis;
           }
    else
    {empofaxis1 :
        cout<<endl<<endl;
	cout<<"******** WELCOME TO AXIS BANK OF INDIA ***********" ;
	select2() ;
	switch(bemp)
	{
		case 1 : goto empopenaccountaxis ;
				 break ;
		case 2 : goto empshowaccountaxis ;
				 break ;
		case 3 : goto empdepositaxis ;
				 break ;
		case 4 : goto empwithdrawlaxis;
				 break ;
		case 5 : goto empopenfdaxis ;
				 break ;
		case 6 : goto empopenloanaxis ;
				 break ;
		case 7 : goto empneftaxis ;
				 break ;
	    case 8 : goto empdeleteaxis ;
	             break;
	    case 9 :goto empupdateaxis ;
	             break;
		case 10 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofaxis ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto empofaxis ;
				  break ;
	}
    }

	empopenaccountaxis :
    //int loginid;
    //char pass[50],bname[50];
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bname,"axis");
    root3=t1.insert(root3,loginid,pass,bname);
    if(flag==0)
    {
        cout<<"\nRecord Successfully added";
        fstream fp3;
    fp3.open("caxis.dat",ios::out|ios::binary);

    serialize(root3,fp3);
    fp3.close();
    }
    goto empofaxis1;

    empshowaccountaxis :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    //char bankname[50];
    strcpy(bankname,"axis");
    node *curr3;
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists";
        goto empofaxis1;
    }
    else
    {
        curr3->b.getbankdata();
        goto empofaxis1;
    }

    empdepositaxis :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be deposited : ";
        cin>>bal;
        if(bal>0)
        {
          curr3->b.ad.bal=curr3->b.ad.bal+bal;
          cout<<"\nAnmount Deposited successfully ";
          cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofaxis1;
    }

    empwithdrawlaxis:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {
        int bal;
        cout<<"\nEnter amount to be withdrawl : ";
        cin>>bal;
        if(bal>0)
        {
            if(curr3->b.ad.bal>bal)
            {
          curr3->b.ad.bal=curr3->b.ad.bal-bal;
          cout<<"\nAmount successfully withdrawl ";
          cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofaxis1;
    }

    empopenfdaxis:

     cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(curr3->b.ad.bal > bal)
            {
          curr3->b.ad.bal=curr3->b.ad.bal-bal;
          curr3->b.fd.amountf=bal;
          curr3->b.fd.flag=1;
          curr3->b.fd.time=t;
          curr3->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofaxis1;
    }

    empopenloanaxis :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1 ;
    }
    else
    {
        int bal,t;
        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*curr3->b.ad.bal))
            {
          curr3->b.ad.bal=curr3->b.ad.bal+bal;
          curr3->b.la.amountl=bal;
          curr3->b.la.flagl=1;
          curr3->b.la.timel=t;
          curr3->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto empofaxis1;
    }

    empneftaxis :

    cout<<"\nEnter account no. of sender's account ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {
        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. of receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"axis")==0)
        {
            node *curr6;
           curr6=t1.searchaccount(root3,rloginid);
        if(curr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofaxis1;
          }
          else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto empofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr3->b.ad.bal)
            {
              curr3->b.ad.bal=curr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
              curr6->b.ad.bal=curr6->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofaxis1;
            }
         }
        }

        else if(strcmp(bname,"sbi")==0)
        {
            node *curr4;
           curr4=t1.searchaccount(root1,rloginid);
        if(curr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr3->b.ad.bal)
            {
              curr3->b.ad.bal=curr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
              curr4->b.ad.bal=curr4->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofaxis1;
            }
         }
        }

        else if(strcmp(bname,"pnb")==0)
        {
            node *curr5;
           curr5=t1.searchaccount(root2,rloginid);
        if(curr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto empofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=curr3->b.ad.bal)
            {
              curr3->b.ad.bal=curr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<curr3->b.ad.bal;
              curr5->b.ad.bal=curr5->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto empofaxis1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto empofaxis1;
         }

         goto empofaxis1;
    }

    empdeleteaxis:

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {

          root3=t1.deletee(root3,loginid);
          cout<<"\nAccount successfully Deleted ";

          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();

          goto empofaxis1;
    }

    empupdateaxis :

    cout<<"\nEnter account no. : ";
    cin>>loginid;
    strcpy(bankname,"axis");
    curr3=t1.searchforemp(root3,loginid,bankname);
    if(curr3==NULL)
    {
        cout<<"\nNO such account exists ";
        goto empofaxis1;
    }
    else
    {
          char ch;

          cout<<"\nWant to Change Name of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char name[50];
          cout<<"\nEnter new Name of Account holder : ";
          fflush(stdin);
          gets(name);
          strcpy(curr3->b.ad.name,name);
          }

          cout<<"\nWant to Change Address of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           char add[100];
          cout<<"\nEnter new Address of Account holder : ";
          fflush(stdin);
          gets(add);
          strcpy(curr3->b.ad.add,add);
          }
          cout<<"\nWant to Change Age of Account holder : ";
          cout<<"\nPress 'y' for yes 'n' for no : ";
          cin>>ch;
          if(ch=='y'||ch=='Y')
          {
           int age;
          cout<<"\nEnter new age of Account holder : ";
          cin>>age;
          curr3->b.ad.age=age;
          }
          cout<<"\nAccount successfully Updated ";

          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();

          goto empofaxis1;
    }

   userofaxis :
    {
    cout<<"\nEnter account no. : ";
    cin>>loginid;
    cout<<"\nEnter customer password : ";
    getpass(pass);
    strcpy(bankname,"axis");
    node *ccurr3=t1.search(root3,loginid,pass,bankname);
    if(ccurr3==NULL)
    {
        cout<<"\nInvalid account no. or password ";
        cout<<endl;
        goto startofaxis;
    }
    else
    {userofaxis1:
        cout<<endl<<endl;
	cout<<"******** WELCOME TO AXIS BANK OF INDIA ***********" ;
	select3() ;
	switch(service)
	{
		case 1 : goto usershowaxis ;
				 break ;
		case 2 : goto usershowbalaxis ;
				 break ;
		case 3 : goto useropenfdaxis ;
				 break ;
        case 4 : goto useropenloanaxis ;
                 break ;
        case 5 : goto userneftaxis ;
                  break;
		case 6 : cout<<"\nYou Have Successfully Log Out!!!!!!!!!\n"<<endl ;
				 goto startofaxis ;
				 break ;
		default : cout<<"\nYou Entered A Wrong Choice" ;
				  goto userofaxis ;
				  break ;
	}
    }

    usershowaxis :
        ccurr3->b.getbankdata();
        goto userofaxis1;

    usershowbalaxis :
        cout<<"\nBalance in Account = "<<ccurr3->b.ad.bal;
        goto userofaxis1;

    useropenfdaxis :

        int bal,t;
        cout<<"\nEnter amount of Fixed Deposit : ";
        cin>>bal;
        cout<<"\nEnter the Fixed Deposit time : ";
        cin>>t;
        if(bal>0)
        {
            if(ccurr3->b.ad.bal > bal)
            {
          ccurr3->b.ad.bal=ccurr3->b.ad.bal-bal;
          ccurr3->b.fd.amountf=bal;
          ccurr3->b.fd.flag=1;
          ccurr3->b.fd.time=t;
          ccurr3->b.fd.rate=fdrate;
          cout<<"\nFixed Account created ";
          cout<<"\nUpdated balance = "<<ccurr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
            }
            else
            {
                cout<<"\nInsufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofaxis1;

    useropenloanaxis :


        cout<<"\nEnter amount of Loan : ";
        cin>>bal;
        cout<<"\nEnter the Loan time : ";
        cin>>t;
        if(bal>0)
        {
            if(bal <= (10*ccurr3->b.ad.bal))
            {
          ccurr3->b.ad.bal=ccurr3->b.ad.bal+bal;
          ccurr3->b.la.amountl=bal;
          ccurr3->b.la.flagl=1;
          ccurr3->b.la.timel=t;
          ccurr3->b.la.ratel=loanrate;
          cout<<"\nLoan account created ";
          cout<<"\nUpdated balance = "<<ccurr3->b.ad.bal;
          fstream fp3;
          fp3.open("caxis.dat",ios::out|ios::binary);

          serialize(root3,fp3);
          fp3.close();
            }
            else
            {
                cout<<"\nLoan can't be sanctioned ....... Insufficient balance ";
            }
        }
        else
            cout<<"\nInvalid amount entered : ";

        goto userofaxis1;

   userneftaxis :


        int rloginid;
        char bname[50];
        cout<<"\nEnter account no. of receiver : ";
        cin>>rloginid;
        cout<<"\nEnter bankname of receiver : ";
        fflush(stdin);
        gets(bname);
        if(strcmp(bname,"axis")==0)
        {
            node *ccurr6;
           ccurr6=t1.searchaccount(root3,rloginid);
        if(ccurr6==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofaxis1;
          }
          else if(loginid==rloginid)
          {
              cout<<"\nMoney can't be transferred to same account ";
              goto userofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr3->b.ad.bal)
            {
              ccurr3->b.ad.bal=ccurr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr3->b.ad.bal;
              ccurr6->b.ad.bal=ccurr6->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();
            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofaxis1;
            }
         }
        }

        else if(strcmp(bname,"sbi")==0)
        {
            node *ccurr4;
           ccurr4=t1.searchaccount(root1,rloginid);
        if(ccurr4==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr3->b.ad.bal)
            {
              ccurr3->b.ad.bal=ccurr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr3->b.ad.bal;
              ccurr4->b.ad.bal=ccurr4->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();

             fstream fp1;
             fp1.open("csbi.dat",ios::out|ios::binary);

            serialize(root1,fp1);
            fp1.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofaxis1;
            }
         }
        }

        else if(strcmp(bname,"pnb")==0)
        {
            node *ccurr5;
           ccurr5=t1.searchaccount(root2,rloginid);
        if(ccurr5==NULL)
          {
            cout<<"\nNO such receiver's account exists : ";
            goto userofaxis1;
          }
        else
        {
        int bal;
        cout<<"\nEnter amount to be transferred : ";
        cin>>bal;
        if(bal>0)
        {
            if(bal<=ccurr3->b.ad.bal)
            {
              ccurr3->b.ad.bal=ccurr3->b.ad.bal-bal;
               cout<<"\nAnmount Transferred successfully ";
              cout<<"\nUpdated balance = "<<ccurr3->b.ad.bal;
              ccurr5->b.ad.bal=ccurr5->b.ad.bal+bal;

             fstream fp3;
             fp3.open("caxis.dat",ios::out|ios::binary);

            serialize(root3,fp3);
            fp3.close();

             fstream fp2;
             fp2.open("cpnb.dat",ios::out|ios::binary);

            serialize(root2,fp2);
            fp2.close();


            }
            else
                cout<<"\nInsufficient balance ";
        }

        else
            {
                cout<<"\nInvalid amount entered : ";
                goto userofaxis1;
            }
         }
        }

         else
         {
             cout<<"\nWrong bankname entered ";
             goto userofaxis1;
         }

         goto userofaxis1;

    }

     enterempofaxis:
         {
         cout<<"\nEnter employeeid : ";
         cin>>empid;
         cout<<"\nEnter employee password : ";
         getpass(emppass);
         strcpy(empbank,"axis");
         eroot3=t2.empinsert(eroot3,empid,emppass,empbank);
         fstream efp3;
         efp3.open("eaxis.dat",ios::out|ios::binary);

         eserialize(eroot3,efp3);
         efp3.close();
         goto startofaxis;
         }


return 0;
}
void select1()
{
	cout<<"\nEnter 1 For Bank Employee" ;
	cout<<"\nEnter 2 For Personal User" ;
	cout<<"\nEnter 3 To Enter Bank Employee" ;
	cout<<"\nEnter 4 To Go Back" ;
	cout<<"\nEnter Your Choice : " ;
	cin>>user ;
}
void select2()
{
	cout<<"\nEnter 1 To Open An Account" ;
	cout<<"\nEnter 2 To Show Account Details" ;
	cout<<"\nEnter 3 To Deposit Amount" ;
	cout<<"\nEnter 4 To Withdraw Amount" ;
	cout<<"\nEnter 5 To Open An Fixed Account" ;
	cout<<"\nEnter 6 To Pass An Loan" ;
	cout<<"\nEnter 7 NEFT" ;
	cout<<"\nEnter 8 To Delete An Account";
	cout<<"\nEnter 9 To Update An Account";
	cout<<"\nEnter 10 To Log Out" ;
	cout<<"\nEnter Your Choice : " ;
	cin>>bemp ;
}
void select3()
{
	cout<<"\nEnter 1 To Show Account Details" ;
	cout<<"\nEnter 2 For Balance Enquiry" ;
	cout<<"\nEnter 3 To Open A Fixed Account" ;
	cout<<"\nEnter 4 To Request A Loan" ;
	cout<<"\nEnter 5 For NEFT" ;
	cout<<"\nEnter 6 To Log Out" ;
	cout<<"\nEnter Your Choice : " ;
	cin>>service ;
}

