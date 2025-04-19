#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

struct Node* DeleteNode(struct Node * head, int val)
{
  struct Node *prev;
  struct Node *curr;      // 1 -> 2 -> 3 -> 4 -> NIL
  struct Node *next;      // p    c   [n]        Step 1
                          //   ------>           Step 2
  prev = NULL;
  curr = head;
 
  while (true)
  {
    next = curr->next;
    if (curr->data == val)
    {
       free(curr);
       if (prev == NULL)
       {
           head = next;
       }
       else
       {
          prev->next = next;
       }
       break;
    }
    if (next)
    {
      prev = curr;
      curr = next;
      next = next->next;
    }
    else
    {
      break;
    }
  }
  return head;
}

void PrintList(struct Node *node)
{
  while (node)
  {
          if (node != NULL )
          {
            printf("%d\n", node->data);
          }
          if (node->next != NULL)
          {
            node = node->next;
          }
          else
          {
            node = NULL;
          }
  }

}

int main()
{
  struct Node *header;
  struct Node *previous;
  previous = malloc(sizeof(previous));
  struct Node *current;
  //[4, ] <- [3, ] ... <- [1, ] (header)

  previous->data = 4;      //[4, ]
  previous->next = NULL;

  //[prepare the test linked list data
  for (int i = 3; i >= 1; i--)    //...    [3, ], ...
  {
    current = malloc(sizeof(current));
    current->data = i;
    current->next = previous;
    previous = current;
    //printf("%d", i);
    if (i == 1)
    {
       header = current;
    }
  }
  //]end of prepare the test linked list data
 
  printf("The original list:\n");
  struct Node *travel = header;
  PrintList(travel);

printf("reverse...\n");
  struct Node* newHead = rverseList(header);
  travel = newHead;
  PrintList(travel);


printf("Delete 4...\n");
  newHead = DeleteNode(newHead, 4);

  travel = newHead;
  PrintList(travel);

  return 0;
}



