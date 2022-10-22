



#include <iostream>
#include <string>
	
using namespace std;

                 //the structurs used in this progarm: //


struct record
{
    int PID;
    string Pname1;
    string Pname2;
    int PNo;
    int Page;
    string Healthstat;
};

struct Node
{
    record Precord;
    Node *next;
};

//****************************************************************************//

Node *head;


                    // the function to print all records //

void printRec(void)
{
      if (!head)
    {
        cout<<"\n                 ****There are no records****"<<endl;
    
    }
    cout<<"____________________________________________________________________"<<endl;
    cout<<"\n                   The patients records: "<<endl;
    Node *curr;
    curr=head;
   while(curr!=NULL)
   {
       
       cout<<"\n**************************************************************\n"<<endl;
       cout<<"patient ID: "<<curr->Precord.PID<<endl;
       cout<<"patient Name: "<<curr->Precord.Pname1<<" "<<curr->Precord.Pname2<<endl;
       cout<<"patient Number: "<<curr->Precord.PNo<<endl;
       cout<<"patient age: "<<curr->Precord.Page<<endl;
       cout<<"patient Health status: "<<curr->Precord.Healthstat<<endl;
       curr=curr->next;
   }
   cout<<"___________________________________________________________________"<<endl;
}
//****************************************************************************//


            //this function is to check if a record already exists//
            
bool checkRec(int id)
{
    Node *curr;
    curr=head;
       while (curr!=NULL && curr->Precord.PID!=id)
   {
     
       curr=curr->next;
   }
   
   if(curr->Precord.PID==id)
   {
      return true;
   }
      else
      return false;
       
   
}
//****************************************************************************//


                   // the function to insert a record //

void InsertRec(int id, string name, string Lname, int num, int age, string HS)
{
    Node *curr, *prev=NULL, *newNode;
    
    newNode=new Node();
    newNode->Precord.PID=id;
    newNode->Precord.Pname1=name;
    newNode->Precord.Pname2=Lname;
    newNode->Precord.PNo=num;
    newNode->Precord.Page=age;
    newNode->Precord.Healthstat=HS;
    if(!head)
    {
        head=newNode;
        newNode->next=NULL;
    }
    else
    {
        
    curr=head;
    while (curr!=NULL && curr->Precord.PID<id)
    {
        prev=curr;
        curr=curr->next;
    }
    if(prev==NULL)
    {
        head=newNode;
        newNode->next=curr;
    }
    else{
        prev->next=newNode;
        newNode->next=curr;
    }
}
cout<<"\n                   ***The record is inserted***\n"<<endl;
}
//****************************************************************************//




                    // the function to delete a record //

int deleteRecord(int id)
{
    Node *curr , *prev;
    if (!head)
    {
        cout<<"\n      ****There are no records to be deleted****\n"<<endl;
    
    }
    
    else if(head->Precord.PID==id)
    {
        curr=head->next;
        delete head;
        head=curr;
    }
    else
    {
    curr=head;
    
    
     while(curr!=NULL && curr->Precord.PID!=id)
      {
          prev=curr;
          curr=curr->next;
      }
      
    if(curr==NULL)
      {
         return -1;
       
      }
      
    else
    {
        prev->next=curr->next;
         delete curr;
         return 0;
    }
   
   }

}

//****************************************************************************//


                 // the function to search for a record //

void search(int id)
{
     if (!head)
    {
        cout<<"\n                 ****There are no records****\n"<<endl;
         return;
    }
    
    Node *curr=head;
    while(curr!=NULL)
    {
        if(curr->Precord.PID==id)
        {
            cout<<"\n             ****The record is found****\n"<<endl;
            return;
        }
        else
       { 
           curr=curr->next;
       }
    }
    
    if(curr==NULL)
    {
        cout<<"\n               ****The record is not found****\n"<<endl;
    }
}
//****************************************************************************//



                            //the main function//
int main()
{
   	int choice, ID, NUM, AGE ;
   	string  NAME1, NAME2;
   	string HEALTHS;
   	bool x=false;
   	int chk;
	do
	{
	    cout<<"****MENU****\n";
		cout<<"1. Insert a record"<<"\n";
		cout<<"2. display a record"<<"\n";
	    cout<<"3. delete a record"<<"\n";
		cout<<"4. search"<<"\n";
		cout<<"5. exit"<<"\n";
		cout<<"Enter your choice (1-5)"<<"\n";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
			
				cout<<"Enter patient ID: ";
				cin>>ID;
				cout<<"Enter patient first and last name: ";
				cin>>NAME1>>NAME2;
				cout<<"Enter patient number: ";
				cin>>NUM;
				cout<<"Enter patient age: ";
				cin>>AGE;
				cout<<"Enter patient Health status (stable/unstable): ";
				cin>>HEALTHS;
				
				
				if(x)
				{
				    cout<<"\n        ****The record already exists**** \n";
				   
				}
				else
				InsertRec(ID, NAME1, NAME2, NUM, AGE, HEALTHS);
				
			 	  break;
				
				  case 2:
					printRec();
					cout<<endl;
					   break;
					   
					   case 3:
					      cout<<"\nEnter the ID for the record you want to delete: \n";
					      cin>>ID;
					      chk=deleteRecord(ID);
				    	  if(chk==-1)
				    	  cout<<"\n                ***The record doesn't exist***\n";
				    	  
				    	  else if (chk==0)
				    	  cout<<"\n                ****The record is deleted**** \n";
				    	  
				          cout<<endl;
						     break;
						     
						     case 4:
						        cout<<"\n Enter the ID for the record you want to search: \n";
					            cin>>ID;
					            search(ID);
						          break;
						          
						          case 5:
						            break;
						            
						            default:
							          cout<<"\n ****The number you enterd is out of range****\n";
							
						
				
		        }
		
	    }
	while(choice!=5) ;

    return 0;
    
}

                            //end of the progarm//
