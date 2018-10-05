#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<process.h>

using namespace std;

int UniversalCode=0;
int lifeline[3] = {0,0,0};
class Question{
	 char ques[50];
	 char option1[50];
	 char option2[50];
	 char option3[50];
	 char option4[50];
	 int ans;
	public:
		  int code;
		  void setData(Question allData){
				strcpy(ques,allData.getQues());
				ans = allData.getAnswer();
				strcpy(option1,allData.getOption1());
				strcpy(option2,allData.getOption2());
				strcpy(option3,allData.getOption3());
				strcpy(option4,allData.getOption4());
		  }

		  void codeChange();

		  char* getQues(){
				return ques;
		  }

		  char* getOption1(){
				return option1;
		  }

		  char* getOption2(){
				return option2;
		  }

		  char* getOption3(){
				return option3;
		  }

		  char* getOption4(){
				return option4;
		  }

		  int getAnswer(){
				return ans;
		  }

		  void addQues();

		  void addNewQues();

		  void dell();

		  void display();

};
int main()
{
	 int option();
	 void play();
	 Question q,codeObj;
	 ifstream f1("KBC.dat",ios::binary);
	 while(f1.read((char *)&codeObj, sizeof(Question))){
		  UniversalCode = codeObj.code;
	 }
	 int choice;
	 do{
		choice = option();
		  switch(choice){
				case 1:play();
					 break;
				case 2:q.addNewQues();
					 break;
				case 3:q.addQues();
					 break;
				case 4:q.dell();
					 break;
				case 100:q.display();
					 break;
				case 0:break;
		  }
	 }while(choice!=0);
	 return 0;
}

int audiencePole(Question ques){
	//clrscr();
	system("cls");
	int ans = ques.getAnswer(),newAns;
	int total=100,randum=0;
	for(int i=1; i<=4; i++){
		total-=randum;
		if(i==ans){
			cout<<"\nOption "<<i<<" ";
			randum = (rand()%1)+50;
			for(int j=0; j<randum; j++){
				cout<<"*";
			}
			cout<<"\n";
		}else{
			cout<<"\nOption "<<i<<" ";
			randum = (rand()%40)+1;
			for(int j=0; j<randum; j++){
				cout<<"*";
			}
			cout<<"\n";
		}
	}
	cout<<"\n\n Enter your Answer:";
    cin>>newAns;
    return newAns;
}

int DoubleDip(Question ques){
	//clrscr();
	system("cls");
	int chances=2,ans=0;
	cout<<"\n\nNow you have two chances\t\tChances::"<<chances<<"\n";
	cout<<"\n\n"<<ques.getQues();
	cout<<"\n\t1."<<ques.getOption1()<<"\t\t2."<<ques.getOption2();
    cout<<"\n\n\t3."<<ques.getOption3()<<"\t\t\t4."<<ques.getOption4();
    cout<<"\n\n Enter your Answer:";
    cin>>ans;
    if(ans==ques.getAnswer()){
        return ans;
    }else{
        //clrscr();
        system("cls");
        chances--;
        cout<<"\n\nNow you have two chances\t\tChances::"<<chances<<"\n";
        cout<<"\n\n"<<ques.getQues();
        cout<<"\n\t1."<<ques.getOption1()<<"\t\t2."<<ques.getOption2();
        cout<<"\n\n\t3."<<ques.getOption3()<<"\t\t\t4."<<ques.getOption4();
        cout<<"\n\n Enter your Answer:";
        cin>>ans;
        if(ans==ques.getAnswer()){
            return ans;
        }else{
            return 0;
        }
    }
}


int Fifty_Fifty(Question ques){
	//clrscr();
	system("cls");
	int ans=0;
	cout<<"\n\n"<<ques.getQues();
	int random;
	do{
		random = (rand()%4)+1;
	}while(random==ques.getAnswer());
	switch(ques.getAnswer()){
		case 1:
			cout<<"\n\t1."<<ques.getOption1();
			break;
		case 2:
			cout<<"\n\t1."<<ques.getOption2();
			break;
		case 3:
			cout<<"\n\t1."<<ques.getOption3();
			break;
		case 4:
			cout<<"\n\t1."<<ques.getOption4();
			break;
	}
	switch(random){
		case 1:
			cout<<"\n\t2."<<ques.getOption1();
			break;
		case 2:
			cout<<"\n\t2."<<ques.getOption2();
			break;
		case 3:
			cout<<"\n\t2."<<ques.getOption3();
			break;
		case 4:
			cout<<"\n\t2."<<ques.getOption4();
			break;
	}
	cout<<"\n\n Enter your Answer:";
    cin>>ans;
    return ans;
}

int option(){
    //clrscr();
     system("cls");
	 cout<<"\n";
	 for(int i=0; i<80; i++)
		  cout<<"#";
	 cout<<"\n\t\tKaun Banega Crorepati";
	 cout<<"\n\t\t\t1-Play";
	 cout<<"\n\t\t\t2-Add New Question";
	 cout<<"\n\t\t\t3-Add Question(All Previous Question will be erased)";
	 cout<<"\n\t\t\t4-Delete Question";
	 cout<<"\n\t\t\t0-Exit";
	 int ch;
	 cout<<"\n\n\t\tEnter choice:";
	 cin>>ch;
	 return ch;
}

int Lifeline(int pos,Question ques){
    int answer=0;
	switch(pos){
		case 1:
			if(lifeline[0]==0){
				answer = Fifty_Fifty(ques);
				lifeline[0]=1;
			}else{
				cout<<"\nYou have already used this Lifeline";
			}
			break;
		case 2:
			if(lifeline[1]==0){
				answer = audiencePole(ques);
				lifeline[1]=1;
			}else{
				cout<<"\nYou have already used this Lifeline";
			}
			break;
		case 3:
			if(lifeline[2]==0){
				answer = DoubleDip(ques);
				lifeline[2]=1;
			}else{
				cout<<"\nYou have already used this Lifeline";
			}
			break;
		default:cout<<"\n Wrong Choice Entered";
	}
	return answer;
}

void play(){
	 //clrscr();
	 system("cls");
	 lifeline[0]=0;
	 lifeline[1]=0;
	 lifeline[2]=0;
	 long userScore=0;
	 int getRandom();
	 long score(int);
	 Question ques;
	 Question random;
	 int lifelineUsed = 0;
	 int ans=99,count=1,level=0;
	 while(level!=14){
		  //clrscr();
		  system("cls");
		  level++;
		  for(int i=0; i<80; i++)
				cout<<"#";
		  cout<<"\n\t\tKaun Banega Crorepati"<<"\t\t\t\tLevel:"<<level;
		  cout<<"\n\n\t\tPress 0 to quit this game";
		  cout<<"\n\n\t\tMoney you have now $"<<userScore;
		  ifstream f1("KBC.dat",ios::binary);
		  int ran = getRandom();
		  while(f1.read((char *)&ques, sizeof(Question))){
				if(ques.code==ran){
					 random.setData(ques);
				}
		  }
		  f1.close();
		  cout<<"\n\n"<<count<<"."<<random.getQues();
		  cout<<"\n\t1."<<random.getOption1()<<"\t\t2."<<random.getOption2();
		  cout<<"\n\n\t3."<<random.getOption3()<<"\t\t\t4."<<random.getOption4();
		  int line;
		  lifelineUsed=0;
		  do{
				cout<<"\n\n Enter your Answer[Press 6 for Lifeline]:";
				cin>>ans;
				if(ans==6){
				  //clrscr();
				  system("cls");
				  int all=0;
				  for(int l=0; l<3; l++){
                    if(lifeline[l]==1){
                        all=1;
                    }else{
                        all=0;
                    }
                  }
                  if(all==1){
                    cout<<"All your lifelines have been already used. There is no lifeline left for you now";
                    cout<<"\n\n"<<count<<"."<<random.getQues();
        cout<<"\n\t1."<<random.getOption1()<<"\t\t2."<<random.getOption2();
        cout<<"\n\n\t3."<<random.getOption3()<<"\t\t\t4."<<random.getOption4();
                  }else{
                  cout<<"\n\t\tKaun Banega Crorepati"<<"\t\t\t\tLevel:"<<level;
                        cout<<"\n\n\t\tPress 0 to quit this game";
                        cout<<"\n\n\t\tMoney you have now $"<<userScore;
                        cout<<"\n\n\t\tLifeLines available:";
                        cout<<"\n\t\t1. 50-50 Lifeline";
                        cout<<"\n\t\t2. Audience pole Lifeline";
                        cout<<"\n\t\t3. Double Dip Lifeline";
                        cout<<"\n\t\t0. Exit";
                        do{
                            cout<<"\n\t\tEnter option to use lifeline:";
                            cin>>line;
                        }while(line>4);
                        if(line==0){
                            system("cls");
                            ans=7;
                            cout<<"\n\n"<<count<<"."<<random.getQues();
        cout<<"\n\t1."<<random.getOption1()<<"\t\t2."<<random.getOption2();
        cout<<"\n\n\t3."<<random.getOption3()<<"\t\t\t4."<<random.getOption4();
                        }else{
                            if(lifeline[line-1]==0){
                                ans = Lifeline(line,random);
                                lifelineUsed=1;
                            }else{
                                cout<<"\nLifeline is already used";
                                getch();
                                ans=8;
                            }
                        }
                  }
				}
		  }while(ans>5);
		  if(ans==0){
            break;
		  }else{
            if(lifelineUsed==1){
                if(line==1){
                    //clrscr();
                    system("cls");
                    if(ans==1){
                        long price = score(count);
          				cout<<"\nCongratulations your answer is correct.You have won $"<<price;
          				userScore = price;
            			getch();
                    }else{
            			//clrscr();
          				system("cls");
            			cout<<"\nSorry to say, you made a wrong choice. You have taken $"<<userScore<<" Thanks for playing";
            			getch();
            			break;
                    }
                }else{
          			if(ans==random.getAnswer()){
                        //clrscr();
                        system("cls");
                        long price = score(count);
                        cout<<"\nCongratulations your answer is correct.You have won $"<<price;
                        userScore = price;
                        getch();
                    }else{
                        //clrscr();
                        system("cls");
                        cout<<"\nSorry to say, you made a wrong choice. You have taken $"<<userScore<<" Thanks for playing";
                        getch();
                        break;
                    }
                }
		  }else{
				if(ans==random.getAnswer()){
					//clrscr();
					system("cls");
					long price = score(count);
					cout<<"\nCongratulations your answer is correct.You have won $"<<price;
					userScore = price;
					getch();
                }else{
					//clrscr();
					system("cls");
					cout<<"\nSorry to say, you made a wrong choice. You have taken $"<<userScore<<" Thanks for playing";
					getch();
					break;
			  }
		  }
        }
		  count++;
		  f1.close();
	 }
	 if(level==14){
        system("cls");
        cout<<"\nCONGRATULATIONS You won the game. You scored $"<<userScore;
        cout<<"\n Lifelines used:";
        if(lifeline[0]==1){
            cout<<"\n\t\t1. 50-50 Lifeline";
        }
        if(lifeline[1]==1){
            cout<<"\n\t\t2. Audience pole Lifeline";
        }
        if(lifeline[2]==1){
            cout<<"\n\t\t3. Double Dip Lifeline";
        }
        if(lifeline[0]==0 && lifeline[1]==0 && lifeline[2]==0){
            cout<<"No Lifeline Used";
        }
        getch();
	 }
}

int getRandom(){
	 return (rand()%2)+1;
}

long score(int level){
	switch(level){
	 case 1:return 1000;
	 case 2:return 5000;
	 case 3:return 10000;
	 case 4:return 30000;
	 case 5:return 80000;
	 case 6:return 100000;
	 case 7:return 500000;
	 case 8:return 2000000;
	 case 9:return 3000000;
	 case 10:return 5000000;
	 case 11:return 10000000;
	 case 12:return 20000000;
	 case 13:return 30000000;
	 case 14:return 50000000;
	 default:return 0;
	}
}

void Question::addQues(){
	//clrscr();
	system("cls");
	ofstream f1("KBC.dat",ios::binary);
	char ch;
	UniversalCode=0;
	do{
		cout<<"\nEnter Question:";
		//gets(ques);
		cin.getline(ques, 50,'?');
		cout<<"\nEnter Option 1 of above question:";
		//gets(option1);
		cin.getline(option1, 50,'.');
		cout<<"\nEnter Option 2 of above question:";
		//gets(option2);
		cin.getline(option2, 50,'.');
		cout<<"\nEnter Option 3 of above question:";
		//gets(option3);
		cin.getline(option3, 50,'.');
		cout<<"\nEnter Option 4 of above question:";
		//gets(option4);
		cin.getline(option4, 50,'.');
		cout<<"\nEnter the answer of the above question[only option number]:";
		cin>>ans;
		code=UniversalCode+1;
		UniversalCode++;
		f1.write((char *)this, sizeof(Question));
		cout<<"\nDo you want to add more question[Y/N]:";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	f1.close();
}
void Question::addNewQues(){
	//clrscr();
	system("cls");
	ofstream f1("KBC.dat",ios::binary | ios::app);
	char ch;
	do{
		cout<<"\nEnter Question:";
		//gets(ques);
		cin.getline(ques, 50,'?');
		cout<<"\nEnter Option 1 of above question:";
		//gets(option1);
		cin.getline(option1, 50,'.');
		cout<<"\nEnter Option 2 of above question:";
		//gets(option2);
		cin.getline(option2, 50,'.');
		cout<<"\nEnter Option 3 of above question:";
		//gets(option3);
		cin.getline(option3, 50,'.');
		cout<<"\nEnter Option 4 of above question:";
		//gets(option4);
		cin.getline(option4, 50,'.');
		cout<<"\nEnter the answer of the above question[only option number]:";
		cin>>ans;
		code=UniversalCode+1;
		UniversalCode++;
		f1.write((char *)this, sizeof(Question));
		cout<<"\nDo you want to add more question[Y/N]:";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	f1.close();
}

void Question::dell(){
	ifstream f1("KBC.dat",ios::binary);
	ofstream f2("temp.dat",ios::binary);
	cout<<"\nEnter the code of question to delete:";
	int ch;
	cin>>ch;
	while(f1.read((char *)this, sizeof(Question))){
		if(ch!=code){
			f2.write((char *)this, sizeof(Question));
			cout<<"\nQuestion deleted Successfully\n";
			getch();
		}
	}
	f1.close();
	f2.close();
	remove("KBC.dat");
	rename("temp.dat","KBC.dat");
	codeChange();
}

void Question::display(){
				ifstream f1("KBC.dat",ios::binary);
				while(f1.read((char *)this, sizeof(Question))){
					 //clrscr();
					 system("cls");
					 cout<<"\nQuestion:"<<ques;
					 cout<<"\n Option:"<<option1;
					 cout<<"\n Option :"<<option2;
					 cout<<"\n Option :"<<option3;
					 cout<<"\n Option :"<<option4;
					 cout<<"\n Answer:"<<ans;
					 cout<<"\nCode :"<<code;
					 getch();
				}
				//clrscr();
				system("cls");
}

void Question::codeChange(){
	ifstream f1("KBC.dat",ios::binary);
	ofstream f2("temp.dat",ios::binary);
	int startCode=1;
	while(f1.read((char *)this, sizeof(Question))){
		if(code!=startCode)
			code = startCode;
		f2.write((char *)this, sizeof(Question));
		startCode++;
	}
	f1.close();
	f2.close();
	remove("KBC.dat");
	rename("temp.dat","KBC.dat");
}
