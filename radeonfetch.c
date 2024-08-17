#include "radeonfetch.h"

int main(int argc, char *argv[])
{
home_dir = getenv("HOME");
readconf();

	if (argc > 1)
	{
		char *endptr;
		devicenumber = strtol(argv[1], &endptr, 10);
	}

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