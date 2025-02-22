#include "monster.h"

char *monster_getName(monster_t monster) {
  return monster.name;
}

int monster_getLevel(monster_t monster) {
  return monster.level;
}

int monster_getHp(monster_t monster) {
  return monster.hp;
}

int monster_getAtk(monster_t monster) {
  return monster.atk;
}

int monster_getArmor(monster_t monster) {
  return monster.armor;
}

void monster_setName(monster_t monster, char *name) {
  monster.name = name;
}

void monster_setLevel(monster_t monster, int level) {
  monster.level = level;
}

void monster_setHp(monster_t monster, int hp) {
  monster.hp = hp;
}

void monster_setAtk(monster_t monster, int atk) {
  monster.atk = atk;
}

void monster_setArmor(monster_t monster, int armor) {
  monster.armor = armor;
}

monster_t monster_create(char *name, int level, int hp, int atk, int armor) {
  monster_t monster = {name, level, hp, atk, armor};

  return monster;
}