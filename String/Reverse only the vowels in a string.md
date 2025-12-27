# Python DSA Notes – Reverse only the vowels in a string, keeping all other characters in the same position.

## ❌ Naive Thinking (Common First Thought)
__Idea 1: Extract vowels, reverse them, reinsert__

Steps:

- Traverse string → collect vowels
- Reverse vowel list
- Traverse string again → replace vowels one by one

Pseudocode
```
vowels_list = []
for char in s:
    if vowel:
        add to vowels_list

reverse(vowels_list)

for i in range(len(s)):
    if s[i] is vowel:
        replace with vowels_list.pop(0)
```
⏱ Complexity

- Time: O(n)
- Space: O(n)

✅ Correct
- ❌ Extra space + two passes

💡 Better Intuition: Two Ends, One Goal
- Key observation

First vowel to be replaced comes from last vowel

Last vowel to be replaced comes from first vowel

👉 This screams TWO POINTERS
## 1. Python Strings Are Immutable
- You cannot change characters in a string directly.
 - s[i] = 'a'   ❌

```
str_list = list(s)     # convert to list
s = "".join(str_list) # convert back to string
```

- Strings = read-only
- Lists = editable

## 2. Why "".join(str_list) is needed
- join() rebuilds a string from a list of characters.
- "" means no separator.
- ['h','o','l','l','e'] → "holle"

## 3. Membership checks: list vs set
- If you are checking presence often, use a set

```
vowels = ['a','e','i','o','u','A','E','I','O','U']
vowels = set('aeiouAEIOU')
```

### Access or Search
- List	O(n)
- Set	O(1)

## 4. Two-Pointer Technique (MOST IMPORTANT)
### ❌ Common mistake you made

- Moving i and j every loop iteration
- Causing skipped characters and wrong swaps

### ✅ Correct Pointer Rules
```
If left is not valid → move left pointer
If right is not valid → move right pointer
If both valid → swap AND move both
```

### ✅ Correct Template (Memorize This)
```
while i < j:
    if left_not_valid:
        i += 1
    elif right_not_valid:
        j -= 1
    else:
        swap
        i += 1
        j -= 1
```

## 5. Swapping Logic

- if both_are_valid   ✅
- e ↔ o  → valid swap even if characters differ

## 6. Loop Boundaries Matter
```
Always protect inner loops:

while i < j and condition:

❌ Otherwise:

Index out of bounds

Infinite loops

```

### 7. Final Correct Solution
```
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        str_list = list(s)
        i, j = 0, len(str_list) - 1

        while i < j:
            if str_list[i] not in vowels:
                i += 1
            elif str_list[j] not in vowels:
                j -= 1
            else:
                str_list[i], str_list[j] = str_list[j], str_list[i]
                i += 1
                j -= 1

        return "".join(str_list)
```