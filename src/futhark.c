#include "futhark.h"
#include "deps/map/map.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

char*   fehu     = "ᚠ";
char*   uruz     = "ᚢ";
char*   thurisaz = "ᚦ";
char*	ansuz    = "ᚨ";
char*	raido    = "ᚱ";
char*	kaunan   = "ᚲ";
char*	gebo     = "ᚷ";
char*	wunjo    = "ᚹ";
char*	hagalaz  = "ᚺ";
char*	naudiz   = "ᚾ";
char*	isaz     = "ᛁ";
char*	jera     = "ᛃ";
char*	eihwaz   = "ᛇ";
char*	perth    = "ᛈ";
char*	algiz    = "ᛉ";
char*	sowilo   = "ᛋ";
char*	tiwaz    = "ᛏ";
char*	berkanan = "ᛒ";
char*	ehwaz    = "ᛖ";
char*	mannaz   = "ᛗ";
char*	laguz    = "ᛚ";
char*	ingwaz   = "ᛜ";
char*	othala   = "ᛟ";
char*	dagaz    = "ᛞ";

map_str_t latin_futhark_map;

void init_futhark() {
   
    map_init(&latin_futhark_map);

    map_set(&latin_futhark_map, "a", ansuz);
    map_set(&latin_futhark_map, "b", berkanan);
    map_set(&latin_futhark_map, "c", kaunan);
    map_set(&latin_futhark_map, "d", dagaz);

    map_set(&latin_futhark_map, "f", fehu);
	map_set(&latin_futhark_map, "u", uruz);
	map_set(&latin_futhark_map, "þ", thurisaz);
	map_set(&latin_futhark_map, "a", ansuz);
	map_set(&latin_futhark_map, "r", raido);
	map_set(&latin_futhark_map, "k", kaunan);
	map_set(&latin_futhark_map, "c", kaunan);
	map_set(&latin_futhark_map, "g", gebo);
	map_set(&latin_futhark_map, "w", wunjo);
	map_set(&latin_futhark_map, "h", hagalaz);
	map_set(&latin_futhark_map, "n", naudiz);
	map_set(&latin_futhark_map, "i", isaz);
	map_set(&latin_futhark_map, "j", jera);
	map_set(&latin_futhark_map, "y", jera);
	map_set(&latin_futhark_map, "æ", eihwaz);
	map_set(&latin_futhark_map, "ï", eihwaz);
	map_set(&latin_futhark_map, "p", perth);
	map_set(&latin_futhark_map, "z", algiz);
	map_set(&latin_futhark_map, "s", sowilo);
	map_set(&latin_futhark_map, "t", tiwaz);
	map_set(&latin_futhark_map, "b", berkanan);
	map_set(&latin_futhark_map, "e", ehwaz);
	map_set(&latin_futhark_map, "m", mannaz);
	map_set(&latin_futhark_map, "l", laguz);
	map_set(&latin_futhark_map, "ŋ", ingwaz);
	map_set(&latin_futhark_map, "o", othala);
	map_set(&latin_futhark_map, "d", dagaz);
	map_set(&latin_futhark_map, "v", fehu);
	map_set(&latin_futhark_map, "ð", thurisaz);

    /**
     * Set x to use the ks sound
      */
    int x_size = sizeof(kaunan) + sizeof(sowilo);
    char x[x_size];
    sprintf(x, "%s%s", kaunan,sowilo);
	map_set(&latin_futhark_map, "x", strdup(x));

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


	map_set(&latin_futhark_map, "ng",  ingwaz);

	// "chj": hagalaz + jera,
	// "nk":  ingwaz + kaunan,
	// "chw": hagalaz + wunjo,
	// "ei":  sowilo,
	// "ø":   othala + ehwaz,
	// "å":   ansuz + ansuz,

	// "q": kaunan,
}

void deinit_futhark() {
    map_deinit(&latin_futhark_map);
}

char* get_futhark_for_latin(char* latin) {
    char** val = map_get(&latin_futhark_map, latin);
	if (!val) {
		return latin;
	}
    return *val;
}


