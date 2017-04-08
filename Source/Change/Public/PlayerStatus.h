// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "PlayerStatus.generated.h"

/*
 *Struct for bars
 */
USTRUCT(BlueprintType)
struct FStatusLive
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32Max;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32Min;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32Death;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32Current;
	void MakeZero()
	{
		if (i32Max < 0)
			i32Max = 0;
		if (i32Min < 0)
			i32Min = 0;
		if (i32Death < 0)
			i32Death = 0;
		if (i32Current < 0)
			i32Current = 0;
	}
};
/*
 *Struct for level
 */
USTRUCT(BlueprintType)
struct FLevelStatus
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32CurentLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float fPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 i32NextLevelXpValue;

};
/**
*
*/
UCLASS()
class CHANGE_API APlayerStatus : public APlayerState
{
	GENERATED_BODY()

private:
	/*
	 *Player name
	 */
	UPROPERTY(SaveGame)
		FText PName;

	/*
	 *===special se calculeaza in functie de celelalte===
	 */

	 /*
	  *>Health Points or HP - represents the amount of damage a character can take before dying or being knocked out.
	  */
	UPROPERTY(SaveGame)
		FStatusLive HP;

	/*
	 *>Magic Points or MP - represents the amount of magical power a character has. Higher the power, the more spells can be cast.
	 */
	UPROPERTY(SaveGame)
		FStatusLive MP;

	/*
	 *>Stamina points or SP - represend the amount of energy a character has.
	 */
	UPROPERTY(SaveGame)
		FStatusLive SP;

	/*
	 *===PHYSICAL===
	 */

	 /*
	  *>Strength
	  *	A measure of how physically strong a character is.	Strength often controls the maximum weight the character can carry, melee attack and/or damage,
	  *	and sometimes hit points. Armor and weapons might also have a Strength requirement.
	  */
	UPROPERTY(SaveGame)
		int32 Strength;

	/*
	 *>Dexterity aka Agility
	 *	A measure of how agile a character is. Dexterity controls attack and movement speed and accuracy, as well as evading an opponent's attack.
	 *	-AGILITY (movement)/SPEED
	 *	-DEXTERITY (weapon aim.. hand/eye coordination)
	 */
	UPROPERTY(SaveGame)
		int32 Dexterity;

	/*
	 *>Vitality
	 *	A measure of how sturdy a character is. Constitution often influences hit points, resistances for special types of damage (poisons, illness, heat etc.)
	 *	and fatigue.
	 */
	UPROPERTY(SaveGame)
		int32 Vitality;

	/*
	 *>Defense
	 *	A measure of how resilient a character is. Defence usually decreases taken damage by either a percentage or a fixed amount per hit.
	 *	Occasionally combined with Constitution.
	 */
	UPROPERTY(SaveGame)
		int32 Defense;

	/*
	 *===MENTAL===
	 */

	 /*
	  *>Intelligence
	  *	A measure of a character's problem-solving ability. Intelligence often controls a character's ability to comprehend foreign languages and their skill
	  *	in magic.In some cases, intelligence controls how many skill points the character gets at "level up". In some games, it controls the rate at which
	  *	experience points are earned, or the amount needed to level up. Under certain circumstances, this skill can also negate combat actions between players
	  *	and NPC enemies. *This is sometimes combined with wisdom and/or willpower.*
	  */
	UPROPERTY(SaveGame)
		int32 Intelligence;

	/*
	 *>Charisma
	 *	A measure of a character's social skills, and sometimes their physical appearance. Charisma generally influences prices while trading, and NPC reactions.
	 *	Under certain circumstances, this skill can negate combat actions between players and NPC enemies.
	 */
	UPROPERTY(SaveGame)
		int32 Charisma;

	/*
	 *>Wisdom
	 *	A measure of a character's common sense and/or spirituality. Wisdom often controls a character's ability to cast certain spells, communicate to mystical
	 *	entities, or discern other characters' motives or feelings.
	 */
	UPROPERTY(SaveGame)
		int32 Wisdom;

	/*
	 *>Willpower
	 *	A measure of the character's mental resistance (against pain, fear etc.) when falling victim to mind-altering magic, torture, or insanity. Many games
	 *	combine willpower and wisdom.
	 */
	UPROPERTY(SaveGame)
		int32 Willpower;

	/*
	 *>Perception
	 *	A measure of a character's openness to their surroundings. Perception controls the chance to detect vital clues, traps, or hiding enemies, and might
	 *	influence combat sequence, or the accuracy of ranged attacks. Perception-type attributes are more common in more modern games. Note that this skill is
	 *	usually understood only to apply to what a character can perceive with their established senses (ie sight, sound, smell, etc), and does not usually include
	 *	extrasensory perception or other forms of mental telepathy or telekinesis in the given game unless the character's specific attributes expressly include
	 *	such abilities (such as the force in Star Wars). Sometimes combined with wisdom.
	 */
	UPROPERTY(SaveGame)
		int32 Perception;

	/*
	 *===Special===
	 */

	 /*
	  *>Luck
	  *	A measure of a character's luck. Luck might influence anything, but mostly random items, encounters and outstanding successes/failures
	  *	(such as critical hits).
	  */
	UPROPERTY(SaveGame)
		int32 Luck;
public:
	/*
	 *=Geters=
	 */

	 /*
	  *Get function for:
	  *Player name
	  *@param nothing
	  *@return Player name
	  */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		FText GetPlayerName();
	/*
	 *Get function for:
	 *>Health Points or HP - represents the amount of damage a character can take before dying or being knocked out.
	 *@param nothing
	 *@return HP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|HP")
		FStatusLive GetHP();
	/*
	 *Get function for:
	 *>Magic Points or MP - represents the amount of magical power a character has. Higher the power, the more spells can be cast.
	 *@param nothing
	 *@return MP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|MP")
		FStatusLive GetMP();
	/*
	 *Get function for:
	 *>Stamina points or SP - represend the amount of energy a character has.
	 *@param nothing
	 *@return SP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|SP")
		FStatusLive GetSP();
	/*
	 *Get function for:
	 *>Strength
	 * A measure of how physically strong a character is.	Strength often controls the maximum weight the character can carry, melee attack and/or damage,
	 * and sometimes hit points. Armor and weapons might also have a Strength requirement.
	 *@param nothing
	 *@return Strength
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Strength")
		int32 GetStrength();
	/*
	 *Get function for:
	 *>Dexterity aka Agility
	 *	A measure of how agile a character is. Dexterity controls attack and movement speed and accuracy, as well as evading an opponent's attack.
	 *	-AGILITY (movement)/SPEED
	 *	-DEXTERITY (weapon aim.. hand/eye coordination)
	 *@param nothing
	 *@return Dexterity
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Dexterity")
		int32 GetDexterity();
	/*
	 *Get function for:
	 *>Vitality
	 *	A measure of how sturdy a character is. Constitution often influences hit points, resistances for special types of damage (poisons, illness, heat etc.)
	 *	and fatigue.
	 *@param nothing
	 *@return Vitality
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Vitality")
		int32 GetVitality();
	/*
	 *Get function for:
	 *>Defense
	 *	A measure of how resilient a character is. Defence usually decreases taken damage by either a percentage or a fixed amount per hit.
	 *	Occasionally combined with Constitution.
	 *@param nothing
	 *@return Defense
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Defense")
		int32 GetDefense();
	/*
	 *Get function for:
	 *>Intelligence
	 *	A measure of a character's problem-solving ability. Intelligence often controls a character's ability to comprehend foreign languages and their skill
	 *	in magic.In some cases, intelligence controls how many skill points the character gets at "level up". In some games, it controls the rate at which
	 *	experience points are earned, or the amount needed to level up. Under certain circumstances, this skill can also negate combat actions between players
	 *	and NPC enemies. *This is sometimes combined with wisdom and/or willpower.
	 *@param nothing
	 *@return Intelligence
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Intelligence")
		int32 GetIntelligence();
	/*
	 *Get function for:
	 *>Charisma
	 *	A measure of a character's social skills, and sometimes their physical appearance. Charisma generally influences prices while trading, and NPC reactions.
	 *	Under certain circumstances, this skill can negate combat actions between players and NPC enemies.
	 *@param nothing
	 *@return Charisma
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Charisma")
		int32 GetCharisma();
	/*
	 *Get function for:
	 *>Wisdom
	 *	A measure of a character's common sense and/or spirituality. Wisdom often controls a character's ability to cast certain spells, communicate to mystical
	 *	entities, or discern other characters' motives or feelings.
	 *@param nothing
	 *@return Wisdom
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Wisdom")
		int32 GetWisdom();
	/*
	 *Get function for:
	 *>Willpower
	 *	A measure of the character's mental resistance (against pain, fear etc.) when falling victim to mind-altering magic, torture, or insanity. Many games
	 *	combine willpower and wisdom.
	 *@param nothing
	 *@return Willpower
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Willpower")
		int32 GetWillpower();
	/*
	 *Get function for:
	 *>Perception
	 * 	A measure of a character's openness to their surroundings. Perception controls the chance to detect vital clues, traps, or hiding enemies, and might
	 *	influence combat sequence, or the accuracy of ranged attacks. Perception-type attributes are more common in more modern games. Note that this skill is
	 *	usually understood only to apply to what a character can perceive with their established senses (ie sight, sound, smell, etc), and does not usually include
	 *	extrasensory perception or other forms of mental telepathy or telekinesis in the given game unless the character's specific attributes expressly include
	 *	such abilities (such as the force in Star Wars). Sometimes combined with wisdom.
	 *@param nothing
	 *@return Perception
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Perception")
		int32 GetPerception();
	/*
	 *Get function for:
	 *>Luck
	 *	A measure of a character's luck. Luck might influence anything, but mostly random items, encounters and outstanding successes/failures
	 *	(such as critical hits).
	 *@param nothing
	 *@return Luck
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Luck")
		int32 GetLuck();

	/*
	 *=Seters=
	 */

	 /*
	 *Set function for:
	 *Player name
	 *@param tPName- Player name to be set
	 *@return PName
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats")
		FText SetName(FText tPName);
	/*
	 *Set function for:
	 *>Health Points or HP - represents the amount of damage a character can take before dying or being knocked out.
	 *@param tHP- Health to be set
	 *@return HP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|HP")
		FStatusLive SetHP(FStatusLive tHP);
	/*
	 *Set function for:
	 *>Magic Points or MP - represents the amount of magical power a character has. Higher the power, the more spells can be cast.
	 *@param tMP- Magic to be set
	 *@return MP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|MP")
		FStatusLive SetMP(FStatusLive tMP);
	/*
	 *Set function for:
	 *>Stamina points or SP - represend the amount of energy a character has.
	 *@param tSP- Stamina to be set
	 *@return SP
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|SP")
		FStatusLive SetSP(FStatusLive tSP);
	/*
	 *Set function for:
	 *>Strength
	 *	A measure of how physically strong a character is.	Strength often controls the maximum weight the character can carry, melee attack and/or damage,
	 *	and sometimes hit points. Armor and weapons might also have a Strength requirement.
	 *@param tStrength- Strength to be set
	 *@return Strength
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Strength")
		int32 SetStrength(int32 tStrength);
	/*
	 *Set function for:
	 *>Dexterity aka Agility
	 *	A measure of how agile a character is. Dexterity controls attack and movement speed and accuracy, as well as evading an opponent's attack.
	 *	-AGILITY (movement)/SPEED
	 *	-DEXTERITY (weapon aim.. hand/eye coordination)
	 *@param tDexterity- Dexterity to be set
	 *@return Dexterity
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Dexterity")
		int32 SetDexterity(int32 tDexterity);
	/*
	 *Set function for:
	 *>Vitality
	 *	A measure of how sturdy a character is. Constitution often influences hit points, resistances for special types of damage (poisons, illness, heat etc.)
	 *	and fatigue.
	 *@param tVitality- Vitality to be set
	 *@return Vitality
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Vitality")
		int32 SetVitality(int32 tVitality);
	/*
	 *Set function for:
	 *>Defense
	 *	A measure of how resilient a character is. Defence usually decreases taken damage by either a percentage or a fixed amount per hit.
	 *	Occasionally combined with Constitution.
	 *@param tDefense- Defense to be set
	 *@return Defense
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Defense")
		int32 SetDefense(int32 tDefense);
	/*
	 *Set function for:
	 *>Intelligence
	 *	A measure of a character's problem-solving ability. Intelligence often controls a character's ability to comprehend foreign languages and their skill
	 *	in magic.In some cases, intelligence controls how many skill points the character gets at "level up". In some games, it controls the rate at which
	 *	experience points are earned, or the amount needed to level up. Under certain circumstances, this skill can also negate combat actions between players
	 *	and NPC enemies. *This is sometimes combined with wisdom and/or willpower.
	 *@param tIntelligence- Intelligence to be set
	 *@return Intelligence
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Intelligence")
		int32 SetIntelligence(int32 tIntelligence);
	/*
	 *Set function for:
	 *>Charisma
	 *	A measure of a character's social skills, and sometimes their physical appearance. Charisma generally influences prices while trading, and NPC reactions.
	 *	Under certain circumstances, this skill can negate combat actions between players and NPC enemies.
	 *@param tCharisma- Charisma to be set
	 *@return Charisma
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Charisma")
		int32 SetCharisma(int32 tCharisma);
	/*
	 *Set function for:
	 *>Wisdom
	 *	A measure of a character's common sense and/or spirituality. Wisdom often controls a character's ability to cast certain spells, communicate to mystical
	 *	entities, or discern other characters' motives or feelings.
	 *@param tWisdom- Wisdom to be set
	 *@return Wisdom
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Wisdom")
		int32 SetWisdom(int32 tWisdom);
	/*
	 *Set function for:
	 *>Willpower
	 *	A measure of the character's mental resistance (against pain, fear etc.) when falling victim to mind-altering magic, torture, or insanity. Many games
	 *	combine willpower and wisdom.
	 *@param tWillpower- Willpower to be set
	 *@return Willpower
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Willpower")
		int32 SetWillpower(int32 tWillpower);
	/*
	 *Set function for:
	 *>Perception
	 *	A measure of a character's openness to their surroundings. Perception controls the chance to detect vital clues, traps, or hiding enemies, and might
	 *	influence combat sequence, or the accuracy of ranged attacks. Perception-type attributes are more common in more modern games. Note that this skill is
	 *	usually understood only to apply to what a character can perceive with their established senses (ie sight, sound, smell, etc), and does not usually include
	 *	extrasensory perception or other forms of mental telepathy or telekinesis in the given game unless the character's specific attributes expressly include
	 *	such abilities (such as the force in Star Wars). Sometimes combined with wisdom.
	 *@param tPerception - Perception to be set
	 *@return Perception
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Perception")
		int32 SetPerception(int32 tPerception);
	/*
	 *Set function for:
	 *>Luck
	 *	A measure of a character's luck. Luck might influence anything, but mostly random items, encounters and outstanding successes/failures
	 *	(such as critical hits).
	 *@param tLuck - Luck to be set
	 *@return Luck
	 */
	UFUNCTION(BlueprintCallable, Category = "PlayerStats|Luck")
		int32 SetLuck(int32 tLuck);
};
