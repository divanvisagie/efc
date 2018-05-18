#include "futhark.h"
#include "string_replacer.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define fehu      "ᚠ"
#define uruz      "ᚢ"
#define thurisaz  "ᚦ"
#define ansuz     "ᚨ"
#define raido     "ᚱ"
#define kaunan    "ᚲ"
#define gebo      "ᚷ"
#define wunjo     "ᚹ"
#define hagalaz   "ᚺ"
#define naudiz    "ᚾ"
#define isaz      "ᛁ"
#define jera      "ᛃ"
#define eihwaz    "ᛇ"
#define perth     "ᛈ"
#define algiz     "ᛉ"
#define sowilo    "ᛋ"
#define tiwaz     "ᛏ"
#define berkanan  "ᛒ"
#define ehwaz     "ᛖ"
#define mannaz    "ᛗ"
#define laguz     "ᛚ"
#define ingwaz    "ᛜ"
#define othala    "ᛟ"
#define dagaz     "ᛞ"

#define othala_ehwaz  "ᛟᛖ"
#define kaunan_sowilo "ᚲᛋ"
#define ansuz_ansuz   "ᚨ"
#define hagalaz_raido "ᚺᚱ"
#define hagalaz_jera  "ᚺᛃ"
#define ingwaz_kaunan "ᛜᚲ"
#define hagalaz_wunjo "ᚺᚹ"
#define hagalaz_laguz "ᚺᛚ"

typedef struct latin_rune_pair_s {
	char* latin;
	char* rune;
} latin_rune_pair;

#define LRP_LEN 33
latin_rune_pair latin_rune_pairs[] = {

    // Basic Latin Alphabet
	{ "a" ,  ansuz },
	{ "b" ,  berkanan },
	{ "c",   kaunan },
	{ "d",   dagaz },
	{ "e",   ehwaz },
	{ "f",   fehu },
	{ "g",   gebo },
	{ "h",   hagalaz },
	{ "i",   ingwaz },
	{ "j",   jera },
	{ "k",   kaunan },
	{ "l",   laguz },
	{ "m",   mannaz },
	{ "n",   naudiz },
	{ "o",   othala },
	{ "p",   perth },
	{ "q",   kaunan },
	{ "r",   raido },
	{ "s",   sowilo },
    { "t",   tiwaz },
    { "u",   uruz },
    { "v",   fehu },
    { "w",   wunjo },
    { "x",   kaunan_sowilo },
    { "y",   jera },
    { "z",   algiz },

    // Extended Latin Alphabet
	{ "þ",   thurisaz },
	{ "æ",   eihwaz },
	{ "ï",   eihwaz },
	{ "ŋ",   ingwaz },
	{ "ð",   thurisaz },
    { "ø",   othala_ehwaz },
	{ "å",   ansuz_ansuz }

};

#define LSP_LEN 13
latin_rune_pair latin_sound_rune_pairs[] = {

    /**
     * The longer phonetics must go first because they are more unique and will 
     * not be replaced by the shorter strings later.
    */
    { "eau",  othala },
	{ "chr",  hagalaz_raido },
	{ "ing",  ingwaz },
	{ "chl",  hagalaz_laguz },
	{ "chj",  hagalaz_jera },
	{ "chw",  hagalaz_wunjo },

	{ "ch" , gebo },
	{ "ij" , ehwaz },
	{ "cc" , kaunan_sowilo },
	{ "th" ,  thurisaz },
	{ "ng" ,  ingwaz },
	{ "nk" ,  ingwaz_kaunan },
	{ "ei" ,  sowilo }
};

char* to_lower_case (char *s) {
  unsigned char *p = (unsigned char *)s;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return s;
}

char* replace_latin_characters (char* victim, latin_rune_pair latin_rune_map[], int length) {
    victim = to_lower_case(strdup(victim));
	for (int i = 0; i < length; i++) {
		victim = replace(victim, latin_rune_map[i].latin, latin_rune_map[i].rune);
	}
	free (victim);
    return victim;
}

char* replace_rune_characters (char* victim, latin_rune_pair latin_rune_map[], int length) {
    victim = to_lower_case(strdup(victim));
    for (int i = 0; i < length; i++) {
        victim = replace(victim, latin_rune_map[i].rune, latin_rune_map[i].latin);
    }
    free (victim);
    return victim;
}

char* get_futhark_for_latin (char* latin, bool phonetics) {
    if (phonetics) {
        latin = replace_latin_characters(latin, latin_sound_rune_pairs, LSP_LEN);
    }
    latin = replace_latin_characters(latin, latin_rune_pairs, LRP_LEN);

    return latin;
}

char* get_latin_for_futhark(char* futhark, bool phonetics) {
    if (phonetics) {
        futhark = replace_rune_characters(futhark, latin_sound_rune_pairs, LSP_LEN);
    }
    futhark = replace_rune_characters(futhark, latin_rune_pairs, LRP_LEN);

    return futhark;
}