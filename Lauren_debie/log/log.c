#include "log.h"
int main(void)
{
	struct log_data_styl my_struct;
	time_set(my_struct.times);
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
}


void log_set(struct log_data_styl *data)
{
	int max_length = 29;
	char log_line[30];
	snprintf(log_line, max_length, "%s||%s||%s", data->times, data->temp, data->licht);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    	struct stat attributen;
	struct log_file log_f_1;
	struct log_file log_f_2;
	struct log_file log_f_3;
    	// kijk log file 1 bestaat
    	if (stat(LOG_1, &attributen) == 0)
	{
		//zo ja zet in struct
		log_f_1.bestaat = 1;

		//zet de laatste edit date
		log_f_1.wijziging = attributen.st_mtime;

        	// pak grote bestant
        	log_f_1.size = attributen.st_size;
    	}
	else
	{
		//zet dat log file 1 niet bestaat
		log_f_1.bestaat = 0;
		//printf("bestant bestaat niet");
	}

/////////////////////////////////////////////////////
// kijk log file 2 bestaat
        if (stat(LOG_2, &attributen) == 0)
        {
                //zo ja zet in struct
                log_f_2.bestaat = 1;

                //zet de laatste edit date
                log_f_2.wijziging = attributen.st_mtime;

                // pak grote bestant
                log_f_2.size = attributen.st_size;
        }
        else
        {
                //zet dat log file 1 niet bestaat
                log_f_2.bestaat = 0;
               // printf("bestant bestaat niet");
        }
//////////////////////////////////////////////////////////
// kijk log file 3 bestaat
        if (stat(LOG_3, &attributen) == 0)
        {
                //zo ja zet in struct
                log_f_3.bestaat = 1;

                //zet de laatste edit date
                log_f_3.wijziging = attributen.st_mtime;

                // pak grote bestant
                log_f_3.size = attributen.st_size;
        }
        else
        {
                //zet dat log file 1 niet bestaat
                log_f_3.bestaat = 0;
               // printf("bestant bestaat niet");
        }
	//kijk of alle logfilles bestaan
	int schrijf_log =1;

	if(log_f_1.bestaat == 1 && log_f_2.bestaat == 1 && log_f_3.bestaat == 1 )
	{
		//vergelijk datum
		printf("%ld\r\n",log_f_1.wijziging);
		printf("%ld\r\n",log_f_2.wijziging);
		printf("%ld\r\n",log_f_3.wijziging);
		if(log_f_1.wijziging < log_f_2.wijziging)
		{
			schrijf_log = 2;
			if(log_f_2.wijziging < log_f_3.wijziging)
			{
				schrijf_log = 3;
			}
		}
		else
		{
			if(log_f_1.wijziging < log_f_3.wijziging)
			{
				schrijf_log = 3;
			}
		}

	}
	else
	{
		if(log_f_1.bestaat == 1)
		{
			schrijf_log = 1;
		}
		if(log_f_2.bestaat == 1)
                {
                        schrijf_log = 2;
                }
		if(log_f_3.bestaat == 1)
                {
                        schrijf_log = 3;
                }
	}
	printf("schrijft:%d",schrijf_log);
	if(schrijf_log = 1)
	{
		if(log_f_1.size > max_size)
		{
			remove(LOG_2);
			FILE *fp =fopen(LOG_2,"w");
			fprintf(fp,"%s\r\n",log_line);
			fclose(fp);
		}
		else
		{
			FILE *fp =fopen(LOG_1,"a");
                        fprintf(fp,"%s\r\n",log_line);
                        fclose(fp);
		}
	}
	if(schrijf_log = 2)
        {
                if(log_f_2.size > max_size)
                {
                        remove(LOG_3);
                        FILE *fp =fopen(LOG_3,"w");
                        fprintf(fp,"%s\r\n",log_line);
                        fclose(fp);
                }
                else
                {
                        FILE *fp =fopen(LOG_2,"a");
                        fprintf(fp,"%s\r\n",log_line);
                        fclose(fp);
                }
        }
	if(schrijf_log = 3)
        {
                if(log_f_3.size > max_size)
                {
                        remove(LOG_1);
                        FILE *fp =fopen(LOG_1,"w");
                        fprintf(fp,"%s\r\n",log_line);
                        fclose(fp);
                }
                else
                {
                        FILE *fp =fopen(LOG_3,"a");
                        fprintf(fp,"%s\r\n",log_line);
                        fclose(fp);
                }
        }


}


