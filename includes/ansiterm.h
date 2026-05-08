void ansiterm_init (void);
void ansiterm_clean_up (void);

void ansiterm_out (const char *, int);

int ansiterm_getch (void);
int ansiterm_getche (void);
void ansiterm_delch (void);
void ansiterm_show_cursor(int visible);
void ansiterm_flush_input(void);
