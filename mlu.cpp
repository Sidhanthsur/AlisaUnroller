#include<iostream>
#include<stdio.h>

#include<string.h>
#include<fstream>
using namespace std;

/*
 * INPUT FORMAT
 * Instrution_ID	Parent_Instruction	Loop_Type	Loop_Skip	Initial_Value	Condition_type	Final_Value	Child Loop_Level	
 * 
 * */
 /*
  * 1.add end of loop in the instruction format
  * 2.then end of loop level has to be to match parent
  * 3.execute instructions within for loop
  * 4.change for,while,do while according to the condition
  * 5.make two functions as one function 
  * */
  

	 
	 
	 






void unroll(string id, char pi[],int lt,string ls,int in,int co,int fi,int child)
{
	int i;
	switch(co)
	/*
	 * 1	->	<
	 * 2	->	<=
	 * 3	->	>
	 * 4	->	>=
	 * */
	{
		case 1:
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i<fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";
		}
		break;
		case 2:
		
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i<=fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";//i denotes the ith time instructions are being scheduled
		}
		break;
		case 3:
	
		cout<<"\n unrolling loop with id :"<<id;
		for(i=0;i>fi;i++)
		{
			cout<<"\n"<<i<<": Instructions scheduling and executing ";
		}
		break;
	}
}

void unrollchild(string nid, char npi[],int nlt,string nls,int nin,int nco,int nfi,int nchild) //not needed
{ int y=1;
	string id;
	 char pi[2];
	 int lt;
	 string ls;
	 int il;
	 int in,co,fi;
	 string lot;
int child;
	ifstream fc("input.txt");
	 while(y==1)
	 {
	 fc>>id;
	 fc>>pi;
	 fc>>lt;
	 fc>>ls>>in>>co>>fi>>child>>il;
	 if(id == nid)
	 {
		  fc>>id;
	 fc>>pi;
	 fc>>lt;
	 fc>>ls>>in>>co>>fi>>child>>il;
	 if(child > 0)
	 {
		 unrollchild(id,pi,lt,ls,in,co,fi,child);
	 }
	 else
	 unroll(id, pi,lt,ls,in,co,fi,child);
	 
	 unroll(nid, npi,nlt,nls,nin,nco,nfi,nchild);
	 y=0;
 }
}
fc.close();
}

void table(string nid, char npi[],int nlt,string nls,int nin,int nco,int nfi,int nchild)
{
	//cout<<"\n hitable";
	//ifstream f2;
	 ifstream f2("input.txt");
	 string id;
	 char pi[2];
	 string ppi[20];
	 int lt;
	 string ls;
	 int i,j;
	 int m;
	 /*
	  * ffi stores the final value in the table
	  * ppi stores the parent instruction in the table
	  * ti stores the total index in the table
	  * */
	 int ffi[20];
	 int in,co,fi;
	 string lot;
	 int il;
int child;
	int ll[20];
	int ti[20];
	/* Initially we put the instruction with nested loop level as 0
	 * we then save it in table 
	 * */
	ll[0]=1;
	ti[0]=nfi;
	//cout<<"\n ti="<<ti[0];
	i=1;
	j=1;
	ppi[0]=npi;
	//cout<<"ppi "<<ppi[0];
	ffi[0]=nfi;
	int k=0;
	unroll(nid, npi,nlt,nls,nin,nco,nfi,child);//This is to unroll the instruction with nested loop level 0
	
	while(!f2.eof())
	 {
		 k++;
	 f2>>id;
	 f2>>pi;
	 f2>>lt;
	
	 f2>>ls>>in>>co>>fi>>child>>il;
	 //cout<<"\n sid id"<<id;
	 if(id == nid)
	 { //cout<<"\nlol";
		 while(!f2.eof())
		 { 	k++;
			f2>>id;
			f2>>pi;
			f2>>lt;
			f2>>ls>>in>>co>>fi>>child>>il;
			/* The following functions are for unrolling instructions that follow after the 
			 * loops but belong to a particular nested level
			 * we put initial value as zero and final value as the same number 
			 * of times its parent instruction executes
			 * */
		 if(in == 0 && fi == 0)
		 {//cout<<endl<<i<<"\n yay";
			 for(m=0;m<k-1;m++)
	 {
		 if(il == ll[m])
		 {//cout<<"woojoo";
			 unroll(id, pi,lt,ls,in,co,ffi[m],child);
			 
		 }
	 }
 }
		/*
		 * The following lines are to put the instructions with nested loop >1
		 * in the table.
		 * The total index value is calculated by multiplying the final value to the total index of previous instruction
		 * EXAMPLE:
		 * ID		Final value		Total index			LoopLevel
		 * I1			5				5  					1
		 * I2			6				30(6*Prev ti)		2
		 * I3			0				5					1
		 * */ 
	  ffi[i]=fi;
	 ppi[i]=pi;
	 ll[i]=il;
	 ti[i]=fi*ti[i-1];
	 //if(ti[i] != 750)
	 unroll(id, pi,lt,ls,in,co,ti[i],child);
	 
	 cout<<"\n Table value ffi "<<ffi[i]<<"ppi "<<ppi[i]<<"ll "<<ll[i]<<"ti "<<ti[i];
	 i++;
	 cout<<endl<<"i "<<i<<endl<<"k "<<k;
	 

}
break;

}
}
f2.close();

}
	 
		 
	
	
		
	
			

int main()
{
	
	/*
	 * INITIALIZATION
	 **/
	 ifstream f1;
	 string id;
	 char pi[2];
	 int lt;
	 int il;
	 string ls;
	 int in,co,fi;
	 string lot;
int child;
	 
	 /*********************************************SECTION ENDS **********************************************/
	 
	 
	 
	 /*
	  * RREADING FROM THE INPUT FILE
	  * 
	  * */
	 f1.open("input.txt");
	 while(!f1.eof())
	 {
	 f1>>id;
	 f1>>pi;
	 f1>>lt;
	 f1>>ls>>in>>co>>fi>>child>>il;
	 if(lt == 1)
	 lot="For";
	 else if(lt == 2)
	 lot="while";
	 else if(lt == 3)
	 lot="do-while";
	 else if(lt == 4)
	 lot ="if-else";
	 else
	 lot="no loop";	
	
 
 
 if((strcmp(pi,"o") == 0) && lt != 0 && child == 0)//if its a instruction that has no child
	 {
		unroll(id, pi,lt,ls,in,co,fi,child);
	 }
	 else if((strcmp(pi,"o") == 0) && lt >0 && child == 1)//instruction with a child
	  {
		  table(id,pi,lt,ls,in,co,fi,child);
		//  unrollchild(id,pi,lt,ls,in,co,fi,child);
	}
	  else//instruction other than loop instructions
	  cout<<" ";
	 
		  
	 
 
 
}
f1.close();
 /*************************************************SECTION ENDS****************************************************/
	 f1.open("input.txt");
	 while(!f1.eof())
	 {
	 f1>>id;
	 f1>>pi;
	 f1>>lt;
	 f1>>ls>>in>>co>>fi>>child>>il;
	 if(lt == 1)
	 lot="For";
	 else if(lt == 2)
	 lot="while";
	 else if(lt == 3)
	 lot="do-while";
	 else if(lt == 4)
	 lot ="if-else";
	 else
	 lot="no loop";	
	 
	 cout<<"\nID="<<id<<"\nParent instruction="<<pi<<"\nLoop type="<<lot<<"\nloop skip"<<ls<<"\nIntial value="<<in<<"\nConditional type="<<co<<"\nfinal value ="<<fi<<"\n child="<<child<<"\n\n"; 
 }

f1.close();
return 0;
}
