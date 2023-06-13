#include "temp.h"
void init_temp(int arg)
{
//als ik 1 mee krijg zet de tempratuur driver op
    if(arg == 1)
    {
        system("sudo ./temperatuurDriver d &"); //voor linux comando uit;
    }

    if(arg == 0)
    {
//maak vars
        char temp[20];
	char temp_2[20];
	int x = 0;
//voer comando uit dat het prosses ID trug geef
        int pid = system("ps aux | grep \"./temperatuurDriver d\" | head -n 1 | awk '{print $2}'");
//pak de output van vorige comando en steek het in een string
        sprintf(temp, "%d", pid);
	char temp_3[20];
//maak een kill comando met vorige output
	sprintf(temp_3, "sudo kill %s", temp);
//voer kill prosses comando uit;
	system(temp_3);
    }


}

void temp_read(char* temp)
{
//open file
	FILE *fp;
	fp = fopen("/tmp/tmpValue","r");
//lees file
	fscanf(fp, "%s", temp);

//sluit file
	fclose(fp);

}
