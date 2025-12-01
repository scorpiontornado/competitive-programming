CXX = g++-15 # macOS: replace with g++-15 (installed via brew)
CPPFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal \
		   -Wconversion -Wlogical-op -D_GLIBCXX_DEBUG \
		   -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
		   -fno-sanitize-recover -fstack-protector \
           -O2 --std=c++23 # -g
# macOS: remove -fsanitize=address -fsanitize=undefined
