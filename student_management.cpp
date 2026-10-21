
#include<iostream>
#include<string>
using namespace std;

int main(){
    int choice;
    int roll_num[100];
    string name[100];
    int maths_marks[100];
    int physics_marks[100];
    int chemistry_marks[100];
    int student_count = 0;

    do{
        cout<<"1.ADD STUDENT"<<endl;
        cout<<"2.DISPLAY ALL THE STUDENTS"<<endl;
        cout<<"3.SEARCH STUDENT"<<endl;
        cout<<"4.UPDATE MARKS"<<endl;
        cout<<"5.GENERATE REPORT CARD"<<endl;
        cout<<"6.CLASS STATISTICS"<<endl;
        cout<<"7.EXIT"<<endl;

        cout<<"enter your choice"<<endl;
        cin>>choice;

        if(choice==1){
            if(student_count < 100){
                cout<<"Enter student roll number: ";
                cin>>roll_num[student_count];

                cout<<"Enter student name: ";
                cin>>name[student_count];

                cout<<"Enter maths marks: ";
                cin>>maths_marks[student_count];

                cout<<"Enter physics marks: ";
                cin>>physics_marks[student_count];

                cout<<"Enter chemistry marks: ";
                cin>>chemistry_marks[student_count];

                student_count++;

                cout<<"Student added successfully!"<<endl;
            }
            else{
                cout<<"Maximum student capacity reached!"<<endl;
            }
        }

        else if(choice==2){
            if(student_count==0){
                cout<<"no student found!"<<endl;
            }
            else{
                cout<<"DISPLAYING ALL THE STUDENTS :"<<endl;

                for(int i=0; i<student_count; i++){
                    cout<<"roll number: "<<roll_num[i]<<endl;
                    cout<<"name: "<<name[i]<<endl;
                    cout<<"maths marks: "<<maths_marks[i]<<endl;
                    cout<<"physics marks: "<<physics_marks[i]<<endl;
                    cout<<"chemistry marks: "<<chemistry_marks[i]<<endl;
                    cout<<" --------------------"<<endl;
                }
            }
        }

        else if(choice==3){
            if(student_count==0){
                cout<<"no student found!"<<endl;
            }
            else{
                int search_roll;
                int found=0;

                cout<<"enter roll number to search:"<<endl;
                cin>>search_roll;

                for(int i=0; i<student_count; i++){
                    if(roll_num[i]==search_roll){
                        found=1;

                        cout<<"roll number: "<<roll_num[i]<<endl;
                        cout<<"name: "<<name[i]<<endl;
                        cout<<"maths marks: "<<maths_marks[i]<<endl;
                        cout<<"physics marks: "<<physics_marks[i]<<endl;
                        cout<<"chemistry marks: "<<chemistry_marks[i]<<endl;

                        break;
                    }
                }

                if(found==0){
                    cout<<"Student not found!"<<endl;
                }
            }
        }

        else if(choice==4){
            if(student_count==0){
                cout<<"no student found!"<<endl;
            }
            else{
                int search_roll;
                int found=0;
                int subject_choice;
                int new_marks;

                cout<<"enter roll number to update"<<endl;
                cin>>search_roll;

                for(int i=0; i<student_count; i++){
                    if(roll_num[i]==search_roll){
                        found=1;

                        cout<<"1.maths"<<endl;
                        cout<<"2.physics"<<endl;
                        cout<<"3.chemistry"<<endl;

                        cout<<"enter subject to update"<<endl;
                        cin>>subject_choice;

                        if(subject_choice>=1 && subject_choice<=3){
                            cout<<"enter new marks"<<endl;
                            cin>>new_marks;

                            if(new_marks<0 || new_marks>100){
                                cout<<"Invalid marks!"<<endl;
                            }
                            else if(subject_choice==1){
                                maths_marks[i]=new_marks;
                                cout<<"maths marks updated successfully"<<endl;
                            }
                            else if(subject_choice==2){
                                physics_marks[i]=new_marks;
                                cout<<"physics marks updated successfully"<<endl;
                            }
                            else if(subject_choice==3){
                                chemistry_marks[i]=new_marks;
                                cout<<"chemistry marks updated successfully"<<endl;
                            }
                        }
                        else{
                            cout<<"invalid subject choice"<<endl;
                        }

                        break;
                    }
                }

                if(found==0){
                    cout<<"student not found!"<<endl;
                }
            }
        }

        else if(choice==5){
            if(student_count==0){
                cout<<"no student found!"<<endl;
            }
            else{
                int search;
                int found=0;

                cout<<"Enter roll number: ";
                cin>>search;

                for(int i=0; i<student_count; i++){
                    if(roll_num[i]==search){
                        found=1;

                        cout<<"Roll number: "<<roll_num[i]<<endl;
                        cout<<"Name: "<<name[i]<<endl;
                        cout<<"Maths marks obtained: "<<maths_marks[i]<<endl;
                        cout<<"Physics marks obtained: "<<physics_marks[i]<<endl;
                        cout<<"Chemistry marks obtained: "<<chemistry_marks[i]<<endl;

                        int total=maths_marks[i]+physics_marks[i]+chemistry_marks[i];
                        double percentage=total/300.0*100;

                        cout<<"Total marks: "<<total<<"/300"<<endl;
                        cout<<"Percentage: "<<percentage<<"%"<<endl;

                        if(maths_marks[i]>=35 && physics_marks[i]>=35 && chemistry_marks[i]>=35){
                            cout<<"PASSED"<<endl;
                        }
                        else{
                            cout<<"FAILED"<<endl;
                        }

                        cout<<"---------------"<<endl;
                        break;
                    }
                }

                if(found==0){
                    cout<<"Student not found!"<<endl;
                }
            }
        }

        else if(choice==6){
            if(student_count==0){
                cout<<"No student found!"<<endl;
            }
            else{
                int total_marks=0;
                int highest_total=0;
                int lowest_total=300;
                int topper_index=0;
                int lowest_index=0;

                for(int i=0; i<student_count; i++){
                    int total=maths_marks[i]+physics_marks[i]+chemistry_marks[i];

                    total_marks=total_marks+total;

                    if(total>highest_total){
                        highest_total=total;
                        topper_index=i;
                    }

                    if(total<lowest_total){
                        lowest_total=total;
                        lowest_index=i;
                    }
                }

                double average=total_marks/(student_count*3.0)*100;

                cout<<"----- CLASS STATISTICS -----"<<endl;
                cout<<"Total number of students: "<<student_count<<endl;
                cout<<"Class average percentage: "<<average<<"%"<<endl;

                cout<<"----- TOPPER -----"<<endl;
                cout<<"Roll number: "<<roll_num[topper_index]<<endl;
                cout<<"Name: "<<name[topper_index]<<endl;
                cout<<"Total marks: "<<highest_total<<"/300"<<endl;

                cout<<"----- LOWEST SCORER -----"<<endl;
                cout<<"Roll number: "<<roll_num[lowest_index]<<endl;
                cout<<"Name: "<<name[lowest_index]<<endl;
                cout<<"Total marks: "<<lowest_total<<"/300"<<endl;

                cout<<"----------------------------"<<endl;
            }
        }

        else if(choice==7){
            cout<<"Thank you for using Student Management System!"<<endl;
            cout<<"Exiting program..."<<endl;
        }
        else{
            cout<<"Sorry, invalid input"<<endl;
        }

    }while(choice!=7);

    return 0;
}
