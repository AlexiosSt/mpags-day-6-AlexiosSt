//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"


auto makeCaesarCipherFromString = [] (const std::string& key){
    CaesarCipher cc{key};
};

TEST_CASE("Caesar Cipher encryption/decryption", "[caesar]")
{
    const std::size_t key{10};
    const std::string keyStr{"10"};
    CaesarCipher cc1{key};
    CaesarCipher cc2{keyStr};
    const std::string plainText{"HELLOWORLD"};
    const std::string cipherText{"ROVVYGYBVN"};

    REQUIRE_NOTHROW(makeCaesarCipherFromString(keyStr));

    SECTION("encryption"){
        REQUIRE(cc1.applyCipher(plainText, CipherMode::Encrypt)==cipherText);
        REQUIRE(cc2.applyCipher(plainText, CipherMode::Encrypt)==cipherText);
    }
    SECTION("decryption"){
        REQUIRE(cc1.applyCipher(cipherText, CipherMode::Decrypt)==plainText);
        REQUIRE(cc2.applyCipher(cipherText, CipherMode::Decrypt)==plainText);
    }
}

TEST_CASE("Caesar cipher with negative key", "[cesar]"){
    REQUIRE_THROWS_AS(makeCaesarCipherFromString("-1"), InvalidKey);
}
TEST_CASE("Caesar cipher with non-numeric key", "[cesar]"){
    REQUIRE_THROWS_AS(makeCaesarCipherFromString("hello"), InvalidKey);
}
TEST_CASE("Caesar cipher with too large key", "[cesar]"){
    REQUIRE_THROWS_AS(makeCaesarCipherFromString("199999999999999999999999999"), InvalidKey);
}