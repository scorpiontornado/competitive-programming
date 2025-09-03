// Author: scorpiontornado
// Created: 2025-09-04 2:21am
// Source: https://atcoder.jp/contests/abc420/tasks/abc420_f

// IDEA: 2D prefix sum of number of '.'s, then check for all rectangular regions
// of size <= K, does count == size (width * height)?
//  -> initially motivated by bounds, 10^5... wait gg doesn't that make n^2 too
//  slow? -> nvm, N * M <= 5e6... still, surely many many regions? 2:24:00am,
//  move on... think D is a straightforward BFS, bit unsure about E.
#