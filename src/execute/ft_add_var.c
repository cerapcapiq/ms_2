
#include "../include/minishell.h"

struct LinkedList* display_linked_node(struct LinkedList *head)
{
    struct LinkedList* temp; 
    temp = head; // temp points to head;
    printf("\n");
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf(" %s->NULL\n", temp->data);
        }
        else {
            printf("\n%s->", temp->data);
        }
        temp = temp->next; // Traversing the List till end
    }
    printf("\n\n");
    return head;
}

char *ft_add_var_content(char *lineptr, struct LinkedList *head)
 {
        if (*lineptr == '$') lineptr++;
        char *contactName = lineptr;
        char *new = NULL;
        int i = 1;

        struct LinkedList *temp = head;
        while (temp != NULL)
        {
            if (strstr(temp->data, contactName))
            {
                new = temp->data;
                printf("%s whre is it", new);
            }
            temp = temp->next;
            i++;
        }
        return new;
 }

struct LinkedList *ft_create_list(struct LinkedList **head, char *str)
{
    char *nodedata = str;
    struct LinkedList *new = malloc(sizeof(struct LinkedList));
    new->data = nodedata;
    new->next = NULL;

  if (*head == NULL)
    *head = new;
  else
  {
    struct LinkedList *last = *head;

    while (last->next != NULL)
    {
        last = last->next;
    }
   last->next = new;  // keep address to link to next node
  }
  return (*head); 
}

char *get_the_new_var(char *lineptr, struct LinkedList *head)
{
    int i = 1;
    if (*lineptr == '$') lineptr++;
        char *contactName = lineptr;
    struct LinkedList *temp = head;
    while (temp != NULL)
    {
        if (strstr(temp->data, contactName))
        {
            printf("$var saved is : %s\n",temp->data);
            printf("saved in the %d th place\n", i);
            return contactName;
        }
        temp = temp->next;
        i++;
    }
    return (NULL);
}

struct LinkedList* ft_pass_content(char *cpy, struct LinkedList *head)
{
    struct LinkedList *temp = NULL;
    head = ft_create_list(&head, cpy);
    temp = head;
    return temp;
}

struct LinkedList* add_to_var(char *str, struct LinkedList *head)
{
    head = ft_pass_content(str, head);
    printf("this is sparta %s", str);
    return head;
}

char *strremove(char *str, const char *sub)
{
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}