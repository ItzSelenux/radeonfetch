void mapgpu()
{
	FILE *file = fopen("/usr/share/hwdata/pci.ids", "r");
	if (file == NULL)
	{
		name = "Unknown AMD GPU";
		return;
	}

	const char *npciid = pciid + 2;
	char line[256];

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (strstr(line, npciid) != NULL)
		{
			line[strcspn(line, "\n")] = 0;

			char *token = NULL;
			char *temp = line;
			while ((temp = strstr(temp, "  ")) != NULL)
			{
				token = temp;
				temp += 2;
			}

			if (token != NULL)
			{
				token += 2;

				if (strstr(token, "Graphics") != NULL ||
					strstr(token, "Radeon") != NULL ||
					strstr(token, "Vega") != NULL)
				{
					name = malloc(strlen(token) + 1);
					if (name != NULL)
					{
						strcpy(name, token);
					}
					break;
				}
			}
			else
			{
				if (strstr(line, "Graphics") != NULL ||
					strstr(line, "Radeon") != NULL ||
					strstr(line, "Vega") != NULL)
				{
					name = malloc(strlen(line) + 1);
					if (name != NULL)
					{
						strcpy(name, line);
					}
					break;
				}
			}
		}
	}

	fclose(file);
}

void mapdriver ()
{
	driver += strlen("DRIVER=");
}



void mappwr(char *var, const char *file)
{
	if (var != "Unknown")
	{
		char fullpath[256];
		snprintf(fullpath, sizeof(fullpath), "%s%s", fprefix, file);

		FILE *fp = fopen(fullpath, "r");
		if (fp == NULL)
		{
			strcpy(var, "Unknown");
			return;
		}

		char line[256];
		while (fgets(line, sizeof(line), fp) != NULL)
		{
			if (strchr(line, '*') != NULL)
			{
				if (!showspeedindex)
				{
					char *colon_pos = strstr(line, ": ");
					if (colon_pos != NULL)
					{
						colon_pos += 2;
						char *newline_pos = strchr(colon_pos, '\n');
						if (newline_pos != NULL)
						{
							*newline_pos = '\0';
						}
						strcpy(var, colon_pos);
					}
					else
					{
						strcpy(var, "Unknown");
					}
				}
				else
				{
					line[strcspn(line, "\n")] = '\0';
					strcpy(var, line);
				}

				size_t len = strlen(var);
				if (len > 0 && var[len - 1] == '*')
				{
					var[len - 1] = '\0';
				}

				fclose(fp);
				return;
			}
		}

		strcpy(var, "");
		fclose(fp);
	}
}


void mapttl()
{
	if (ttl != "Unknown")
	{
		char status[10];

		if (strstr(ttl, "enabled"))
		{
			strcpy(status, "enabled");
		}
		else
		{
			strcpy(status, "disabled");
		}

		char *comma_pos;
		char result[256];
		char *interval;

		comma_pos = strchr(ttl, ',');
		if (comma_pos != NULL)
		{
			comma_pos++;

			strncpy(result, comma_pos, sizeof(result) - 1);
			result[sizeof(result) - 1] = '\0';

			interval = result;
		}
		else
		{
			interval = "With unknown interval";
		}

		sprintf(ttl, "%s,%s", status, interval);
	}
}


void mapmem(char *var)
{
	if (usehumanvalues && var != "Unknown")
	{
		unsigned long long bytes = strtoull(var, NULL, 10);
		unsigned long long megabytes = bytes / (1024 * 1024);
		snprintf(var, 20, "%llu", megabytes);
	}
	else if (var == "Unknown")
	{
		mb = "";
	}
}