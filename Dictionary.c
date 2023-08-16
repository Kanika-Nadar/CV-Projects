 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<conio.h>

  struct BSTnode {
        char word[128], meaning[256], pronun[100], pos[100];
        struct BSTnode *left, *right;
  };

  struct BSTnode *root = NULL;

  struct BSTnode * createNode(char *word, char *meaning, char *pronun, char *pos) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        strcpy(newnode->pronun, pronun);
        strcpy(newnode->pos, pos);
        strcpy(newnode->meaning, meaning);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word, char *meaning, char *pronun, char *pos) {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = createNode(word, meaning, pronun, pos);
                return;
        }
        for (current = root; current !=NULL;
           current = (res > 0) ? current->right : current->left) { /*If the element to be inserted is greater than the data at the node,
                                                                   then we insert it in the right subtree*/
                res = strcasecmp(word, current->word);
                if (res == 0) {
                        printf("Duplicate entry!!\n");
                        return;
                }
                parent = current;
        }
        newnode = createNode(word, meaning, pronun, pos);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  void deleteNode(char *str) {
        struct BSTnode *parent = NULL, *current = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!root) {
                printf("BST is not present!!\n");
                return;
        }
        current = root;
        while (1) {
                res = strcasecmp(current->word, str);
                if (res == 0)
                        break;
                flag = res;
                parent = current;
                current = (res > 0) ? current->left : current->right;
                if (current == NULL)
                        return;
        }
        /* deleting leaf node */
        if (current->right == NULL) {
                if (current == root && current->left == NULL) {
                        free(current);
                        root = NULL;
                        return;
                } else if (current == root) {
                        root = current->left;
                        free (current);
                        return;
                }

                flag > 0 ? (parent->left = current->left) :
                                (parent->right = current->left);
        } else {
                /* delete node with single child */
                temp = current->right;
                if (!temp->left) {
                        temp->left = current->left;
                        if (current == root) {
                                root = temp;
                                free(current);
                                return;
                        }
                        flag > 0 ? (parent->left = temp) :
                                        (parent->right = temp);
                } else {
                        // delete node with two children - delete the node set null pointer to its parent's left pointer.
                        struct BSTnode *successor = NULL;
                        while (1) {
                                successor = temp->left;
                                if (!successor->left)
                                        break;
                                temp = successor;
                        }
                        temp->left = successor->right;
                        successor->left = current->left;
                        successor->right = current->right;
                        if (current == root) {
                                root = successor;
                                free(current);
                                return;
                        }
                        (flag > 0) ? (parent->left = successor) :
                                        (parent->right = successor);
                }
        }
        free (current);
        return;
  }

  void findElement(char *str) {
        struct BSTnode *temp = NULL;
        int flag = 0, res = 0;
        if (root == NULL) { //If the subtree is empty, the search is unsuccessful
                printf("Binary Search Tree is out of station!!\n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) { //If the target value is equal, the search is successful.

                        printf("Word          : %s", str);
                        printf("Pronunciation : %s", temp->pronun);
                        printf("Part of Speech: %s", temp->pos);
                        printf("Meaning       : %s", temp->meaning);
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right; //If target value is less, search the left subtree else search the right subtree.

        }
        if (!flag)
                printf("\nSearch Element not found in Binary Search Tree\n");
        return;
  }

  void inorderTraversal(struct BSTnode *myNode) {
        if (myNode) {
            //system("cls");
                inorderTraversal(myNode->left);
                printf("Word          : %s", myNode->word); //printing the word
                printf("Pronunciation : %s", myNode->pronun);
                printf("Part of Speech: %s", myNode->pos);
                printf("Meaning       : %s", myNode->meaning);
                printf("\n");
                inorderTraversal(myNode->right);
        }
        return;
  }

  int main() {
      printf("\n\n\t\t\t\t\t\t------UNABRIDGED-----\n\n");
        int ch;
        char str[128], meaning[256], pos[100], pronun[100];
        while (1) {
                 system("COLOR F5");
                 //system("pause");
                printf("\n1. Insert a word\n2. Delete a word\n");
                printf("3. Search a word\n4. Display words\n");
                printf("5. Exit\n\nEnter your choice: ");
                scanf("%d", &ch);
                getchar();
                switch (ch) {
                        case 1:
                                printf("\nEnter word: ");
                                fgets(str, 100, stdin);
                                printf("Pronunciation: ");
                                fgets(pronun, 100, stdin);
                                printf("Part of speech: ");
                                fgets(pos, 100, stdin);
                                printf("Meaning: ");
                                fgets(meaning, 256, stdin);
                                insert(str, meaning, pronun, pos);
                                break;
                        case 2:
                                printf("\nEnter the word to delete: ");
                                fgets(str, 100, stdin);
                                deleteNode(str);
                                break;
                        case 3:
                                printf("\nEnter the search word: ");
                                fgets(str, 100, stdin);
                                findElement(str);
                                break;
                        case 4:
                                inorderTraversal(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("\nYou have entered wrong option\n");
                                break;
                }
        }
        return 0;
  }
