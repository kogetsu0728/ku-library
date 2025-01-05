#pragma once

#ifdef ONLINE_JUDGE
constexpr bool IS_LOCAL = false;
#else
constexpr bool IS_LOCAL = true;
#endif

#define IF_LOCAL if constexpr (IS_LOCAL)
