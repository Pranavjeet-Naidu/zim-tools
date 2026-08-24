#include <stdexcept>

#include "../src/zimsplit_size.h"
#include "gtest/gtest.h"

namespace
{

#define EXPECT_INVALID_ARG_ERROR(statement, expectedError)                      \
  do {                                                                         \
    try {                                                                      \
      statement;                                                               \
      FAIL() << "Expected std::invalid_argument";                              \
    } catch (const std::invalid_argument& error) {                              \
      EXPECT_STREQ(error.what(), expectedError);                                \
    }                                                                          \
  } while (false)

constexpr auto TOO_LARGE_PART_SIZE_ERROR
    = "part size must be smaller than the input ZIM file";

}  // namespace

TEST(ZimSplitSize, ValidatesPartSizeAgainstArchive)
{
  EXPECT_NO_THROW(validatePartSize(99, 100));
  EXPECT_INVALID_ARG_ERROR(validatePartSize(100, 100),
                           TOO_LARGE_PART_SIZE_ERROR);
  EXPECT_INVALID_ARG_ERROR(validatePartSize(101, 100),
                           TOO_LARGE_PART_SIZE_ERROR);
}
