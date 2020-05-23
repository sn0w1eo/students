#include "stdio.h"
#include "string.h"

#include "hero.h"

//Если значение 1, то сортирует по возрастанию, иначе по убыванию.
#define ASCENDING 1 

//Установить имя по лору.
void SetLorName(Hero* hero, string const name)
{
	hero->heroName.lorName = _strdup(name);
}

//Установить игровое имя.
void SetDota2Name(Hero* hero, string const name)
{
	hero->heroName.dota2Name = _strdup(name);
}

//Установить ко-во hp.
void SetHitPoints(Hero* hero, const double hitPoints)
{
	hero->heroСharacteristics.hitPoints = hitPoints;
}

//Установить ко-во mp.
void SetManaPool(Hero* hero, const double manaPool)
{
	hero->heroСharacteristics.manaPool = manaPool;
}

//Установить ко-во ловкости.
void SetAgility(Hero* hero, const short agility)
{
	hero->heroAttributes.agility = agility;
}

//Установить ко-во силы.
void SetStrength(Hero* hero, const short strength)
{
	hero->heroAttributes.strength = strength;
}

//Установить ко-во интеллекта.
void SetIntelligence(Hero* hero, const short intelligence)
{
	hero->heroAttributes.intelligence = intelligence;
}

//Получить имя по лору.
string GetLorName(Hero const hero)
{
	return hero.heroName.lorName;
}

//Получить игровое имя.
string GetDota2Name(Hero const hero)
{
	return hero.heroName.dota2Name;
}

//Получить hp.
double GetHitPoints(Hero const hero)
{
	return hero.heroСharacteristics.hitPoints;
}

//Получить mp.
double GetManaPool(Hero const hero)
{
	return hero.heroСharacteristics.manaPool;
}

//Получить ловкость
short GetAgility(Hero const hero)
{
	return hero.heroAttributes.agility;
}

//Получить силу.
short GetStrength(Hero const hero)
{
	return hero.heroAttributes.strength;
}

//Получить интеллект.
short GetIntelligence(Hero const hero)
{
	return hero.heroAttributes.intelligence;
}

//Записать данные героя.
void SetHero(Hero* const dotaHero, string const lorName, string const dota2Name, double const hitPoints, double const manaPool, short const agi, short const str, short const intl)
{
	SetLorName(dotaHero, lorName);
	SetDota2Name(dotaHero, dota2Name);
	SetHitPoints(dotaHero, hitPoints);
	SetManaPool(dotaHero, manaPool);
	SetAgility(dotaHero, agi);
	SetStrength(dotaHero, str);
	SetIntelligence(dotaHero, intl);
}

//Отобразить всех героев.
void DisplayAllHeroes(const Hero* dotaHeroes, int const heroesCount)
{
	for (int i = 0; i < heroesCount; i++)
	{
		printf("[%d]-th hero:\n", i);
		printf("%s \"%s\"\n", GetDota2Name(dotaHeroes[i]), GetLorName(dotaHeroes[i]));
		printf("Hit Points: %.2lf Mana Pool: %.2lf\n", GetHitPoints(dotaHeroes[i]), GetManaPool(dotaHeroes[i]));
		printf("Agility: %i Strength: %i Intelligence: %i\n\n", GetAgility(dotaHeroes[i]), GetStrength(dotaHeroes[i]), GetIntelligence(dotaHeroes[i]));
	}
}

//Сравнить по ловкости.
int CompareByAgility(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;

#if ASCENDING == 1
	return ptrHero1->heroAttributes.agility - ptrHero2->heroAttributes.agility;
#else
	return ptrHero2->heroAttributes.agility - ptrHero1->heroAttributes.agility;
#endif
}

//Сравнить по силе.
int CompareByStrength(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;

#if ASCENDING == 1
	return ptrHero1->heroAttributes.strength - ptrHero2->heroAttributes.strength;
#else
	return ptrHero2->heroAttributes.strength - ptrHero1->heroAttributes.strength;
#endif
}

//Сравнить по интеллекту.
int CompareByIntelligence(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;

#if ASCENDING == 1
	return ptrHero1->heroAttributes.intelligence - ptrHero2->heroAttributes.intelligence;
#else
	return ptrHero2->heroAttributes.intelligence - ptrHero1->heroAttributes.intelligence;
#endif
}

//Сравнить по запасу хп.
int CompareByHitPoints(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	double result;

#if ASCENDING == 1
	result = ptrHero1->heroСharacteristics.hitPoints - ptrHero2->heroСharacteristics.hitPoints;
	if (result < 0)
	{
		return -1;
	}
	return 1;
#else
	result = ptrHero2->heroСharacteristics.hitPoints - ptrHero1->heroСharacteristics.hitPoints;
	if (result < 0)
	{
		return -1;
	}
	return 1;
#endif
}

//Сравнить по запасу мп.
int CompareByManaPool(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	double result;

#if ASCENDING == 1
	result = ptrHero1->heroСharacteristics.manaPool - ptrHero2->heroСharacteristics.manaPool;
	if (result < 0)
	{
		return -1;
	}
	return 1;
#else
	result = ptrHero2->heroСharacteristics.manaPool - ptrHero1->heroСharacteristics.manaPool;
	if (result < 0)
	{
		return -1;
	}
	return 1;
#endif
}

//Сравнить по имени с лора.
int CompareByLorName(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;

#if ASCENDING == 1
	return strcmp(ptrHero1->heroName.lorName, ptrHero2->heroName.lorName);
#else
	return strcmp(ptrHero2->heroName.lorName, ptrHero1->heroName.lorName);
#endif
}

//Сравнить по имени с игры.
int CompareByDota2Name(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;

#if ASCENDING == 1
	return strcmp(ptrHero1->heroName.dota2Name, ptrHero2->heroName.dota2Name);
#else
	return strcmp(ptrHero2->heroName.dota2Name, ptrHero1->heroName.dota2Name);
#endif
}