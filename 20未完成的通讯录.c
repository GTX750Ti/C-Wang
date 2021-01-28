/*
 * 实现一个通讯录；
 * 通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
 * 提供方法：
 * 添加联系人信息
 * 删除指定联系人信息
 * 查找指定联系人信息
 * 修改指定联系人信息
 * 显示所有联系人信息
 * 清空所有联系人
 * 以名字排序所有联系人
 */
#include "conact.h"

int main() {
    contact_t *ct=InitContact();
    int quit=0;
    int select = 0;
    while (!quit){
        Menu();
        scanf("%d", &select);
        switch(select){
            case 1:
                AddPerson(&ct);
                break;
            case 2:
                DelPerson(ct);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                ShowContact(ct);
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                break;
            default:
                quit=1;
                SaveContact(ct);
                break;
        }
    }
    printf("ByeBye!\n");
    return 0;
}
