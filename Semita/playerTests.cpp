#define CATCH_CONFIG_MAIN
// #include "catch.hpp" - does not work in this environment
#include "player.h"
/*

                            =================================
Though this does not work, I will include it to show how unit tests would be structures 
                            =================================
TEST_CASE("Player initial values", "[player]") {
    Player player;

    SECTION("Initial HP and Mana") {
        REQUIRE(player.getHP() == 100);
        REQUIRE(player.getMana() == 100);
    }

    SECTION("Initial Gold") {
        REQUIRE(player.getGold() == 20);
    }

    SECTION("Initial Experience and Level") {
        REQUIRE(player.getExperience() == 0);
        REQUIRE(player.getLevel() == 1);
    }

    SECTION("Initial Class") {
        REQUIRE(player.getClass() == PlayerClass::Unselected);
    }
}

TEST_CASE("Player gold manipulation", "[player]") {
    Player player;

    SECTION("Add gold") {
        player.addGold(10);
        REQUIRE(player.getGold() == 30);
    }

    SECTION("Spend gold successfully") {
        player.setGold(20); // Ensure starting gold
        REQUIRE(player.spendGold(10));
        REQUIRE(player.getGold() == 10);
    }

    SECTION("Spend gold fails if not enough") {
        player.setGold(20); // Ensure starting gold
        REQUIRE_FALSE(player.spendGold(100));
        REQUIRE(player.getGold() == 20);
    }
}

TEST_CASE("Player HP and Mana setters", "[player]") {
    Player player;
    player.setHP(50);
    player.setMana(75);

    REQUIRE(player.getHP() == 50);
    REQUIRE(player.getMana() == 75);
}

*/