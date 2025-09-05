// Author: scorpiontornado
// Created: 2025-09-05 10:14pm
// Source: https://atcoder.jp/contests/abc419/tasks/abc419_f

// OBS: tiny input (<= 8 strings of length <= 100), mod huge prime
// - nvm, string length acc <= 10; L <= 100 is the "superstring" length
// IDEA: "What is a substring?" -> delete chars from start/end, so to make
//      "superstrings", add to start/end.
//! EDGE: S_i substring of S_j
//! EDGE: double-counting when adding another substring (de-duplicate, but can't
//!     store all? Way too many) ... e.g. if have "abc" & "def", can't start w
//!     "abc" then add d, then e, then f & end up with abcdef ... then start w
//!     "def" & add "abc" to front, etc

// (10:22pm) ... wait, just realised, all must contain all S_i as substrings
//  -> ? S1 ? S2 ? S3 ? ... ? S8 ?, and all permutations of S's
//  -> still might double-count if the ?'s are one of S.... & need len of ? and
//  S_i to sum to L
// 10:24pm, feeling kinda close but not rly, 25 min left... was going so well!

// Feels kinda DP but idk what the state would be...! Could also just be
// combinatorics? (Which ig is often DP in disguise)
