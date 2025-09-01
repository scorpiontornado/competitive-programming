CXX = g++-15 # changed from g++, cause aliases don't apply outside a shell & /usr/bin/gcc is actually Apple clang by default

# (removed `-fsanitize=address -fsanitize=undefined` from after -D_FORTIFY_SOURCE=2, doesn't support macOS)
CPPFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
           -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
           -fno-sanitize-recover -fstack-protector \
           -O2 -std=c++20 # changed from --std=c++17 -g

# --- CSE ---
# CXX = g++
# CPPFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
#            -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
#            -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector \
#            -O2 --std=c++20 -g # changed from --std=c++17 -g
