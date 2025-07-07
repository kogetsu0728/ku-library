#pragma once

#ifdef ONLINE_JUDGE
inline constexpr bool IS_LOCAL = false;
#else
inline constexpr bool IS_LOCAL = true;
#endif

#define IF_LOCAL if constexpr (IS_LOCAL)
