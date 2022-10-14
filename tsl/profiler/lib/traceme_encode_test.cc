/* Copyright 2020 The TensorFlow Authors All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "tsl/profiler/lib/traceme_encode.h"

#include <string>

#include "absl/strings/str_cat.h"
#include "tsl/platform/platform.h"
#include "tsl/platform/test.h"

namespace tsl {
namespace profiler {
namespace {

TEST(TraceMeEncodeTest, NoArgTest) {
  EXPECT_EQ(TraceMeEncode("Hello!", {}), "Hello!");
}

TEST(TraceMeEncodeTest, OneArgTest) {
  EXPECT_EQ(TraceMeEncode("Hello", {{"context", "World"}}),
            "Hello#context=World#");
}

TEST(TraceMeEncodeTest, TwoArgsTest) {
  EXPECT_EQ(TraceMeEncode("Hello", {{"context", "World"}, {"request_id", 42}}),
            "Hello#context=World,request_id=42#");
}

TEST(TraceMeEncodeTest, ThreeArgsTest) {
  EXPECT_EQ(TraceMeEncode("Hello", {{"context", "World"},
                                    {"request_id", 42},
                                    {"addr", absl::Hex(0xdeadbeef)}}),
            "Hello#context=World,request_id=42,addr=deadbeef#");
}

#if !defined(PLATFORM_WINDOWS)
TEST(TraceMeEncodeTest, TemporaryStringTest) {
  EXPECT_EQ(TraceMeEncode("Hello", {{std::string("context"),
                                     absl::StrCat("World:", 2020)}}),
            "Hello#context=World:2020#");
}
#endif

TEST(TraceMeEncodeTest, NoNameTest) {
  EXPECT_EQ(TraceMeEncode({{"context", "World"}, {"request_id", 42}}),
            "#context=World,request_id=42#");
}

}  // namespace
}  // namespace profiler
}  // namespace tsl