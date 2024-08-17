void getvalues(char *cfile, char **output)
{
	sprintf(fprefix, "/sys/class/drm/card%d/device/", devicenumber);

	int pathsize = snprintf(NULL, 0, "%s%s", fprefix, cfile) + 1;
	char *path = (char *)malloc(pathsize);
	if (path == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		*output = NULL;
		return;
	}

	snprintf(path, pathsize, "%s%s", fprefix, cfile);

	FILE *ffile = fopen(path, "r");
	free(path);
	if (ffile == NULL)
	{
		*output = "Unknown";
		return;
	}

	char line[ML];
	if (fgets(line, sizeof(line), ffile))
	{
		// Remove the newline character if it exists
		size_t len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		size_t output_size = len + 1;
		*output = (char *)malloc(output_size);
		if (*output == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			fclose(ffile);
			return;
		}
		strncpy(*output, line, output_size);
		(*output)[output_size - 1] = '\0';
	}
	else
	{
		*output = NULL;
	}
	fclose(ffile);
}