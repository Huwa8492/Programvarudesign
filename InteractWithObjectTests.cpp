#include <gtest/gtest.h>
#include <memory>
#include "InteractWithObjectController.hpp"
#include "Scene.hpp"
#include "GameObject.hpp"
#include "Interactions.hpp"

using namespace GameEngine;

class InteractWithObjectTests : public ::testing::Test {
protected:
    std::shared_ptr<Scene> testScene;
    std::shared_ptr<GameObject> testObject;
    std::unique_ptr<InteractWithObjectController> controller;

    void SetUp() override {
        testScene = std::make_shared<Scene>();
        testObject = std::make_shared<GameObject>("TestLamp");

        testObject->addInteraction("TurnOn", std::make_shared<TurnOn>());
        testObject->addInteraction("TurnOff", std::make_shared<TurnOff>());
        testObject->addInteraction("Look", std::make_shared<Look>());

        testScene->addObject(testObject);
        controller = std::make_unique<InteractWithObjectController>(testScene);
    }

    void TearDown() override {
        controller.reset();
        testObject.reset();
        testScene.reset();
    }
};

TEST_F(InteractWithObjectTests, SelectGameObject_Positive_ObjectExists_ReturnsTrue) {
    bool result = controller->selectGameObject("TestLamp");
    EXPECT_TRUE(result);
    EXPECT_EQ("TestLamp", controller->getCurrentTarget()->getName());
}

TEST_F(InteractWithObjectTests, SelectGameObject_Negative_ObjectMissing_ReturnsFalse) {
    bool result = controller->selectGameObject("NonExistentDragon");
    EXPECT_FALSE(result);
    EXPECT_EQ(nullptr, controller->getCurrentTarget());
}

TEST_F(InteractWithObjectTests, SelectInteraction_Positive_ValidInteraction_ReturnsTrue) {
    controller->selectGameObject("TestLamp");
    bool result = controller->selectInteraction(testObject, "TurnOn");
    
    EXPECT_TRUE(result);
    EXPECT_NE(nullptr, controller->getCurrentInteraction());
}

TEST_F(InteractWithObjectTests, SelectInteraction_Negative_InvalidInteraction_ReturnsFalse) {
    controller->selectGameObject("TestLamp");
    bool result = controller->selectInteraction(testObject, "Eat"); 
    
    EXPECT_FALSE(result);
    EXPECT_EQ(nullptr, controller->getCurrentInteraction());
}

TEST_F(InteractWithObjectTests, SetInteractionOptions_Positive_WithSelectedInteraction_ReturnsTrue) {
    controller->selectGameObject("TestLamp");
    controller->selectInteraction(testObject, "Look");
    
    bool result = controller->setInteractionOptions("closely");
    
    EXPECT_TRUE(result);
    EXPECT_EQ("closely", controller->getCurrentOptions());
}

TEST_F(InteractWithObjectTests, SetInteractionOptions_Negative_NoInteractionSelected_ReturnsFalse) {
    bool result = controller->setInteractionOptions("closely");
    
    EXPECT_FALSE(result);
    EXPECT_EQ("", controller->getCurrentOptions());
}

TEST_F(InteractWithObjectTests, StartInteraction_Positive_TurnOnAndLook_ChangesState) {
    controller->selectGameObject("TestLamp");
    controller->selectInteraction(testObject, "TurnOn");
    std::string resultOn = controller->startInteraction();

    EXPECT_EQ("TestLamp is now turned ON.", resultOn);
    EXPECT_TRUE(testObject->getIsOn());

    controller->selectInteraction(testObject, "Look");
    std::string resultLook = controller->startInteraction();

    EXPECT_EQ("You look at the TestLamp. It is currently ON.", resultLook);
}

TEST_F(InteractWithObjectTests, StartInteraction_Negative_NoTargetSelected_ThrowsException) {
    EXPECT_THROW(controller->startInteraction(), std::logic_error);
}