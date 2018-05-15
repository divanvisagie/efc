#include "futhark.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

static char* const  fehu     = "ᚠ";
static char* const  uruz     = "ᚢ";
static char* const  thurisaz = "ᚦ";
static char* const	ansuz    = "ᚨ";
static char* const	raido    = "ᚱ";
static char* const	kaunan   = "ᚲ";
static char* const	gebo     = "ᚷ";
static char* const	wunjo    = "ᚹ";
static char* const	hagalaz  = "ᚺ";
static char* const	naudiz   = "ᚾ";
static char* const	isaz     = "ᛁ";
static char* const	jera     = "ᛃ";
static char* const	eihwaz   = "ᛇ";
static char* const	perth    = "ᛈ";
static char* const	algiz    = "ᛉ";
static char* const	sowilo   = "ᛋ";
static char* const	tiwaz    = "ᛏ";
static char* const	berkanan = "ᛒ";
static char* const	ehwaz    = "ᛖ";
static char* const	mannaz   = "ᛗ";
static char* const	laguz    = "ᛚ";
static char* const	ingwaz   = "ᛜ";
static char* const	othala   = "ᛟ";
static char* const	dagaz    = "ᛞ";

static char* const othala_ehwaz  = "ᛟᛖ";
static char* const kaunan_sowilo = "ᚲᛋ";
static char* const ansuz_ansuz   = "ᚨ";
static char* const hagalaz_raido = "ᚺᚱ";
static char* const hagalaz_jera  = "ᚺᛃ";
static char* const ingwaz_kaunan = "ᛜᚲ";
static char* const hagalaz_wunjo = "ᚺᚹ";
static char* const hagalaz_laguz = "ᚺᛚ";

typedef struct latin_rune_pair {
	char* latin;
	char* rune;
};

struct latin_rune_pair latin_rune_pairs[] = {

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

struct latin_rune_pair latin_sound_rune_pair[] = {

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


/**
 * Taken from https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
*/
char* replace(char* s, char* victim, char* with) {
    char *result;
    int i, cnt = 0;
    int withlen = strlen(with);
    int victimlen = strlen(victim);
 
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], victim) == &s[i])
        {
            cnt++;
 
            // Jumping to index after the old word.
            i += victimlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char *)malloc(i + cnt * (withlen - victimlen) + 1);
 
    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, victim) == s)
        {
            strcpy(&result[i], with);
            i += withlen;
            s += victimlen;
        }
        else
            result[i++] = *s++;
    }
 
    result[i] = '\0';
    return result;
}

char* to_lower_case(char *s) {
  unsigned char *p = (unsigned char *)s;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return s;
}

char* replace_characters(char* victim, latin_rune_pair latin_rune_map[]) {
    victim = to_lower_case(strdup(victim));
	int size = sizeof(latin_rune_map)/sizeof(latin_rune_pair);
	
	for(int i=0; i < size; i++) {
		victim = replace(victim, latin_rune_map[i].latin, latin_rune_map[i].rune);
	}

	free(victim);
    return victim;
}

char* get_futhark_for_latin(char* latin, bool phonetics) {
	return replace_characters(latin, latin_rune_pairs);
}


