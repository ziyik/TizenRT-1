/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// size_type size() const;

#include <string>
#include <cassert>
#include "test_macros.h"
#include "libcxx_tc_common.h"


template <class S>
static int
test(const S& s, typename S::size_type c)
{
    TC_ASSERT_EXPR(s.size() == c);
    return 0;
}

int tc_libcxx_strings_string_capacity_size(void)
{
    {
    typedef std::string S;
    TC_ASSERT_FUNC((test(S(), 0)));
    TC_ASSERT_FUNC((test(S("123"), 3)));
    TC_ASSERT_FUNC((test(S("12345678901234567890123456789012345678901234567890"), 50)));
    }
    TC_SUCCESS_RESULT();
    return 0;
}
