#include <bits/stdc++.h>

using namespace std;

class bank
{
private:
    int pin;
    float balance;
    string id,pass,name,fName,adress,phone;
    
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void billPay();
    void search_user();
    void edit();
    void del();
    void allBankRecord();
    void allPaymentRecord();
public:
    void menu();
    void bank_management();
   
    
};

void bank::menu()
{
p:
    cout << "\033[2J\033[H"; // Clear the screen (Unix-like systems)

    int choice;
    string pin, pass, email;

    cout << "\n\n\t\t  Control Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. Exit";
    cout << "\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\n\t\t\t Login Account";
        cout << "\n\n E-mail: ";
        cin >> email;
        cout << "\n\n Pin Code: ";
        cin >> pin;
        cout << "\n\n Password: ";
        cin >> pass;

        if (email == "pranshu@gmail.com" && pin == "12345" && pass == "india")
            bank_management();
        else
            cout << "Sorry, details are not valid" << endl;
        break;
    case 2:
        exit(0);
    default:
        cout << "\n\n Invalid value. Please try again." << endl;
    }

    char c;
    cin >> c;
    goto p;
}

void bank::bank_management()
{
p:
    cout << "\033[2J\033[H"; 
    int choice;
    cout<<"\n\n\t\t\t Bank management system";
    cout<<"\n\n 1.New User";
    cout<<"\n 2. Already User";
    cout<<"\n 3. Deposit option";
    cout<<"\n 4. Withdraw option";
    cout<<"\n 5. Transfer option";
    cout<<"\n 6. Payment option";
    cout<<"\n 7. search User Record";
    cout<<"\n 8. Edit User Record";
    cout<<"\n 9. Delete User Record";
    cout<<"\n 10.show all Record";
    cout<<"\n 11.Payment All Record";
    cout<<"\n 12. Go back";
    cout<<"\n Enter the choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            new_user();
            break;
        case 2:
            already_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            billPay();
            break;
         case 7:
            search_user();
            break;
        case 8:
            edit();
            break;
        case 9:
            del();
            break;
        case 10:
            allBankRecord();
            break;
        case 11:
            allPaymentRecord();
            break;
        case 12:
            menu();
            break;
        
    }
    char c;
    cin>>c;
    goto p;
}

void bank::new_user()
{
    p:
     cout << "\033[2J\033[H";
     cout<<"\n\n\t\t Add new User ";
     cout<<"\n\n\t\t user id ";
     cin>>id;
     cout<<"\n\n\t\t Name ";
     cin>>name;
     cout<<"\n\n\t\t father's Name ";
     cin>>fName;
     cout<<"\n\n\t\t adress ";
     cin>>adress;
     cout<<"\n\n\t\t pin code ";
     cin>>pin;
     cout<<"\n\n\t\t Password ";
     cin>>pass;
     cout<<"\n\n\t\t phone No. ";
     cin>> phone;
     cout<<"\n\n\t\t current Balance ";
     cin>>balance;
     
        int pin1;
        float balance1;
        string id1,pass1,name1,fName1,adress1,phone1;
        
     fstream file;
     file.open("data.txt",ios::in);
     if(!file)
     {
        file.open("data.txt",ios::out);
        file<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
        file.close();
     }
     else
     {
         
         while(!file.eof())
         {
             file>>id1>>name1>>fName1>>adress1>>pin1>>pass1>>phone1>>balance1;
            //   cout<<id1<<name1<<fName1<<adress1<<pin1<<pass1<<phone1<<balance1<<endl;
              
             if(id1==id)
             {
                 cout<<"user Already exist";
                 char c;
                 cin>>c;
                 goto p;
             }
             
         }
         file.close();
         file.open("data.txt",ios::app);
         file<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
         file.close();
     }
      char c;
     cin>>c;
     exit(0);
     
}
void bank :: already_user()
{
     cout << "\033[2J\033[H";
     cout<<"\n\n Already User Account";
     fstream file;
     string tempId;
     bool flag=0;
     cout<<"\n\n enter the user id";
     cin>>tempId;
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
             if(id==tempId)
             {
                 cout<<"\n\n\t\t Account Exist Already";
                 cout<<"\n id is "<<id<<"name is "<<name<<"balance is "<<balance;
                 flag=1;
             }
         }
         
         
     }
     if(flag==0)
     {
          cout<<"\n\n\t\t Account Does Not Exist";
     }
     file.close();
      char c;
     cin>>c;
     bank_management();
     
}
void bank :: deposit()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId;
     float amount;
     bool flag=0;
     
     fileTemp.open("dataTemp.txt",ios::out);
     
     cout<<"\n\n\t\t Enter the Id of the User";
     cin>>tempId;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId)
             {
                 balance=balance+amount;
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
                 cout<<"\n\n\t\t Succesfully deposit to "<<id;
                 cout<<"\n id is "<<id<<"name is "<<name<<"balance is "<<balance;
                 flag=1;
             }
             else
             {
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
             }
         }
         file.close();
         fileTemp.close();
         remove("data.txt");
         rename("dataTemp.txt","data.txt");
         if(flag==0)
         {
             cout<<"\n\n\t\t id does not exist";
         }
         
     }
      char c;
     cin>>c;
     exit(0);
   
     
     
}
void bank :: withdraw()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId;
     float amount;
     int flag=0;
     
     fileTemp.open("dataTemp.txt",ios::out);
     
     cout<<"\n\n\t\t Enter the Id of the User";
     cin>>tempId;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId )
             {
                 if(balance<amount)
                    flag=2;
                else
                {
                 balance=balance-amount;
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
                 cout<<"\n\n\t\t Succesfully withdraw from "<<id;
                 cout<<"\n id is "<<id<<"name is "<<name<<"balance is "<<balance;
                 flag=1;
                 }
             }
             else
             {
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
             }
         }
         file.close();
         fileTemp.close();
         remove("data.txt");
         rename("dataTemp.txt","data.txt");
         if(flag==0)
         {
             cout<<"\n\n\t\t id does not exist";
         }
         if(flag==2)
         {
             cout<<"\n\n\t\t insufficient balance";
         }
         
     }
      char c;
     cin>>c;
     bank_management();
   
}
void bank :: transfer()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId1,tempId2;
     float amount;
     int flag=0;
     
     cout<<"\n\n\t\t Enter the Id of the sender";
     cin>>tempId1;
     cout<<"\n\n\t\t Enter the Id of the receiver";
     cin>>tempId2;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId1 && balance>=amount)
             {
                flag++;
             }
             if(id==tempId2)
                flag++;
             
         }
         file.close();
         
         
         file.open("data.txt",ios::in);
         fileTemp.open("dataTemp.txt",ios::out);
         if(flag==2)
         {
            while(!file.eof())
            {
                file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
                if(id==tempId1)
                {
                    balance-=amount;
                }
                if(id==tempId2)
                {
                    balance+=amount;
                }
                fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
            }
             cout<<"\n\n\t\t amount Succesfully transfered";
             file.close();
             fileTemp.close();
             remove("data.txt");
             rename("dataTemp.txt","data.txt");
            
        
         }
         else
         {
            cout<<"\n\n\t\t not possible";
            cout<<flag<<endl;
         }
          
         
     }
      char c;
     cin>>c;
     exit(0);
   
}
void bank :: billPay()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId,billName;
     float amount;
     int flag=0;
     
     fileTemp.open("dataTemp.txt",ios::out);
     
     cout<<"\n\n\t\t Enter the Id of the User";
     cin>>tempId;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     cout<<"\n\n\t\t Enter the bill name";
     cin>>billName;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId )
             {
                 if(balance<amount)
                    flag=2;
                else
                {
                 balance=balance-amount;
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
                 cout<<"\n\n\t\t payment Succesfully "<<id;
                 cout<<"\n id is "<<id<<" name is "<<name<<" balance is "<<balance;
                 flag=1;
                 }
             }
             else
             {
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
             }
         }
         file.close();
         fileTemp.close();
         remove("data.txt");
         rename("dataTemp.txt","data.txt");
         if(flag==0)
         {
             cout<<"\n\n\t\t id does not exist";
         }
         if(flag==2)
         {
             cout<<"\n\n\t\t insufficient balance payment can not be made";
         }
         if(flag==1)
         {
             file.open("bill.txt",ios::app);
             file<<" "<<id<<" "<<billName<<" "<<amount;
             cout<<"\n\n\t\t"<<billName<<" Bill payment Succesfully";
             file.close();
         }
         
         
     }
      char c;
     cin>>c;
     exit(0);
}
void bank :: search_user()
{
     cout << "\033[2J\033[H";
     cout<<"\n\n Search User Account";
     fstream file;
     string tempId;
     bool flag=0;
     cout<<"\n\n enter the user id";
     cin>>tempId;
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
             if(id==tempId)
             {
                 cout<<"\n\n\t\t User found details are as follows";
                 cout<<"\n\n id is "<<id<<" \tname is "<<name<<" \tfather's name is "<<fName;
                 cout<<"\n\n adress is "<<adress<<" \tphone no is "<<phone<<" \tbalance is "<<balance;
                 flag=1;
             }
         }
         
         
     }
     if(flag==0)
     {
          cout<<"\n\n\t\t Account Does Not Exist";
     }
     file.close();
      char c;
     cin>>c;
     bank_management();
     
}
void bank :: edit()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId;
     float amount;
     bool flag=0;
     
     fileTemp.open("dataTemp.txt",ios::out);
     
     cout<<"\n\n\t\t Enter the Id of the User";
     cin>>tempId;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId)
             {
                  int p;
                  float bal;
                  string i,pa,n,fN,ad,ph;
                  cout << "\033[2J\033[H";
                 cout<<"\n\n\t\t enter the new details";
                 cout<<"\n\n\t\t Name";
                 cin>>n;
                 cout<<"\n\n\t\t father's Name";
                 cin>>fN;
                 cout<<"\n\n\t\t adress";
                 cin>>ad;
                 cout<<"\n\n\t\t pin code";
                 cin>>p;
                 cout<<"\n\n\t\t Password";
                 cin>>pa;
                 cout<<"\n\n\t\t phone No.";
                 cin>> ph;
                 fileTemp<<" "<<id<<" "<<n<<" "<<fN<<" "<<ad<<" "<<p<<" "<<pa<<" "<<ph<<" "<<balance;
                  flag=1;
                  cout<<"\n\n\t\t Details edited Succesfully.";
             }
             else
             {
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
             }
         }
         file.close();
         fileTemp.close();
         remove("data.txt");
         rename("dataTemp.txt","data.txt");
         if(flag==0)
         {
             cout<<"\n\n\t\t id does not exist";
         }
         
     }
      char c;
     cin>>c;
     exit(0);
     
     
}
void bank :: del()
{
     cout << "\033[2J\033[H";
     fstream file,fileTemp;
     string tempId;
     float amount;
     bool flag=0;
     
     fileTemp.open("dataTemp.txt",ios::out);
     
     cout<<"\n\n\t\t Enter the Id of the User";
     cin>>tempId;
    
     cout<<"\n\n\t\t Enter the amount";
     cin>>amount;
     
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
            //  cout<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<endl;
             if(id==tempId)
             {
                cout<<"\n\n\t\t Account Deleted Succesfully";
                 flag=1;
             }
             else
             {
                 fileTemp<<" "<<id<<" "<<name<<" "<<fName<<" "<<adress<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance;
             }
         }
         file.close();
         fileTemp.close();
         remove("data.txt");
         rename("dataTemp.txt","data.txt");
         if(flag==0)
         {
             cout<<"\n\n\t\t id does not exist";
         }
         
     }
      char c;
     cin>>c;
     exit(0);
   
     
     
}
void bank :: allBankRecord()
{
    cout << "\033[2J\033[H";
     cout<<"\n\n All Bank Records are as follows"<<endl;
     fstream file;
    
     bool flag=0;
  
     file.open("data.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         while(!file.eof())
         {
             file>>id>>name>>fName>>adress>>pin>>pass>>phone>>balance;
             cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Father's Name: " << fName << endl;
            cout << "Address: " << adress << endl;
            cout << "Phone: " << phone << endl;
            cout << "Balance: " << balance << endl;
            cout<<"================================"<<endl;
             flag=1;
             
         }
         
         
     }
 
     file.close();
     char c;
     cin>>c;
     exit(0);
     
}
void bank :: allPaymentRecord()
{
    cout << "\033[2J\033[H";
     cout<<"\n\n All Bill Payment Records are as follows"<<endl;
     fstream file;
    
     bool flag=0;
  
     file.open("bill.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n no file exist";
     }
     
     else
     {
         string billName;
         float amount;
         while(!file.eof())
         {
             file>>id>>billName>>amount;
             cout << "ID: " << id << endl;
            cout << "BillName: " << billName << endl;
            cout << "Amount: " << amount << endl;
            cout<<"================================"<<endl;
             flag=1;
             
         }
         
         
     }
 
     file.close();
     char c;
     cin>>c;
     exit(0);
     
}
int main()
{
    bank myBank;
    myBank.menu();
    return 0;
}
