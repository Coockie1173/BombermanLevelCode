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

int CoinPickedUp = 0xFFFFFFFF;
float CoinTimer = 0xFFFFFFFF;
float PreviousVelocity = 0xFFFFFFFF;

float CoinOrigX = 0xFFFFFFFF;
float CoinOrigY = 0xFFFFFFFF;
float CoinOrigZ = 0xFFFFFFFF;
float CoinOrigRotX = 0xFFFFFFFF;
float CoinOrigRotY = 0xFFFFFFFF;
float CoinOrigRotZ = 0xFFFFFFFF;

SkyBox *MySkybox = 0xFFFFFFFF;

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
            64,
            2350.0f,
            240.0f,
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
        &DoNothing, // exit scene
        &Init,      // init
        &Update,    // update
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
        &Death, // death
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
            DoNothing(); // tile EFFECT 1
            return;
        }
        else if (State == 0x53)
        {
            DoNothing(); // tile EFFECT 2
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
        ModelEntry *ModelPTR = LoadModelInRAM(SO.ModelID, 0xD0, SO.X, SO.Y, SO.Z);
        LoadModelUnk(ModelPTR, 0x03000000);
        SpecialObjectTable[i].Ptr = ModelPTR;
    }

    MySkybox = SetSkyBox(0x1FD);
    CoinPickedUp = 0;
    CoinTimer = 0;
    PreviousVelocity = 0;
    return;
}

void Death()
{
    return;
}

int isPlayerWithinRange(ModelData mdl, ModelData playerMDL, float range)
{
    // Calculate the distance between the two positions
    float distanceX = mdl.posX - playerMDL.posX;
    float distanceZ = mdl.posZ - playerMDL.posZ;
    float distanceSquared = (distanceX * distanceX) + (distanceZ * distanceZ);

    // Calculate the squared range to avoid using sqrt function
    float rangeSquared = range * range;

    // Compare the squared distance with the squared range
    if (distanceSquared <= rangeSquared)
    {
        return 1; // Player is within range
    }
    else
    {
        return 0; // Player is not within range
    }
}

void Update()
{
    ModelData *mdl = SpecialObjectTable[0].Ptr->ModelDataPtr;
    ModelData *playerMDL = (*PlayerPointer)->ModelDataPtr;

    if (CoinPickedUp == 1)
    {
        ModelEntry *PP = *(PlayerPointer);

        mdl->posX = playerMDL->posX;
        mdl->posY = playerMDL->posY;
        mdl->posY += 200;
        mdl->posZ = playerMDL->posZ;
        mdl->rotX = playerMDL->rotX;
        mdl->rotY = playerMDL->rotY;
        mdl->rotZ = playerMDL->rotZ;

        CoinTimer -= *DeltaTime;
        if (CoinTimer < 0)
        {
            CoinPickedUp = 2;
        }
        if (((*PlayerInput) & L_TRIG) != 0 && PP->VelocityY == 0 && PreviousVelocity <= 0)
        {
            PP->VelocityY = -20;
        }
        PreviousVelocity = PP->VelocityY;
    }
    else if (CoinPickedUp == 2)
    {
        mdl->posX = CoinOrigX;
        mdl->posY = CoinOrigY;
        mdl->posZ = CoinOrigZ;
        mdl->rotX = CoinOrigRotX;
        mdl->rotY = CoinOrigRotY;
        mdl->rotZ = CoinOrigRotZ;
        CoinPickedUp = 0;
    }
    else
    {
        mdl->rotY += *DeltaTime;
        if (isPlayerWithinRange(*mdl, *playerMDL, 25))
        {
            CoinPickedUp = 1;
            CoinTimer = 30 * 60.0f;
            PreviousVelocity = (*PlayerPointer)->VelocityY;
            CoinOrigX = mdl->posX;
            CoinOrigY = mdl->posY;
            CoinOrigZ = mdl->posZ;
            CoinOrigRotX = mdl->rotX;
            CoinOrigRotY = mdl->rotY;
            CoinOrigRotZ = mdl->rotZ;
        }
    }
}