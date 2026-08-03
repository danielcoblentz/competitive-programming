
// Return ans, or 0/1 as a fallback if ans wasn't set (0 if nums is empty, else 1).
int result = max(ans, nums.empty() ? 0 : 1); // pick the larger of ans and the fallback
// condition ? value_if_true : value_if_false
//     ^            ^               ^
//     │            │               └── result when condition is false
//     │            └────────────────── result when condition is true
//     └─────────────────────────────── bool expression being tested
