// Import the eosio base library.
#include <eosio/eosio.hpp>

// For convenience use the eosio namespace.
using namespace eosio;
using namespace std;

enum DefensiveBuildingType {
    None, Cannon, ArcherTower, Mortar, AirDefense, WizardTower, AirSweeper, HiddenTesla, 
    BombTower, X_Bow, InfernoTower, EagleArtillery, Scattershot, BuilderHut, GigaTesla, 
    GigaInferno_TH13, GigaInferno_TH14, Walls, Bomb, SpringTrap, AirBomb, GiantBomb, 
    SeekingAirMine, SkeletonTrap, TornadoTrap    
}

enum TrapsType {
    None, Traps
}

enum DamageType {
    None, SingleTarget, Splash_15_Tiles, Splash_1_Tile,  
}

enum UnitTypeTargeted {
    None, Ground, GroundAndAir
}

enum BuildingType {
    None, HomeVillage, BuilderBase
}

struct [[table("GoldPassModifier"), contract("DefensiveBuilding")]] GoldPassModifier {
    uint64_t townHallLevel = {}; // Town Hall Level
    uint64_t numberAvailable = {}; // Number Available

    uint64_t getTownHallLevel() const { return townHallLevel; }
    uint64_t getNumberAvailable() const { return numberAvailable; }
}

struct [[table("GearUpStatistics"), contract("DefensiveBuilding")]] GearUpStatistics {
    uint64_t cost = {}; // Gear Up Cost
    uint64_t time = {}; // Gear Up Time
    uint64_t cannonLevel = {}; // Home Village Cannon Level Required Level 
    uint64_t doubleCannonLevel = {}; // Double Cannon Level Required

    uint64_t getCost() const { return cost; }
    uint64_t getTime() const { return time; }
    uint64_t getCannonLevel() const { return cannonLevel; }
    uint64_t getDoubleCannonLevel() const { return doubleCannonLevel; }
}

struct [[table("BuilderStatistics"), contract("DefensiveBuilding")]] BuilderStatistics {
    uint64_t range = {}; // Gear Up Cost
    uint64_t repairSpeed = {}; // Gear Up Time
    uint64_t movementSpeed = {}; // Home Village Cannon Level Required Level 
    uint64_t unitType = {}; // Double Cannon Level Required

    uint64_t getRange() const { return range; }
    uint64_t getRepairSpeed() const { return repairSpeed; }
    uint64_t getMovementSpeed() const { return movementSpeed; }
    uint64_t getUnitType() const { return unitType; }
}

struct [[table("DefensiveProperty"), contract("DefensiveBuilding")]] DefensiveProperty {
    uint64_t range = {}; // Range
    uint64_t attackSpeed = {}; // Attack Speed (0.5s)
    DamageType damageType = {}; // Damage Type
    UnitTypeTargeted unitType = {}; // Unit Type Targeted
    uint64_t numberOfRounds = {}; // Number Of Rounds

    uint64_t getRange() const { return range; }
    uint64_t getAttackSpeed() const { return attackSpeed; }
    DamageType getDamageType() const { return damageType; }
    UnitTypeTargeted getUnitType() const { return unitType; }
    uint64_t getNumberOfRounds() const { return numberOfRounds; }
}

struct [[table("DefensiveBuildingInterface1"), contract("DefensiveBuilding")]] DefensiveBuildingInterface1 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec = {}; // Damage Per Second
    uint64_t damagePerShot = {}; // Damage Per Shot
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    uint64_t getLevel() const { return level; }
    uint64_t getSize() const { return size; }
    uint64_t getDamagePerSec() const { return damagePerSec; }
    uint64_t getDamagePerShot() const { return damagePerShot; }
    uint64_t getHitPoints() const { return hitPoints; }
    uint64_t getBuildCost() const { return buildCost; }
    uint64_t getBuildTime() const { return buildTime; }
    uint64_t getExpGained() const { return expGained; }
    uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}