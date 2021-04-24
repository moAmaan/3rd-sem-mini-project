#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class student
{
    public:
    int rollno;
    string name;
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade;
    char sec;
}st;

FILE *fp;

void insert_record()
{
    fp=fopen("student.txt","ab+");
    if(fp==NULL){
        cout<<"\n\t\tError: Cannot open file!!!";
        return;
    }
    cout<<"\n\n\t****Enter new Student Record****";
    cout<<"\n\tEnter student Roll Number ";
    cin>>st.rollno;
    cin.ignore();
    cout<<"\n\tEnter student Name ";
   getline(cin,st.name);
     cout<<"\n\tEnter Student section ";
    cin>>st.sec;
    cout<<"\n\tEnter the Marks in Physics out of 100: ";
    cin>>st.p_marks;
    cout<<"\n\tEnter the Marks in Chemistry out of 100: ";
    cin>>st.c_marks;
    cout<<"\n\tEnter the Marks in Mathematics out of 100: ";
    cin>>st.m_marks;
    cout<<"\n\tEnter the Marks in English out of 100: ";
    cin>>st.e_marks;
    cout<<"\n\tEnter the Marks in Computer science out of 100: ";
    cin>>st.cs_marks;
    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
    if(st.per>60){
        st.grade='A';
    }
    else if(st.per>=50&&st.per<=60){
        st.grade='B';
    }
    else if(st.per>=33&&st.per<=50){
        st.grade='C';
    }
    else{
        st.grade='D';
    }
    fwrite(&st,sizeof(st),1,fp);
    fclose(fp);
    cout<<"\n\t***Student record updated***";
   
}

void display_record()
{
    FILE *fp;
    fp=fopen("student.txt","rb");
    if(fp==NULL){
        cout<<"\n\t\tError: Cannot open file!!!";
        return;
    }
    cout<<"\n\t\t***Students Record is as follows***"<<endl;
    cout<<"===========================================================================================\n";
    cout<<"R.No.    Name    Section        P       C       M       E       CS      %age       Grade\n";
    cout<<"===========================================================================================\n";
    while(fread(&st,sizeof(st),1,fp)==1){
        cout<<st.rollno<<"\t"<<st.name<<"\t "<<st.sec<<"\t\t"<<st.p_marks<<"\t"<<st.c_marks<<"\t"<<st.m_marks<<"\t"<<st.e_marks<<"\t"<<st.cs_marks<<"\t"<<st.per<<"\t    "<<st.grade<<endl;

    }
    fclose(fp);
}

void search_record()
{
    int ro,count=0;
    FILE *fp;
    fp=fopen("student.txt","rb");
    if(fp==NULL){
        cout<<"\n\t\tError: Cannot open file!!!";
        return;
    }
    cout<<"\n\t\tEnter Stuedent roll no which u want to search:";
    cin>>ro;
    while(fread(&st,sizeof(st),1,fp)>0 && count==0){
        if(ro==st.rollno){
            system("cls");
            count=1;
            cout<<"\n\t\tSearch Successfull and Student Records is as follows:";
            cout<<"\nRoll Number of the Student : "<<st.rollno;
            cout<<"\nName of the student is : "<<st.name;
            cout<<"\nSection Of the Student : "<<st.sec;
            cout<<"\nMarks in Physics : "<<st.p_marks;
            cout<<"\nMarks in Chemistry : "<<st.c_marks;
            cout<<"\nMarks in Mathematics : "<<st.m_marks;
            cout<<"\nMarks in English : "<<st.e_marks;
            cout<<"\nMarks in Computer science : "<<st.cs_marks;
            cout<<"\nPercentage of the Student is : "<<st.per;
            cout<<"\nGrade of the student is : "<<st.grade;
        }
    }
    fclose(fp);
    if(count==0){
        cout<<"\n\t\tRecord does not Exists!!!\n";
    }
}

void del_record()
{
    int ro;
    FILE *fp,*ft;
    system("cls");
    fp=fopen("student.txt","rb");
    if(fp==NULL){
        cout<<"\n\t\tError: Cannot open file!!!";
        return;
    }
    cout<<"\n\t***Previous Records***";
    display_record();
    cout<<"\n\n\tEnter Student Roll No. whose record you have to delete ";
    cin>>ro;
    ft=fopen("student1.txt","ab+");
    while(fread(&st,sizeof(st),1,fp)==1){
        if(ro==st.rollno){
            cout<<"\n\tRecord Deleted Successfully!!!";
            continue;
        }
        fwrite(&st,sizeof(st),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("student1.txt","student.txt");
    cout<<"\n\t\tRecord Deleted!!";
    display_record();
}

void modify_record()
{
    int ro,count=0;
    FILE *fp;
    fp=fopen("student.txt","rb+");
    if(fp==NULL){
        cout<<"\n\t\tError: File Not found!!!";
        return;
    }
    cout<<"\n\n\tEnter student Roll no , you want to modify:";
    cin>>ro;
    cout<<"\n\t\tPreviously Stored Record of the student ";
    while(fread(&st,sizeof(st),1,fp)>0 && count==0){
        if(ro==st.rollno){
             cout<<"\nRoll Number of the Student : "<<st.rollno;
            cout<<"\nName of the student is : "<<st.name;
            cout<<"\nSection Of the Student : "<<st.sec;
            cout<<"\nMarks in Physics : "<<st.p_marks;
            cout<<"\nMarks in Chemistry : "<<st.c_marks;
            cout<<"\nMarks in Mathematics : "<<st.m_marks;
            cout<<"\nMarks in English : "<<st.e_marks;
            cout<<"\nMarks in Computer science : "<<st.cs_marks;
            cout<<"\nPercentage of the Student is : "<<st.per;
            cout<<"\nGrade of the student is : "<<st.grade;
            cout<<"\n\t\tEnter New Details of the Student:";
             cout<<"\n\tEnter student Roll Number";
    cin>>st.rollno;
    cin.ignore();
    cout<<"\n\tEnter student Name";
   getline(cin,st.name);
     cout<<"\n\tEnter Student section";
    cin>>st.sec;
    cout<<"\n\tEnter the Marks in Physics out of 100:";
    cin>>st.p_marks;
    cout<<"\n\tEnter the Marks in Chemistry out of 100:";
    cin>>st.c_marks;
    cout<<"\n\tEnter the Marks in Mathematics out of 100:";
    cin>>st.m_marks;
    cout<<"\n\tEnter the Marks in English out of 100:";
    cin>>st.e_marks;
    cout<<"\n\tEnter the Marks in Computer science out of 100:";
    cin>>st.cs_marks;
    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
    if(st.per>60){
        st.grade='A';
    }
    else if(st.per>=50&&st.per<=60){
        st.grade='B';
    }
    else if(st.per>=33&&st.per<=50){
        st.grade='C';
    }
    else{
        st.grade='D';
    }
    fseek(fp,-(long)sizeof(st),1);
    fwrite(&st,sizeof(st),1,fp);
    cout<<"\n\tRecord modified Successfully!!!";
    count=1;
        }
    }
    if(count==0){
        cout<<"\n\t REcord Not Found!!";
    }
  fclose(fp);
}

void sort_record()
{
    student temp;
    student arr[50];
    int i,j,k=0;
    FILE *fp;
    fp=fopen("student.txt","rb");
    if(fp==NULL){
        cout<<"\n\t\tError : File not found!!!";
        return;
    }
    i=0;
    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1){
        i++;
        k++;
    }
    for(i=0;i<k;i++){
        for(j=0;j<k-i-1;j++){
            if(arr[j].rollno>arr[j+1].rollno){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"\n\t\tAfter sorting Students DEtails:";
    for(i=0;i<k;i++){
         cout<<"\n\n\tRoll Number of the Student : "<<arr[i].rollno;
            cout<<"\nName of the student is : "<<arr[i].name;
            cout<<"\nSection Of the Student : "<<arr[i].sec;
            cout<<"\nMarks in Physics : "<<arr[i].p_marks;
            cout<<"\nMarks in Chemistry : "<<arr[i].c_marks;
            cout<<"\nMarks in Mathematics : "<<arr[i].m_marks;
            cout<<"\nMarks in English : "<<arr[i].e_marks;
            cout<<"\nMarks in Computer science : "<<arr[i].cs_marks;
            cout<<"\nPercentage of the Student is : "<<arr[i].per;
            cout<<"\nGrade of the student is : "<<arr[i].grade;
    }
    fclose(fp);
}

int main()
{
    int n;
    system("cls");
    while(n!=7)
    {
        cout<<"\n\t*******************************************************\n";
        cout<<"\t\tWelcome to Student Report card handling System\n";
        cout<<"\t*******************************************************\n";
        cout<<"\t****Available Functions****\n";
        cout<<"\t\t1:Insert Student Record\n";
        cout<<"\t\t2:Display Student Record\n";
        cout<<"\t\t3:Search Student Record\n";
        cout<<"\t\t4:Delete Student record\n";
        cout<<"\t\t5:Modify Student Record\n";
        cout<<"\t\t6:Sort Students Records\n";
        cout<<"\t\t7:EXIT\n\n";
        cout<<"\t\tEnter your choice: \n";
        cin>>n;
        switch (n)
        {
            case 1: system("cls");
            insert_record();
            break;
            case 2: system("cls");
            display_record();
            break;
            case 3: system("cls");
            search_record();
            break;
            case 4: system("cls");
            del_record();
            break;
            case 5: system("cls");
            modify_record();
            break;
            case 6: system("cls");
            sort_record();
            break;
            case 7:exit(1);
            default:
            cout<<"\n\t\tInvalid choice!!!";
            break;
        }
        cout<<"\n\t\tPress Any Key to continue";
    }
    return 0;
}