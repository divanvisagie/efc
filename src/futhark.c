#include "futhark.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

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

struct latin_rune_pair {
	char* latin;
	char* rune;
};

struct latin_rune_pair latin_rune_pairs[] = {
	{ "a" ,  ansuz },
	{ "b" ,  berkanan },
	{ "c",   kaunan },
	{ "d",   dagaz },
	{ "e",   ehwaz },
	{ "f",   fehu },
	{ "g",   gebo },
	{ "h",   hagalaz },
	{ "ei",  sowilo }
};

void init_futhark() {
   
    // map_init(&latin_futhark_map);

    // map_set(&latin_futhark_map, "a", ansuz);
    // map_set(&latin_futhark_map, "b", berkanan);
    // map_set(&latin_futhark_map, "c", kaunan);
    // map_set(&latin_futhark_map, "d", dagaz);

    // map_set(&latin_futhark_map, "f", fehu);
	// map_set(&latin_futhark_map, "u", uruz);
	// map_set(&latin_futhark_map, "þ", thurisaz);
	// map_set(&latin_futhark_map, "a", ansuz);
	// map_set(&latin_futhark_map, "r", raido);
	// map_set(&latin_futhark_map, "k", kaunan);
	// map_set(&latin_futhark_map, "c", kaunan);
	// map_set(&latin_futhark_map, "g", gebo);
	// map_set(&latin_futhark_map, "w", wunjo);
	// map_set(&latin_futhark_map, "h", hagalaz);
	// map_set(&latin_futhark_map, "n", naudiz);
	// map_set(&latin_futhark_map, "i", isaz);
	// map_set(&latin_futhark_map, "j", jera);
	// map_set(&latin_futhark_map, "y", jera);
	// map_set(&latin_futhark_map, "æ", eihwaz);
	// map_set(&latin_futhark_map, "ï", eihwaz);
	// map_set(&latin_futhark_map, "p", perth);
	// map_set(&latin_futhark_map, "z", algiz);
	// map_set(&latin_futhark_map, "s", sowilo);
	// map_set(&latin_futhark_map, "t", tiwaz);
	// map_set(&latin_futhark_map, "b", berkanan);
	// map_set(&latin_futhark_map, "e", ehwaz);
	// map_set(&latin_futhark_map, "m", mannaz);
	// map_set(&latin_futhark_map, "l", laguz);
	// map_set(&latin_futhark_map, "ŋ", ingwaz);
	// map_set(&latin_futhark_map, "o", othala);
	// map_set(&latin_futhark_map, "d", dagaz);
	// map_set(&latin_futhark_map, "v", fehu);
	// map_set(&latin_futhark_map, "ð", thurisaz);

    /**
     * Set x to use the ks sound
      */
    // int x_size = sizeof(kaunan) + sizeof(sowilo);
    // char x[x_size];
    // sprintf(x, "%s%s", kaunan,sowilo);
	// map_set(&latin_futhark_map, "x", strdup(x));

	// map_set(&latin_futhark_map, "ch", gebo);
	// map_set(&latin_futhark_map, "ij", ehwaz);
	// map_set(&latin_futhark_map, "cc" , x);

	// map_set(&latin_futhark_map, "th",  thurisaz);
	// map_set(&latin_futhark_map, "eau", othala);

    /**
     * Set chr to be hr
    */
    // char chr[sizeof(char)*2];
    // strcat(chr, hagalaz);
    // strcat(chr, raido);
	// map_set(&latin_futhark_map, "chr", chr);

	// map_set(&latin_futhark_map, "ing", ingwaz);

    /**
     * Set chl to be hl
    */
    // char chl[sizeof(char)*2];
    // strcat(chl, hagalaz);
    // strcat(chl, laguz);
	// map_set(&latin_futhark_map, "chl", chl);


	// map_set(&latin_futhark_map, "ng",  ingwaz);

	// "chj": hagalaz + jera,
	// "nk":  ingwaz + kaunan,
	// "chw": hagalaz + wunjo,
	// "ei":  sowilo,
	// "ø":   othala + ehwaz,
	// "å":   ansuz + ansuz,

	// "q": kaunan,
}

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

char* get_futhark_for_latin(char* latin) {
	latin = to_lower_case(strdup(latin));
	int size = sizeof(latin_rune_pairs)/sizeof(struct latin_rune_pair);
	
	for(int i=0; i < size; i++) {
		latin = replace(latin, latin_rune_pairs[i].latin, latin_rune_pairs[i].rune);
	}

	free(latin);
    return latin;
}


