#ifndef _FUNCDEFS_H_
#define _FUNCDEFS_H_

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
    int *Ptr;
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

typedef int *(*LoadModelInRAMS)(int ModelID, int Unk, float X, float Y, float Z);
LoadModelInRAMS LoadModelInRAM = (LoadModelInRAMS)0x802310F4;

typedef void *(*LoadModelUnkS)(int *ModelPTR, int Unk);
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

typedef void *(*UnlockCameraS)(int Val);
UnlockCameraS UnlockCamera = (UnlockCameraS)0x802362B8;

typedef void *(*StallFramesS)(int Frames);
StallFramesS StallFrames = (StallFramesS)0x8023903C;

typedef void *(*MovePlayerS)(int flag, int Direction, float Speed, int Distance);
MovePlayerS MovePlayer = (MovePlayerS)0x8024A824;

typedef void *(*LockPlayerS)(int Locked);
LockPlayerS LockPlayer = (LockPlayerS)0x802452E8;

typedef enum
{
    INPUT_L = 0x00200000
} Inputs;

float* DeltaTime = (float*)0x802AC644;

const int *PlayerInput = (int *)0x80027064;
const int *PlayerPointer = (int *)0x800AEE18;
#endif
