#ifndef __ITEM_H__
#define __ITEM_H__

struct item_s {
  char *name;
  int hp;
  int atk;
  int armor;
};

typedef struct item_s *item_t;

char *item_getName(item_t item);
int item_getHp(item_t item);
int item_getAtk(item_t item);
int item_getArmor(item_t item);

void item_setName(item_t item, char *name);
void item_setHp(item_t item, int hp);
void item_setAtk(item_t item, int atk);
void item_setArmor(item_t item, int armor);

item_t item_create(char *name, int hp, int atk, int armor);
item_t item_copy(item_t item);
void item_delete(item_t item);
void item_showInfo(item_t item);

#endif