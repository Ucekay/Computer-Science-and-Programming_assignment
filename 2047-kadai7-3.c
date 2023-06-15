#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} CELL;

CELL head;

void free_memory(CELL *head) {
  CELL *p, *q;
  for (p = head; p != NULL;) {
    q = p->next;
    free(p);
    p = q;
  }
}

void InsertCell(int x) {
  CELL *p, *new;
  new = (CELL *)malloc(sizeof(CELL));
  new->data = x;
  for (p = &head; p->next != NULL; p = p->next) {
    if (new->data < (p->next)->data) {
      new->next = p->next;
      p->next = new;
      return;
    } else if (new->data == (p->next)->data) {
      return;
    }
  }
  new->next = NULL;
  p->next = new;
}

void DeleteCell(int x) {
  CELL *p, *q;
  int i = 0;
  p = &head;
  while (p->next != NULL) {
    if (x == (p->next)->data) {
      i += 1;
      q = (p->next);
      p->next = q->next;
      free(q);
    } else {
      p = p->next;
    }
  }
  if (i == 0) {
    printf("そのような数字はありません。\n");
  }
}

void DeletePositiveCell() {
  CELL *p, *q;
  p = &head;
  while (p->next != NULL) {
    if ((p->next)->data > 0) {
      q = p->next;
      p->next = q->next;
      free(q);
    } else {
      p = p->next;
    }
  }
  return;
}

void DeleteNegativeCell() {
  CELL *p, *q;
  p = &head;
  while (p->next != NULL) {
    if ((p->next)->data < 0) {
      q = p->next;
      p->next = q->next;
      free(q);
    } else {
      p = p->next;
    }
  }
}

void DeleteEvenCell() {
  CELL *p, *q;
  p = &head;
  while (p->next != NULL) {
    if ((p->next)->data == 0) {
      p = p->next;
    } else if ((p->next)->data % 2 == 0) {
      q = p->next;
      p->next = q->next;
      free(q);
    } else {
      p = p->next;
    }
  }
}

void PrintList() {
  CELL *p;
  for (p = &head; p->next != NULL; p = p->next) {
    printf("%d ", (p->next)->data);
  }
  printf("\n");
}

int Command(int c) {
  int x;
  switch (c) {
  case 'i':
    printf("整数を入力してください： ");
    scanf("%d", &x);
    InsertCell(x);
    fflush(stdin);
    return 1;
  case 'd':
    printf("整数を入力してください： ");
    scanf("%d", &x);
    DeleteCell(x);
    fflush(stdin);
    return 1;
  case 'p':
    DeletePositiveCell();
    fflush(stdin);
    return 1;
  case 'n':
    DeleteNegativeCell();
    fflush(stdin);
    return 1;
  case 'e':
    DeleteEvenCell();
    fflush(stdin);
    return 1;
  case 's':
    PrintList();
    fflush(stdin);
    return 1;
  case 'x':
    printf("終了します。\n");
    return 0;
  default:
    printf("コマンドが正しくありません。\n");
    fflush(stdin);
    return 1;
  }
}

int main(void) {
  char c;
  int x;
  while (1) {
    printf("コマンドを入力してください。(i, d, p, n, e, s, x): ");
    scanf("%c", &c);
    if (!Command(c)) {
      break;
    }
  }

  free_memory(head.next);
  return 0;
}
