#pragma once
#include <array>
#include <string>
#include <memory>
#include <optional>
#include <ostream>
#include "types.h"

class Move;
struct MoveResult;

class Pokemon {
    public:
        Pokemon(std::string name, Type primaryType, Type secondaryType, int hp, int attack, int defense, int spAtk, int spDef, int speed)
            :name(name), primaryType(primaryType), secondaryType(secondaryType), dualType(primaryType != secondaryType),
             hp(hp), maxHP(hp), attack(attack), defense(defense), spAtk(spAtk), spDef(spDef),
             speed(speed), criticalChance(speed/512.0), majorEffect(StatusEffect::NONE) { } 

        Pokemon(std::string name, Type primaryType, int hp, int attack, int defense, int spAtk, int spDef, int speed)
            :name(name), primaryType(primaryType), secondaryType(primaryType), dualType(false),
             hp(hp), maxHP(hp), attack(attack), defense(defense), spAtk(spAtk), spDef(spDef),
             speed(speed), criticalChance(speed/512.0), majorEffect(StatusEffect::NONE) { }
        
        Pokemon(std::string name)
            :name(name), primaryType(Type::NORMAL), secondaryType(Type::NORMAL), dualType(false),
             hp(8), maxHP(8), attack(4), defense(1), spAtk(3), spDef(0),
             speed(11), criticalChance(11/512.0), majorEffect(StatusEffect::NONE) { }
        
        virtual ~Pokemon() = default;
        virtual bool isCatchable() const { return true; }
        virtual bool isLegendary() const { return false; }

        bool operator==(const Pokemon& other) const;
        bool operator<(const  Pokemon& other) const; 
        std::ostream& operator<<(std::ostream & os);

        std::string getName() const;
        Type getPrimaryType() const;
        Type getSecondaryType() const;
        bool isDualType() const;
        int getHP() const;
        int getMaxHP() const;
        int getAttack() const;
        int getEffectiveAttack() const;
        int getDefense() const;
        int getSpAtk() const;
        int getSpDef() const;
        int getSpeed() const;
        int getEffectiveSpeed() const;
        float getCriticalChance() const;
        std::optional<Move*> getMoveByName(std::string name) const;
        std::optional<Move*> getMoveByIndex(int i) const;
        std::optional<int>   getIndexByName(std::string name) const;
        std::optional<int>   getIndexByMove(Move*) const;
        bool canMove() const;
        bool hasMaxMoves() const;

        void addMove(std::unique_ptr<Move> m);
        void replaceMove(std::string name, std::unique_ptr<Move> m);
        void replaceMove(int i, std::unique_ptr<Move> m);
        void replaceMove(Move*, std::unique_ptr<Move> m);
        MoveResult useMove(Move*, Pokemon& p);
        
        void takeDamage(int amount);
        void applyEffect(StatusEffect s);
        void applyEndOfTurnEffects();

        void heal(int amount);
        bool isFainted() const;
        
        virtual void printStats() const;

    protected:
        std::string name;
        Type primaryType;
        Type secondaryType;
        bool dualType;
        int hp;
        int maxHP;
        int attack;
        int defense;
        int spAtk;
        int spDef;
        int speed;
        float criticalChance;
        StatusEffect majorEffect;
        int sleepCounter;
        int toxicCounter;
        std::array<std::unique_ptr<Move>, 4> moves;
    };