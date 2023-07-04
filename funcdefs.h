#ifndef _FUNCDEFS_H_
#define _FUNCDEFS_H_

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#define DEG_TO_RAD(degrees) ((degrees) * (M_PI / 180.0f))

typedef struct {
    int modelFlags;         // Offset: 0x00
    int Unk04;             // Offset: 0x04
    int Unk08;             // Offset: 0x08
    int visibilityAnimationFlags;   // Offset: 0x0C
    float posX;              // Offset: 0x10
    float posY;              // Offset: 0x14
    float posZ;              // Offset: 0x18
    float rotX;              // Offset: 0x1C
    float rotY;              // Offset: 0x20
    float rotZ;              // Offset: 0x22
    float scaleX;            // Offset: 0x24
    float scaleY;            // Offset: 0x28
    float scaleZ;            // Offset: 0x2C
    int Unk30;             // Offset: 0x30
    int Unk34;             // Offset: 0x34
    int Unk38;             // Offset: 0x38
    int* modelPtr;         // Offset: 0x3C
    int Unk40;             // Offset: 0x40
    int Unk44;             // Offset: 0x44
    int Unk48;             // Offset: 0x48
    int Unk4C;             // Offset: 0x4C
} ModelData;

typedef struct {
    int ID;      // Offset: 0x00
    int Unk1;      // Offset: 0x04
    int Unk2;      // Offset: 0x08
    int Unk3;      // Offset: 0x0C
    int Unk4;         // Offset: 0x10
    int Unk5;         // Offset: 0x14
    int Unk6;         // Offset: 0x18
    int Unk7;         // Offset: 0x1C
    int Unk8;         // Offset: 0x20
    int Unk9;         // Offset: 0x24
    int Unk10;        // Offset: 0x28
    int Unk11;        // Offset: 0x2C
    int Unk12;        // Offset: 0x30
    float Unk13;        // Offset: 0x34
    float Unk14;        // Offset: 0x38
    int Unk15;        // Offset: 0x3C
    ModelData* ModelDataPtr;        // Offset: 0x40
    int Unk17;        // Offset: 0x44
    int Unk18;        // Offset: 0x48
    int Unk19;        // Offset: 0x4C
    int Unk20;        // Offset: 0x50
    int Unk21;        // Offset: 0x54
    const float X;        // Offset: 0x58
    const float Y;        // Offset: 0x5C
    const float Z;        // Offset: 0x60
    int Unk25;        // Offset: 0x64
    int Unk26;        // Offset: 0x68
    float VelocityY;        // Offset: 0x6C
    float Unk28;        // Offset: 0x70
    float Unk29;        // Offset: 0x74
    int* Unk30;        // Offset: 0x78
    int* Unk31;        // Offset: 0x7C
} ModelEntry;

typedef enum {
    R_CBUTTONS   = 0x0001,
    L_CBUTTONS   = 0x0002,
    D_CBUTTONS   = 0x0004,
    U_CBUTTONS   = 0x0008,
    R_TRIG       = 0x0010,
    L_TRIG       = 0x0020,
    R_JPAD       = 0x0100,
    L_JPAD       = 0x0200,
    D_JPAD       = 0x0400,
    U_JPAD       = 0x0800,
    START_BUTTON = 0x1000,
    Z_TRIG       = 0x2000,
    B_BUTTON     = 0x4000,
    A_BUTTON     = 0x8000
} ControllerButtons;

typedef int (*CheckTileFuncS)(short X1, short Y1, short X2, short Y2);
CheckTileFuncS CheckTileFunc = (CheckTileFuncS)0x802457D8;

typedef void (*EndLevelS)();
EndLevelS EndLevelFunc = (EndLevelS)0x8023E8AC;

typedef struct
{
    short ObjectID;
    short ColissionType;
    short Unknown;
    short ExplosionType;
    short Flags;
} AllocatedObject;

typedef void (*ObjectAllocateS)(AllocatedObject *Objects);
ObjectAllocateS ObjectAllocate = (ObjectAllocateS)0x8027EB5C;

typedef enum
{
    Regularredenemy = 0x0000,
    Regularredenemy2 = 0x0001,
    Spinner = 0x0002,
    ShooterDifferentto0x0008 = 0x0003,
    Swooper = 0x0004,
    Totem = 0x0005,
    Splittingfrogthing = 0x0006,
    Butterfly = 0x0007,
    Shooter = 0x0008,
    Genericdwellingenemyprobablyfish = 0x0009,
    Fishoutofwater = 0x000A,
    Weirdwaterbubble = 0x000B,
    Permanentspinnerprobshardmode = 0x000C,
    Firespittingtower = 0x000D,
    FuckedupspinnerMightbeminer = 0x000E,
    Bat = 0x000F,
    Somethinghot = 0x0010,
    Rocketlauncherman = 0x0011,
    Snowman = 0x0012,
    Bunny = 0x0013,
    Spinnerbutnotdeadly = 0x0014,
    Splitondeathnonlethal = 0x0015,
    Slowpatrollingenemy = 0x0016,
    Nonlethalspinner = 0x0017,
    ShootingthingfromBF3 = 0x0018,
    UnusedicespiketowerthingDoesnothingdropsheart = 0x0019,
    Lasershootingdown = 0x001A,
    Thejetthing = 0x001B,
    Somethingbigthatshootsyouaround = 0x001C,
    Genericdwellingenemy = 0x001D,
    purplecardshooterfromrainbowpalace = 0x001E,
    oneoftheotherrainbowpalaceguards = 0x001F,
    therainbowpalaceguardthatactslikeaspinner = 0x0020,
    Thefunnycloud = 0x0021,
    Zigzaggingspinner = 0x0022,
    Hardmodebird = 0x0023,
    Nonlethalfastspinner = 0x0024,
    Genericdwellingenemyharmless = 0x0025,
    Staticthingtakesmultiplehitsdropsgem = 0x0026,
    Nothing = 0x0027,
    Nothing2 = 0x0028,
    Genericdwellingenemyspicy = 0x0029,
} EnemyBehaviour;

typedef void (*EnemyAllocateS)(int ID, EnemyBehaviour Behaviour, int Model);
EnemyAllocateS EnemyAllocate = (EnemyAllocateS)0x80287008;

typedef struct
{
    short ID;
    EnemyBehaviour Behaviour;
    short ModelID;
} Enemy;

typedef void (*AllocateLevelS)(int Model);
AllocateLevelS AllocateLevel = (AllocateLevelS)0x80243BA8;
AllocateLevelS AllocateColission = (AllocateLevelS)0x8026FF64;

typedef void (*InitPlayerS)(void);
InitPlayerS InitPlayer = (InitPlayerS)0x80245CDC;

typedef struct
{
    ModelEntry *Ptr;
    int ModelID;
    float X;
    float Y;
    float Z;
    int TileX1;
    int TileType;
    int TileY1;
    int LayerTop;
    int LayerWallEnd;
    int UniqueID;
    int Inventory;
} SpecialObject;

typedef ModelEntry *(*LoadModelInRAMS)(int ModelID, int Unk, float X, float Y, float Z);
LoadModelInRAMS LoadModelInRAM = (LoadModelInRAMS)0x802310F4;

typedef void *(*LoadModelUnkS)(ModelEntry *ModelPTR, int Unk);
LoadModelUnkS LoadModelUnk = (LoadModelUnkS)0x80231408;

typedef void *(*SetColissionTopS)(int TileX1, int Layer, int TileY1, int TileX2, int TileY2, int TileType); //tiletype in raw tiledata
SetColissionTopS SetColissionSingleLayer = (SetColissionTopS)0x8026DA2C;

typedef void *(*SetColissionBottomS)(int TileX1, int ToLayer, int TileY1, int TileX2, int FromLayer, int TileY2, int TileType); //tiletype in raw tiledata
SetColissionBottomS SetColissionMultiLayer = (SetColissionBottomS)0x8026DB88;

typedef int *(*CheckUnkS)(int Unk);
typedef void *(*CheckUnkS2)(int Unk);
CheckUnkS CheckUnk = (CheckUnkS)0x8028A1DC;
CheckUnkS2 CheckUnk2 = (CheckUnkS2)0x8028A24C;

typedef int *(*UnkFunctionAllocateS)(int Unk1, int Unk2, int Unk3, int Unk4);
UnkFunctionAllocateS UnkFunctionAllocate = (UnkFunctionAllocateS)0x80231274;

typedef void *(*UnkFunctionAllocate2S)(int *ptr, int unk1);
UnkFunctionAllocate2S UnkFunctionAllocate2 = (UnkFunctionAllocate2S)0x8022984C;

/// @brief 0x7F to lock
typedef void *(*UnlockCameraS)(int Val);
UnlockCameraS SetCameraLock = (UnlockCameraS)0x802362B8;

typedef void *(*StallFramesS)(int Frames);
StallFramesS StallFrames = (StallFramesS)0x8023903C;

typedef void *(*MovePlayerS)(int flag, int Direction, float Speed, int Distance);
MovePlayerS MovePlayer = (MovePlayerS)0x8024A824;

typedef void *(*LockPlayerS)(int Locked);
LockPlayerS LockPlayer = (LockPlayerS)0x802452E8;

typedef void *(*SetCameraPositionLateral)();

SetCameraPositionLateral SetCameraLateralS = (SetCameraPositionLateral)0x802346C8;

void SetCameraFocusPoint(float x, float y, float z) {
    asm volatile (
        "mov.s $f12, %0\n"  // Move x to f12 register
        "mov.s $f14, %2\n"  // Move z to f14 register
        "mfc1 $a2, %1\n"   // Move y to a2 register
        :
        : "f"(x), "f"(y), "f"(z)
    );

    void* result = SetCameraLateralS();

    return 0;
}

typedef void *(*SetCameraPositionZoomRotationS)();
SetCameraPositionZoomRotationS SetCameraPositionZoomRotation = (SetCameraPositionZoomRotationS)0x80234778;

void SetCameraRotationAroundPoint(float RotY, float RotZ, float Distance) {
    asm volatile (
        "mov.s $f12, %0\n"  // Move x to f12 register
        "mov.s $f14, %2\n"  // Move z to f14 register
        "mfc1 $a2, %1\n"   // Move y to a2 register
        :
        : "f"(RotY), "f"(Distance), "f"(RotZ)
    );

    void* result = SetCameraPositionZoomRotation();

    return 0;
}

//potentially threading so steer clear :)
//typedef void *(*SetHasteModeFunctionS)(void* Func, int Unk1, int Unk2, int Unk3);
//SetHasteModeFunctionS SetHasteModeFunction = (SetHasteModeFunctionS)0x80238B9C;

typedef struct {
    int Unk00;     // Offset: 0x00
    int UnkFlags1;     // Offset: 0x04
    int FileID;     // Offset: 0x08
    int UnkFlags2;     // Offset: 0x0C
    int UnkFlags3;     // Offset: 0x10
    int UnkFlags4;     // Offset: 0x14
    float ScrollXSpeed;     // Offset: 0x18
    float ScrollYSpeed;     // Offset: 0x1C
    float ScrollX;     // Offset: 0x20
    float ScrollY;     // Offset: 0x24
    float OffsetX;     // Offset: 0x28
    float OffsetY;     // Offset: 0x2C
    float ResX;     // Offset: 0x30
    float ResY;     // Offset: 0x34
    float ShiftX;     // Offset: 0x38
    float ShiftY;     // Offset: 0x3C
    float ScaleX;     // Offset: 0x40
    float ScaleY;     // Offset: 0x44
    float ImageWidth;     // Offset: 0x48
    float ImageHeight;     // Offset: 0x4C
} SkyBox;

SkyBox* SetSkyBox(int FileID)
{
    SkyBox* (*InitSkyBox)(int FileID);
    InitSkyBox = (int* (*)(int FileID))0x80287DC0;
    SkyBox* LoadedSkybox = InitSkyBox(FileID);

    void* (*SetSkyBoxFlags)(SkyBox* Sky, int Flags);
    SetSkyBoxFlags = (void* (*)(SkyBox* Sky, int Flags)) 0x802878E0;
    SetSkyBoxFlags(LoadedSkybox, 0x20000001);

    return LoadedSkybox;
}

float* DeltaTime = (float*)0x802AC644;

const short *PlayerInput = (short *)0x80027064;
const ModelEntry **PlayerPointer = (ModelEntry **)0x800AEE18;
#endif
