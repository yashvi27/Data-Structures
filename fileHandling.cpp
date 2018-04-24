#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>


using namespace std;

class record
{
    char name[20];
    char address[50];
    int tno;

public:

    void getdata()
    {
        cout<<"\n Name :";
        cin>>name;

        cout<<"\nAddress :";
        cin>>address;

        cout<<"\nPhone number : ";
        cin>>tno;
    }

    void showdata()
    {
        cout<<"\n\nName : "<<name;
        cout<<"\nAddress : "<<(address);
        cout<<"\nPhone number : "<<tno;
    }

    int matchnm(char a[20])
    {
        return( strcmp(name,a) );
    }

    void showtell()
    {
        cout<<endl<<tno;
    }

    void modifyadd()
    {
        cout<<"\n\nOld address: "<<address;
        cout<<"\n\nNew address:  ";
        cin>>address;

    }

    void modifypno()
    {
        cout<<"\n\nOld number : ";
        cout<<tno;
        cout<<"\n\nNew number:";
        cin>>tno;
    }
} s1;

int k=1;
int main()
{
  int i,j,l,m;
  while(k)
  {
	cout<<endl<<endl;

	ifstream fin;
	ofstream fout;
	fstream f;

	cout<<"\n\n\tMain Menu\n";
	cout<<"\t1.Get records\n"
	    <<"\t2.Append records \n"
	    <<"\t3.Display records \n"
	    <<"\t4.Exit\n";
	    cout<<"Enter choice  ";
	    cin>>j;
		switch(j)
		 {
		    case 1:cout<<"\nNo of records : ";
			   cin>>l;
			   fout.open("test.txt",ios::out);
			   for(i=0;i<l;i++)
			   {
			     s1.getdata();
			     fout.write( (char*)&s1,sizeof(s1));
			   }
			   fout.close();
			   break;

		    case 2:cout<<"\n\nNo of records to add:  ";
			   cin>>m;
			   fout.open("test.txt",ios::app);
			   for(i=0;i<m;i++)
			   {
			     s1.getdata();
			     fout.write((char*)&s1,sizeof(s1) );
			   }
			   cout<<"\n\nRecords Added Successfully!!\n";
			   fout.close();
			   break;

		    case 3:
               fin.open("test.txt",ios::in);
			   while(fin.read((char*)&s1,sizeof(s1)) )
			   {
                    cout<<endl;
                    s1.showdata();
			   }
			   fin.close();
			   break;

		    case 4:
		        k=0;        //terminate :exit condition
                break;
		 }
  }
  int y,found,recno;
  while(1)
  {
	//system("cls");


	ifstream fin;
	ofstream fout;
	fstream f;
	cout<<"\n\n\tSub menu\n";
	cout<<"\t1.Search telephone no\n"
	    <<"\t2.Modify address \n"
	    <<"\t3.Modify telephone no \n"
	    <<"\t4.Deleting \n"
	    <<"\t5.Exit\n";
	    cout<<"Enter choice    ";
	    cin>>j;
		switch(j)
		 {
		     case 1:
               char x[20];
               found=0;
			   cout<<"\nName:";
                cin>>x;
			   fin.open("test.txt",ios::in);
			   while(fin.read((char*)&s1,sizeof(s1)))
			   {
			     y=s1.matchnm(x);
			     if(y==0)
			     {
			       cout<<"\n\nMatch Found\n Old telephone number :";
			       s1.showtell();
			       found=1;
			     }
			   }
			   fin.close();
			   if(found==0)
			   {
			     cout<<"\n\nSorry , No Match";
			   }
			   break;

		     case 2:
                recno=0;
			    found=0;
			   cout<<"\nName:";
			   cin>>(x);
			   fin.open("test.txt",ios::in);

			   //to find the match
			   while(fin.read((char*)&s1,sizeof(s1)))
			   {
			     y=s1.matchnm(x);
			     if(y==0)
			     {
			       cout<<"\n\nMatch found\n";
			       found=1;
			     }
			     else
			     recno++;
			   }

			   fin.close();

			   if(found==0)
			   {
			     cout<<"\n\nNo Match \n";
			   }
			   else
			   {
			     f.open("test.txt",ios::in|ios::out);
			     f.seekg(recno*sizeof(s1),ios::beg);
			     fin.read((char*)&s1,sizeof(s1));
			     s1.modifyadd();
			     f.seekg(recno*sizeof(s1),ios::beg);
			     f.write((char*)&s1,sizeof(s1));
			     f.close();
			     cout<<"\n\nAddress modified !!\n\n";
			     s1.showdata();
			   }

                break;

		     case 3:
                recno=0;
			    found=0;
			   cout<<"\nName:";
			   cin>>(x);

			   fin.open("test.txt",ios::in);
			   while(fin.read((char*)&s1,sizeof(s1)))
			   {
			     y=s1.matchnm(x);
			     if(y==0)
			     {
			       cout<<"\n\nMatch found\n";
			       found=1;
			     }
			     else
			     recno++;
			   }
			   fin.close();
			   if(found==0)
			   {
			     cout<<"\n\nNo Match Found\n";
			   }
			   else
			   {
			     f.open("test.txt",ios::in|ios::out);
			     f.seekg(recno*sizeof(s1),ios::beg);
			     fin.read((char*)&s1,sizeof(s1));
			     s1.modifypno();
			     f.seekg(recno*sizeof(s1),ios::beg);
			     f.write((char*)&s1,sizeof(s1));
			     f.close();

			     cout<<"\n\nPhone number modified!!\n\n";
                 s1.showdata();
			   }


			   break;

		     case 4:
                found=0;
			    cout<<"\nName :";
			    cin>>x;
			    fin.open("test.txt",ios::in);
			    fout.open("newtest.txt",ios::out);

			    while(fin.read((char*)&s1,sizeof(s1)))
			    {
                 y=s1.matchnm(x);
			     if(y==0)
			     {
			       cout<<"\n\nMatch found\nRecord to be deleted\n";
			       s1.showdata();
			       found=1;
			     }
			     else
			     fout.write((char*)&s1,sizeof(s1));
			    }
			    fin.close();
			    fout.close();
			       if(found==0)
			       {
                    cout<<"\n\nNo Match Found !!\n";
			       }
			       else
			       {
                    if( remove( "test.txt" ) != 0 )
                        perror( "Error deleting file" );
                    else
                        puts( "\nOld File successfully deleted\n\nUpdated File : " );

                fin.open("newtest.txt",ios::in);
				  while(fin.read((char*)&s1,sizeof(s1)))
				 {
                    cout<<"\n";
                    s1.showdata();
				 }
			       }
			   fin.close();
			   break;

		     case 5:
		         return 0;
		 }
  }
}
