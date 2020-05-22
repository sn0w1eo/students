#include "stdio.h"
#include "string.h"

#include "hero.h"

//���������� ���1.
void SetLorName(Hero* hero, string const name)
{
	hero->heroName.lorName = _strdup(name);
}

//���������� ���2.
void SetDota2Name(Hero* hero, string const name)
{
	hero->heroName.dota2Name = _strdup(name);
}

//���������� ��-�� hp.
void SetHitPoints(Hero* hero, const double hitPoints)
{
	hero->hero�haracteristics.hitPoints = hitPoints;
}

//���������� ��-�� mp.
void SetManaPool(Hero* hero, const double manaPool)
{
	hero->hero�haracteristics.manaPool = manaPool;
}

//���������� ��-�� ��������.
void SetAgility(Hero* hero, const short agility)
{
	hero->heroAttributes.agility = agility;
}

//���������� ��-�� ����.
void SetStrength(Hero* hero, const short strength)
{
	hero->heroAttributes.strength = strength;
}

//���������� ��-�� ����������.
void SetIntelligence(Hero* hero, const short intelligence)
{
	hero->heroAttributes.intelligence = intelligence;
}

//�������� ���1.
string GetLorName(const Hero hero)
{
	return hero.heroName.lorName;
}

//�������� ���2.
string GetDota2Name(const Hero hero)
{
	return hero.heroName.dota2Name;
}

//�������� hp.
double GetHitPoints(const Hero hero)
{
	return hero.hero�haracteristics.hitPoints;
}

//�������� mp.
double GetManaPool(const Hero hero)
{
	return hero.hero�haracteristics.manaPool;
}

//�������� ��������
short GetAgility(const Hero hero)
{
	return hero.heroAttributes.agility;
}

//�������� ����.
short GetStrength(const Hero hero)
{
	return hero.heroAttributes.strength;
}

//�������� ���������.
short GetIntelligence(const Hero hero)
{
	return hero.heroAttributes.intelligence;
}

//�������� ������ �����.
void SetHero(Hero* dotaHero, string const lorName, string const dota2Name, double const hitPoints, const double manaPool, short const agi, short const str, short const intl)
{
	SetLorName(dotaHero, lorName);
	SetDota2Name(dotaHero, dota2Name);
	SetHitPoints(dotaHero, hitPoints);
	SetManaPool(dotaHero, manaPool);
	SetAgility(dotaHero, agi);
	SetStrength(dotaHero, str);
	SetIntelligence(dotaHero, intl);
}

//���������� ���� ������.
void DisplayAllHeroes(const Hero* dotaHeroes, const int heroesCount)
{
	for (int i = 0; i < heroesCount; i++)
	{
		printf("[%d]-th hero:\n", i);
		printf("%s \"%s\"\n", GetDota2Name(dotaHeroes[i]), GetLorName(dotaHeroes[i]));
		printf("Hit Points: %.2lf Mana Pool: %.2lf\n", GetHitPoints(dotaHeroes[i]), GetManaPool(dotaHeroes[i]));
		printf("Agility: %i Strength: %i Intelligence: %i\n\n", GetAgility(dotaHeroes[i]), GetStrength(dotaHeroes[i]), GetIntelligence(dotaHeroes[i]));
	}
}

//�������� �� ��������.
int CompareByAgility(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return ptrHero1->heroAttributes.agility - ptrHero2->heroAttributes.agility;
}

//�������� �� ����.
int CompareByStrength(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return ptrHero1->heroAttributes.strength - ptrHero2->heroAttributes.strength;
}

//�������� �� ����������.
int CompareByIntelligence(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return ptrHero1->heroAttributes.intelligence - ptrHero2->heroAttributes.intelligence;
}

//�������� �� ������ ��.
int CompareByHitPoints(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return ptrHero1->hero�haracteristics.hitPoints - ptrHero2->hero�haracteristics.hitPoints;
}

//�������� �� ������ ��.
int CompareByManaPool(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return ptrHero1->hero�haracteristics.manaPool - ptrHero2->hero�haracteristics.manaPool;
}

//�������� �� ����� � ����.
int CompareByLorName(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return strcmp(ptrHero1->heroName.lorName, ptrHero2->heroName.lorName);
}

//�������� �� ����� � ����.
int CompareByDota2Name(const void* a, const void* b)
{
	const Hero* ptrHero1 = a;
	const Hero* ptrHero2 = b;
	return strcmp(ptrHero1->heroName.dota2Name, ptrHero2->heroName.dota2Name);
}