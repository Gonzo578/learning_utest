#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

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

TEST_F(SoundexEncoding, ReplacesMultipleConstantsWithDigits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
	ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
	ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
	ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
	ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
	ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

	ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
	ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
	ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, CombinesDuplicateWhen2ndLetterDuplicates1st) {
	ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, PeriodLettersAreIgnored){
	ASSERT_THAT(soundex.encode("Mr.Smith"), Eq("M625"));
}
