// declaration
int p_new ();
int p_add ();
int p_vote ();
int p_clean ();

struct Reader {
    char name[50];
    int code;
};

int p_init(struct Reader *tab_r, int *number);
int p_show (struct Reader *tab_r, int number);

