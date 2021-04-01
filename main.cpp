
#include <vector>

float Max(float a, float b)
{
    return a < b ? a : b;
}

int Max(int a, int b)
{
    return a < b ? a : b;
}

class Component
{
public:
    virtual  void Update();
};

class Transform : public Component
{
public:
    float x, y;

    virtual void Update();

    bool operator==(const Transform& other) const
    {

    }
};

class MeshComponent : public Component
{
public:
    void Update();
};

class GameObject
{
public:
    std::vector<Component*> AllComponents;
    //Transform* MyTransform;
    //MeshComponent* MyMeshComponent;

    void Update()
    {
        for (Component* component : AllComponents)
        {
            component->Update();
        }
    }
};

class World
{
public:
    std::vector<GameObject> AllGameObjects;

    void Update()
    {
        for (GameObject& GO : AllGameObjects)
        {
            GO.Update();
        }
    }
};

void main()
{
    World MyWorld;

    while (1)
    {
        MyWorld.Update();
    }


}