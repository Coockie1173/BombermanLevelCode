#include "funcdefs.h"
#define LevelModel 578
#define LevelColission 588
#define SpecialObjectCount 1

const void *__start() __attribute__((section(".text.start")));
const void main(int State);
void OnActionTile();
void DoNothing();
void Init();
void Update();
void Death();

AllocatedObject ObjectTable[] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {
            0xFFFF,
            0xFFFF,
            0xFFFF,
            0xFFFF,
            0xFFFF,
        }};

Enemy EnemyTable[] =
    {
        {0,
         Regularredenemy,
         0xDE},
        {1,
         Regularredenemy,
         0xDE},
        {2,
         Regularredenemy,
         0xDE},
        {3,
         Regularredenemy,
         0xDE},
        {4,
         Regularredenemy,
         0xDE},
        {5,
         Regularredenemy,
         0xDE},
};

SpecialObject SpecialObjectTable[] =
    {
        {
            0, // ptr should always be 0, there's a function that sets it
            0x9D,
            2350.0f,
            200.0f,
            2850.0f,
            0x0F,
            0x01,
            0x0C,
            0x05,
            0x04,
            0x41D,
            0x0C,
        }};

void *JumpTable[] =
    {
        &DoNothing, //exit scene
        &Init, //init
        &Update, //update
        &DoNothing, 
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &DoNothing,
        &Death, //death
        &DoNothing};

const void *__start()
{
    return &main;
}

const void main(int State)
{
    if (State >= 0x0052)
    {
        if (State == 0x52)
        {
            DoNothing(); //tile EFFECT 1
            return;
        }
        else if (State == 0x53)
        {
            DoNothing(); //tile EFFECT 2
            return;
        }
        return;
    }
    if (State >= 0x0051)
    {
        if (State == 0x51)
        {
            DoNothing();
            return;
        }
        return;
    }
    if (State >= 0x0012)
    {
        if (State == 0x0050)
        {
            OnActionTile();
            return;
        }
        return;
    }
    int JumpTableLoc = State - 1;
    if (JumpTableLoc >= 0x11)
    {
        DoNothing();
        return;
    }

    void (*function)() = (void (*)())JumpTable[JumpTableLoc];
    function();
}

void DoNothing()
{
    return;
}

void OnActionTile()
{
    return;
}

void Init()
{
    ObjectAllocate(&ObjectTable);

    for (int i = 0; i < 6; i++)
    {
        Enemy n = EnemyTable[i];
        EnemyAllocate(n.ID, n.Behaviour, n.ModelID);
    }

    AllocateLevel(LevelModel);
    AllocateColission(LevelColission);
    InitPlayer();

    for (int i = 0; i < SpecialObjectCount; i++)
    {
        SpecialObject SO = SpecialObjectTable[i];
        int *ModelPTR = LoadModelInRAM(SO.ModelID, 0xD0, SO.X, SO.Y, SO.Z);
        LoadModelUnk(ModelPTR, 0x03000000);
        SpecialObjectTable[i].Ptr = ModelPTR;
    }
    return;
}

void Death()
{
    return;
}

void Update()
{

}