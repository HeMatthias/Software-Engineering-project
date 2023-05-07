//volgorde log
//datum d:m:j//u:m:s//temp:..//licht:..//

#include <stdio.h>
#include <time.h>
#define FILE_LOC "/home/debie"

struct log_data_styl
{
	char times[100];
	char temp[10];
	char licht[10];
};

void time_set(char *);
void log_set(struct log_data_styl *);

int main(void)
{
	struct log_data_styl my_struct;
	time_set(my_struct.times);
	//printf("t:%s\r\n",my_struct.times); 
	sprintf(my_struct.temp,"404");
	sprintf(my_struct.licht,"405");
	log_set(&my_struct); 
	return 0;
}

void time_set(char *times)
{
	time_t temp_time = time(NULL);
	struct tm *mt = localtime(&temp_time);
	sprintf(times,"%2d:%2d:%2d||%2d:%2d:%2d",mt->tm_mday, mt->tm_mon + 1, mt->tm_year + 1900, mt->tm_hour, mt->tm_min, mt->tm_sec);
//	printf("Current date: %s\n", times);
}


void log_set(struct log_data_styl *data)
{
	char log_line[30];
	sprintf(log_line,"%s||%s||%s",data->times,data->temp,data->licht);
	printf("%s",log_line);

}
