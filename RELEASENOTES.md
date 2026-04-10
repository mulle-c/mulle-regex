## 0.1.0







feature: export public regex API symbols for proper linking

* annotate public mulle-utf32regex APIs with `MULLE__REGEX_GLOBAL` so symbols (compile, execute, substitute, match, `substitution_length,` `range_for_index,` dump) are exported and usable across shared/static builds
* make visibility macros selectable based on build flags `(MULLE__REGEX_BUILD` / `MULLE_REGEX_INCLUDE_DYNAMIC),` improving portability of library exports
