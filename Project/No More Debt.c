#include <stdio.h>
#include <string.h>
int main(){
    char student[10],add[10]; // cm,up,ex,mo เปนแค่ตัวเช็คค่า string อย่าไปใส่ใจ
    int check,cm,up,ex,mo,bk,money,person = 10,status = 0; // money คือ เงินที่จะบวกหรือลบให้กับ id นั้นๆ
    struct data
    {
        int id,debt;
    }user[person];
    for(int i = 0; i < person; i++){
        user[i].id = 61070001 + i;
        user[i].debt = 0;
    }
    while(1){
        if (status == 0){
        printf("ID student\n");
        scanf("%s",student);
        cm = strcmp(student,"admin");
        ex = strcmp(student,"exit");
        status = 1;
        }
        else if (cm == 0) {
            printf("option\n");
            scanf("%s",add);
            up = strcmp(add,"update");
            mo = strcmp(add,"month");
            bk = strcmp(add,"back");
            cm = 1;
        }
        else if (up == 0) {
            printf("what is update ID student\n");
            scanf("%d",&check);
            check -= 61070001;
            printf("how much\n");
            scanf("%d",&money);
            user[check].debt += money;
            up = 1;
            cm = 0;
        }
        else if (mo == 0) {
            printf("pay of the month\n");
            scanf("%d",&money);
            for (int i = 0; i < person; i++){
                user[i].debt += money;
                mo = 1;
                cm = 0;
            }  
        }
        else if (bk == 0) {
            status = 0;
            bk = 1;
            }
        else if (ex == 0){
            ex = 1;
            break;
        }
        else{
            check = atoi(student) - 61070001;
                printf("History of %d\n",check + 61070001);
                printf("%d\n",user[check].id);
                printf("%d\n",user[check].debt);          
            status = 0;
        }
    }

    return 0;
}
