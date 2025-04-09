#include<stdio.h>
#include<stdlib.h>
typedef struct st{
    int a;
    struct st *next;
}chain;

int hash(int a){
    return a%10;
}

void main(){
    int a[10]={5,11,12,1,2,2,3,4,5,1};
    int flag,res=0,len = 10,result[10],k;
    chain a1[10];
    for (int i = 0; i < 10; i++) {
        a1[i].a = 0;
        a1[i].next = NULL;
    }
    for(int i=0;i<len;i++){
        k = hash(a[i]);
        flag = 0;
        if(a1[k].a==0){
            a1[k].a = a[i];
            result[res++]=a[i];
        }
        else{
            chain *current = &a1[k];
            while(current){
                if(current->a==a[i]){
                    flag = 1;
                    break;
                }
                current = current->next;
            }
            if(flag==0){
                chain *newNode = (chain *)malloc(sizeof(chain));
                newNode->a = a[i];
                newNode->next = NULL;

                current = &a1[k];
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;

                result[res++] = a[i];
            }
        }
    }
    for(int i=0;i<res;i++){
        printf("%d ",result[i]);
    }
}
