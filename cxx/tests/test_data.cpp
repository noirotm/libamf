#include <gtest/gtest.h>

#include <amf/data.hpp>

namespace {

TEST(DataTest, EqualityWorks) {
    amf::undefined undef1, undef2;
    amf::null null1, null2;

    EXPECT_TRUE(undef1 == undef2) << "undef data not equal";
    EXPECT_TRUE(null1 == null2) << "null data not equal";
    EXPECT_FALSE(undef1 == null1) << "null data and undef data equal";
    EXPECT_FALSE(undef2 == null1) << "null data and undef data equal";
    EXPECT_FALSE(undef1 == null2) << "null data and undef data equal";
    EXPECT_FALSE(undef2 == null2) << "null data and undef data equal";
}

TEST(DataTest, InequalityWorks) {
    amf::undefined undef1, undef2;
    amf::null null1, null2;

    EXPECT_FALSE(undef1 != undef2) << "undef data not equal";
    EXPECT_FALSE(null1 != null2) << "null data not equal";
    EXPECT_TRUE(undef1 != null1) << "null data and undef data equal";
    EXPECT_TRUE(undef2 != null1) << "null data and undef data equal";
    EXPECT_TRUE(undef1 != null2) << "null data and undef data equal";
    EXPECT_TRUE(undef2 != null2) << "null data and undef data equal";
}

TEST(UndefinedTest, UndefinedWorks) {
    amf::undefined undef;
    EXPECT_EQ(amf::TYPE_UNDEFINED, undef.getType()) << "incorrect type: " << undef.getType();
}

TEST(NullTest, NullWorks) {
    amf::null n;
    EXPECT_EQ(amf::TYPE_NULL, n.getType()) << "incorrect type: " << n.getType();
}

TEST(BooleanTest, ConstructorWorks) {
    amf::boolean b;
    EXPECT_EQ(amf::TYPE_BOOLEAN, b.getType()) << "incorrect type: " << b.getType();
}

TEST(BooleanTest, ConstructorWithParamWorks) {
    amf::boolean b(true);
    EXPECT_EQ(amf::TYPE_BOOLEAN, b.getType()) << "incorrect type: " << b.getType();
    EXPECT_EQ(true, (bool)b) << "incorrect value: " << (bool)b;
}

TEST(BooleanTest, AssignConstructorWorks) {
    amf::boolean b = true;
    EXPECT_EQ(amf::TYPE_BOOLEAN, b.getType()) << "incorrect type: " << b.getType();
    EXPECT_EQ(true, (bool)b) << "incorrect value: " << (bool)b;
}

TEST(BooleanTest, CopyConstructorWorks) {
    amf::boolean b1 = true;
    amf::boolean b2 = b1;
    EXPECT_EQ(amf::TYPE_BOOLEAN, b2.getType()) << "incorrect type: " << b2.getType();
    EXPECT_EQ(true, (bool)b2) << "incorrect value: " << (bool)b2;
}

TEST(BooleanTest, AssignWorks) {
    amf::boolean b1;
    amf::boolean b2;
    
    b1 = true;
    EXPECT_EQ(true, (bool)b1) << "incorrect value: " << (bool)b1;

    b2 = b1;
    EXPECT_EQ(true, (bool)b2) << "incorrect value: " << (bool)b2;

    b2 = b1 = false;
    EXPECT_EQ(false, (bool)b1) << "incorrect value: " << (bool)b1;
    EXPECT_EQ(false, (bool)b2) << "incorrect value: " << (bool)b2;
}

TEST(BooleanTest, EqualityWorks) {
    amf::boolean b1(false), b2(false), b3(true), b4(true);

    EXPECT_TRUE(b1 == b2) << "bool data not equal";
    EXPECT_TRUE(b3 == b4) << "bool data not equal";
    EXPECT_FALSE(b1 == b3) << "bool data equal";
    EXPECT_FALSE(b2 == b3) << "bool data equal";
    EXPECT_FALSE(b1 == b4) << "bool data equal";
    EXPECT_FALSE(b2 == b4) << "bool data equal";
}

TEST(BooleanTest, InequalityWorks) {
    amf::boolean b1(false), b2(false), b3(true), b4(true);

    EXPECT_FALSE(b1 != b2) << "bool data not equal";
    EXPECT_FALSE(b3 != b4) << "bool data not equal";
    EXPECT_TRUE(b1 != b3) << "bool data equal";
    EXPECT_TRUE(b2 != b3) << "bool data equal";
    EXPECT_TRUE(b1 != b4) << "bool data equal";
    EXPECT_TRUE(b2 != b4) << "bool data equal";
}

TEST(IntegerTest, ConstructorWorks) {
    amf::integer i;
    EXPECT_EQ(amf::TYPE_INTEGER, i.getType()) << "incorrect type: " << i.getType();
}

TEST(IntegerTest, ConstructorWithParamWorks) {
    amf::integer i(654);
    EXPECT_EQ(amf::TYPE_INTEGER, i.getType()) << "incorrect type: " << i.getType();
    EXPECT_EQ(654, (int)i) << "incorrect value: " << (int)i;
}

TEST(IntegerTest, AssignConstructorWorks) {
    amf::integer i = -251;
    EXPECT_EQ(amf::TYPE_INTEGER, i.getType()) << "incorrect type: " << i.getType();
    EXPECT_EQ(-251, (int)i) << "incorrect value: " << (int)i;
}

TEST(IntegerTest, CopyConstructorWorks) {
    amf::integer i1 = 7;
    amf::integer i2 = i1;
    EXPECT_EQ(amf::TYPE_INTEGER, i2.getType()) << "incorrect type: " << i2.getType();
    EXPECT_EQ(7, (int)i2) << "incorrect value: " << (int)i2;
}

TEST(IntegerTest, AssignWorks) {
    amf::integer i1;
    amf::integer i2;
    
    i1 = -89;
    EXPECT_EQ(-89, (int)i1);

    i2 = i1;
    EXPECT_EQ(-89, (int)i2);

    i2 = i1 = 720;
    EXPECT_EQ(720, (int)i1);
    EXPECT_EQ(720, (int)i2);
}

TEST(IntegerTest, EqualityWorks) {
    amf::integer i1(81), i2(81), i3(-12), i4(-12);

    EXPECT_TRUE(i1 == i2);
    EXPECT_TRUE(i3 == i4);
    EXPECT_FALSE(i1 == i3);
    EXPECT_FALSE(i2 == i3);
    EXPECT_FALSE(i1 == i4);
    EXPECT_FALSE(i2 == i4);
}

TEST(IntegerTest, InequalityWorks) {
    amf::integer i1(81), i2(81), i3(-12), i4(-12);

    EXPECT_FALSE(i1 != i2);
    EXPECT_FALSE(i3 != i4);
    EXPECT_TRUE(i1 != i3);
    EXPECT_TRUE(i2 != i3);
    EXPECT_TRUE(i1 != i4);
    EXPECT_TRUE(i2 != i4);
}

TEST(IntegerTest, ComparisonWorks) {
    amf::integer i1(5), i2(5), i3(35);
    EXPECT_TRUE(i1 < i3);
    EXPECT_TRUE(i1 <= i3);
    EXPECT_TRUE(i1 <= i2);
    EXPECT_FALSE(i1 > i3);
    EXPECT_FALSE(i1 >= i3);
    EXPECT_TRUE(i1 >= i2);
}

TEST(StringTest, ConstructorWorks) {
    amf::string s;
    EXPECT_EQ(amf::TYPE_STRING, s.getType());
}

TEST(StringTest, AssignConstructorWorks) {
    amf::string s = "tototest";
    EXPECT_EQ("tototest", static_cast<std::string>(s));
}

} // namespace

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
