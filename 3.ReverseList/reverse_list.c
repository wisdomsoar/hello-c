#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rverseList(struct Node *head)
{
  if (!head)
  {
    return head;
  }

  struct Node *prev = NULL;
  struct Node *curr, *next;

  // 1 -> 2 -> 3 -> 4
  // =head
  // =curr
//***************************************
  // Step 1: Find the "next" node
  //         1 -> 2 -> 3 -> 4
  //         =head
  //         =curr
  //              =next!!!
  //-------------------------------------
  // Step 2: Change the next pointer of current node (The main link we want to reverse!)
  //      !!!
  // NULL <- 1    2 -> 3 -> 4
  //         =head
  //         =curr ( curr->next=NULL (prev) !!! )
  //              =next 
  //-------------------------------------
  // Step 3: previous node 
  // NULL <- 1    2 -> 3 -> 4
  //         =head
  //         =curr
  //         =prev!!!
  //-------------------------------------      
  // NULL <- 1    2 -> 3 -> 4
  //         =head
  //         =prev
  //              =next
  //              =curr!!!
  //-------------------------------------      
  curr = head;
  while (curr)            //    curr = head   (Step2) curr->next = prev (NULL) for first step
  {                       //    v
    next = curr->next;    //    1 -> 2 -> 3 -> 4
    curr->next = prev;    //    ^    ^next (Step1)  <- curr
    prev = curr;          //    L prev (Step3)
    curr = next;
  }
  return prev;
}

int main()
{
  struct Node *header;
  //header = malloc(sizeof(header));
  struct Node *previous;
  previous = malloc(sizeof(previous));
  struct Node *current;
  //[4, ] <- [3, ] ... <- [1, ] (header)

  previous->data = 4;      //[4, ]
  previous->next = NULL;

  for (int i = 3; i >= 1; i--)    //...    [3, ], ...
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
  travel = newHead;

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


  return 0;
}



