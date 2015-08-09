
var isAnagram = require("./ValidAnagram.js")
var TESTLIB = require("../common/testlib.js")

TESTLIB.ASSERT_TRUE(isAnagram("", ""))
TESTLIB.ASSERT_FALSE(isAnagram("a", "b"))
TESTLIB.ASSERT_TRUE(isAnagram("ab", "ba"))
TESTLIB.ASSERT_FALSE(isAnagram("abc", "bc"))


