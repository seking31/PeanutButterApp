#ifndef NOTES_H
#define NOTES_H

#include <array>
#include <iostream>
#include <math.h>

namespace scales
{
  extern int* get_step_pattern(int mode, bool harmonic=false);
  extern int* get_pentatonic_pattern(int mode);
  extern int* get_blues_pattern(int mode);
}

namespace notes
{
  int* get_all_notes(int starting_note, int mode, bool harmonic);
  int find_lowest_note(int starting_note);
  int find_highest_note(int starting_note);
}

#endif
