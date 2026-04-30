#pragma once
#include <array>
#include <optional>
#include <stdexcept>

template <typename T, int MaxSize>
class Inventory {
    public:
        Inventory(): count(0) {}

        bool add(T item) {
            if (isFull()) return false;
            slots[count++] = item;
            return true;
        }

        bool remove(int index) {
            if (index  < 0 || index >= count) return false;

            for (int i = index; i < count - 1; i++) {
                slots[i] = slots[i + 1];
            }
            count--;
            return true;
        }

        std::optional<T> get(int index) const {
            if (index < 0 || index >= count) return std::nullopt;
            return slots[index];
        }

        int size() const { return count; }
        bool isFull() const { return count >= MaxSize; }
        bool isEmpty() const { return count == 0; }

    private:
        std::array<T, MaxSize> slots;
        int count;
};