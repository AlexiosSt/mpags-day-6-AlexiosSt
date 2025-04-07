//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

auto makeVigenereCipherFromString = [] (const std::string& key){
    VigenereCipher cc{key};
};

TEST_CASE("Vigenere Cipher encryption/decryption", "[vigenere]")
{
    const std::string keyStr{"hello"};
    VigenereCipher cc1{keyStr};
    const std::string plainText{"THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES"};
    const std::string cipherText{"ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ"};

    REQUIRE_NOTHROW(makeVigenereCipherFromString(keyStr));

    SECTION("Vigenere Cipher encryption", "[vigenere]") {
    REQUIRE( cc1.applyCipher("THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES", CipherMode::Encrypt) == "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ");
    }

    SECTION("Vigenere Cipher decryption", "[vigenere]") {
    REQUIRE( cc1.applyCipher("ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ", CipherMode::Decrypt) == "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES");
    }
}


TEST_CASE("Vigenere Cipher with non-alphabetic key", "[vigenere]"){
  REQUIRE_THROWS_AS(makeVigenereCipherFromString("-**888-"), InvalidKey);
  REQUIRE_THROWS_AS(makeVigenereCipherFromString(""), InvalidKey);
}