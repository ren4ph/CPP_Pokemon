#pragma once
#include <random>

class RNG {
    public:
        static RNG& get() {
            static RNG instance;
            return instance;
        }

        int randInt(int min, int max) {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(engine);
        }

        float randFloat(float min, float max) {
            std::uniform_real_distribution<float> dist(min, max);
            return dist(engine);
        }

        bool chance(float probability) {
            return randFloat(0.0f, 1.0f) < probability;
        }

        void seed(unsigned int s) { engine.seed(s); }
    
    private:
        RNG() : engine(std::random_device{}()) {}
        std::mt19937 engine;
};