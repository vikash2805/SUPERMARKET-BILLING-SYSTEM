//project on super market billing system

#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
       int Product_Code;
       float Price;
       float Discount;
       string Product_Name;

       public:
       void menu();
       void administrator();
       void Customer();
       void add();
       void edit();
       void rem();
       void list();
       void receipt();
};

void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t      D-MART MAIN MENU      \n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t\t                            \n";

    cout<<"\t\t\t\t\t||  1) Administrator         || \n";
    cout<<"\t\t\t\t\t||  2) Customer             || \n";
    cout<<"\t\t\t\t\t||  3) Exit                  || \n";
    cout<<"\v\t\t\t\t   PLEASE SELECT              \n";

    cin>>choice;


    switch(choice)
    {
        case 1:
             cout<<"\t\t\t\t  PLEASE LOGIN \n";
             cout<<"\t\t\t\t  Enter Email id \n";
             cin>>email;
             cout<<"\t\t\t\t  Enter password  \n";
             cin>>password;

             if(email=="viku2701@gmail.com" && password=="vikash") 
             {
                administrator();
             }
             else
             {
                cout<<"INVALID USER OR PASSWORD \n";
             }
             break;
        case 2:
            {
                Customer();
            }
        case 3:
            {
                exit(0);
            }
        default:
            {
                cout<<" please select from the given options \n";
            }
    }
 goto m;


}


void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\t\t\t\t  Administrator Menu    \n";
    cout<<"\n\t\t\t  1)Add the Product   \n";
    cout<<"\n\t\t\t                       \n";
    cout<<"\n\t\t\t  2)Modify the product  \n";
    cout<<"\n\t\t\t                        \n";
    cout<<"\n\t\t\t  3)Delete the product   \n";
    cout<<"\n\t\t\t                          \n";
    cout<<"\n\t\t\t  4)Back to main menu     \n";
    
    cout<<"\n\t\t\t  PLEASE ENTER YOUR CHOICE  \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default:
            cout<<"Invalid Choice \n";
    }
    goto m;
}

void shopping:: Customer()
{
    m:
    int choice;
    cout<<"\t\t\t\t\t   Buyer                  \n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t   1) buy product             \n";
    cout<<"\t\t\t\t\t                            \n";
    cout<<"\t\t\t\t\t    2)     go back                   \n";

    cout<<"\n\n\n\n\n  ENTER YOUR CHOICE          \n";

    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
           cout<<"INVALID CHOICE \n";
    }
    goto m;
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t Add new product \n";
    cout<<"\n\n\t\t CODE of product  \n";

    cin>>Product_Code;
    
    cout<<"\n\n\\t\t Name of the product \n";

    cin>>Product_Name;

    cout<<"\n\n\t\t price of the product \n";
    cin>>Price;

    cout<<"\n\n\t\t  Enter discount on product\n";
    
    cin>>Discount;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<Product_Code<<" "<<Product_Name<<" "<<Price<<" "<<Discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==Product_Code)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
    goto m;
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<Product_Code<<" "<<Product_Name<<" "<<Price<<" "<<Discount<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t  Record Inserted  \n";
}

void shopping:: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t Modify the Record \n";
    cout<<"\n\n\t\t  prodect key:  \n";
    cin>>pkey;

    data.open("database.txt" ,ios::in);
    if(!data)
    {
        cout<<"file does not exit \n";
    }
    else
    {
        data1.open("database1.txt" , ios::app|ios::out);
        data>>Product_Code>>Product_Name>>Price>>Discount;

        while(!data.eof())
        {
            if(pkey==Product_Code)
            {
                cout<<"\n\t\t    new product code  \n";
                cin>>c;
                cout<<"\n\t\t\t  enter name of product \n";
                cin>>n;
                cout<<"\n\t\t\t enter price of product \n";
                cin>>p;
                cout<<"\n\n\t enter discount  \n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" \n";
                cout<<"\n\r\\r  record edited   \n";
                token++;
            }
            else
            {
                data1<<" "<<Product_Code<<" "<<Product_Name<<" "<<Price<<" "<<Discount<<"\n";
            }
            data>>Product_Code>>Product_Name>>Price>>Discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found \n";
        }
    }
}

void shopping:: rem()
{
    fstream data;
    fstream data1;
    int pkey;
    int token=0;
    cout<<"\n\t\t\t DELETE PRODUCT \n";
    cout<<"\n\n\n\n  ENTER THE PRODUCT CODE: \n";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"\n\n\n\n FILE DOES NOT EXIST  \n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>Product_Code>>Product_Name>>Price>>Discount;
        
        while(!data.eof())
        {
            if(Product_Code==pkey)
            {
                cout<<"\n\n\n\n product deleted succefully";
                token++;
            }
            else
            {
                data1<<" "<<Product_Code<<" "<<Product_Name<<" "<<Price<<" "<<Discount<<"\n";
            }
             data>>Product_Code>>Product_Name>>Price>>Discount;

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\\n\\n\n record not found \n";
        }
        
    }


     
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n\n\n|______________________\n";
    cout<<"ProNo\t\tName\t\tPrice\t\tDiscount\n";
    cout<<"\n\n___________________\n";
    data>>Product_Code>>Product_Name>>Price>>Discount;

    while(!data.eof())
    {
        cout<<Product_Code <<"\t\t" <<Product_Name <<"\t\t" <<Price <<"\t\t" <<Discount <<"\n\n";
        data>>Product_Code>>Product_Name>>Price>>Discount;
    }
    data.close();

}

void shopping:: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int d=0;
    float amount=0;
    float Dis=0;
    float total=0;

    cout<<"\n\n  RECEIPT ";
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout<<"\n______________________________\n";
        cout<<"|                               \n";
        cout<<"     please place the order     \n";
        cout<<"|                               \n";
        cout<<"________________________________\n";

        do 
        {
            m:
            cout<<"\n\n Enter the product code :";
            cin>>arrc[d];
            cout<<"\n\n Enter the product quantity:";
            cin>>arrq[d];
            for(int i=0; i<d; i++)
            {
                if(arrc[d]==arrc[i])
                {
                    cout<<"\n\n duplicate product code. please try again!";
                    goto m;
                }
            }
            d++;
            cout<<"\n\n Do you want to buy another product? if yes then press yes else no ";
            cin>>choice;

        }
        while(choice=="yes");
     
        cout<<"\n\n\t\t______________RECEIPT_________________\n";
        cout<<"\nproduct no\t product name\t product quantity\tprice\tamount\tamount with discount\n";
     
        for(int i=0; i<=d; i++)
        {
            data.open("database.txt",ios::in);
            data>>Product_Code>>Product_Name>>Price>>Discount;
            while(!data.eof())
            {
                if(Product_Code==arrc[i])
                {
                    amount=Price*arrq[i];
                    Dis=amount-(amount*Discount/100);
                    total+=Dis;

                    cout<<"\n"<<Product_Code <<"\t\t" <<Product_Name <<"\t\t" <<arrq[i] <<"\t\t" <<Price <<"\t\t" <<amount <<"\t\t" <<Dis;


                }  
                   data>>Product_Code>>Product_Name>>Price>>Discount; 
               
            }
            
             data.close();
        }
    
       
        
    }
    cout<<"\n\n_______________________________";
    cout<<"\n Total Amount : " <<total;
}
int main()
{
    shopping s;
    s.menu();
}