#include "tools.h"
#include "stdlib.h"
#define RAND_MIN 1
#define RAND_MAX 15 

sfBool notVeryEffectivePlayer = sfFalse;
sfBool superEffectivePlayer = sfFalse;
sfBool doubleSuperEffectivePlayer = sfFalse;
sfBool neutralPlayer = sfFalse;
sfBool immunePlayer = sfFalse;
sfBool doubleResistancePlayer = sfFalse;
sfBool doubleTypingNPC1 = sfFalse;

sfBool notVeryEffectivePlayer2;
sfBool superEffectivePlayer2;
sfBool neutralPlayer2;
sfBool immunePlayer2;
sfBool doubleResistancePlayer2;

sfBool doubleTypingOrNot() {
	if (pokemon == 4 || pokemon == 5 || pokemon == 7 || pokemon == 8 || pokemon == 9 || pokemon == 10 || pokemon == 11 || pokemon == 19 || pokemon == 20 || pokemon == 23 || pokemon == 24 || pokemon == 25 || pokemon == 26 || pokemon == 27 || pokemon == 28 || pokemon == 29 || pokemon == 30 || pokemon == 32 || pokemon == 33 || pokemon == 35 || pokemon == 36 || pokemon == 37 || pokemon == 38 || pokemon == 50 || pokemon == 51 || pokemon == 52 || pokemon == 53 || pokemon == 54 || pokemon == 55 || pokemon == 56 || pokemon == 57 || pokemon == 58 || pokemon == 59 || pokemon == 60 || pokemon == 61 || pokemon == 63 || pokemon == 64 || pokemon == 65 || pokemon == 66 || pokemon == 67 || pokemon == 68 || pokemon == 77 || pokemon == 78 || pokemon == 86 || pokemon == 88 || pokemon == 89 || pokemon == 96 || pokemon == 98 || pokemon == 99 || pokemon == 97 || pokemon == 100 || pokemon == 101 || pokemon == 104 || pokemon == 105 || pokemon == 106 || pokemon == 107 || pokemon == 108 || pokemon == 109 || pokemon == 110 || pokemon == 113 || pokemon == 114 || pokemon == 115 || pokemon == 116 || pokemon == 117 || pokemon == 118 || pokemon == 119 || pokemon == 120 || pokemon == 121 || pokemon == 125 || pokemon == 126 || pokemon == 127 || pokemon == 128 || pokemon == 129 || pokemon == 132 || pokemon == 134 || pokemon == 135 || pokemon == 136 || pokemon == 137 || pokemon == 143 || pokemon == 147 || pokemon == 148 || pokemon == 150 || pokemon == 151 || pokemon == 152 || pokemon == 153 || pokemon == 154 || pokemon == 155 || pokemon == 156 || pokemon == 157 || pokemon == 158 || pokemon == 159 || pokemon == 160 || pokemon == 161 || pokemon == 162 || pokemon == 172 || pokemon == 173 || pokemon == 174 || pokemon == 175 || pokemon == 179 || pokemon == 180 || pokemon == 181 || pokemon == 182 || pokemon == 185 || pokemon == 186 || pokemon == 190 || pokemon == 191 || pokemon == 192 || pokemon == 196 || pokemon == 197 || pokemon == 200 || pokemon == 201 || pokemon == 202 || pokemon == 204 || pokemon == 206 || pokemon == 209 || pokemon == 210 || pokemon == 216 || pokemon == 217 || pokemon == 218 || pokemon == 223 || pokemon == 224 || pokemon == 231 || pokemon == 232 || pokemon == 233 || pokemon == 234 || pokemon == 235 || pokemon == 236 || pokemon == 237 || pokemon == 238 || pokemon == 239 || pokemon == 240 || pokemon == 241 || pokemon == 242 || pokemon == 243 || pokemon == 244 || pokemon == 245) {
		return sfFalse;
	}
	else {
		return sfTrue;
	}
}

typedef enum {
}brick;

typedef enum {
	levitate = 1,
	waterAbsorb,
	voltAbsorb,
	thickFat,
	flashFire,
	stormDrain,
	drySkin,
	scrappy,
	sapSipper,
	earthEater
}brick5;

brick5 playerAbility; 

typedef enum {
	airBalloon = 1
}brick7;

brick7 playerItem;

typedef enum {
	airBalloon1 = 1
}brick8;

brick8 NPCItem;

typedef enum {
	levitate1 = 1,
	waterAbsorb1,
	voltAbsorb1,
	thickFat1,
	flashFire1,
	stormDrain1,
	drySkin1,
	scrappy1,
	sapSipper1,
	earthEater1
}brick6;

brick6 NPCAbility;

typedef enum {
	normal = 1,
	feu,
	eau,
	plante,
	electrik,
	glace,
	combat,
	poison,
	sol,
	vol,
	psy,
	insecte,
	roche,
	spectre,
	dragon,
	tenebres,
	acier,
	fee
}brick;

brick type1;

typedef enum {
	normal1 = 1,
	feu1,
	eau1,
	plante1,
	electrik1,
	glace1,
	combat1,
	poison1,
	sol1,
	vol1,
	psy1,
	insecte1,
	roche1,
	spectre1,
	dragon1,
	tenebres1,
	acier1,
	fee1
}brick2;

brick2 type2;

typedef enum {
	normal2 = 1,
	feu2,
	eau2,
	plante2,
	electrik2,
	glace2,
	combat2,
	poison2,
	sol2,
	vol2,
	psy2,
	insecte2,
	roche2,
	spectre2,
	dragon2,
	tenebres2,
	acier2,
	fee2
}brick3;

brick3 attaque1;

typedef enum {
	normal3 = 1,
	feu3,
	eau3,
	plante3,
	electrik3,
	glace3,
	combat3,
	poison3,
	sol3,
	vol3,
	psy3,
	insecte3,
	roche3,
	spectre3,
	dragon3,
	tenebres3,
	acier3,
	fee3
}brick4;

brick4 attaque2;

int typeAdvantagePlayerType1() {
	doubleResistancePlayer = sfFalse;
	doubleSuperEffectivePlayer = sfFalse;
	if (type1 == normal && attaque2 == spectre3 || type1 == vol && attaque2 == sol3 || type1 == spectre && attaque2 == normal3 || type1 == spectre && attaque2 == combat3 || type1 == tenebres && attaque2 == psy3 || type1 == acier && attaque2 == poison3 || type1 == fee && attaque2 == dragon3) {
		immunePlayer = sfTrue;
	}
	else if (type1 == normal) {
		if (attaque2 != spectre3 && attaque2 != combat3) {
			neutralPlayer = sfTrue;
		}
		else if (attaque2 == combat3) {
			superEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == feu) {
		if (attaque2 == fee3 || attaque2 == plante3 || attaque2 == acier3 || attaque2 == insecte3 || attaque2 == glace3 || attaque2 == feu3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else if (attaque2 == sol3 || attaque2 == roche3 || attaque2 == eau3) {
			superEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == eau) {
		if (attaque2 == plante3 || attaque2 == electrik3) {
			superEffectivePlayer = sfTrue;
		}
		else if (attaque2 == eau3 || attaque2 == feu3 || attaque2 == glace3 || attaque2 == acier3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == plante) {
		if (attaque2 == plante3 || attaque2 == eau3 || attaque2 == electrik3 || attaque2 == sol3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else if (attaque2 == poison3 || attaque2 == vol3 || attaque2 == insecte3 || attaque2 == feu3 || attaque2 == glace3) {
			superEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == electrik) {
		if (attaque2 == sol3) {
			if (playerAbility != earthEater && playerItem == airBalloon) {
				superEffectivePlayer = sfTrue;
			}
		}
		else if (attaque2 == electrik3 || attaque2 == vol3 || attaque2 == acier3) {
			if (playerAbility != voltAbsorb && playerAbility != levitate) {
				notVeryEffectivePlayer = sfTrue;
			}
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == glace) {
		if (attaque2 == feu3 || attaque2 == roche3 || attaque2 == acier3) {
			superEffectivePlayer = sfTrue;
		}
		else if (attaque2 == glace3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == combat) {
		if (attaque2 == psy3 || attaque2 == vol3 || attaque2 == fee3) {
			superEffectivePlayer = sfTrue;
		}
		else if (attaque2 == tenebres3 || attaque2 == insecte3 || attaque2 == roche3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
	else if (type1 == poison) {
		if (attaque2 == psy3 || attaque2 == sol3) {
			superEffectivePlayer = sfTrue;
		}
		else if (attaque2 == fee3 || attaque2 == plante3 || attaque2 == poison3 || attaque2 == insecte3) {
			notVeryEffectivePlayer = sfTrue;
		}
		else {
			neutralPlayer = sfTrue;
		}
	}
}

int doubleTypingPlayer() {
	if (doubleTypingOrNot() == sfTrue) {
		if (notVeryEffectivePlayer == sfTrue && superEffectivePlayer2 == sfTrue || notVeryEffectivePlayer2 == sfTrue && superEffectivePlayer == sfTrue) {
			notVeryEffectivePlayer = sfFalse;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfTrue;
			immunePlayer = sfFalse;
		}
		else if (neutralPlayer == sfTrue && notVeryEffectivePlayer2 == sfTrue || neutralPlayer2 == sfTrue && notVeryEffectivePlayer2 == sfTrue) {
			notVeryEffectivePlayer = sfTrue;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfFalse;
		}
		else if (neutralPlayer == sfTrue && superEffectivePlayer2 == sfTrue || neutralPlayer2 == sfTrue && superEffectivePlayer == sfTrue) {
			notVeryEffectivePlayer = sfTrue;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfFalse;
		}
		else if (neutralPlayer == sfTrue && neutralPlayer2 == sfTrue) {
			notVeryEffectivePlayer = sfTrue;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfFalse;
		}
		else if (notVeryEffectivePlayer == sfTrue && notVeryEffectivePlayer2 == sfTrue) {
			notVeryEffectivePlayer = sfFalse;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfFalse;

			doubleResistancePlayer = sfTrue;
		}
		else if (superEffectivePlayer == sfTrue && superEffectivePlayer2 == sfTrue) {
			doubleSuperEffectivePlayer = sfTrue;

			notVeryEffectivePlayer = sfFalse;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfFalse;
		}
		else if (immunePlayer == sfTrue) {
			notVeryEffectivePlayer = sfFalse;
			superEffectivePlayer = sfFalse;
			neutralPlayer = sfFalse;
			immunePlayer = sfTrue;
		}
	}
}