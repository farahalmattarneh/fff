//POWERPUFF GIRLS (BATOOL-SARA-FARAH)
#include<unistd.h>
char tasks[100][1001];
int count=0;
////////////////////////////////////////////////////////////////////////////////////
void writeNumber(int num) {
    char digits[4];
    int i=0;
    if(num==0){
        char c='0';
        write(1,&c,1);
        return;
    }
    while(num>0){
        digits[i]=(num%10)+'0';
        num=num/10;
        i++;
    }
    while(i>0){
        i--;
        write(1,&digits[i],1);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
int strsize(char*string) {
    if (*string=='\0') return 0;
    else {
        return 1+strsize(string+1);
    }
}
////////////////////////////////////////////////////////////////////////////////////
void addTask(){
    if(count>=100){
        write(1,"We know you are pumped, but not that crazy!\n",44);
        return;
    }
    write(1,"Wanna add a task, or should I handle it with you???\n",49);
    int n=read(0,tasks[count],1000);
    if(n>0&&tasks[count][n-1]=='\n'){
        tasks[count][n-1] ='\0';
    }else{
        tasks[count][n] ='\0';
    }
    count++;
    write(1,"Proud of you for listening, but do not test me!\n",49);
}
///////////////////////////////////////////////////////////////////////////////////
void viewTasks(){
    if(count==0){
        write(1,"It happened, we are not in the mood, but we gotta fight it!\n",60);
        return;
    }
    int i=0;
    while(i<count){
        writeNumber(i+1);
        write(1,"- ",2);
        write(1,tasks[i],strsize(tasks[i]));
        write(1,"\n",1);
        i++;
    }
}
///////////////////////////////////////////////////////////////////////////////
void deleteTask(){
    if(count==0){
        write(1,"How are you gonna succeed if you do not have any tasks?\n",56);
        return;
    }
    viewTasks();
    write(1,"Still gonna delete tasks, huh?!",31);
    char buffer[7];
    int n=read(0,buffer,6);
    buffer[n]='\0';
    int num=0;
    int i=0;
    while(buffer[i]>='0'&& buffer[i]<='9'){
        num=num*10+(buffer[i]-'0');
        i++;
    }
    if(num<1||num>count){
        write(1,"Invalid task number,Focus\n",26);
        return;
    }
    int index=num-1;
    int j;
    i=index;
    while(i<count-1){
        j=0;
        while(tasks[i+1][j]!='\0') {
            tasks[i][j]=tasks[i+1][j];
            j++;
        }
        tasks[i][j]='\0';
        i++;
    }
    count--;
    write(1,"So you really deleted it, huh?!\n",32);
}
//////////////////////////////////////////////////////////////////////////
int main() {
    int choice;
    while(1){
        write(1,"1- Add Task\n",12);
        write(1,"2- View Tasks\n",14);
        write(1,"3- Delete Task\n",15);
        write(1,"4- Exit",7);
        write(1,"\nEnter your choice:",19);
        char buffer[4];
        int n=read(0,buffer,3);
        buffer[n]='\0';
        choice=0;
        int i=0;
        while(buffer[i]>='0'&&buffer[i]<='9'){
            choice=choice*10+(buffer[i]-'0');
            i++;
        }
        if(choice==1)addTask();
        else if(choice==2)viewTasks();
        else if(choice==3)deleteTask();
        else if(choice==4)break;
        else{
            write(1,"Do not be lazy, choose a number between 1 and 4\n",50);
        }
    }
}