// declaration


struct Reader {
    char name[50];
    int code;
};

struct Book {
    char author[26]; 
    char title[26];
    int votes;
    int points;
    int signature;
};

int p_new (struct Reader *tab_r, int *n_r);
int p_add (struct Book *tab_b, int *n_b);
int p_vote (struct Book *tab_b, int *n_b);
int p_clean (struct Reader *tab_r, int *n_r);
int p_init(struct Reader *tab_r, int *n_r, struct Book *tab_b, int *n_b);
int p_show (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b);
int p_fin (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b);

