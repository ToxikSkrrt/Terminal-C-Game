#ifndef __ITEM_H__
#define __ITEM_H__

typedef struct {
  char *name;
  int hp;
  int atk;
  int armor;
} item_t;

extern item_t EMPTY_ITEM;

char *item_getName(item_t item);
int item_getHp(item_t item);
int item_getAtk(item_t item);
int item_getArmor(item_t item);

void item_setName(item_t item, char *name);
void item_setHp(item_t item, int hp);
void item_setAtk(item_t item, int atk);
void item_setArmor(item_t item, int armor);

item_t item_create(char *name, int hp, int atk, int armor);

#endif