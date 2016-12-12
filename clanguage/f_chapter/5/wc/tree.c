#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* talloc: make a tnode */
static struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}

/*
char *strdup(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
*/

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) { 	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else	/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
