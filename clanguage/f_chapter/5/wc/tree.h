struct tnode {		/* the tree node: */
	char *word;		/* pointers to the text */
	int count;		/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
};

/* static char *strdup(char *s); */
static struct tnode *talloc(void);

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
