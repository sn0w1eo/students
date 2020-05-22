#ifndef HERO_H
#define HERO_H

typedef char* string;

typedef struct name
{
	string lorName;
	string dota2Name;
}Name;

typedef struct characteristics
{
	double hitPoints;
	double manaPool;
}—haracteristics;

typedef struct atributes
{
	short agility;
	short strength;
	short intelligence;
}Attributes;

typedef struct hero
{
	Name heroName;
	Attributes heroAttributes;
	—haracteristics hero—haracteristics;
}Hero;

void SetHero(Hero*, string, string, double, double, short, short, short);
void SetLorName(Hero*, string);
void SetDota2Name(Hero*, string);
void SetHitPoints(Hero*, double);
void SetManaPool(Hero*, double);
void SetAgility(Hero*, short);
void SetStrength(Hero*, short);
void SetIntelligence(Hero*, short);

void DisplayAllHeroes(const Hero*, const int);
string GetLorName(const Hero);
string GetDota2Name(const Hero);
double GetHitPoints(const Hero);
double GetManaPool(const Hero);
short GetAgility(const Hero);
short GetStrength(const Hero);
short GetIntelligence(const Hero);

int CompareByAgility(const void* a, const void* b);
int CompareByStrength(const void* a, const void* b);
int CompareByIntelligence(const void* a, const void* b);
int CompareByHitPoints(const void* a, const void* b);
int CompareByManaPool(const void* a, const void* b);
int CompareByLorName(const void* a, const void* b);
int CompareByDota2Name(const void* a, const void* b);


#endif // !HERO_H
