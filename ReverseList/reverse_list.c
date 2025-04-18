#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rverseList(struct Node *head)
{
  struct Node *travel = head;
  struct Node *tmp;
  struct Node *nextToReverse;
  while (travel->next)
  {       //  2             1
	  // previous <-  travel (head)
	  //  |
	  //  v
	  // tmp 
	  //
	  //let tmp as travel
	  //
	nextToReverse = travel->next;
        tmp = malloc(sizeof(tmp));
  	tmp->data = travel->next->data;
	tmp->next = travel; //ie. reverse
	printf("data: %d\n",tmp->data);

	travel = nextToReverse;
  }
  printf("result list: \n");
  travel = head = tmp;
  while (travel)
  {
          if (travel != NULL )
          {
            printf("%d\n", travel->data);
          }
          if (travel->next != NULL)
          {
            travel = travel->next;
          }
          else
          {
            travel = NULL;
          }
  }
   return NULL;
}

int main()
{
  struct Node *header;
  header = malloc(sizeof(header));
  struct Node *previous;
  previous = malloc(sizeof(previous));
  struct Node *current;
  //[4, ] <- [3, ] ... <- [1, ] (header)

  previous->data = 4;      //[4, ]
  previous->next = NULL;

  for (int i = 3; i >= 1; i--)    //...    [3, ]
  {
          current = malloc(sizeof(current));
	  current->data = i;
	  current->next = previous;
          
	  previous = current;

	  printf("%d", i);
    if (i == 1)
    {
       header = current;
    }
  }
 
  printf("The original list:\n");
  struct Node *travel = header;
  while (travel)
  {
	  if (travel != NULL )
	  {
	    printf("%d\n", travel->data);
	  }
	  if (travel->next != NULL)
	  {
	    travel = travel->next;
	  }
	  else
	  {
	    travel = NULL;
	  }
  }
printf("reverse...\n");
  struct Node* newHead = rverseList(header);

  return 0;
}



