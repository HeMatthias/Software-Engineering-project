//volgorde log
//datum d:m:j//u:m:s//temp:..//licht:..//



#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
// hier wortd de plaats van waar de logvile geschreven wort met de naam gezet
#define LOG_1 "log_1.log"
#define LOG_2 "log_2.log"
#define LOG_3 "log_3.log"

//hier wort de max size van de logfile gedefineert
#define max_size 1024

//dit is een struct type voor mijn data in te zetten om door tegeven en gebruiken
struct log_data_styl
{
        char times[100];
        char temp[10];
        char licht[10];
};

struct log_file
{
        int bestaat;
        off_t size;
        time_t wijziging;
};

//met deze funksie kan men de current time haalen men moet hier een poineter van een char megeven met voorkeur die van struct log_data_styl
void time_set(char *);

//met deze funksie wordt er gelogt men moet de struct log_data_styl megeven.
void log_set(struct log_data_styl *);
