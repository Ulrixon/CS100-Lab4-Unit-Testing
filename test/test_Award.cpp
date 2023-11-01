#include "gtest/gtest.h"
#include "../include/Awards.h"
#include <gmock/gmock.h>
using awards::RankList;
using awards::AwardCeremonyActions;
using ::testing::Return;
using ::testing::InSequence;
class MockRankList : public RankList
{
private:
    /* data */
    std::string mockArray[6];
    int head = 0;

public:
    virtual std::string getNext() override
    {

        mockArray[0] = "Tony";
        mockArray[1] = "Ryan";
        mockArray[2] = "Anderson";
        mockArray[3] = "Boyi";
        mockArray[4] = "Aamir";
        mockArray[5] = "Jason";
        head++;
        return mockArray[head - 1];
    }
};

class MockAwardCeremonyActions: public AwardCeremonyActions
{
private:
    /* data */
public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
    MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
    MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

TEST(AwardsTests, testPerformAwardCeremony)
{
    MockAwardCeremonyActions awardCeremony;
    MockRankList rank1, rank2;
    
    InSequence seq;
    EXPECT_CALL(awardCeremony, playAnthem())
        .Times(1);
    EXPECT_CALL(awardCeremony, awardBronze(rank1.getNext()))
        .Times(1);
    EXPECT_CALL(awardCeremony, awardSilver(rank1.getNext()))
        .Times(1);
    EXPECT_CALL(awardCeremony, awardGold(rank1.getNext()))
        .Times(1);
    EXPECT_CALL(awardCeremony, turnOffTheLightsAndGoHome())
        .Times(1);

    performAwardCeremony(rank2, awardCeremony);
}