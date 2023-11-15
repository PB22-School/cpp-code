#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Dinosaur.h"
using namespace std;

TEST_CASE("Test can create and render a Dinosaur Object") {
    Dinosaur myobj("Jeff","GROWL",200.259833,100,50);
    CHECK(myobj.to_string() == "Dinosaur Jeff: Health = 50 Weight = 200.253 Strength = 100 Growl Sound = GROWL");
}