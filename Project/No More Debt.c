#include <stdio.h>
#include <string.h>
int main(){
    char student[10],add[10]; // cm,up,ex,mo เปนแค่ตัวเช็คค่า string อย่าไปใส่ใจ
    int check,cm,up,ex,mo,money,person = 10; // money คือ เงินที่จะบวกหรือลบให้กับ id นั้นๆ
    struct data
    {
        int id,debt;
    }user[person];
    for(int i = 0; i < person; i++){
        user[i].id = 61070001 + i;
        user[i].debt = 0;
    }
    scanf("%s",student);
    cm = strcmp(student,"admin");
    if (cm == 0) {
        while(1){
            scanf("%s",add);
            up = strcmp(add,"update");
            ex = strcmp(add,"exit");
            mo = strcmp(add,"month");
            if (up == 0) {
        scanf("%d",&check);
        check -= 61070001;
        printf("update DATA\n");
        scanf("%d",&money);
        user[check].debt += money;
            }
            else if (mo == 0) {
        scanf("%d",&money);
        for (int i = 0; i < person; i++){
            user[i].debt += money;
        }  
            }
        if (ex == 0) {
            break;
            }
        }
        for(int i = 0; i < person; i++){
        printf("%d\n",user[i].id);
        printf("%d\n",user[i].debt);
        }
    }
    return 0;
}
