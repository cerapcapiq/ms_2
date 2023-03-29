#include "../include/minishell.h"
#include "../libft/libft.h"
#define j 100000000

void show_var(char *lineptr, struct node *head)
{
    int i = 1;
    if (*lineptr == '$') lineptr++;
        char *contactName = lineptr;
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

char *ft_var_content(char *lineptr, struct node *head)
{
    if (*lineptr == '$') lineptr++;
        char *contactName = lineptr;
        char *new = NULL;
        int i = 1;

        struct node *temp = head;
        while (temp != NULL)
        {
            if (strstr(temp->data, contactName))
            {
                new = get_arg_content(temp->data);
            }
            temp = temp->nxtpointer;
            i++;
        }
    return new;
}

char * get_arg_to_del(char *lineptr)
{
    size_t i = 0;
    char *interesting_stuff;
    while (i<strlen(lineptr)) 
    {
        if (lineptr[i] ==  ' ')
        {
            interesting_stuff = lineptr + i + 1;
        }
        i++;
    }
    return interesting_stuff;
}

struct node * delete_var(char *lineptr, struct node* head_ref)
{
    struct node *tmp;
    struct node* temp = head_ref; 
    char *p;

    //if ((ft_strchr(str, ' ')) || (ft_strchr(str, '$')))
    //    str++;
    p = get_arg_to_del(lineptr);
    printf("$var to be unset is %s", p);
    if (strstr(head_ref->data, p))
    {
        printf("\nFirst element deleted is : %s\n", temp->data);
        head_ref = temp->nxtpointer; // Advancing the head pointer
        temp->nxtpointer = NULL;
        free(temp); // Node is deleted
    }
    else 
    {   struct node *current = head_ref;
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
    return head_ref;
}

struct node * del_path(char *now)
{
      char **s = &now;
      int i = 0;

  while (s[i]) 
  {
    if (strstr(s[i], "PATH"))
	{
    printf("%s\n [%d] \n", s[i], i);
	size_t len = ft_strlen(s[i]);
	memcpy(s[i], now, len);
	printf("%s\n [%d] \n", s[i], i);
	}
    i++;
  }
  return (head_ref);
}

void ft_add_back(char *cpy)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->data = cpy;     //Links the data part
        fnNode->nxtpointer = NULL; 
        tmp = head_ref;
        while(tmp->nxtpointer != NULL)
            tmp = tmp->nxtpointer;
        tmp->nxtpointer = fnNode;  //Links the address part
    }
}

void ft_linked_list(char *cpy)
{
    if (ft_strchr(cpy, '$'))
            show_var(cpy, head_ref);
    else if (strstr(cpy, "unset "))
          delete_var(cpy, head_ref);
    else if (!ft_strcmp(cpy, "unset $PATH"))
            del_path("$PATH=");
    else if (!ft_strcmp(cpy, "env") || !ft_strcmp(cpy, "export"))
        display_node(head_ref);
    else if (strstr(cpy, "export "))
    {
        cpy = strremove(cpy, "export ");
        cpy = get_the_new_var(cpy, head);
        if (cpy != NULL)
            ft_add_back(cpy);
        else
            printf("non exisxtent");
    }
    else if (ft_strchr(cpy, '=') && !strstr(cpy, "export ") && !strstr(cpy, "unset "))
    {
        head = add_to_var(cpy, head);
        display_linked_node(head);
    }
        
    else
        return;

}