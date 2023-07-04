#include "funcdefs.h"
#define LevelModel 0x205
#define LevelColission 0x21A

const void *__start() __attribute__((section(".text.start")));
const void main(int State);
void OnActionTile();
void DoNothing();
void Init();
void Update();
void Death();
void Haste();

float RotY = 0;
float DestY = 0;
float RotationSpeed = 10;
float Timer = 0;
char HurryHappened = 0;

AllocatedObject ObjectTable[] =
    {
        {0x9D, 0, 0x10, 0xC, 0},
        {0x4, 0, 0, 0, 0},
        {0, 0x4, 0, 0, 0},
        {0, 0, 0x4, 0, 0},
        {0xFFFF, 0xFFFF, 0, 0x1B6, 0xFFFF},
        {0xFFFF, 0xFFFF, 0xFFFF, 0, 0},
        {
            0xFFFF,
            0xFFFF,
            0xFFFF,
            0xFFFF,
            0xFFFF,
        }};

void *JumpTable[] =
    {
        &DoNothing, // exit scene
        &Init,      // init
        &Update,    // update
        &DoNothing,
        &Haste, // hurry up!
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

    AllocateLevel(LevelModel);
    AllocateColission(LevelColission);
    InitPlayer();

    SetCameraLock(0x7F);
    SetCameraFocusPoint(2365, 1354, 350);
    SetCameraRotationAroundPoint(0, 55, 3500);

    RotY = 0;
    DestY = 0;
    Timer = 0;
    return;
}

void Death()
{
    return;
}


void Update()
{
    if (HurryHappened)
    {
        Timer++;
        if(Timer >= 300)
        {
            Timer = 0;
            DestY += 90;
        }

        if(RotY < DestY)
        {
            RotY += RotationSpeed;
            SetCameraRotationAroundPoint(RotY, 55, 3500);
        }
        else if(DestY >= 360)
        {
            RotY = 0;
            DestY = 0;
        }
    }
}

void Haste()
{
    HurryHappened = 1;
}