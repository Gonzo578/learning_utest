#include "gmock/gmock.h"
#include "Soundex.h"

using testing::Eq;

class SoundexEncoding : public testing::Test {
public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
	EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
	EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
	EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNoneAlphabetics) {
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, DISABLED_ReplacesMultipleConstantsWithDigits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}
