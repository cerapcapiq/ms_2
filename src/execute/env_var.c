
#include "../include/minishell.h"




struct node* createList(struct node **head_ref, char *lineptr)
{
  char *nodedata = lineptr;
  struct node *new = malloc(sizeof(struct node));
  new->data = nodedata;
  new->nxtpointer = NULL;

  if (*head_ref == NULL)
    *head_ref = new;
  else
  {
    struct node *last = *head_ref;

    while (last->nxtpointer != NULL)
    {
        last = last->nxtpointer;
    }
   last->nxtpointer = new;  // keep address to link to next node
  }
  return (*head_ref);
}

struct node* display_node(struct node *head_ref)
{
    struct node* temp; 
    temp = head_ref; // temp points to head;
    printf("\n");
    if (temp == NULL)
        printf(" NULL\n\n");
    while (temp != NULL) {
        if (temp->nxtpointer == NULL) {
            printf(" %s->NULL\n", temp->data);
        }
        else {
            printf("\n%s->", temp->data);
        }
        temp = temp->nxtpointer; // Traversing the List till end
    }
    printf("\n\n");
    return head_ref;
}

char *get_name(char *linestr)
{
    char *str = linestr;
    char *cpy;

    printf("%s\n", str);
    int i = 0;
    while (str[i] != '=')
        i++;
    cpy = ft_substr(str, 0, i);
    printf ("the $var is %s\n", cpy); 
    return (cpy);

}

void get_arg(char *lineptr)
{ 
    char *str = lineptr;
    char *arg = str;
    size_t j = 0;
    char after[j];

    if ((arg = ft_strchr(str, '='))) 
    {
        size_t len = ft_strlen (++arg);
        if (len > j - 1) 
        {
            printf("error");
        } 
        memcpy (after, arg, len + 1);
        printf ("the arg(value) is %s\n", arg);    
    }
}

struct node *ft_var_main(char *argv, struct node *head_ref)
{  
    struct node *temp = NULL;

    head_ref = createList(&head_ref, argv);
    temp = head_ref;
    return temp;

}