char* my_strcpy(char* pd, char* ps) {
	char* po = pd;

	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}