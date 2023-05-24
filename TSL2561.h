#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

void initTSL2561();
void no_connection();
void in_out_err();
float getVisibleLight();
float getInfraredLight();
float getFullSpectrumLight();
