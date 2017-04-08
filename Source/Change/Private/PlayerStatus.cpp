// Fill out your copyright notice in the Description page of Project Settings.

#include "Change.h"
#include "../Public/PlayerStatus.h"

FText APlayerStatus::GetPlayerName()
{
	return PName;
}

FStatusLive APlayerStatus::GetHP()
{
	return HP;
}

FStatusLive APlayerStatus::GetMP()
{
	return MP;
}

FStatusLive APlayerStatus::GetSP()
{
	return SP;
}

int32 APlayerStatus::GetStrength()
{
	return Strength;
}

int32 APlayerStatus::GetDexterity()
{
	return Dexterity;
}

int32 APlayerStatus::GetVitality()
{
	return Vitality;
}

int32 APlayerStatus::GetDefense()
{
	return Defense;
}

int32 APlayerStatus::GetIntelligence()
{
	return Intelligence;
}

int32 APlayerStatus::GetCharisma()
{
	return Charisma;
}

int32 APlayerStatus::GetWisdom()
{
	return Wisdom;
}

int32 APlayerStatus::GetWillpower()
{
	return Willpower;
}

int32 APlayerStatus::GetPerception()
{
	return Perception;
}

int32 APlayerStatus::GetLuck()
{
	return Luck;
}
FText APlayerStatus::SetName(FText tPName)
{
	PName = tPName;
	return PName;
}
/*
 *=Seters=
 */
FStatusLive APlayerStatus::SetHP(FStatusLive tHP)
{
	tHP.MakeZero();
	HP.i32Max     = tHP.i32Max;
	HP.i32Min     = tHP.i32Min;
	HP.i32Death   = tHP.i32Death;
	HP.i32Current = tHP.i32Current;

	return HP;
}

FStatusLive APlayerStatus::SetMP(FStatusLive tMP)
{
	tMP.MakeZero();
	MP.i32Max     = tMP.i32Max;
	MP.i32Min     = tMP.i32Min;
	MP.i32Death   = tMP.i32Death;
	MP.i32Current = tMP.i32Current;

	return MP;
}

FStatusLive APlayerStatus::SetSP(FStatusLive tSP)
{
	tSP.MakeZero();
	SP.i32Max = tSP.i32Max;
	SP.i32Min = tSP.i32Min;
	SP.i32Death = tSP.i32Death;
	SP.i32Current = tSP.i32Current;

	return SP;
}

int32 APlayerStatus::SetStrength(int32 tStrength)
{
	Strength = tStrength;
	
	return Strength;
}

int32 APlayerStatus::SetDexterity(int32 tDexterity)
{
	Dexterity = tDexterity;

	return Dexterity;
}

int32 APlayerStatus::SetVitality(int32 tVitality)
{
	Vitality = tVitality;

	return Vitality;
}

int32 APlayerStatus::SetDefense(int32 tDefense)
{
	Defense = tDefense;

	return Defense;
}

int32 APlayerStatus::SetIntelligence(int32 tIntelligence)
{
	Intelligence = tIntelligence;

	return Intelligence;
}

int32 APlayerStatus::SetCharisma(int32 tCharisma)
{
	Charisma = tCharisma;

	return Charisma;
}

int32 APlayerStatus::SetWisdom(int32 tWisdom)
{
	Wisdom = tWisdom;

	return Wisdom;
}

int32 APlayerStatus::SetWillpower(int32 tWillpower)
{
	Willpower = tWillpower;

	return Willpower;
}

int32 APlayerStatus::SetPerception(int32 tPerception)
{
	Perception = tPerception;
	return Perception;
}

int32 APlayerStatus::SetLuck(int32 tLuck)
{
	Luck = tLuck;
	return Luck;
}
