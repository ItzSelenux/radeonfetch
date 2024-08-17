#include "radeonfetch.h"

int main(int argc, char *argv[])
{
home_dir = getenv("HOME");
readconf();

if (!usehumanvalues)
{
	mb="";
}

if (!showlevel)
{
	lvl="";
}

if (!showpercentage)
{
	perc="";
}

PrintInfo();
}