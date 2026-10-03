## 0.2.0


* Document ``mulle_utf32regex_compile_options(` pattern, options)` and the ``MULLE_UTF32REGEX_EXTENDED`` (0x0001) option, which enables escapes and named character classes such as `[[:alpha:]]` and `[[:space:]]`.
* Document that ``mulle_utf32regex_range_for_index`` returns an invalid range for non-participating capture groups and out-of-range indices, to be checked via ``mulle_range_is_valid()`.`
* Note the new mulle-unicode dependency used to resolve named character classes.



feature: add named Unicode character classes and extended escape handling

* new `MULLE_UTF32REGEX_EXTENDED` option enables [[:alpha:]], [[:word:]], [[:ident:]], [[:digit:]], [[:space:]] and other named classes, matched via mulle-unicode predicates instead of expanded member lists
* named classes are answered from a 256-codepoint bitmap plus a plane mask, so large classes like [[:alpha:]] no longer scan hundreds of KB per input character
* extended mode resolves escapes \t \n \r \f \v \a \e and \] \\ \- \^ inside character classes; an unknown alphanumeric escape such as \d or \q is now a compile error rather than silently matching a letter
* add `mulle_utf32regex_compile_options()` to pass options; `mulle_utf32regex_compile()` remains as a zero-option wrapper
* `mulle_utf32regex_range_for_index()` now reports no-match via `mulle_not_found_e` instead of `LONG_MAX`
* fix alignment of the compiled program buffer by placing it in a union with a `mulle_utf32_t` member


### 0.1.2






* integration docs now centered on the mulle-core umbrella library
* added cmake, mulle-sde, and clib embedding instructions
* removed legacy quickstart and manual cmake install sections



* source files now carry BSD 3-clause license headers
* API documentation table of contents moved to asset/dox/api/toc/

### 0.1.1

Various small improvements
