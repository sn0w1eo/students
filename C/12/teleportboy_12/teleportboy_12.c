#include "stdio.h"
#include "stdlib.h"

#include "hero.h"

void StartNextSort()
{
	getchar();
	system("cls");
}

int main()
{
	int heroCount = 5;
	Hero* dotaHeroes = (Hero*)calloc(heroCount, sizeof(Hero));

	SetHero(&dotaHeroes[0], "Nevermore", "Shadow Fiend", 580.00, 281.00, 20, 19, 18);
	SetHero(&dotaHeroes[1], "Sun Wukong", "Monkey King", 580.00, 315.00, 22, 19, 20);
	SetHero(&dotaHeroes[2], "Azwraith", "Phantom Lancer", 620.00, 303.00, 26, 19, 19);
	SetHero(&dotaHeroes[3], "Yurnero", "Juggernaut", 600.00, 243.00, 34, 20, 14);
	SetHero(&dotaHeroes[4], "Akasha", "Queen of Pain", 560.00, 375.00, 22, 18, 25);
	
	DisplayAllHeroes(dotaHeroes, heroCount);
	
	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByLorName);
	DisplayAllHeroes(dotaHeroes, heroCount);

	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByDota2Name);
	DisplayAllHeroes(dotaHeroes, heroCount);

	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByHitPoints);
	DisplayAllHeroes(dotaHeroes, heroCount);
	
	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByManaPool);
	DisplayAllHeroes(dotaHeroes, heroCount);
	
	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByAgility);
	DisplayAllHeroes(dotaHeroes, heroCount);

	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByStrength);
	DisplayAllHeroes(dotaHeroes, heroCount);

	StartNextSort();
	qsort(dotaHeroes, heroCount, sizeof(Hero), CompareByIntelligence);
	DisplayAllHeroes(dotaHeroes, heroCount);

}