#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_utils.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

NODE *root = NULL;

// Returns true if user types "yes" or "y" (upper or lower case)
// and returns false if user types "no" or "n". Keeps
// prompting otherwise.

BOOL yes_response()
{

  char response[100];

    while(1) {
        read_line(response);

        if(strcasecmp(response, "yes") == 0 || strcasecmp(response, "y") == 0)
            return TRUE;
        else if(strcasecmp(response, "no") == 0 || strcasecmp(response, "n") == 0)
            return FALSE;
        else
            printf("Please enter 'yes' or 'no'.\n");
    }
  //Hint: You might consider using the C library function strcasecmp()

}

// This procedure creates a new NODE and copies
// the contents of string s into the 
// question_or_animal field.  It also initializes
// the left and right fields to NULL.
// It should return a pointer to the new node

NODE *new_node(char *s)
{

  NODE *node = (NODE *) malloc(sizeof(NODE));
    if(node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(node->question_or_animal, s);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This is the procedure that performs the guessing.
// If the animal is not correctly guessed, it prompts
// the user for the name of the animal and inserts a
// new node for that animal into the tree.

void guess_animal()
{
  // If the root is NULL, then there are no animals in 
  // the tree. Prompt the player for the name of an 
  // animal, create a node for that animal, and make
  // that node the root of the tree.

  if (root == NULL) {
        char animal[200];
        printf("What animal were you thinking of?\n");
        read_line(animal);
        root = new_node(animal);
        return;
    }

    NODE *current = root;
    NODE *previous = NULL;
    BOOL left_child_taken = FALSE;

    while(current->left && current->right) {
        printf("%s\n", current->question_or_animal);
        BOOL answer = yes_response();
        previous = current;

        if(answer) {
            current = current->left;
            left_child_taken = TRUE;
        } else {
            current = current->right;
            left_child_taken = FALSE;
        }
    }

    printf("Is it %s?\n", current->question_or_animal);
    if(yes_response()) {
        printf("I guessed it right!\n");
        return;
    }

    char new_animal[200], new_question[200], old_animal_answer[5];
    printf("What animal were you thinking of?\n");
    read_line(new_animal);
    printf("Provide a yes or no question distinguishing %s from %s.\n", new_animal, current->question_or_animal);
    read_line(new_question);
    printf("What would be the answer for %s? (yes or no)\n", new_animal);
    read_line(old_animal_answer);

    NODE *old_animal_node = new_node(current->question_or_animal);
    NODE *new_animal_node = new_node(new_animal);

    if(strcasecmp(old_animal_answer, "yes") == 0 || strcasecmp(old_animal_answer, "y") == 0) {
        current->left = new_animal_node;
        current->right = old_animal_node;
    } else {
        current->left = old_animal_node;
        current->right = new_animal_node;
    }

    strcpy(current->question_or_animal, new_question);

    /*
      Otherwise (i.e. if the root is not NULL)
      Then descend down the tree. At each node encountered:

      If the left and right fields of the node are not NULL, i.e. the node
      is an interior node and must contain a question, then:
      - print the question_or_answer field, which will be a yes/no question.
      - read the response from the user
      - If the response is yes, follow the left field to the next node. Otherwise,
        follow the right field.
    */

  //FILL IN CODE HERE
      

  /*
      Otherwise, if the left and right fields are NULL (i.e. the node is a leaf), 
      then the question_or_animal field contains an animal. Print the
      the question_or_animal field as the guess and prompt the user
      if the guess was correct. If the guess was correct, then 
      return. Otherwise, do the following:
           - prompt the user for the name of the new animal she was thinking of
           - prompt the user for a yes or no question distinguishing the new animal from the guessed animal
	   - ask the user what the answer for the new animal would be (yes or no)
           - create a new node with the new animal in the question_or_animal field
	   - create another new node that has the guessed animal in the question_or_animal field
           - make the two new nodes the children of the current node, where the animal for which the
             answer to the question is "yes" is the left child and the other animal is the right child.
           - overwrite the question_or_animal field of the current node with the new question.

      Note that the tree is a stricly binary tree, i.e. left and right fields of each node are either both NULL or 
      both valid pointers to child nodes (in other words, each node is a leaf or has exactly two children).
    */

  //FILL IN CODE HERE

}



//This code is complete. Just add comments where indicated.

int main()
{ int i;
  BOOL done = FALSE;

  //Opens the data file for reading.
  FILE *datafile = fopen("data.dat", "r"); 

  //If datafile is not found, print error and exit.

  if (datafile == NULL) {
    printf("data.dat not found\n");
    exit(1);
  }

  //Opens the backup file for writing.
  FILE *backupfile = fopen("data.dat.bak", "w");

  //Reads the tree from the data file.
  root = read_tree(datafile);

  //call write_tree() to write the initial tree to the
  //backup file (i.e. to backup the tree data)
  //Writes the initial tree to the backup file.
  write_tree(root,backupfile);

  //close both files (for now)
  fclose(backupfile);
  fclose(datafile);

  printf("Welcome to the animal guessing game (like 20 questions).\n");
  //Play the guessing game until user wants to quit.
  do { 
    printf("\nThink of an animal...\n");
    guess_animal();  //insert comment here
    printf("\nDo you want to play again? (yes/no) >");
  } while (yes_response());  //insert comment here


  //now open the "data.dat" file for writing
  datafile = fopen("data.dat", "w");

  //Write the updated tree back to the data file.
  write_tree(root, datafile);

  //close the data.dat file
  fclose(datafile);

}

