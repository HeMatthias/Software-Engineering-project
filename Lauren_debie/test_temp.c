#include "temp.h"
int main(void)
{
    init_temp(1);
        sleep(1);
        char temp[20];
        char *temp2;
        temp2 = temp;
        temp_read(temp2);
        printf("waarde is:%s\r\n",temp);
    init_temp(0);
    return 0;
}
