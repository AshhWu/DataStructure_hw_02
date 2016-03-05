//使用CodeBolcks
#include <iostream>
#include <stack>
using namespace std;

void non_recursive_perm(char *a, int i, int n)
{
    struct perm_record      //把每個recursive calls中會變的資訊當作一個struct
    {
        char *a;            //parameter
        int i;              //parameter
        int stage;          //因recursive後還有程式碼要跑，記錄現在在哪一stage
    };

    stack<perm_record> perm_stack;  //perm_record的stack
    perm_record current_perm;       //創造一個current_perm當作現在的狀態
    current_perm.a=a;
    current_perm.i=i;
    current_perm.stage=0;

    perm_stack.push(current_perm);

    while(!perm_stack.empty())  //還有function call時
    {
        current_perm=perm_stack.top();  //進行最上層的perm
        perm_stack.pop();       //每個while loop會pop一個 perm object from the stack

        switch(current_perm.stage)
        {

            case 0:
                if(current_perm.i==n)                   //排完的話就print out
                {
                    for(int j=0; j <= n; j++) cout << current_perm.a[j];
                    cout<<" ";
                }
                else
                {
                    current_perm.stage=1;               //未排完就進入stage1排列
                    perm_stack.push(current_perm);
                }
                break;

            case 1:
                if(current_perm.i<n)                    //未排完
                {
                    for(int j=n;j>=current_perm.i;j--)  //因為我是將所有的排列都排完後才print out，其順序會整個顛倒，所以從後面
                    {                                   //開始排列，最後可以print出原本的順序
                        perm_record newPerm;            //create a new perm_record
                        newPerm.a=new char [n];
                        newPerm.i=current_perm.i+1;
                        newPerm.stage=0;
                        swap(current_perm.a[current_perm.i],current_perm.a[j]);
                        for(int k=0;k<=n;k++)           //複製swap後的current_perm.a到新perm
                            newPerm.a[k]=current_perm.a[k];
                        perm_stack.push(newPerm);       //push new perm
                        swap(current_perm.a[current_perm.i],current_perm.a[j]); //swap回來

                    }
                }
                break;
        }
    }
}
