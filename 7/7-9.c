/* Functions like isupper can be implemented to save space or to save
   time. Explore both possibilities. */

int isupper_save_space(char c) {
    if (c >= 'A' && c <= 'Z')
	return 1;
    else
	return 0;
}

#define isupper_save_time(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0
