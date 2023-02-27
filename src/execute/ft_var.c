#include "../include/minishell.h"
#include "../libft/libft.h"
#define j 100000000

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


void get_env()
{
  char **s = environ;
  int i = 0;

  while (s[i] != NULL) 
  {
    printf("[%d] = %s \n",i, s[i]);
    i++;
  }
    return;
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
/*
char * get_arg_to_del(char *lineptr)
{ 
    char *str = lineptr;
    char *arg = str;
    char after[j];

    if ((arg = ft_strchr(str, ' ')) || (arg = ft_strchr(str, '$'))) 
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
*/
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

/*
char *select_var(char *lineptr, struct node *head_ref)
{
    if (*lineptr == '$') lineptr++;
    char *var_chosen = lineptr;
    int i = 0;
    
    struct node* temp = head_ref;
    while (temp != NULL)
    {
        if (strstr(temp->data, var_chosen))
        {
            retu
        }
    }
}
*/

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
    if (ft_strchr(cpy, '='))
    	ft_add_back(cpy); 
    else if (ft_strchr(cpy, '$'))
            show_var(cpy, head_ref);
    else if (strstr(cpy, "unset"))
          delete_var(cpy, head_ref);
    else if (!ft_strcmp(cpy, "unset $PATH"))
            del_path("$PATH=");
    else if (!ft_strcmp(cpy, "env"))
     
        display_node(head_ref);
        //ft_link_env();}
        //display_node(head_ref);}
    else
        return;

}