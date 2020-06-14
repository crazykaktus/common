#include <gtest/gtest.h>
#include <exceptions/Exception.hpp>

TEST(Exception, Constructor)
{
    EXPECT_NO_THROW(kaktus::Exception customException("Somethings is wrong"));
    EXPECT_NO_THROW(kaktus::Exception customException2("Somethings is wrong", {}));
}
TEST(Exception, RaiseException)
{
    try
    {
        throw kaktus::Exception("Somethings is wrong");
    }
    catch (std::exception &exception)
    {
        std::string errorMessage(exception.what());
        std::cout << errorMessage << std::endl;
        EXPECT_FALSE(errorMessage.empty());
    }

    try
    {
        throw kaktus::Exception("Somethings is wrong", {});
    }
    catch (std::exception &exception)
    {
        std::string errorMessage(exception.what());
        std::cout << errorMessage << std::endl;
        EXPECT_FALSE(errorMessage.empty());
    }
}

TEST(Exception, Message)
{
    const std::string errorMessage = "Here we have some error to solve.";
    try
    {
        throw kaktus::Exception(errorMessage.c_str());
    }
    catch (std::exception &exception)
    {
        std::string raisedErrorMessage(exception.what());
        std::cout << raisedErrorMessage << std::endl;
        ASSERT_NE(raisedErrorMessage.find(errorMessage), std::string::npos);
    }
}
