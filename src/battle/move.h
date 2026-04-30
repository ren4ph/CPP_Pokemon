#pragma once
#include <string>
#include "../core/types.h"

struct MoveResult {
    bool missed;
    int damageDealt;
    bool statusApplied;
    std::string message;
};

class Pokemon;

class Move {
    public:
        Move(std::string name, Type moveType, int PP, float accuracy):
            name(name), moveType(moveType), PP(PP), maxPP(PP), accuracy(accuracy) { };

        virtual ~Move() = default;

        virtual MoveResult use(Pokemon& attacker, Pokemon& defender);

        std::string getName() const;
        Type getMoveType() const;
        virtual int getPower() const { return 0; }
        int getPP() const;
        int getMaxPP() const;
        float getAccuracy() const;

        bool checkPP() const;
        bool canUse() const;

        void setPP(int newPP);
        void incPP(int diff);
        void incPP();
        void decPP(int diff);
        void decPP();
        void resetPP();

        void setMaxPP(int newPP);
        void incMaxPP(int diff);
        void incMaxPP();
        void decMaxPP(int diff);
        void decMaxPP();

    protected:
        std::string name;
        Type moveType;
        int PP;
        int maxPP;
        float accuracy;        
};