// Import the eosio base library.
#include <eosio/eosio.hpp>

// For convenience use the eosio namespace.
using namespace eosio;

enum DefensiveBuildingType {
    Cannon, ArcherTower, Mortar, AirDefense, WizardTower, AirSweeper, HiddenTesla, 
    BombTower, X_Bow, InfernoTower, EagleArtillery, Scattershot, BuilderHut, 
    GigaTesla, GigaInferno_TH13, GigaInferno_TH14, Walls, Bomb, SpringTrap, 
    AirBomb, GiantBomb, SeekingAirMine, SkeletonTrap, TornadoTrap    
}

enum TrapsType {
    Traps, NonTraps
}

struct [[table("DefensiveBuildingInterface1"), contract("DefensiveBuilding")]] DefensiveBuildingInterface1 {
    DefensiveBuildingType defensiveType = {}; // Defensive Building Type
    TrapsType trapsType = {}; // whether is traps or not in Defensive Buildings
    uint64_t level = {}; // Level
    uint64_t size = {}; // The size of building (1*1, 2*2, 3*3, ...)
    uint64_t damagePerSec = {}; // Damage Per Second
    uint64_t damagePerShot = {}; // Damage Per Shot
    uint64_t hitPoints = {}; // Hitpoints
    uint64_t buildCost = {}; // Build Cost
    uint64_t buildTime = {}; // Build Time(second)
    uint64_t expGained = {}; // Experience Gained
    uint64_t townHallLevelRequired = {}; // Town Hall Level Required

    uint64_t primary_key() const { return level; }
    DefensiveBuildingType getDefensiveType() const { return defensiveType; }
    TrapsType getTrapsType() const { return trapsType; }
    uint64_t getSize() const { return size; }
    uint64_t getDamagePerSec() const { return damagePerSec; }
    uint64_t getDamagePerShot() const { return damagePerShot; }
    uint64_t getHitPoints() const { return hitPoints; }
    uint64_t getBuildCost() const { return buildCost; }
    uint64_t getBuildTime() const { return buildTime; }
    uint64_t getExpGained() const { return expGained; }
    uint64_t getTownHallLevelRequired() const { return townHallLevelRequired; }
};

