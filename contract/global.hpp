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
    None, Ground, Air, Buildings
}

enum BuildingType {
    None, HomeVillage, BuilderBase
}

enum FavoriteTarget {
    None, Any
}

///////////////////////////////////////  Modifier Structure //////////////////////////////////////////////

struct [[table("GoldPassModifier"), contract("DefensiveBuilding")]] GoldPassModifier {
    uint64_t townHallLevel = {}; // Town Hall Level
    uint64_t numberAvailable = {}; // Number Available

    // uint64_t getTownHallLevel() const { return townHallLevel; }
    // uint64_t getNumberAvailable() const { return numberAvailable; }
}

///////////////////////////////////////  Statistics Structure //////////////////////////////////////////////

struct [[table("GeneralStatistics1"), contract("DefensiveBuilding")]] GeneralStatistics1 {
    uint64_t cost = {}; // Gear Up Cost
    uint64_t time = {}; // Gear Up Time
    uint64_t level1 = {}; // Home Village Level Required 
    uint64_t level2 = {}; // Builder Base Level Required

    // uint64_t getCost() const { return cost; }
    // uint64_t getTime() const { return time; }
    // uint64_t getLevel1() const { return level1; }
    // uint64_t getLevel2() const { return level2; }
}

struct [[table("BuilderStatistics"), contract("DefensiveBuilding")]] BuilderStatistics {
    uint64_t range = {}; // Gear Up Cost
    uint64_t repairSpeed = {}; // Gear Up Time
    uint64_t movementSpeed = {}; // Home Village Cannon Level Required Level 
    uint64_t unitType = {}; // Double Cannon Level Required

    // uint64_t getRange() const { return range; }
    // uint64_t getRepairSpeed() const { return repairSpeed; }
    // uint64_t getMovementSpeed() const { return movementSpeed; }
    // uint64_t getUnitType() const { return unitType; }
}

///////////////////////////////////////  Property Structure //////////////////////////////////////////////

/* Cannon, Archer Tower, Mortar, Air Defense, Wizard Tower, Air Sweeper, Bomb Tower */
struct [[table("DefensiveProperty1"), contract("DefensiveBuilding")]] DefensiveProperty1 {
    uint64_t range = {}; // Range
    uint64_t attackSpeed = {}; // Attack Speed (0.5s)
    DamageType damageType = {}; // Damage Type
    UnitTypeTargeted unitType = {}; // Unit Type Targeted

    // uint64_t getRange() const { return range; }
    // uint64_t getAttackSpeed() const { return attackSpeed; }
    // DamageType getDamageType() const { return damageType; }
    // UnitTypeTargeted getUnitType() const { return unitType; }
}

/*  */
struct [[table("DefensiveProperty2"), contract("DefensiveBuilding")]] DefensiveProperty2 {
    uint64_t range = {}; // Range
    uint64_t attackSpeed = {}; // Attack Speed (0.5s)
    DamageType damageType = {}; // Damage Type
    UnitTypeTargeted unitType = {}; // Unit Type Targeted
    uint64_t numberOfRounds = {}; // Number Of Rounds

    // uint64_t getRange() const { return range; }
    // uint64_t getAttackSpeed() const { return attackSpeed; }
    // DamageType getDamageType() const { return damageType; }
    // UnitTypeTargeted getUnitType() const { return unitType; }
    // uint64_t getNumberOfRounds() const { return numberOfRounds; }
}

/* Hidden Tesla, */
struct [[table("DefensiveProperty3"), contract("DefensiveBuilding")]] DefensiveProperty3 {
    uint64_t range = {}; // Range
    uint64_t triggerRange = {}; // Trigger Range
    uint64_t attackSpeed = {}; // Attack Speed (0.5s)
    DamageType damageType = {}; // Damage Type
    UnitTypeTargeted unitType = {}; // Unit Type Targeted
    FavoriteTarget favTarget = {}; // Favorite Target

    // uint64_t getRange() const { return range; }
    // uint64_t getTriggerRange() const { return range; }
    // uint64_t getAttackSpeed() const { return attackSpeed; }
    // DamageType getDamageType() const { return damageType; }
    // UnitTypeTargeted getUnitType() const { return unitType; }
    // FavoriteTarget getFavoriteTarget() const { return favTarget; }
}

/* X-Bow */
struct [[table("DefensiveProperty4"), contract("DefensiveBuilding")]] DefensiveProperty4 {
    uint64_t range = {}; // Range
    uint64_t attackSpeed = {}; // Attack Speed (0.5s)
    DamageType damageType = {}; // Damage Type
    uint64_t numberOfRounds = {}; // Number Of Rounds

    // uint64_t getRange() const { return range; }
    // uint64_t getAttackSpeed() const { return attackSpeed; }
    // DamageType getDamageType() const { return damageType; }
    // uint64_t getNumberOfRounds() const { return numberOfRounds; }
}

///////////////////////////////////////  General Structure //////////////////////////////////////////////

/* Cannon, Archer Tower, Mortar, Wizard Tower, Hidden Tesla, X-Bow */
struct [[table("DefensiveBuildingGeneral1"), contract("DefensiveBuilding")]] DefensiveBuildingGeneral1 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec = {}; // Damage Per Second
    uint64_t damagePerShot = {}; // Damage Per Shot
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    // uint64_t getLevel() const { return level; }
    // uint64_t getSize() const { return size; }
    // uint64_t getDamagePerSec() const { return damagePerSec; }
    // uint64_t getDamagePerShot() const { return damagePerShot; }
    // uint64_t getHitPoints() const { return hitPoints; }
    // uint64_t getBuildCost() const { return buildCost; }
    // uint64_t getBuildTime() const { return buildTime; }
    // uint64_t getExpGained() const { return expGained; }
    // uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}

/* Air Defense, */
struct [[table("DefensiveBuildingGeneral2"), contract("DefensiveBuilding")]] DefensiveBuildingGeneral2 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec = {}; // Damage Per Second
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    // uint64_t getLevel() const { return level; }
    // uint64_t getSize() const { return size; }
    // uint64_t getDamagePerSec() const { return damagePerSec; }
    // uint64_t getHitPoints() const { return hitPoints; }
    // uint64_t getBuildCost() const { return buildCost; }
    // uint64_t getBuildTime() const { return buildTime; }
    // uint64_t getExpGained() const { return expGained; }
    // uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}

/* Air Sweeper */
struct [[table("DefensiveBuildingGeneral3"), contract("DefensiveBuilding")]] DefensiveBuildingGeneral3 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t pushStrength = {}; // Push Strength
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    // uint64_t getLevel() const { return level; }
    // uint64_t getSize() const { return size; }
    // uint64_t getPushStrength() const { return pushStrength; }
    // uint64_t getHitPoints() const { return hitPoints; }
    // uint64_t getBuildCost() const { return buildCost; }
    // uint64_t getBuildTime() const { return buildTime; }
    // uint64_t getExpGained() const { return expGained; }
    // uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}

/*  Bomb Tower, */
struct [[table("DefensiveBuildingGeneral4"), contract("DefensiveBuilding")]] DefensiveBuildingGeneral4 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec = {}; // Damage Per Second
    uint64_t damagePerShot = {}; // Damage Per Shot
    uint64_t damageWhenDestroyed = {}; // Damage When Destroyed
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    // uint64_t getLevel() const { return level; }
    // uint64_t getSize() const { return size; }
    // uint64_t getDamagePerSec() const { return damagePerSec; }
    // uint64_t getDamagePerShot() const { return damagePerShot; }
    // uint64_t getDamageWhenDestroyed() const { return damageWhenDestroyed; }
    // uint64_t getHitPoints() const { return hitPoints; }
    // uint64_t getBuildCost() const { return buildCost; }
    // uint64_t getBuildTime() const { return buildTime; }
    // uint64_t getExpGained() const { return expGained; }
    // uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}

/*  Inferno Tower */
struct [[table("DefensiveBuildingGeneral5"), contract("DefensiveBuilding")]] DefensiveBuildingGeneral5 {
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec[3] = {0}; // 0: initial, 1: after 1.5s,  2: after 5.25s
    uint64_t damagePerHit[3] = {0}; // 0: initial, 1: after 1.5s,  2: after 5.25s
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    // uint64_t getLevel() const { return level; }
    // uint64_t getSize() const { return size; }
    // uint64_t 
    // uint64_t getHitPoints() const { return hitPoints; }
    // uint64_t getBuildCost() const { return buildCost; }
    // uint64_t getBuildTime() const { return buildTime; }
    // uint64_t getExpGained() const { return expGained; }
    // uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
}
