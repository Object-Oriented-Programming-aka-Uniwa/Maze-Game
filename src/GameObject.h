#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    protected:
        int x, y;
        char symbol;
        int colorPair;
    
    public:
        GameObject(int startX, int startY, char sym, int color)
            : x(startX), y(startY), symbol(sym), colorPair(color) {}

        virtual ~GameObject() {}

        int getX() const { return x; }
        int getY() const { return y; }
        void setPosition(int newX, int newY) { x = newX; y = newY; }

        virtual void draw() = 0;
};

#endif