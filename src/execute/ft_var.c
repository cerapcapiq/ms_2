#include "../include/minishell.h"
#include "../libft/libft.h"
#define j 2048

struct node* ft_link_env()
{
  char **s = environ;

  while (*s) 
  {
    head_ref = ft_var_main(*s, head_ref);
    s++;
  }
    return head_ref;
}

/*void check_old_path()
{
      char **s = environ;
      int i = 0;

  while (s[i]) 
  {
    if (strstr(s[i], "OLDPWD"))
    printf("%s\n [%d] \n", s[i], i);
    i++;
  }
}
*/

char * get_arg_to_del(char *lineptr)
{ 
    char *str = lineptr;
    char *arg = str;
    char after[j];

    if ((arg = strchr(str, ' '))) 
    {
        size_t len = strlen (++arg);
        if (len > j - 1) 
        {
            printf("error");
        } 
        memcpy (after, arg, len + 1);  
        
    }
    return (arg);
}

void show_var(char *lineptr, struct node *head)
 {
        if (*lineptr == '$') lineptr++;
        char *contactName = lineptr;
        int i = 1;

        struct node *temp = head;
        while (temp != NULL)
        {
            if (strstr(temp->data, contactName))
            {
                printf("$var saved is : %s\n",temp->data);
                printf("saved in the %d th place\n", i);
            }
            temp = temp->nxtpointer;
            i++;
        }
 }

struct node* delete_var(char *lineptr, struct node* head)
{
    struct node *tmp;
    struct node* temp = head; 
    char *p;

    p = get_arg_to_del(lineptr);
    printf("$var to be unset is %s", p);
    if (strstr(head->data, p))
    {
        printf("\nFirst element deleted is : %s\n", temp->data);
        head = temp->nxtpointer; // Advancing the head pointer
        temp->nxtpointer = NULL;
        free(temp); // Node is deleted
    }
    else 
    {   struct node *current = head;
        while(current->nxtpointer != NULL)
        {
            if (strstr(current->nxtpointer->data, p)) 
            {
            tmp = current->nxtpointer;
            current->nxtpointer = current->nxtpointer->nxtpointer;
            printf("\nElement deleted is : %s\n", tmp->data);
            free(tmp);
            break;
            }
            else
                current = current->nxtpointer;
        }
    }
    return (head);
}

void ft_linked_list(char *cpy)
{
    //head_ref = ft_link_env();
    //check_old_path();

    if (ft_strchr(cpy, '='))
           	head_ref = ft_var_main(cpy, head_ref);  
    if (ft_strchr(cpy, '$'))
            show_var(cpy, head_ref);
    if (strstr(cpy, "unset"))
            head_ref = delete_var(cpy, head_ref);
    if (!ft_strcmp(cpy, "env"))
        display_node(head_ref);
    else
        return;

}